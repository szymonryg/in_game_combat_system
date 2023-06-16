//
// Created by timo0 on 18.05.2023.
//

#include "game_model.h"

game_model::game_model(game_board &board) : board(board) {
}

void game_model::choose_character(int n) {
    enemy* enem = new enemy;
    this->enemy_character = enem;

    if(n == 1) {
        warrior* war = new warrior;
        this->player_character = war;
    }
    else if(n == 2) {
        archer* arch = new archer;
        this->player_character = arch;
    }
    else if(n == 3) {
        sorcerer* sorc = new sorcerer;
        this->player_character = sorc;
    }
}

character * game_model::get_player() {
    return this->player_character;
}

character * game_model::get_enemy() {
    return this->enemy_character;
}

bool game_model::win() {
    if(this->enemy_character->get_health() <= 0) {
        return true;
    }
    return false;
}

bool game_model::lose() {
    if(this->player_character->get_health() <= 0) {
        return true;
    }
    return false;
}




