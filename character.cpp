//
// Created by timo0 on 18.05.2023.
//

#include "character.h"

character::character() {
}

void character::take_damage(int dmg) {
    this->hp -= dmg;
}

void character::special_attack(character* en) {
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

std::string character::get_name() {
    return this->name;
}

std::string character::get_stamina_name() {
    return this->stamina_name;
}

std::string character::get_ability_name() {
    return this->ability_name;
}


warrior::warrior() {
     this->hp = 200;
     this->attack_points = 30;
     this->movement = 3;
     this->stamina = 100;
     this->stamina_name = "Stamina: ";
     this->name = "WARRIOR";
     this->ability_name = "Special attack";
}

void warrior::special_attack(character* en) {
    if(this->stamina >= 50){
        en->take_damage(40);
        this->hp += 10;
        this->stamina -= 50;
    }
}

archer::archer() {
    this->hp = 100;
    this->attack_points = 10;
    this->movement = 6;
    this->stamina = 5;
    this->stamina_name = "Arrows: ";
    this->name = "ARCHER";
    this->ability_name = "Shoot";
}

void archer::special_attack(character* en) {
    if(this->stamina >= 1){
        en->take_damage(20);
        this->stamina -= 1;
    }
}

sorcerer::sorcerer() {
    this->hp = 140;
    this->attack_points = 20;
    this->movement = 4;
    this->stamina = 100;
    this->stamina_name = "Mana: ";
    this->name = "SORCERER";
    this->ability_name = "Heal";
}

void sorcerer::special_attack(character* en) {
    if(this->stamina >= 50){
        this->hp += 40;
        this->stamina -= 50;
    }
}

enemy::enemy() {
    this->hp = 150;
    this->attack_points = 20;
}
