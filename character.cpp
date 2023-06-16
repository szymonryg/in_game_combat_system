/*
 Created by Szymon Rygiel on 18.05.2023.
 Plik przechowuje deklarację klasy character oraz jej klas pochodnych
 Klasy te odpowiadają postaciom w grze warrior, archer, sorcerer i enemy
*/

#include "character.h"

character::character() {
}

// Metoda odpowiadająca za przyjmowanie obrażeń
void character::take_damage(int dmg) {
    this->hp -= dmg;
}

// Metoda wirtualna jest nadpisywana w klasach pochodnych
void character::special_attack(character* en) {
}

// Zwraca ilość punktów zdrowia
int character::get_health() {
    return this->hp;
}

// Zwraca ilość punktów staminy
int character::get_stamina() {
    return this->stamina;
}

// Zwraca zwraca ilość punktów ruchu
int character::get_movement() {
    return this->movement;
}

// Zwraca ilość punktów ataku
int character::get_attack() {
    return this->attack_points;
}

// Zwraca nazwę bohatera
std::string character::get_name() {
    return this->name;
}

// Zwraca zwraca nazwę punktów staminy (sorcerer ma manę, archer ma strzały)
std::string character::get_stamina_name() {
    return this->stamina_name;
}

// Zwraca nazwę umiejętności specjalnej
std::string character::get_ability_name() {
    return this->ability_name;
}

// Konstruktor klasy pochodnej warrior
warrior::warrior() {
     this->hp = 200;
     this->attack_points = 30;
     this->movement = 3;
     this->stamina = 100;
     this->stamina_name = "Stamina: ";
     this->name = "WARRIOR";
     this->ability_name = "Special attack";
}

// Nadpisywanie metody special_attack metodą special_attack unikalną dla klasy warrior
void warrior::special_attack(character* en) {
    if(this->stamina >= 50){
        en->take_damage(40);
        this->hp += 10;
        this->stamina -= 50;
    }
}

// Konstruktor klasy pochodnej archer
archer::archer() {
    this->hp = 100;
    this->attack_points = 10;
    this->movement = 6;
    this->stamina = 5;
    this->stamina_name = "Arrows: ";
    this->name = "ARCHER";
    this->ability_name = "Shoot";
}

// Nadpisywanie metody special_attack metodą special_attack unikalną dla klasy archer
void archer::special_attack(character* en) {
    if(this->stamina >= 1){
        en->take_damage(20);
        this->stamina -= 1;
    }
}

// Konstruktor klasy pochodnej sorcerer
sorcerer::sorcerer() {
    this->hp = 140;
    this->attack_points = 20;
    this->movement = 4;
    this->stamina = 100;
    this->stamina_name = "Mana: ";
    this->name = "SORCERER";
    this->ability_name = "Heal";
}

// Nadpisywanie metody special_attack metodą special_attack unikalną dla klasy sorcerer
void sorcerer::special_attack(character* en) {
    if(this->stamina >= 50){
        this->hp += 40;
        this->stamina -= 50;
    }
}

// Konstruktor klasy pochodnej enemy
enemy::enemy() {
    this->hp = 150;
    this->attack_points = 20;
}
