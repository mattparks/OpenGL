add_executable(Generator Program.cs Registry.cs Extensions.cs gl.h.in gl.cpp.in gles.h.in gles.cpp.in)

set_property(TARGET Generator PROPERTY VS_DOTNET_REFERENCES
		"System"
		"System.Core"
		"System.Data"
		"System.Xml"
		)

add_custom_command(TARGET Generator POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/gl.h.in ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
		COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/gl.cpp.in ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
		COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/gles.h.in ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
		COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/gles.cpp.in ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
        )
