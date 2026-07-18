cmake_minimum_required(VERSION 4.2)

project(Server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED On)

file(GLOB HDR_FILES "include/*.hpp" "include/request-strategy/*.hpp" "include/service/*.hpp"
                    "include/model/*.hpp")

set(SRC_FILES "src/session.cpp" "src/repository.cpp" 
              "src/deserializatino-request-service.cpp" "src/serialization-response-service.cpp"
              "src/request-strategy.cpp" "src/new-data-request-strategy.cpp"
              "src/get-data-request-strategy.cpp" "src/request-service.cpp" "src/server.cpp"
              "src/take-key-request-strategy.cpp")

find_package(Boost REQUIRED COMPONENTS charconv)

set(SERVER_LIBRARIES ProtocolLib Boost::charconv)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../ProtocolLib" "${CMAKE_BINARY_DIR}/ProtocolLib")

add_executable(${PROJECT_NAME} ${HDR_FILES} ${SRC_FILES} "src/main.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE ${SERVER_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE "include")

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

add_executable(${PROJECT_NAME}Tests ${TEST_SRC_FILES} ${HDR_FILES} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME}Tests PRIVATE GTest::gtest GTest::gtest_main GTest::gmock
                                                   GTest::gmock_main ${SERVER_LIBRARIES})
target_include_directories(${PROJECT_NAME}Tests PRIVATE "include")
