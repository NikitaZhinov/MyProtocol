cmake_minimum_required(VERSION 4.2)

project(ProtocolLib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED On)

# Library
file(GLOB HDR_FILES "include/protocol/*.hpp"
                    "include/protocol/request/*.hpp"
                    "include/protocol/response/*.hpp"
                    "include/protocol/encryption/*.hpp"
                    "include/protocol/serialization/*.hpp"
                    "include/protocol/deserialization/*.hpp")

file(GLOB SRC_FILES "src/*.cpp")    

add_library(${PROJECT_NAME} STATIC ${HDR_FILES} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC "include")

find_package(OpenSSL CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenSSL::SSL OpenSSL::Crypto)

# Doxygen
find_package(Doxygen REQUIRED)
if(DOXYGEN_FOUND)
    message("Doxygen build started")
 	add_custom_target(${PROJECT_NAME}Doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        VERBATIM)
    message("Doxygen build finished")
else()
    message("Doxygen need to be installed to generate the doxygen documentation")
endif()

# Tests 
include(CTest)
enable_testing()

file(GLOB TEST_SRC_FILES "test/*.cpp")

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME}Tests ${TEST_SRC_FILES})
target_link_libraries(${PROJECT_NAME}Tests PRIVATE GTest::gtest GTest::gtest_main GTest::gmock
                                                   GTest::gmock_main ${PROJECT_NAME})

add_test(NAME AllTestsIn${PROJECT_NAME} COMMAND ${PROJECT_NAME}Tests)

add_custom_command(TARGET ${PROJECT_NAME}Tests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}Tests>
        $<TARGET_FILE_DIR:${PROJECT_NAME}Tests>
    COMMAND_EXPAND_LISTS
)
