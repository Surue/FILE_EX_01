#ifndef MONSTER_H
#define MONSTER_H

enum class Races {
	ORC,
	TROLL,
	GOBLIN,
	LENGHT
};
class Monster {
private:
	double m_health = 0;
	double m_attackPower = 0;
	double m_defensePower = 0;
	double m_speed = 0;
	Races m_race;

public:

	Monster(int race, double health, double attackPower, double defensePower, double speed);
	Monster();
	~Monster();

	void attack(Monster& monsterAttacked, int turn = 0);
	void printStat();

	bool MonsterFinishedConstruct();

	void setHealth(double);
	void setAttackPower(double);
	void setDefensePower(double);
	void setSpeed(double);
	void setRace(int);
};
#endif
