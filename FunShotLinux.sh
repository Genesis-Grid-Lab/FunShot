#!/bin/bash

# output directory

target="Targets/$1"

# generate cmake build files

echo ${VULKAN_SDK}

cmake -S . -B $target -DCMAKE_BUILD_TYPE=$1 -DVULKAN_SDK=${VULKAN_SDK}

# compile cmake build files

cmake --build $target --config $1
