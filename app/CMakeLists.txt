
add_executable(app main.cpp)

target_link_libraries(app cactuar)

if(WIN32)
  auto_copy_dlls_for_target(app)
endif()
