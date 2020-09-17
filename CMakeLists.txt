cmake_minimum_required(VERSION 2.8)
project(autodrive-vision)
add_definitions("-Wall -g")
add_definitions(-std=c++14)
find_package(OpenCV REQUIRED)
# option(BUILD_ATOM "build for atom" ON)

include_directories(
	${PROJECT_SOURCE_DIR}/include 
	${PROJECT_SOURCE_DIR}/test/include
	${PROJECT_SOURCE_DIR}/../autodrive-calibration-api/include
	${PROJECT_SOURCE_DIR}/../autodrive-sensor-model/include
	${PROJECT_SOURCE_DIR}/../autodrive-sensor-model/proto 
	${PROJECT_SOURCE_DIR}/../autodrive-common/common/include
    ${PROJECT_SOURCE_DIR}/../autodrive-interface/include
    ${PROJECT_SOURCE_DIR}/../autodrive-algorithm/include
	${PROJECT_SOURCE_DIR}/../thirdparty/threadpool
	${PROJECT_SOURCE_DIR}/../thirdparty/libicsneo/include
	# ${PROJECT_SOURCE_DIR}/../thirdparty/black-sesame/include
	${PROJECT_SOURCE_DIR}/../thirdparty/calmcar/src
	# ${PROJECT_SOURCE_DIR}/../thirdparty/linuxcan/include
	${PROJECT_SOURCE_DIR}/../thirdparty/restbed/distribution/include
	${PROJECT_SOURCE_DIR}/jsoncpp/include
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
	${PROJECT_BINARY_DIR}/lib
)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${PROJECT_SOURCE_DIR}/../thirdparty/libicsneo icsneo)
# add_subdirectory(${PROJECT_SOURCE_DIR}/jsoncpp)
# add_subdirectory(${PROJECT_SOURCE_DIR}/test)
