cmake_minimum_required(VERSION 3.20)
project(TUI_Tycoon VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)

add_executable(app
    src/main.cpp
    src/AppEngine.cpp
)

target_include_directories(app PRIVATE ${CURSES_INCLUDE_DIRS})
target_link_libraries(app PRIVATE ${CURSES_LIBRARIES})
