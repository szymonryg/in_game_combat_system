//
// Created by timo0 on 18.05.2023.
//

#include <iostream>
#include "character.h"

character::character() {
    this->hp = 100;
    this->attack_points = 15;
    this->stamina = 100;
    this->movement = 4;
    std::cout << "okok";
}

void character::take_damage(int dmg) {
    this->hp -= dmg;
}

void character::special_attack() {

}

int character::get_health() {
    return this->hp;
}

int character::get_stamina() {
    return this->stamina;
}

int character::get_movement() {
    return this->movement;
}

int character::get_attack() {
    return this->attack_points;
}
