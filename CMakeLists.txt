cmake_minimum_required(VERSION 3.28)

set(PROJECT_NAME "Simple-Graphics")
set(EXECUTABLE_NAME "Simple Graphics")
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
set(ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets")
set(COPY_ASSETS OFF)
set(AUDIO_SUPPORT OFF)


project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
endif()

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Recursively add source files in the src directory
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
if (AUDIO_SUPPORT)
    target_link_libraries(${PROJECT_NAME} sfml-audio)
endif ()

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${EXECUTABLE_NAME}")

if(WIN32)
    if (COPY_ASSETS)
        add_custom_command(
            TARGET ${PROJECT_NAME}
            COMMENT "Copy assets"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${ASSETS_DIR} $<TARGET_FILE_DIR:${PROJECT_NAME}>
            VERBATIM)
    endif()

    if (AUDIO_SUPPORT)
        add_custom_command(
            TARGET ${PROJECT_NAME}
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
            VERBATIM
        )
    endif()


    if (MSVC)
        target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
        if (CMAKE_BUILD_TYPE MATCHES Debug)
            target_compile_options(${PROJECT_NAME} PRIVATE /MDd)
        elseif (CMAKE_BUILD_TYPE MATCHES Release)
            # Disable console window
            set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
            target_compile_options(${PROJECT_NAME} PRIVATE /MD)
        endif()

    else()
        target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)

    endif ()

endif()
