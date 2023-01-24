####################################################################
################# Cactuar ##########################################
####################################################################

set(ORPHAN_MODULE_ROOT "${MODULE_ROOT}/orphan")

set(cpp_sources 
  "crypto.cpp"
  "encoding.cpp" 
  "functional.cpp"
  "hash.cpp" 
  "rlp.cpp"
  "signing.cpp" 
  "target.cpp"
  "transaction.cpp"
  )

set(c_sources 
  "keccak.c"
  )

set(orphan_module 
  "${ORPHAN_MODULE_ROOT}/orphan.h" # ixx"
  "${ORPHAN_MODULE_ROOT}/orphan-crypto.h" # ixx"
  "${ORPHAN_MODULE_ROOT}/orphan-encoding.h" # ixx"
  "${ORPHAN_MODULE_ROOT}/orphan-functional.h" # ixx"
  "${ORPHAN_MODULE_ROOT}/orphan-hash.h" # ixx"
  "${ORPHAN_MODULE_ROOT}/orphan-keccak.h" # ixx"
  "${ORPHAN_MODULE_ROOT}/orphan-rlp.h" # ixx"
  "${ORPHAN_MODULE_ROOT}/orphan-serializer.h" # ixx"
  "${ORPHAN_MODULE_ROOT}/orphan-signing.h" # ixx"
  "${ORPHAN_MODULE_ROOT}/orphan-target.h" # ixx"
  "${ORPHAN_MODULE_ROOT}/orphan-transaction.h" # ixx"
  "${ORPHAN_MODULE_ROOT}/_orphanconfig.h" # ixx"
  )

add_library(orphan SHARED ${cpp_sources} ${c_sources})

target_compile_definitions(orphan PRIVATE ORPHAN_BUILD_DLL)

target_sources(orphan PUBLIC
  FILE_SET headers 
  TYPE HEADERS
  BASE_DIRS ${MODULE_ROOT}
  FILES ${orphan_module}
  )




