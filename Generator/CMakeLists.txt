add_executable(Generator Program.cs Registry.cs Extensions.cs source.h.in source.cpp.in)

set_property(TARGET Generator PROPERTY VS_DOTNET_REFERENCES
		"System"
		"System.Core"
		"System.Data"
		"System.Xml"
		)

add_custom_command(TARGET Generator POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/source.h.in ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
		COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/source.cpp.in ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
        )
