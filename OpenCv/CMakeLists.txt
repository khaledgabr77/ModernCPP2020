cmake_minimum_required(VERSION 3.10)
project( DisplayImage )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( DisplayImage src/light.cpp )
target_link_libraries( DisplayImage ${OpenCV_LIBS} )

add_executable( imread  src/imread.cpp )
target_link_libraries( imread ${OpenCV_LIBS} )

add_executable( imwrite src/imwrite.cpp )
target_link_libraries( imwrite ${OpenCV_LIBS} )

add_executable( io src/IO.cpp )
target_link_libraries( io ${OpenCV_LIBS} )
add_executable( img src/Load&Dispaly.cpp )
target_link_libraries( img ${OpenCV_LIBS} )

add_executable( blank src/BlankImage.cpp )
target_link_libraries( blank ${OpenCV_LIBS} )

add_executable( video src/PlayVideo.cpp )
target_link_libraries( video ${OpenCV_LIBS} )
add_executable( open src/CameraVideo.cpp )
target_link_libraries( open ${OpenCV_LIBS} )

add_executable( filter src/filter.cpp )
target_link_libraries( filter ${OpenCV_LIBS} )

add_executable( op src/introductionOpencv.cpp )
target_link_libraries( op ${OpenCV_LIBS} )

add_executable( smooth src/smoothing.cpp )
target_link_libraries( smooth ${OpenCV_LIBS} )

add_executable( fil src/filtering.cpp )
target_link_libraries( fil ${OpenCV_LIBS} )

add_executable( ero src/ero&dil.cpp )
target_link_libraries( ero ${OpenCV_LIBS} )
add_executable( equ src/HistEqualization.cpp )
target_link_libraries( equ ${OpenCV_LIBS} )

add_executable( cal src/HistCal.cpp )
target_link_libraries( cal ${OpenCV_LIBS} )

add_executable( comp src/HistComparison.cpp )
target_link_libraries( comp ${OpenCV_LIBS} )

add_executable( binary src/binaryVision.cpp )
target_link_libraries( binary ${OpenCV_LIBS} )