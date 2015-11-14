cmake_minimum_required (VERSION 2.8.9)

find_package(
	OpenGL REQUIRED
	GLUT REQUIRED
)
include_directories(
	/System/Library/Frameworks/OpenGL.framework/Headers
	/System/Library/Frameworks/GLUT.framework/Headers	
	include
)

aux_source_directory(src DIR_SRCS)
add_executable(HelloWorld ${DIR_SRCS})

target_link_libraries(HelloWorld ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

