####################################################################
################# Cactuar ##########################################
####################################################################

set(ORPHAN_MODULE_ROOT "${MODULE_ROOT}/orphan")

set(cpp_sources 
  "bigint.cpp"
  "hash.cpp" 
  "integral.cpp"
  "keccak.cpp"
  "signing.cpp" 
  )

set(c_sources 
  "keccak.c"
  )

set(orphan_module 
  "${ORPHAN_MODULE_ROOT}/_orphanconfig.h" # ixx"
  "${ORPHAN_MODULE_ROOT}/orphan-bigint.h" # ixx"
  "${ORPHAN_MODULE_ROOT}/orphan-hash.h" # ixx"
  "${ORPHAN_MODULE_ROOT}/orphan-integral.h" # ixx"
  "${ORPHAN_MODULE_ROOT}/orphan-keccak.h" # ixx"
  "${ORPHAN_MODULE_ROOT}/orphan-signing.h" # ixx"
  )

add_library(orphan SHARED ${cpp_sources} ${c_sources})

target_compile_definitions(orphan PRIVATE ORPHAN_BUILD_DLL)

target_sources(orphan PUBLIC
  FILE_SET HEADERS
  TYPE HEADERS
  BASE_DIRS ${MODULE_ROOT}
  FILES ${orphan_module}
  )




