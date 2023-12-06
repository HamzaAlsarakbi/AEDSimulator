add_subdirectory(googletest)
include_directories(${GTEST_INCLUDE_DIRS})


set(TEST_FILES
    ../model/patient/Patient.h
    ../model/patient/Patient.cpp
    ../model/patient/heart/Heart.h
    ../model/patient/heart/Heart.cpp
    ../model/patient/heart/pulse/Pulse.h
    ../model/patient/heart/pulse/Pulse.cpp
    tests/test_pulse.cpp
    tests/test_heart.cpp
    tests/test_patient.cpp)

add_executable(AED_TESTS ${TEST_FILES})

target_link_libraries(AED_TESTS gtest gtest_main)
