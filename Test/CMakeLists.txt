file(MAKE_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/include")
file(MAKE_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/src")
file(TOUCH "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/src/OpenGL.cpp")

add_executable(Test Test.cpp "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/src/OpenGL.cpp")
target_include_directories(Test PRIVATE "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/include")

find_package(glfw3 CONFIG)
target_link_libraries(Test PRIVATE glfw)
