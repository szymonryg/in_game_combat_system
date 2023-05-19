//
// Created by timo0 on 18.05.2023.
//

#include "game_board.h"

void game_board::move_player() {

}

void game_board::move_enemy() {

}

game_board::position game_board::get_player_position() {
    return game_board::player_position;
}

game_board::position game_board::get_enemy_position() {
    return game_board::enemy_position;
}

bool game_board::attack_possible() {
    return false;
}

void game_board::reset_board() {

}
