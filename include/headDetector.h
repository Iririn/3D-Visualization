#include <opencv.hpp>
#include <highgui.hpp>
#include <imgproc.hpp>
#include <core.hpp>

#include "common.h"

namespace posedetector {

class HeadDetector {
private:
	//Cascade Classifier
	cv::CascadeClassifier face_cascade;
	cv::CascadeClassifier eye_cascade;
	
	// OpenCV x Camera
	cv::VideoCapture videoCapture;
	cv::Mat frame;
	cv::Mat gray;
	cv::Rect eyeRect;
	cv::Mat eyeTemp;
	
	// Camera frame size
	int camWidth;
	int camHeight;
	double glCamX;
	double glCamY;
	double glCamZ;
	
	const int minFaceSize = 80;
	const float focal = 500;
	const float eyesGap = 6.5;
	
public:
	// Constructor
	HeadDetector();
	
	// Testing
	std::string temp;

	// Functions
	void foo();
	void testVideo();
	
	int initializeCamera();
	int loadCascade();
	int detectEye(cv::Mat& gray, cv::Mat& eyeTemp, cv::Rect& eyeRect);
	void trackEye(cv::Mat& gray, cv::Mat& eyeTemp, cv::Rect& eyeRect);
};

} // end namespace

