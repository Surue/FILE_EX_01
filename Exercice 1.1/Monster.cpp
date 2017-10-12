#include "stdafx.h"
#include "Monster.h"
#include <iostream>

std::ostream& operator << (std::ostream& os, const Races& obj) {
	os << static_cast<std::underlying_type<Races>::type>(obj);
	return os;
}

Monster::Monster() {
	m_health = -1;
	m_attackPower = -1;
	m_defensePower = -1;
	m_speed = -1;
	m_race = (Races)-1;
}

Monster::Monster(int race, double health, double attackPower, double defensePower, double speed) :
	m_health(health),
	m_attackPower(attackPower),
	m_defensePower(defensePower),
	m_speed(speed),
	m_race((Races)race) {
}

Monster::~Monster() {
}

void Monster::attack(Monster& monsterAttacked, int turn) {
	//if first turn -> decided who start
	if (turn == 0 && monsterAttacked.m_speed  > m_speed) {
		monsterAttacked.attack(*this, turn);
		return;
	}

	//Test if they can fight each other
	if (m_race != monsterAttacked.m_race) {
		double damage = m_attackPower - monsterAttacked.m_defensePower;
		if (damage <= 0) {
			damage = 1;
		}
		monsterAttacked.m_health -= damage;
		turn++;

		//test if the attacked is dead/alive
		if (monsterAttacked.m_health > 0) {
			monsterAttacked.attack(*this, turn);
		}
		else {
			std::cout << "Le " << monsterAttacked.m_race << " est mort. C'est le " << m_race << " qui gagne apres " << turn << " tours.\n";
		}
	}
	else {
		std::cout << "2 monstres de meme races ne peuvent se combattrent\n";
	}
}

void Monster::printStat() {
	std::cout << "Le monstre de race " << m_race << "\n"
		<< "HP = " << m_health << "\n"
		<< "AP = " << m_attackPower << "\n"
		<< "DP = " << m_defensePower << "\n"
		<< "SP = " << m_speed << "\n";
}

bool Monster::MonsterFinishedConstruct() {
	if (m_health != -1 && m_attackPower != -1 && m_defensePower != -1 && m_speed != -1 && (int)m_race != -1) {
		return true;
	}
	return false;
}

void Monster::setHealth(double health) {
	m_health = health;
}

void Monster::setAttackPower(double attackPower) {
	m_attackPower = attackPower;
}

void Monster::setDefensePower(double defensePower) {
	m_defensePower = defensePower;
}

void Monster::setSpeed(double speed) {
	m_speed = speed;
}

void Monster::setRace(int race) {
	m_race = (Races)race;
}
