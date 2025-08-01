add_project(aws-cpp-sdk-arc-region-switch "C++ SDK for the AWS arc-region-switch service" aws-cpp-sdk-core)

file(GLOB AWS_ARC-REGION-SWITCH_HEADERS
    "include/aws/arc-region-switch/*.h"
)

file(GLOB AWS_ARC-REGION-SWITCH_MODEL_HEADERS
    "include/aws/arc-region-switch/model/*.h"
)

file(GLOB AWS_ARC-REGION-SWITCH_SOURCE
    "source/*.cpp"
)

file(GLOB AWS_ARC-REGION-SWITCH_MODEL_SOURCE
    "source/model/*.cpp"
)

file(GLOB ARC-REGION-SWITCH_UNIFIED_HEADERS
    ${AWS_ARC-REGION-SWITCH_HEADERS}
    ${AWS_ARC-REGION-SWITCH_MODEL_HEADERS}
)

file(GLOB ARC-REGION-SWITCH_UNITY_SRC
    ${AWS_ARC-REGION-SWITCH_SOURCE}
    ${AWS_ARC-REGION-SWITCH_MODEL_SOURCE}
)

if(ENABLE_UNITY_BUILD)
    enable_unity_build("ARC-REGION-SWITCH" ARC-REGION-SWITCH_UNITY_SRC)
endif()

file(GLOB ARC-REGION-SWITCH_SRC
    ${ARC-REGION-SWITCH_UNIFIED_HEADERS}
    ${ARC-REGION-SWITCH_UNITY_SRC}
)

if(WIN32)
    #if we are compiling for visual studio, create a sane directory tree.
    if(MSVC)
        source_group("Header Files\\aws\\arc-region-switch" FILES ${AWS_ARC-REGION-SWITCH_HEADERS})
        source_group("Header Files\\aws\\arc-region-switch\\model" FILES ${AWS_ARC-REGION-SWITCH_MODEL_HEADERS})
        source_group("Source Files" FILES ${AWS_ARC-REGION-SWITCH_SOURCE})
        source_group("Source Files\\model" FILES ${AWS_ARC-REGION-SWITCH_MODEL_SOURCE})
    endif(MSVC)
endif()

set(ARC-REGION-SWITCH_INCLUDES
    "${CMAKE_CURRENT_SOURCE_DIR}/include/"
)

add_library(${PROJECT_NAME} ${ARC-REGION-SWITCH_SRC})
add_library(AWS::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set_compiler_flags(${PROJECT_NAME})
set_compiler_warnings(${PROJECT_NAME})

if(USE_WINDOWS_DLL_SEMANTICS AND BUILD_SHARED_LIBS)
    target_compile_definitions(${PROJECT_NAME} PRIVATE "AWS_ARCREGIONSWITCH_EXPORTS")
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

target_link_libraries(${PROJECT_NAME} PRIVATE ${PLATFORM_DEP_LIBS} ${PROJECT_LIBS})


setup_install()

install (FILES ${AWS_ARC-REGION-SWITCH_HEADERS} DESTINATION ${INCLUDE_DIRECTORY}/aws/arc-region-switch)
install (FILES ${AWS_ARC-REGION-SWITCH_MODEL_HEADERS} DESTINATION ${INCLUDE_DIRECTORY}/aws/arc-region-switch/model)

do_packaging()


