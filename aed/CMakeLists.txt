cmake_minimum_required(VERSION 3.26)
project(aed)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.6.1\\mingw_64\\lib\\cmake")


include_directories(.)

find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)
find_package(Qt6Quick REQUIRED)

add_executable(aed
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        model/Rescuer.h
        model/aed/AED.h
        model/aed/AEDWorker.h
        model/patient/Patient.h
        model/patient/heart/Heart.h
        model/aed/AED.cpp
        model/Rescuer.cpp
        model/patient/heart/Heart.cpp
        model/patient/Patient.cpp
        model/patient/heart/pulse/Pulse.h
        model/patient/heart/pulse/Pulse.cpp
        model/aed/step/Step.h
        model/aed/step/action/Action.h
        model/aed/step/action/Action.cpp
        model/aed/step/Step.cpp)

target_link_libraries(aed Qt6::Widgets)
target_link_libraries(aed Qt6::Core)
target_link_libraries(aed Qt6::Quick)
