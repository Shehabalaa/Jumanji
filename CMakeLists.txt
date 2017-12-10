	# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (Jumanji)

find_package(OpenGL REQUIRED)

# Compile external dependencies 
add_subdirectory (external)

# On Visual 2005 and above, this module can set the debug working directory
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-1c73e35")
include(CreateLaunchers)
include(MSVCMultipleProcessCompile) # /MP

if(INCLUDE_DISTRIB)
	add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)



include_directories(
	external/AntTweakBar-1.16/include/
	external/glfw-2.7.6/include/
	external/glm-0.9.4.0/
	external/glew-1.9.0/include/
	external/assimp-3.0.1270/include/
	external/bullet-2.81-rev2613/src/

	.
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	GLFW_276
	GLEW_190
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)


# Jumanji
add_executable( Jumanji
	Jumanji/main.cpp
	Jumanji/Game/Game.cpp
	Jumanji/Game/Game.h
	Jumanji/suzan/suzan.cpp
	Jumanji/suzan/suzan.h
	Jumanji/lvl/lvl.cpp
	Jumanji/lvl/lvl.h
	Jumanji/lvl1/lvl1.cpp
	Jumanji/lvl1/lvl1.h
	Jumanji/lvl2/lvl2.cpp
	Jumanji/lvl2/lvl2.h
	Jumanji/lvl3/lvl3.cpp
	Jumanji/lvl3/lvl3.h
	Jumanji/lvl4/lvl4.cpp
	Jumanji/lvl4/lvl4.h
	Jumanji/object/object.cpp
	Jumanji/object/object.h
	common/shader.cpp
	common/shader.hpp
	common/controls.cpp
	common/controls.hpp
	common/texture.cpp
	common/texture.hpp
	common/objloader.cpp
	common/objloader.hpp
	common/collisiondetection.cpp
	common/collisiondetection.hpp
)
target_link_libraries(Jumanji
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(Jumanji PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Jumanji/")
create_target_launcher(Jumanji WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Jumanji/")




SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
SOURCE_GROUP(suzan REGULAR_EXPRESSION  ".*/suzan/.*" )
SOURCE_GROUP(lvl REGULAR_EXPRESSION ".*/lvl/.*" )
SOURCE_GROUP(object REGULAR_EXPRESSION  ".*/object/.*" )
SOURCE_GROUP(Game REGULAR_EXPRESSION ".*/Game/.*" )
SOURCE_GROUP(lvl1 REGULAR_EXPRESSION ".*/lvl1/.*" )
SOURCE_GROUP(lvl2 REGULAR_EXPRESSION ".*/lvl2/.*" )
SOURCE_GROUP(lvl3 REGULAR_EXPRESSION ".*/lvl3/.*" )
SOURCE_GROUP(lvl4 REGULAR_EXPRESSION ".*/lvl4/.*" )



if (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )

add_custom_command(
   TARGET Jumanji POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/Jumanji${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/Jumanji/"
)


elseif (${CMAKE_GENERATOR} MATCHES "Xcode" )

endif (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )

