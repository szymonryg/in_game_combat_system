//
// Created by timo0 on 18.05.2023.
//

#include "game_model.h"

game_model::game_model(game_board &board) : board(board) {
    //this->enemy = character();
    this->enemy.take_damage(20);
}

void game_model::choose_character(int n) {
    //this->player_character = character();
}

character game_model::get_player() {
    return this->player_character;
}

character game_model::get_enemy() {
    return this->enemy;
}

bool game_model::end_game() {
    if(this->player_character.get_health() <= 0 || this->enemy.get_health() <= 0) {
        return true;
    }
    return false;
}




