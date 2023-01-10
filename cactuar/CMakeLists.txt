
####################################################################
################# Cactuar ##########################################
####################################################################

set(CACTUAR_MODULE_ROOT "${MODULE_ROOT}/cactuar")

set(cpp_sources 
  "template_helper.cpp"
  )

set(cactuar_module 
  "${CACTUAR_MODULE_ROOT}/cactuar.h" # ixx"
  "${CACTUAR_MODULE_ROOT}/cactuar-template_helper.h" # ixx"
  "${CACTUAR_MODULE_ROOT}/_cactuarconfig.h" # ixx"
  )

add_library(cactuar SHARED ${cpp_sources})

target_compile_definitions(cactuar PRIVATE CACTUAR_BUILD_DLL)

target_sources(cactuar PUBLIC
  FILE_SET headers 
  TYPE HEADERS
  BASE_DIRS ${MODULE_ROOT}
  FILES ${cactuar_module}
  )




