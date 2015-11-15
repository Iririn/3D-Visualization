#include "headDetector.h"

namespace posedetector {
	
HeadDetector::HeadDetector() 
{

}

void HeadDetector::foo()
{
	std::string temp = "hello world";
	cout << "Temp: " << temp << endl;
}

void HeadDetector::initializeCamera()
{
	// Load cascade classifier
	// cout << face_cascade_name << endl;
	// if (!face_cascade->load(face_cascade_name)) {
	// 	cerr << "Fail to load 'haarcascade_frontalface_alt.xml'" << endl;
	// } else {
	// 	cout << "Load cascade classifier succeed" << endl;
	// }

	// Open video stream
	videoCapture->open(0);
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




