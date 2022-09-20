cmake_minimum_required(VERSION 3.20)

project(security LANGUAGES C VERSION 1.0.0)

# include(CTest)
# enable_testing()

include(${CMAKE_SOURCE_DIR}/cmake/option.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake)

set_option(BUILD_TEST OFF BOOL "Build test code for library")

set_choice (CMAKE_BUILD_TYPE "Debug;Release;MinSizeRel;RelWithDebInfo" "Debug" "Choose type of build")

set (SRCS
	${CMAKE_SOURCE_DIR}/src/secure_input.c
    ${CMAKE_SOURCE_DIR}/src/secure_arithmetic_double.c
    ${CMAKE_SOURCE_DIR}/src/secure_arithmetic_float.c
    ${CMAKE_SOURCE_DIR}/src/secure_arithmetic_int.c
    ${CMAKE_SOURCE_DIR}/src/secure_arithmetic_long.c
    ${CMAKE_SOURCE_DIR}/src/secure_arithmetic_long_double.c
    ${CMAKE_SOURCE_DIR}/src/secure_arithmetic_long_long.c
    ${CMAKE_SOURCE_DIR}/src/secure_arithmetic_schar.c
    ${CMAKE_SOURCE_DIR}/src/secure_arithmetic_short.c
    ${CMAKE_SOURCE_DIR}/src/secure_arithmetic_uchar.c
    ${CMAKE_SOURCE_DIR}/src/secure_arithmetic_uint.c
    ${CMAKE_SOURCE_DIR}/src/secure_arithmetic_ulong.c
    ${CMAKE_SOURCE_DIR}/src/secure_arithmetic_ulong_long.c
    ${CMAKE_SOURCE_DIR}/src/secure_arithmetic_ushort.c   
)

set (HEADERS
    ${CMAKE_SOURCE_DIR}/include/secure_input.h
    ${CMAKE_SOURCE_DIR}/include/secure_arithmetic.h
)

if (BUILD_TEST)
    add_subdirectory(${CMAKE_SOURCE_DIR}/test)
endif()

include_directories(${CMAKE_SOURCE_DIR}/include)

set (CMAKE_C_STANDARD 17)
set (CMAKE_C_STANDARD_REQUIRED ON)

add_library (${PROJECT_NAME} STATIC ${SRCS} ${HEADERS})
target_link_libraries(${PROJECT_NAME} PRIVATE m)

foreach(header ${HEADERS})
    set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER ${header})
endforeach()

set_target_warnings(${PROJECT_NAME})

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME} ARCHIVE)
install(TARGETS ${PROJECT_NAME} PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Quentin Horgues")
set(CPACK_DEB_COMPONENTS_INSTALL YES)
set(CPACK_DEBIAN_PACKAGE_DEPENDS "")
set(CPACK_DESKTOP_SHORTCUTS ON)
include(CPack)