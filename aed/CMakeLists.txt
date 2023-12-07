cmake_minimum_required(VERSION 3.24)
project(aed)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.6.1\\mingw_64")

# adding GoogleTests
add_subdirectory(tests)

include_directories(.)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)
find_package(Qt6Quick REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Create pulse library target
add_library(pulse
    model/patient/heart/pulse/Pulse.cpp
    model/patient/heart/pulse/Pulse.h
)

# Create heart library target
add_library(heart
    model/patient/heart/Heart.cpp
    model/patient/heart/Heart.h
)

add_library(patient
    model/patient/Patient.cpp
    model/patient/Patient.h
)

# Link pulse library with heart library
target_link_libraries(patient heart pulse)

add_executable(aed
    main.cpp
    mainwindow.cpp
    img.qrc
    mainwindow.h
    mainwindow.ui
    model/aed/AED.h
    model/patient/Patient.h
    model/aed/AED.cpp
        model/patient/Patient.cpp
        ui/EcgWidget.h
        ui/EcgWidget.cpp)

# Link pulse and heart libraries with the executable
target_link_libraries(aed patient heart pulse Qt6::Widgets Qt6::Core Qt6::Quick)