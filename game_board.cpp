//
// Created by timo0 on 18.05.2023.
//

#include "game_board.h"

game_board::game_board() {
    this->reset_cursor();
    this->reset_board();
}

void game_board::reset_cursor() {
    this->cursor_position.x = 4;
    this->cursor_position.y = 4;
}

void game_board::move_cursor(int x, int y) {
    this->board1[cursor_position.y][cursor_position.x] = ' ';
    this->cursor_position.x += x;
    this->cursor_position.y += y;
    this->board1[cursor_position.y][cursor_position.x] = '+';
    this->board1[enemy_position.y][enemy_position.x] = 'E';
    this->board1[player_position.y][player_position.x] = 'P';
}

void game_board::move_player(position cursor) {
    this->board1[player_position.y][player_position.x] = ' ';
    this->player_position.x = cursor.x;
    this->player_position.y = cursor.y;
    this->board1[player_position.y][player_position.x] = 'P';
}

void game_board::move_enemy(int x, int y) {
    this->board1[enemy_position.y][enemy_position.x] = ' ';
    this->enemy_position.x = x;
    this->enemy_position.y = y;
    this->board1[enemy_position.y][enemy_position.x] = 'E';
}

game_board::position game_board::get_player_position() {
    return this->player_position;
}

game_board::position game_board::get_enemy_position() {
    return this->enemy_position;
}

bool game_board::attack_possible() {
    if((this->player_position.y == this->enemy_position.y) && ((this->player_position.x - 1 == this->enemy_position.x) || (this->player_position.x + 1 == this->enemy_position.x)))
        return true;
    else if((this->player_position.y - 1 == this->enemy_position.y) && ((this->player_position.x - 1 == this->enemy_position.x) || (this->player_position.x == this->enemy_position.x) || (this->player_position.x + 1 == this->enemy_position.x)))
        return true;
    else if((this->player_position.y + 1 == this->enemy_position.y) && ((this->player_position.x - 1 == this->enemy_position.x) || (this->player_position.x == this->enemy_position.x) || (this->player_position.x + 1 == this->enemy_position.x)))
        return true;

    return false;
}

void game_board::reset_board() {
    this->player_position.x = 0;
    this->player_position.y = 4;
    this->enemy_position.x = 7;
    this->enemy_position.y = 4;
    for (int i = 0; i <= 8; i++){
        for (int j = 0; j <= 8; j++) {
            this->board1[i][j] = ' ';
        }
    }
    this->board1[player_position.y][player_position.x] = 'P';
    this->board1[enemy_position.y][enemy_position.x] = 'E';
}

game_board::position game_board::get_cursor_position() {
    return this->cursor_position;
}

bool game_board::move_possible(position character_position, int movement_points) {
    if(abs(character_position.y - cursor_position.y) + abs(character_position.x - cursor_position.x) <= movement_points)
        return true;

    return false;
}






