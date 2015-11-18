#include <opencv.hpp>
#include <highgui.hpp>
#include <imgproc.hpp>
#include <core.hpp>

#include "common.h"

namespace posedetector {

class HeadDetector {
private:
	//Cascade Classifier
	std::string face_cascade_name;
	cv::CascadeClassifier face_cascade;
	
	// OpenCV x Camera
	cv::VideoCapture videoCapture;
	cv::Mat frame;
	
	// Camera frame size
	int camWidth;
	int camHeight;
	
public:
	// Constructor
	HeadDetector();
	
	// Testing
	std::string temp;

	// Functions
	void foo();
	void testVideo();
	
	int initializeCamera();
	int loadCascade(std::string _cascade);
};

} // end namespace

