cmake_minimum_required(VERSION 3.23)

project(orphan
        VERSION 0.0.1
        DESCRIPTION ""
        LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH 
  "${PROJECT_SOURCE_DIR}/cmake"
  ${CMAKE_MODULE_PATH}
  )

include(LibUtils)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if (MSVC)
  add_compile_options(/W4) # /WX)
else()
  add_compile_options(-Wall -Wextra -pedantic) # -Werror)
endif()

set(ORPHAN_BUILD_DOCS ON CACHE BOOL "Whether or not to build documentation.")

set(MODULE_ROOT "${PROJECT_SOURCE_DIR}/include")

# if (CMAKE_SIZEOF_VOID_P GREATER_EQUAL 8)
#   set(VOID_PTR_FITS_x64 1 CACHE INTERNAL "") # Implied FORCE)
# endif ()

add_subdirectory(orphan)
add_subdirectory(bindings)
add_subdirectory(app)

if(ORPHAN_BUILD_DOCS)
  add_subdirectory(docs)
  #Do I need to add dependancies as well or is that transitive!?
  #TODO: # add_dependencies(Doxygen orphan) ??
endif()

