
macro(configure_sphinx_and_add_command)

  set(SPHINX_STATIC_DIR "${SPHINX_ROOT_DIRECTORY}/_static")

  set(SPHINX_CSS 
    "${SPHINX_STATIC_DIR}/css/style.css"
    "${SPHINX_STATIC_DIR}/css/colours.css"
    "${SPHINX_STATIC_DIR}/css/defaults.css"
    "${SPHINX_STATIC_DIR}/css/dark.css"
    "${SPHINX_STATIC_DIR}/css/light.css"
    )

  #Could use list(TRANSFORM but atm its just as easy to write twice
  #Order matters
  set(SPHINX_CSS_FILES_LIST "
  \"css/style.css\",
  \"css/colours.css\",
  \"css/defaults.css\",
  \"css/dark.css\",
  \"css/light.css\",
  ")

  set(BREATHE_DOMAIN_BY_EXTENSION_DICT 
    "\"h\"   : \"cpp\",
     \"ixx\" : \"cpp\",
     ")

  configure_file(${SPHINX_CONF_IN} ${SPHINX_CONF_OUT} @ONLY)

  # As this is a macro, this will be the directory of the caller! :)
  set(SPHINX_DOXYGEN_XML_DIR 
    "${CMAKE_CURRENT_SOURCE_DIR}/${DOXYGEN_OUTPUT_DIRECTORY}/xml")

  set(ORPHAN_DOC_ROOT "${SPHINX_ROOT_DIRECTORY}/orphan")

  # Sphinx rst's Hand wrriten just like source code :P
  # Listed Hierarchically
  set(SPHINX_RESTRUCTRED_TEXT 
    #Root Index
    "${SPHINX_ROOT_DIRECTORY}/index.rst"
    
    #Orphan docs
    "${ORPHAN_DOC_ROOT}/integral.rst"
    )

  add_custom_command(OUTPUT ${SPHINX_HTML_INDEX_FILE}
    COMMAND ${CMAKE_COMMAND} -E rm -r ${SPHINX_OUTPUT_DIRECTORY}
    COMMAND
    ${SPHINX_EXECUTABLE} 
    -b html
    -j auto
    "-Dbreathe_projects.${PROJECT_NAME}=${SPHINX_DOXYGEN_XML_DIR}"
    "-Dbreathe_default_project=${PROJECT_NAME}"
    ${SPHINX_ROOT_DIRECTORY} ${SPHINX_OUTPUT_DIRECTORY}
    # Note incremental build doesn't copy over css/js however I
    # hate having to specify manually so just remember to copy over
    # your css and js if theyre different. I'll add a copy if different later.
    # ${SPHINX_RESTRUCTRED_TEXT} ${SPHINX_CSS} ${SPHINX_JS}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    MAIN_DEPENDENCY ${SPHINX_CONF_OUT}
    DEPENDS ${SPHINX_RESTRUCTRED_TEXT} ${DOXYGEN_XML_INDEX_FILE}
    ${SPHINX_CSS} ${SPHINX_JS}
    COMMENT "Generating documentation with Sphinx")

endmacro()
