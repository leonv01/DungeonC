cmake_minimum_required(VERSION 3.16)
project(DungeonC LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include_directories(include)


add_executable(main
        src/main.cpp

        src/entity/Player.cpp
        src/entity/Enemy.cpp

        src/util/Vector2.cpp

        src/graphics/Render.cpp

        src/core/World.cpp
        include/core/ResourceManager.h
        src/core/Game.cpp
        include/core/Game.h
        include/core/Resources.h
        src/graphics/Animator.cpp
        include/graphics/Animator.h
)
target_link_libraries(main PRIVATE sfml-graphics)
target_compile_features(main PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET main
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()
