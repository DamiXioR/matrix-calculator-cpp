cmake_minimum_required(VERSION 3.16.3)

project(Matrix VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# GTEST MUST HAVE
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()
# GTEST MUST HAVE END

set(TESTS 
    tests/main-ut.cpp
    tests/matrix-ut.cpp
    tests/matrixManager-ut.cpp
)

set(SRC 
    src/testClass.cpp
    src/matrix.cpp
    src/matrixManager.cpp
)

set(FLAGS 
    -Wall
    -Wextra
    -Werror
    -Wconversion
    -Wpedantic
    -g
)

#HEADERS PATH

include_directories(headers)
link_libraries(gtest)

#ADD LIBRARIES
add_library(${PROJECT_NAME}-lib ${SRC})

#SRC

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC ${PROJECT_NAME}-lib)
target_compile_options(${PROJECT_NAME} PUBLIC ${FLAGS})

#TESTS

add_executable(${PROJECT_NAME}-ut tests/gtestMain.cpp ${TESTS})
target_link_libraries(${PROJECT_NAME}-ut PUBLIC ${PROJECT_NAME}-lib)
target_compile_options(${PROJECT_NAME}-ut PUBLIC ${FLAGS})
add_test(NAME ${PROJECT_NAME}-tests COMMAND ${PROJECT_NAME}-ut)
enable_testing()
