#include "headDetector.h"

namespace posedetector {
	
HeadDetector::HeadDetector() 
{

}

void HeadDetector::foo()
{
	cv::Mat temp; // Create a cv::Mat matrix for testing
	cout << "Calling function from headDetector.cpp" << endl;
	cout << this->device << endl;
}

void HeadDetector::initializeCamera()
{
	// Load cascade classifier
	if (!face_cascade.load(face_cascade_name)) {
		cerr << "Fail to load 'haarcascade_frontalface_alt.xml'" << endl;
	} else {
		cout << "Load cascade classifier succeed" << endl;
	}

	// Open video stream
	videoCapture = new cv::VideoCapture(0);
	
	if (videoCapture == NULL || !videoCapture->isOpened()) {
		cerr << "Fail to open camera" << endl;
	} else {
		cout << "Video stream opened" << endl;
	}
}

void HeadDetector::testVideo()
{
	cv::namedWindow("Test", CV_WINDOW_AUTOSIZE);
	
	while (1) {
		if (!videoCapture->read(frame)) {
			cerr << "Fail to read frame" << endl;
			break;
		}
		
		cv::imshow("Test", frame);
		
		if (cv::waitKey() == 27) {
			cout << "Video capture end" << endl;
			break;
		}
	}
}

} //end namespace




