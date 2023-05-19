//
// Created by timo0 on 18.05.2023.
//

#include "game_model.h"

game_model::game_model(game_board &board) : board(board){

}

void game_model::choose_character(int n) {

}

character game_model::get_player() {
    return character();
}

character game_model::get_enemy() {
    return character();
}

bool game_model::end_game() {
    return false;
}


