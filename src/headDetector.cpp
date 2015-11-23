#include "headDetector.h"

namespace posedetector {
	
HeadDetector::HeadDetector() {}

void HeadDetector::foo()
{
	this->temp = "test";
	cout << temp << endl;
}

int HeadDetector::loadCascade()
{
	// "/usr/local/share/OpenCV/haarcascades/haarcascade_frontalface_alt.xml"
	face_cascade.load("/usr/local/share/OpenCV/haarcascades/haarcascade_frontalface_alt2.xml");
	eye_cascade.load("/usr/local/share/OpenCV/haarcascades/haarcascade_eye_tree_eyeglasses.xml");

	if (face_cascade.empty() || eye_cascade.empty()) {
		cerr << "Fail to cascade classifier" << endl;
		return 0;
	} else {
		cout << "Load cascade classifier succeed" << endl;
		return 1;
	}
}
/*
Initial camera to grab color image for eye detection
*/
int HeadDetector::initializeCamera()
{
	videoCapture.open(0);
	
	videoCapture.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	videoCapture.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	
	if (!videoCapture.isOpened()) {
		cerr << "Camera open failed" << endl;
		return 0;
	} else {
		camWidth = (int) videoCapture.get(CV_CAP_PROP_FRAME_WIDTH);
    	camHeight = (int) videoCapture.get(CV_CAP_PROP_FRAME_HEIGHT);
		
		cout << "Camera initial succeed" << endl;
		return 1;
	}
}

void HeadDetector::testVideo()
{
	// Load cascade and init camera
	loadCascade();
	initializeCamera();

	while (cv::waitKey(15) != 'q') {
		videoCapture >> frame;
		if (frame.empty()) {
			break;
		}
		cv::cvtColor(frame, gray, CV_BGR2GRAY);
		
		if (eyeRect.width == 0 && eyeRect.height == 0) {
			detectEye(gray, eyeTemp, eyeRect);
		} else {
			trackEye(gray, eyeTemp, eyeRect);
			cv::rectangle(frame, eyeRect, CV_RGB(0, 255, 0));
		}
		
		cv::imshow("Eye", frame);
	}
}

int HeadDetector::detectEye(cv::Mat& gray, cv::Mat& eyeTemp, cv::Rect& eyeRect)
{
	std::vector<cv::Rect> faces, eyes;
	face_cascade.detectMultiScale(gray, faces, 1.1, 2, CV_HAAR_SCALE_IMAGE, cv::Size(30, 30));
	
	if (!faces.size()) {
		return 0;
	}
	
	cv::Mat face = gray(faces[0]);
	eye_cascade.detectMultiScale(face, eyes, 1.1, 2, CV_HAAR_SCALE_IMAGE, cv::Size(20, 20));

	if (eyes.size()) {
		eyeRect = eyes[0] + cv::Point(faces[0].x, faces[0].y);
		eyeTemp = gray(eyeRect);
		
		cv::imshow("gray", eyeTemp);
		cv::waitKey(0);
	}
	
	return eyes.size();
}

void HeadDetector::trackEye(cv::Mat& gray, cv::Mat& eyeTemp, cv::Rect& eyeRect)
{
	cv::Size size(eyeRect.width * 2, eyeRect.height * 2);
	cv::Rect window(eyeRect + size - cv::Point(size.width / 2, size.height / 2));
	
	window &= cv::Rect(0, 0, gray.cols, gray.rows);
	
	cv::Mat dst(window.width - eyeTemp.rows + 1, window.height - eyeTemp.cols + 1, CV_32FC1);
	cv::matchTemplate(gray(window), eyeTemp, dst, CV_TM_SQDIFF_NORMED);
	
	double minval, maxval;
	cv::Point minloc, maxloc;
	cv::minMaxLoc(dst, &minval, &maxval, &minloc, &maxloc);
	
	if (minval <= 0.2) {
		cout << "X: " << minloc.x << " Y: " << minloc.y << endl;
		eyeRect.x = window.x + minloc.x;
		eyeRect.y = window.y + minloc.y;
	} else {
		cout << "zero" << endl;
		eyeRect.x = eyeRect.y = eyeRect.width = eyeRect.height = 0;	
	}
}

} // end namespace
