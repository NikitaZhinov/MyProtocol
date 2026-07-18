cmake_minimum_required(VERSION 4.2)

project(Client LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED On)

file(GLOB HDR_FILES "include/*.hpp")

file(GLOB SRC_FILES "src/*.cpp")

find_package(Boost REQUIRED COMPONENTS json)
find_package(Qt6 6.11 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

set(CLIENT_LIBRARIES ProtocolLib Boost::headers Boost::json Qt::Core Qt::Widgets)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../ProtocolLib" "${CMAKE_BINARY_DIR}/ProtocolLib")

qt_add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${HDR_FILES} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${CLIENT_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE "include")

set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE On
    MACOSX_BUNDLE On
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
qt_generate_deploy_app_script(TARGET ${PROJECT_NAME}
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

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
