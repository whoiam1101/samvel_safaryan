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

void Human::digestion(Food _food) {
    _physical_health_level++;
}

void Human::digestion(Drink _drink) {
    switch (_drink) {
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

void Human::drink(Drink _drink) {
    digestion(_drink);
}

void Human::eat(Food _food) {
    digestion(_food);
}

void Human::colorHair(Color _color) {
    _hair_color = _color;
}