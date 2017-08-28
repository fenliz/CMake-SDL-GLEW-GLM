project(executable)

add_executable(${PROJECT_NAME} 
	src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
	library1::library1
	library2::library2
)

find_package(SDL2 REQUIRED)
if(WIN32)
	if(CMAKE_SIZEOF_VOID_P EQUAL 8)
		add_custom_command(
			TARGET executable POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/third_party/x64/SDL2.dll ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
		)
	else()
		add_custom_command(
			TARGET executable POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/third_party/x86/SDL2.dll ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
		)
	endif()
endif(WIN32)