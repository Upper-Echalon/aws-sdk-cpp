# Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
# SPDX-License-Identifier: Apache-2.0.
#

cmake_minimum_required(VERSION 3.1)

project(DEPS)

include(ExternalProject)

# zlib
if(BUILD_ZLIB)
    #based on http://stackoverflow.com/questions/16842218/how-to-use-cmake-externalproject-add-or-alternatives-in-a-cross-platform-way
    #likely, some of the things here are unnecessary
    ExternalProject_Add(ZLIB
        SOURCE_DIR ${ZLIB_SOURCE_DIR}
        URL https://sdk.amazonaws.com/cpp/builds/zlib-1.2.11.tar.gz
        URL_HASH "SHA256=c3e5e9fdd5004dcb542feda5ee4f0ff0744628baf8ed2dd5d66f8ca1197cb1a1"
        PATCH_COMMAND ""
        CMAKE_ARGS
        -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}
        -DCMAKE_ANDROID_NDK_TOOLCHAIN_VERSION=${CMAKE_ANDROID_NDK_TOOLCHAIN_VERSION}
        -DANDROID_NATIVE_API_LEVEL=${ANDROID_NATIVE_API_LEVEL}
        -DANDROID_ABI=${ANDROID_ABI}
        -DANDROID_TOOLCHAIN=${ANDROID_TOOLCHAIN}
        -DANDROID_STL=${ANDROID_STL}
        -DCMAKE_INSTALL_PREFIX=${ZLIB_INSTALL_DIR}
        -DCMAKE_CXX_FLAGS=${EXTERNAL_CXX_FLAGS}
        -DCMAKE_C_FLAGS=${EXTERNAL_C_FLAGS}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=OFF
        )
endif()

# OpenSSL
# Download and build openssl alongside the SDK. This not recommended for use. Using your platforms libcrypto is recommended. 
# To use a custom libcrypto please follow the instructions in the developer guide (https://docs.aws.amazon.com/sdk-for-cpp/v1/developer-guide/libcrypto.html).
if(BUILD_OPENSSL)
    ExternalProject_Add(OPENSSL
        SOURCE_DIR ${OPENSSL_SOURCE_DIR}
        GIT_REPOSITORY https://github.com/openssl/openssl.git
        GIT_TAG e2e09d9fba1187f8d6aafaa34d4172f56f1ffb72 # 1.1.1g
        UPDATE_COMMAND ""
        PATCH_COMMAND cd ${CMAKE_BINARY_DIR} && python ${AWS_NATIVE_SDK_ROOT}/tools/android-build/configure_openssl_cmake.py --source ${AWS_NATIVE_SDK_ROOT} --dest ${OPENSSL_SOURCE_DIR}
        CMAKE_ARGS
        -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}
        -DCMAKE_ANDROID_NDK_TOOLCHAIN_VERSION=${CMAKE_ANDROID_NDK_TOOLCHAIN_VERSION}
        -DANDROID_NATIVE_API_LEVEL=${ANDROID_NATIVE_API_LEVEL}
        -DANDROID_ABI=${ANDROID_ABI}
        -DANDROID_TOOLCHAIN=${ANDROID_TOOLCHAIN}
        -DANDROID_STL=${ANDROID_STL}
        -DCMAKE_INSTALL_PREFIX=${OPENSSL_INSTALL_DIR}
        -DCMAKE_CXX_FLAGS=${OPENSSL_CXX_FLAGS}
        -DCMAKE_C_FLAGS=${OPENSSL_C_FLAGS}
        -DCMAKE_EXE_LINKER_FLAGS=${OPENSSL_EXE_LINKER_FLAGS}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=OFF
        )
endif()

# curl
if(BUILD_CURL)
    ExternalProject_Add(CURL
        DEPENDS ${CURL_OPENSSL_DEPENDENCY} ${CURL_ZLIB_DEPENDENCY}
        SOURCE_DIR ${CURL_SOURCE_DIR}
        GIT_REPOSITORY https://github.com/bagder/curl.git
        GIT_TAG 44b9b4d4f56d6f6de92c89636994c03984e9cd01 # 7.52.1
        UPDATE_COMMAND ""
        PATCH_COMMAND ""
        CMAKE_ARGS
        -C ${AWS_NATIVE_SDK_ROOT}/tools/android-build/CurlAndroidCrossCompile.cmake
        -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}
        -DCMAKE_ANDROID_NDK_TOOLCHAIN_VERSION=${CMAKE_ANDROID_NDK_TOOLCHAIN_VERSION}
        -DANDROID_NATIVE_API_LEVEL=${ANDROID_NATIVE_API_LEVEL}
        -DANDROID_ABI=${ANDROID_ABI}
        -DANDROID_TOOLCHAIN=${ANDROID_TOOLCHAIN}
        -DANDROID_STL=${ANDROID_STL}
        -DCMAKE_INSTALL_PREFIX=${CURL_INSTALL_DIR}
        -DCMAKE_CXX_FLAGS=${CURL_CXX_FLAGS}
        -DCMAKE_C_FLAGS=${CURL_C_FLAGS}
        -DCMAKE_STATIC_LINKER_FLAGS=${CURL_STATIC_LINKER_FLAGS}
        -DCMAKE_SHARED_LINKER_FLAGS=${CURL_SHARED_LINKER_FLAGS}
        -DCMAKE_EXE_LINKER_FLAGS=${CURL_EXE_LINKER_FLAGS}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DOPENSSL_ROOT_DIR=${OPENSSL_SOURCE_DIR}
        -DOPENSSL_INCLUDE_DIR=${OPENSSL_INCLUDE_DIR}
        -DCURL_STATICLIB=ON
        -DBUILD_CURL_EXE=ON
        -DBUILD_CURL_TESTS=OFF
        -DCURL_ZLIB=${CURL_USE_ZLIB}
        )
endif()
