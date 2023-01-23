####################################################################
################# Cactuar ##########################################
####################################################################

set(CACTUAR_MODULE_ROOT "${MODULE_ROOT}/cactuar")

set(cpp_sources 
  "block.cpp"
  "blockheader.cpp"
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

set(cactuar_module 
  "${CACTUAR_MODULE_ROOT}/cactuar.h" # ixx"
  "${CACTUAR_MODULE_ROOT}/cactuar-block.h" # ixx"
  "${CACTUAR_MODULE_ROOT}/cactuar-blockheader.h" # ixx"
  "${CACTUAR_MODULE_ROOT}/cactuar-crypto.h" # ixx"
  "${CACTUAR_MODULE_ROOT}/cactuar-encoding.h" # ixx"
  "${CACTUAR_MODULE_ROOT}/cactuar-functional.h" # ixx"
  "${CACTUAR_MODULE_ROOT}/cactuar-hash.h" # ixx"
  "${CACTUAR_MODULE_ROOT}/cactuar-keccak.h" # ixx"
  "${CACTUAR_MODULE_ROOT}/cactuar-rlp.h" # ixx"
  "${CACTUAR_MODULE_ROOT}/cactuar-serializer.h" # ixx"
  "${CACTUAR_MODULE_ROOT}/cactuar-signing.h" # ixx"
  "${CACTUAR_MODULE_ROOT}/cactuar-target.h" # ixx"
  "${CACTUAR_MODULE_ROOT}/cactuar-transaction.h" # ixx"
  "${CACTUAR_MODULE_ROOT}/_cactuarconfig.h" # ixx"
  )

add_library(cactuar SHARED ${cpp_sources} ${c_sources})

target_compile_definitions(cactuar PRIVATE CACTUAR_BUILD_DLL)

target_sources(cactuar PUBLIC
  FILE_SET headers 
  TYPE HEADERS
  BASE_DIRS ${MODULE_ROOT}
  FILES ${cactuar_module}
  )




