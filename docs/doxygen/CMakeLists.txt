#TODO: clean this up and use as cmake dir thinggy.
# Set: DOXYGEN_INPUT_FILES based on passed in targets' sources.
function(set_doxygen_input_files)
  # if(ARGC LESS 2)
  if(ARGC LESS 1)
    message(WARNING "Needs additional arguments; namely targets \
    whos source files require/want documentation.")
    return()
  endif()

  foreach(target ${ARGN})
    # Using just headers (since switching to FILE_SET) 
    # instead of sources is this okay? Yes because we document in header
    get_target_property(target_sources ${target} HEADER_SET)

    foreach(source ${target_sources})    
      cmake_path(
        RELATIVE_PATH source
        #For some reason it relative to the caller which is correct (weird)
        OUTPUT_VARIABLE source_relative_to_doxygen)

      list(APPEND DEPENDENCY_FILES ${source_relative_to_doxygen})
      # string(APPEND SOURCE_TO_DOCUMENT "${source_relative_to_doxygen} ")
    endforeach()
  endforeach()


  set(DOXYGEN_DEPENDENCY_FILES ${DEPENDENCY_FILES} PARENT_SCOPE)
  list(JOIN DEPENDENCY_FILES " " INPUT_FILES)
  set(DOXYGEN_INPUT_FILES ${INPUT_FILES} PARENT_SCOPE)

endfunction()

# The following Variables must be set: 
# { DOXYGEN_INPUT_FILES, DOXYGEN_OUTPUT_DIRECTORY, DOXYGEN_XML_INDEX_FILE,
#   DOXYFILE_IN, DOXYFILE_OUT, DOXYGEN_INPUT_FILES }
macro(configure_doxygen_and_add_command)
  set(DOXYGEN_GENERATE_XML YES)
  set(DOXYGEN_GENERATE_HTML YES)
  set(DOXYGEN_GENERATE_MAN YES)
  set(DOXYGEN_GENERATE_LATEX NO)
  set(DOXYGEN_JAVADOC_BANNER YES)

  configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

  #Can't use doxygen_add_docs as we need doxyfile to be usable for read-the-docs.
  add_custom_command(OUTPUT ${DOXYGEN_XML_INDEX_FILE}
    DEPENDS ${DOXYFILE_IN} ${DOXYGEN_DEPENDENCY_FILES}
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
    MAIN_DEPENDENCY ${DOXYFILE_OUT}
    #^^ I don't really get what it's for in vs, what does hang mean?
    #VV As this is a macro, this will be the directory of the caller! :)
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating Doxygen Documentation ...")
endmacro()
