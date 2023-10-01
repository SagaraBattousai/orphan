
add_executable(app_cpp_orphan main.cpp)
add_executable(app_c_orphan main.c)

target_link_libraries(app_cpp_orphan orphan)
target_link_libraries(app_c_orphan orphan)

if(WIN32)
  auto_copy_dlls_for_target(app_cpp_orphan)
  auto_copy_dlls_for_target(app_c_orphan)
endif()
