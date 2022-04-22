#include "human.h"

char* Human::speak(char* _text) const {
    return _text;
}

void Human::think() {
    _mental_health_level++;
}

void Human::walk() {
    _mental_health_level++;
    _physical_health_level++;
}

void Human::digestion(Food food) {
    _physical_health_level++;
}

void Human::digestion(Drink drink) {
    switch (drink) {
        case Drink::WATER:
        case Drink::MILK:
        case Drink::TEA:
            _physical_health_level++;
            _mental_health_level++;
            break;

        case Drink::COFFEE:
            _mental_health_level++;
            _physical_health_level--;
            break;

        default:
            _mental_health_level--;
            _physical_health_level--;
            break;
    }
}

void Human::drink(Drink drink) {
    digestion(drink);
}

void Human::eat(Food food) {
    digestion(food);
}

void Human::setHairColor(Color color) {
    _hair_color = color;
}