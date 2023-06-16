//
// Created by timo0 on 18.05.2023.
//

#include <iostream>

#include "game_view.h"

game_view::game_view(game_model &model) : model(model) {

}

void game_view::menu() {
    system("cls");
    std::cout << "Choose your character:\n";
    std::cout << "1. Warrior\n";
    std::cout << "2. Archer\n";
    std::cout << "3. Sorcerer\n";
    std::cout << "Esc to exit\n";
}

void game_view::turn_update(std::string comm) {
    system("cls");
    std::cout << "-------------------------------------             " << this->model.get_player()->get_name() << "\n";
    std::cout << "| " << this->model.board.board1[0][0] << " | " << this->model.board.board1[0][1] << " | " << this->model.board.board1[0][2];
    std::cout << " | " << this->model.board.board1[0][3] << " | " << this->model.board.board1[0][4] << " | " << this->model.board.board1[0][5];
    std::cout << " | " << this->model.board.board1[0][6] << " | " << this->model.board.board1[0][7] << " | " << this->model.board.board1[0][8] << " |";
    std::cout << "             " << "Health points: " << this->model.get_player()->get_health() << "\n";
    std::cout << "-------------------------------------             " << this->model.get_player()->get_stamina_name() << this->model.get_player()->get_stamina() << "\n";
    std::cout << "| " << this->model.board.board1[1][0] << " | " << this->model.board.board1[1][1] << " | " << this->model.board.board1[1][2];
    std::cout << " | " << this->model.board.board1[1][3] << " | " << this->model.board.board1[1][4] << " | " << this->model.board.board1[1][5];
    std::cout << " | " << this->model.board.board1[1][6] << " | " << this->model.board.board1[1][7] << " | " << this->model.board.board1[1][8] << " |";
    std::cout << "             " << "Attack points: " << this->model.get_player()->get_attack() << "\n";
    std::cout << "-------------------------------------             " << "Movement points: " << this->model.get_player()->get_movement() << "\n";
    std::cout << "| " << this->model.board.board1[2][0] << " | " << this->model.board.board1[2][1] << " | " << this->model.board.board1[2][2];
    std::cout << " | " << this->model.board.board1[2][3] << " | " << this->model.board.board1[2][4] << " | " << this->model.board.board1[2][5];
    std::cout << " | " << this->model.board.board1[2][6] << " | " << this->model.board.board1[2][7] << " | " << this->model.board.board1[2][8] << " |\n";
    std::cout << "-------------------------------------\n";
    std::cout << "| " << this->model.board.board1[3][0] << " | " << this->model.board.board1[3][1] << " | " << this->model.board.board1[3][2];
    std::cout << " | " << this->model.board.board1[3][3] << " | " << this->model.board.board1[3][4] << " | " << this->model.board.board1[3][5];
    std::cout << " | " << this->model.board.board1[3][6] << " | " << this->model.board.board1[3][7] << " | " << this->model.board.board1[3][8] << " |";
    std::cout << "             " << "ENEMY\n";
    std::cout << "-------------------------------------             " << "Health points: " << this->model.get_enemy()->get_health() << "\n";
    std::cout << "| " << this->model.board.board1[4][0] << " | " << this->model.board.board1[4][1] << " | " << this->model.board.board1[4][2];
    std::cout << " | " << this->model.board.board1[4][3] << " | " << this->model.board.board1[4][4] << " | " << this->model.board.board1[4][5];
    std::cout << " | " << this->model.board.board1[4][6] << " | " << this->model.board.board1[4][7] << " | " << this->model.board.board1[4][8] << " |";
    std::cout << "             " << "Attack points: " << this->model.get_enemy()->get_attack() << "\n";
    std::cout << "-------------------------------------\n";
    std::cout << "| " << this->model.board.board1[5][0] << " | " << this->model.board.board1[5][1] << " | " << this->model.board.board1[5][2];
    std::cout << " | " << this->model.board.board1[5][3] << " | " << this->model.board.board1[5][4] << " | " << this->model.board.board1[5][5];
    std::cout << " | " << this->model.board.board1[5][6] << " | " << this->model.board.board1[5][7] << " | " << this->model.board.board1[5][8] << " |\n";
    std::cout << "-------------------------------------\n";
    std::cout << "| " << this->model.board.board1[6][0] << " | " << this->model.board.board1[6][1] << " | " << this->model.board.board1[6][2];
    std::cout << " | " << this->model.board.board1[6][3] << " | " << this->model.board.board1[6][4] << " | " << this->model.board.board1[6][5];
    std::cout << " | " << this->model.board.board1[6][6] << " | " << this->model.board.board1[6][7] << " | " << this->model.board.board1[6][8] << " |\n";
    std::cout << "-------------------------------------             " << "Your moves:\n";
    std::cout << "| " << this->model.board.board1[7][0] << " | " << this->model.board.board1[7][1] << " | " << this->model.board.board1[7][2];
    std::cout << " | " << this->model.board.board1[7][3] << " | " << this->model.board.board1[7][4] << " | " << this->model.board.board1[7][5];
    std::cout << " | " << this->model.board.board1[7][6] << " | " << this->model.board.board1[7][7] << " | " << this->model.board.board1[7][8] << " |";
    std::cout << "             " << "1. Move\n";
    std::cout << "-------------------------------------             " << "2. Attack\n";
    std::cout << "| " << this->model.board.board1[8][0] << " | " << this->model.board.board1[8][1] << " | " << this->model.board.board1[8][2];
    std::cout << " | " << this->model.board.board1[8][3] << " | " << this->model.board.board1[8][4] << " | " << this->model.board.board1[8][5];
    std::cout << " | " << this->model.board.board1[8][6] << " | " << this->model.board.board1[8][7] << " | " << this->model.board.board1[8][8] << " |";
    std::cout << "             " << "3. " << this->model.get_player()->get_ability_name() << "\n";
    std::cout << "-------------------------------------             " << "4. End turn\n";
    std::cout << "\n" << comm;
}


void game_view::win() {
    system("cls");
    std::cout << "You WON!!\n";
    std::cout << "Press 1 to play again\n";
    std::cout << "Press ESC to exit";
}

void game_view::lose() {
    system("cls");
    std::cout << "You LOST!!\n";
    std::cout << "Press 1 to play again\n";
    std::cout << "Press ESC to exit";
}
