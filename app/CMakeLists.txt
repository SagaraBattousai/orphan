
add_executable(app_cpp main.cpp)
add_executable(app_c main.c)

target_link_libraries(app_cpp orphan)
target_link_libraries(app_c orphan)

if(WIN32)
  auto_copy_dlls_for_target(app_cpp)
  auto_copy_dlls_for_target(app_c)
endif()
