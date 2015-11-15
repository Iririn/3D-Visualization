cmake_minimum_required (VERSION 2.8.9)

project(3D_Visualization)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenCV REQUIRED)


include_directories(
	/System/Library/Frameworks/OpenGL.framework/Headers
	/System/Library/Frameworks/GLUT.framework/Headers
	#${OPENCV_LIBRARY_DIRS}
	/usr/local/include/opencv2
	/usr/local/include/opencv2/core
	/usr/local/include/opencv2/highgui
	/usr/local/include/opencv2/imgproc
	include
)

aux_source_directory(src DIR_SRCS)
add_executable(HelloWorld ${DIR_SRCS})

target_link_libraries(HelloWorld 
	${OPENGL_LIBRARIES} 
	${GLUT_LIBRARIES}
	${OpenCV_LIBS}
)

