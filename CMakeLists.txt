cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(autodrive-vision)
add_definitions("-Wall -g")
add_definitions(-std=c++14)
# CXXFLAGS := -std=c++14 fopenmp `pkg-config --cflags opencv`
# LIBS = 'pkg-config --;ibs opencv'

# Set search directory for looking for our custom CMake scripts to
# look for SuiteSparse, QGLViewer, and Eigen3.

# find_package(Boost COMPONENTS system filesystem regex program_options REQUIRED)
find_package(OpenCV  REQUIRED)
# find_package(Ceres REQUIRED)
# find_package(Eigen3 REQUIRED)
# find_package(G2O REQUIRED)
# find_package(Cholmod  REQUIRED)
# find_package(CSparse REQUIRED)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
	  ${PROJECT_SOURCE_DIR}/test/include
	  ${PROJECT_SOURCE_DIR}/../autodrive-calibration-api/include
	  ${PROJECT_SOURCE_DIR}/../autodrive-sensor-model/include
	  ${PROJECT_SOURCE_DIR}/../autodrive-sensor-model/proto 
	  ${PROJECT_SOURCE_DIR}/../autodrive-common/common/include
	  ${PROJECT_SOURCE_DIR}/../autodrive-sensor-adapter/include 
	  ${PROJECT_SOURCE_DIR}/../autodrive-interface/include
    ${PROJECT_SOURCE_DIR}/../autodrive-algorithm/include
	  ${PROJECT_SOURCE_DIR}/../thirdparty/threadpool
	  # ${PROJECT_SOURCE_DIR}/../thirdparty/libicsneo/include
	  # ${PROJECT_SOURCE_DIR}/../thirdparty/black-sesame/include
	  ${PROJECT_SOURCE_DIR}/../thirdparty/calmcar/src
	  # ${PROJECT_SOURCE_DIR}/../thirdparty/linuxcan/include
	  ${PROJECT_SOURCE_DIR}/../thirdparty/restbed/distribution/include
    ${CERES_INCLUDE_DIRS}
    ${G2O_INCLUDE_DIRS}
    # ${CSPARSE_INCLUDE_DIR}
    ${Cholmod_INCLUDE_DIR}
    ${OpenCV_INCLUDE_DIRS} 
    ${Boost_INCLUDE_DIR}
    ${EIGEN3_INCLUDE_DIR}
)

link_directories(
    ${PROJECT_SOURCE_DIR}/../autodrive-calibration-api/lib
    ${PROJECT_SOURCE_DIR}/../autodrive-common/common/lib
    ${PROJECT_SOURCE_DIR}/../autodrive-sensor-model/lib
    ${PROJECT_SOURCE_DIR}/../autodrive-sensor-adapter/lib 
    ${PROJECT_SOURCE_DIR}/../autodrive-interface/lib
    ${PROJECT_SOURCE_DIR}/../autodrive-algorithm/lib
    ${PROJECT_SOURCE_DIR}/../thirdparty/can
    ${PROJECT_SOURCE_DIR}/../thirdparty/calmcar/lib
    # ${PROJECT_SOURCE_DIR}/../thirdparty/black-sesame/lib
    ${PROJECT_SOURCE_DIR}/../thirdparty/linuxcan/lib
    # ${PROJECT_SOURCE_DIR}/../thirdparty/Pandar40P/build
    # ${PROJECT_SOURCE_DIR}/../thirdparty/Pandar40P/build/src/Pandar40P
    ${PROJECT_SOURCE_DIR}/../thirdparty/restbed/distribution/library
    /usr/local/lib
)

aux_source_directory(. DIR_SRCS)
#add_executable(opencv_test
#  
#  opencv_test.cpp)

#target_link_libraries(opencv_test ${OpenCV_LIBS} liblog4cxx.so)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${PROJECT_SOURCE_DIR}/../thirdparty/libicsneo icsneo)
# add_subdirectory(${PROJECT_SOURCE_DIR}/test)