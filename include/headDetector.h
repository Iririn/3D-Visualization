#include <opencv.hpp>
#include <highgui.hpp>
#include <imgproc.hpp>
#include <core.hpp>

#include "common.h"

namespace posedetector {

class HeadDetector {
private:
	//Cascade Classifier & some variable for OpenCV
	const std::string face_cascade_name = "/usr/local/share/OpenCV/haarcascades/haarcascade_frontalface_alt.xml";
	cv::CascadeClassifier face_cascade;
	cv::VideoCapture videoCapture;
	cv::Mat frame;
	
public:
	// Constructor
	HeadDetector();
	
	// Testing
	std::string temp;

	// Functions
	void foo();
	void initializeCamera();
	void testVideo();
};

} // end namespace

