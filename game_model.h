//
// Created by timo0 on 18.05.2023.
//

#ifndef IN_GAME_COMBAT_SYSTEM_GAME_MODEL_H
#define IN_GAME_COMBAT_SYSTEM_GAME_MODEL_H

#include "game_board.h"
#include "character.h"

class game_model {

public:
    explicit game_model(game_board& board);
    void choose_character(int n);
    character get_player();
    character get_enemy();
    bool end_game();
private:
    game_board& board;
    character enemy;
    character player_character;
};


#endif //IN_GAME_COMBAT_SYSTEM_GAME_MODEL_H
