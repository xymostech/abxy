cmake_minimum_required(VERSION 2.8)
project(UnitTest++)

set(version_MAJOR 1)
set(version_MINOR 4)
set(version_MICRO 0)
set(version_SO_MAJOR_VERSION "${version_MAJOR}.${version_MINOR}")
set(version_SO_MAJOR "${version_MAJOR}.${version_MINOR}")
set(version_SO_VERSION "${version_MAJOR}.${version_MINOR}.${version_MICRO}")

# put our outputs in the lib or bin directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

set(UNITTEST_OBJECTS
    "src/AssertException.cpp"
    "src/Test.cpp"
    "src/Checks.cpp"
    "src/TestRunner.cpp"
    "src/TestResults.cpp"
    "src/TestReporter.cpp"
    "src/TestReporterStdout.cpp"
    "src/ReportAssert.cpp"
    "src/TestList.cpp"
    "src/TimeConstraint.cpp"
    "src/TestDetails.cpp"
    "src/MemoryOutStream.cpp"
    "src/DeferredTestReporter.cpp"
    "src/DeferredTestResult.cpp"
    "src/XmlTestReporter.cpp"
    "src/CurrentTest.cpp"
    )

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(UNITTEST_OBJECTS ${UNITTEST_OBJECTS} "src/Win32/TimeHelpers.cpp")
else()
    set(UNITTEST_OBJECTS ${UNITTEST_OBJECTS}
        "src/Posix/TimeHelpers.cpp"
        "src/Posix/SignalTranslator.cpp"
    )
endif()


# build the static library
add_library(UnitTest++_static STATIC ${UNITTEST_OBJECTS})

set(UnitTest_LIBRARY_NAME "${CMAKE_STATIC_LIBRARY_PREFIX}UnitTest++${CMAKE_STATIC_LIBRARY_SUFFIX}")

# tell the parent about our include and library folders
set(UnitTest_LIBRARIES "${CMAKE_CURRENT_BINARY_DIR}/lib/${UnitTest_LIBRARY_NAME}" PARENT_SCOPE)
set(UnitTest_INCLUDE_DIRS "${CMAKE_CURRENT_BINARY_DIR}/include" PARENT_SCOPE)

# Find all the header files, and copy them into the include directory
file(GLOB_RECURSE UnitTest_HEADERS "*.h")
file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/include")
file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/include/Posix")
file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/include/Win32")
file(COPY ${UnitTest_HEADERS} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/include")
