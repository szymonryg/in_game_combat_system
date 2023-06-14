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

void game_view::player_turn_update() {
    /*std::cout << "-------------------------------------\n"
                 "|   |   |   |   |   |   |   |   |   |\n"
                 "-------------------------------------\n"
                 "|   |   |   |   |   |   |   |   |   |\n"
                 "-------------------------------------\n"
                 "|   |   |   |   |   |   |   |   |   |\n"
                 "-------------------------------------\n"
                 "|   |   |   |   |   |   |   |   |   |\n"
                 "-------------------------------------\n"
                 "|   |   |   |   |   |   |   |   |   |\n"
                 "-------------------------------------\n"
                 "|   |   |   |   |   |   |   |   |   |\n"
                 "-------------------------------------\n"
                 "|   |   |   |   |   |   |   |   |   |\n"
                 "-------------------------------------\n"
                 "|   |   |   |   |   |   |   |   |   |\n"
                 "-------------------------------------\n"
                 "|   |   |   |   |   |   |   |   |   |\n"
                 "-------------------------------------\n";*/
    system("cls");
    for (int i = 0; i <= 8; i++){
        for (int j = 0; j <= 8; j++) {
            std::cout << this->model.board.board1[i][j];
        }
        std::cout << "\n";
    }
    std::cout << "1. Move\n";
    std::cout << "2. Attack\n";
    std::cout << "3. Special ability\n";
    std::cout << "4. End turn\n";
    std::cout << "Enemy hp: " << this->model.get_player().get_health();
    std::cout << "Enemy hp: " << this->model.get_enemy().get_health();


}

void game_view::enemy_turn_update() {

}

void game_view::win() {
    system("cls");
    std::cout << "You WON!!\n";
    std::cout << "Press enter to play again\n";
    std::cout << "Press ESC to exit";
}

void game_view::lose() {
    system("cls");
    std::cout << "You LOST!!\n";
    std::cout << "Press enter to play again\n";
    std::cout << "Press ESC to exit";
}
