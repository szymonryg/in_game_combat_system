cmake_minimum_required(VERSION 3.24)
project(in_game_combat_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(in_game_combat_system main.cpp game_controller.cpp game_controller.h game_model.cpp game_model.h game_view.cpp game_view.h character.cpp character.h game_board.cpp game_board.h)
