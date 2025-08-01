add_project(aws-cpp-sdk-bedrock-agentcore-control "C++ SDK for the AWS bedrock-agentcore-control service" aws-cpp-sdk-core)

file(GLOB AWS_BEDROCK-AGENTCORE-CONTROL_HEADERS
    "include/aws/bedrock-agentcore-control/*.h"
)

file(GLOB AWS_BEDROCK-AGENTCORE-CONTROL_MODEL_HEADERS
    "include/aws/bedrock-agentcore-control/model/*.h"
)

file(GLOB AWS_BEDROCK-AGENTCORE-CONTROL_SOURCE
    "source/*.cpp"
)

file(GLOB AWS_BEDROCK-AGENTCORE-CONTROL_MODEL_SOURCE
    "source/model/*.cpp"
)

file(GLOB BEDROCK-AGENTCORE-CONTROL_UNIFIED_HEADERS
    ${AWS_BEDROCK-AGENTCORE-CONTROL_HEADERS}
    ${AWS_BEDROCK-AGENTCORE-CONTROL_MODEL_HEADERS}
)

file(GLOB BEDROCK-AGENTCORE-CONTROL_UNITY_SRC
    ${AWS_BEDROCK-AGENTCORE-CONTROL_SOURCE}
    ${AWS_BEDROCK-AGENTCORE-CONTROL_MODEL_SOURCE}
)

if(ENABLE_UNITY_BUILD)
    enable_unity_build("BEDROCK-AGENTCORE-CONTROL" BEDROCK-AGENTCORE-CONTROL_UNITY_SRC)
endif()

file(GLOB BEDROCK-AGENTCORE-CONTROL_SRC
    ${BEDROCK-AGENTCORE-CONTROL_UNIFIED_HEADERS}
    ${BEDROCK-AGENTCORE-CONTROL_UNITY_SRC}
)

if(WIN32)
    #if we are compiling for visual studio, create a sane directory tree.
    if(MSVC)
        source_group("Header Files\\aws\\bedrock-agentcore-control" FILES ${AWS_BEDROCK-AGENTCORE-CONTROL_HEADERS})
        source_group("Header Files\\aws\\bedrock-agentcore-control\\model" FILES ${AWS_BEDROCK-AGENTCORE-CONTROL_MODEL_HEADERS})
        source_group("Source Files" FILES ${AWS_BEDROCK-AGENTCORE-CONTROL_SOURCE})
        source_group("Source Files\\model" FILES ${AWS_BEDROCK-AGENTCORE-CONTROL_MODEL_SOURCE})
    endif(MSVC)
endif()

set(BEDROCK-AGENTCORE-CONTROL_INCLUDES
    "${CMAKE_CURRENT_SOURCE_DIR}/include/"
)

add_library(${PROJECT_NAME} ${BEDROCK-AGENTCORE-CONTROL_SRC})
add_library(AWS::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set_compiler_flags(${PROJECT_NAME})
set_compiler_warnings(${PROJECT_NAME})

if(USE_WINDOWS_DLL_SEMANTICS AND BUILD_SHARED_LIBS)
    target_compile_definitions(${PROJECT_NAME} PRIVATE "AWS_BEDROCKAGENTCORECONTROL_EXPORTS")
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

target_link_libraries(${PROJECT_NAME} PRIVATE ${PLATFORM_DEP_LIBS} ${PROJECT_LIBS})


setup_install()

install (FILES ${AWS_BEDROCK-AGENTCORE-CONTROL_HEADERS} DESTINATION ${INCLUDE_DIRECTORY}/aws/bedrock-agentcore-control)
install (FILES ${AWS_BEDROCK-AGENTCORE-CONTROL_MODEL_HEADERS} DESTINATION ${INCLUDE_DIRECTORY}/aws/bedrock-agentcore-control/model)

do_packaging()


