cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(CacTemplate VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated -DCC_TARGET_OS_MAC -fms-extensions -Xlinker --no-demangle -g")
#set(CMAKE_OSX_DEPLOYMENT_TARGET 10.14)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 17)

include_directories(
    Cacao/
    Cacao/include
    Cacao/include/cocos2dx
    Cacao/include/cocos2dx/include
    Cacao/include/cocos2dx/kazmath/include
    Cacao/include/cocos2dx/platform/mac
    Cacao/include/cocos2dx/platform/third_party/mac
    Cacao/include/cocos2dx/platform/third_party/mac/OGLES
    Cacao/include/cocos2dext
    Cacao/include/cocos2dx/custom/Sprites/CCMenuItemSpriteExtra
)

add_subdirectory(Cacao)

add_library(${PROJECT_NAME} SHARED main.cpp)
target_link_directories(${PROJECT_NAME} PRIVATE Cacao)
target_link_libraries(${PROJECT_NAME} Cacao)

add_custom_command(
    TARGET  ${PROJECT_NAME}
    COMMAND sudo osxinj \"Geometry Dash\" *.dylib || true
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Injecting"
)
