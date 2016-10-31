#pragma once

class Fighter
{
public:
	static int lvlOneHitPoints;
	static int Fighter::HitPointLvlCalculation(int levelValue, int constModValue);
	static int Fighter::CalculateProficiency(int levelValue);
	static int d10();
};

