/*
 Created by Szymon Rygiel on 18.05.2023.
 Klasa game_model przechowuje wskaźnik na postać gracza, wskaźnik na postać przeciwnika oraz obiekt klasy game_board, czyli planszę.
*/

#include "game_model.h"

game_model::game_model(game_board &board) : board(board) {
}

// Metoda odpowiada za stworzenie bohatera w zależności od wyboruu gracza
void game_model::choose_character(int n) {
    delete this->enemy_character;
    delete this->player_character;
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

// Zwraca wskaźnik na postać gracza
character * game_model::get_player() {
    return this->player_character;
}

// Zwraca wskaźnik na postać przeciwnika
character * game_model::get_enemy() {
    return this->enemy_character;
}

// Sprawdza czy gracz wygrał, jeśli tak zwraca prawdę, jeśli nie - fałsz
bool game_model::win() {
    if(this->enemy_character->get_health() <= 0) {
        return true;
    }
    return false;
}

// Sprawdza czy gracz przegrał, jeśli tak zwraca prawdę, jeśli nie - fałsz
bool game_model::lose() {
    if(this->player_character->get_health() <= 0) {
        return true;
    }
    return false;
}




