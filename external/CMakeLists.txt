if(MSVC AND NOT "${MSVC_VERSION}" LESS 1400)
	add_definitions( "/MP" )
endif()

add_definitions(
  -DTW_STATIC
  -DTW_NO_LIB_PRAGMA
  -DGLEW_STATIC
  -D_CRT_SECURE_NO_WARNINGS
)

add_subdirectory(SDL2-2.0.4)

include_directories(
  ${SDL_INCLUDE_DIR}
)
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  set(OPENGL_LIBRARY
  ${OPENGL_LIBRARY}
  -lSDL2 -lXrandr -lXext -lx11 -lrt
  ${CMAKE_DL_LIBS}
  ${SDL2_LIBRARY}
)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
set(OPENGL_LIBRARY
	${CMAKE_DL_LIBS}
	${SDL2_LIBRARY}
)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
