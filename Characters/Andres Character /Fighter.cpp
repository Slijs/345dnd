#include "Fighter.h"
#include <random>
#include <ctime>
#include "Character.h";

using namespace std;

int Fighter::d10()
{
	// Create a random number each time 
	std::mt19937 Rng;
	Rng.seed(std::random_device()());
	// Randomly choose between 1 to 10
	std::uniform_int_distribution<std::mt19937::result_type> dist10(1, 10);

	return dist10(Rng);
}

int Fighter::lvlOneHitPoints = 10;

int Fighter::HitPointLvlCalculation(int levelValue, int constModValue)
{

	int counter = 0;
	for (int i = 1; i < levelValue; i++) {
		counter += d10() + constModValue;
	}
	return counter;
}


int Fighter::CalculateProficiency(int levelValue) {

	int proficiency = 0;

	if (levelValue <= 0) {
		return 2;
	}
	if (levelValue <= 4) {
		proficiency = 2;
	}
	else if (levelValue <= 8) {
		proficiency = 3;
	}
	else if (levelValue <= 12) {
		proficiency = 4;
	}
	else if (levelValue <= 16) {
		proficiency = 5;
	}
	else if (levelValue <= 20) {
		proficiency = 6;
	}
	else
		proficiency = 6;

	return proficiency;
}

