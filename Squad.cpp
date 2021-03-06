//
// Created by Fargat on 24/04/2018.
//

#include "Squad.h"
#include <iostream>

Squad::Squad(std::string name) :
        _name(name) {}

std::string Squad::info() const {
    std::string s = _name + " [";
    for (const Unit& unit : _units)
        s += '\n' + unit.info();
    s += "]\n";
    return s;
}

bool Squad::alive() const {
    return !_units.empty();
}

void Squad::recalc() {
    size_t at = 0;
    for (size_t i = 0; i < _units.size(); ++i)
        if (!_units[at].alive())
            std::swap(_units[at], _units[at + 1]);
        else
            ++at;
    _units.erase(_units.begin() + at, _units.end());
}

void Squad::attack(Squad& other) {
    size_t rounds = rand() % 6 + 3;
    while (rounds-- > 0 && alive() && other.alive()) {
        size_t attackerId = rand() % _units.size();
        size_t attackedId = rand() % other._units.size();
        _units[attackerId].attack(other._units[attackedId]);
        recalc();
        other.recalc();
    }
}

void Squad::addUnit(UnitClass* unitClass, std::string newUnitName) {
    _units.push_back(Unit(unitClass, newUnitName));
}