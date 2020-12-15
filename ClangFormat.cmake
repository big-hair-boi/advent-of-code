# get all project files
file(GLOB_RECURSE ALL_SOURCE_FILES 
        ${PROJECT_SOURCE_DIR}/*.cc
        ${PROJECT_SOURCE_DIR}/*.h
        )

find_program(CLANG_FORMAT NAMES clang-format)

if (NOT CLANG_FORMAT)
	message(WARNING "clang-format not found in path! code format target not available.")
else()
	add_custom_target(
			format
			COMMAND ${CLANG_FORMAT}
			-style=file
			-i
			${ALL_SOURCE_FILES}
			)
endif()