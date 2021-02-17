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