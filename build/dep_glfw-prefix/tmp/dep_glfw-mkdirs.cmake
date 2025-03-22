# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/linehad/Desktop/OpenGL/build/dep_glfw-prefix/src/dep_glfw")
  file(MAKE_DIRECTORY "C:/Users/linehad/Desktop/OpenGL/build/dep_glfw-prefix/src/dep_glfw")
endif()
file(MAKE_DIRECTORY
  "C:/Users/linehad/Desktop/OpenGL/build/dep_glfw-prefix/src/dep_glfw-build"
  "C:/Users/linehad/Desktop/OpenGL/build/dep_glfw-prefix"
  "C:/Users/linehad/Desktop/OpenGL/build/dep_glfw-prefix/tmp"
  "C:/Users/linehad/Desktop/OpenGL/build/dep_glfw-prefix/src/dep_glfw-stamp"
  "C:/Users/linehad/Desktop/OpenGL/build/dep_glfw-prefix/src"
  "C:/Users/linehad/Desktop/OpenGL/build/dep_glfw-prefix/src/dep_glfw-stamp"
)

set(configSubDirs Debug;Release;MinSizeRel;RelWithDebInfo)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/linehad/Desktop/OpenGL/build/dep_glfw-prefix/src/dep_glfw-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/linehad/Desktop/OpenGL/build/dep_glfw-prefix/src/dep_glfw-stamp${cfgdir}") # cfgdir has leading slash
endif()
