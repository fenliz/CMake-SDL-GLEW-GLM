project(library2)

add_library(${PROJECT_NAME}
	src/window.cpp
	src/glad.c
	src/imgui.cpp
	src/imgui_demo.cpp
	src/imgui_draw.cpp
	src/imgui_impl_sdl_gl3.cpp
)
add_library(library2::library2 ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
	PUBLIC
		include
		${SDL2_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME}
	library1::library1
	${SDL2_LIBRARY}
)