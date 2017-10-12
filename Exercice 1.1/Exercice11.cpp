//Nicolas Schneider
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Monster.h"
#include <list>

int main() {

	std::ifstream file("MonsterValue.txt");
	std::string nameValue;
	int value;

	if (file) {
		std::cout << "Il y a un fichier\n";
	} else {
		std::cout << "Il n'y a pas de fichier\n";
		return EXIT_FAILURE;
	}

	std::list<Monster> monsterList;
	
	Monster m;
	while (file >> nameValue >> value) {
		if (nameValue == "HP") {
			m.setHealth(value);
		} else if (nameValue == "AP") {
			m.setAttackPower(value);
		} else if (nameValue == "DP") {
			m.setDefensePower(value);
		} else if (nameValue == "SP") {
			m.setSpeed(value);
		} else if (nameValue == "RACE") {
			m.setRace(value);
		} else {
			std::cout << "Nom de valeur non reconnu\n";
		}

		if (m.MonsterFinishedConstruct()) {
			monsterList.push_back(m);
			m = Monster();
		}
	}

	for (auto it = monsterList.begin(); it != --monsterList.end(); it++) {
		auto next = std::next(it, 1);
		it->attack(*next);
	}

	file.close();

	system("pause");
    return EXIT_SUCCESS;
}

