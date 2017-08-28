project(library1)

add_library(${PROJECT_NAME}
	src/log.cpp
)
add_library(library1::library1 ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
	PUBLIC
		include
)