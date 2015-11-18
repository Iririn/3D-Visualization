#include "headDetector.h"

namespace posedetector {
	
HeadDetector::HeadDetector() {}

void HeadDetector::foo()
{
	this->temp = "test";
	cout << temp << endl;
}

int HeadDetector::loadCascade(std::string _cascade)
{
	// "/usr/local/share/OpenCV/haarcascades/haarcascade_frontalface_alt.xml"
	face_cascade_name = _cascade;

	if (!face_cascade.load(face_cascade_name)) {
		cerr << "Fail to load 'haarcascade_frontalface_alt.xml'" << endl;
		return 1;
	} else {
		cout << "Load cascade classifier succeed" << endl;
		return 0;
	}
}
/*
Initial camera to grab color image for eye detection
*/
int HeadDetector::initializeCamera()
{
	videoCapture.open(0);
	
	if (!videoCapture.isOpened()) {
		cerr << "Camera open failed" << endl;
		return 1;
	} else {
		camWidth = (int) videoCapture.get(CV_CAP_PROP_FRAME_WIDTH);
    	camHeight = (int) videoCapture.get(CV_CAP_PROP_FRAME_HEIGHT);
		
		cout << "Camera initial succeed" << endl;
		return 0;
	}
}

void 

void HeadDetector::testVideo()
{
	// Open video stream
	videoCapture.open(0);
	
	cv::namedWindow("Test", CV_WINDOW_AUTOSIZE);
	
	while (1) {
		if (!videoCapture.read(frame)) {
			cerr << "Fail to read frame" << endl;
			break;
		}
		
		cv::imshow("Test", frame);
		// if (cv::waitKey() == 27) {
		// 	cout << "Video capture end" << endl;
		// 	break;
		// }
	}
}

} // end namespace




