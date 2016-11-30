#include "DiceController.h"
#include "MapController.h"
#include "CharacterController.h"
#include "GameController.h"

struct GameLogTest{
	static void gameLogTest()
	{
		cout << "Test for Game Log" << endl;

		int input;

		cout << "Which log to read?\n";
		cout << "1. Game\n2. Map\n3. Character\n4. Dice\n";

		cin >> input;

		while (cin.fail() || (input > 4 && input < 1))
		{
			cout << "Not a valid option. Try again.\n";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> input;
		}

		displayLogChanges(input);

		

		int in2;
		cout << "Would you like to continue? (0: No) ";
		cin >> in2;
		while (cin.fail() || in2 != 0)
		{
			cin.clear();
			cin.ignore(256, '\n');
			gameLogTest();
		}
		
	}

	static void displayLogChanges(int input)
	{
		string log;
		vector<string> lines;
		switch (input)
		{
		case 1:
			log = "Game";
			lines = SingletonInputOutputManager::getInstance()->readFileLineByLine(GameController::getInstance()->getPath());
			break;
		case 2:
			log = "Map";
			lines = SingletonInputOutputManager::getInstance()->readFileLineByLine(MapController::getInstance()->getPath());

			break;
		case 3:
			log ="Character";
			lines = SingletonInputOutputManager::getInstance()->readFileLineByLine(CharacterController::getInstance()->getPath());
			break;
		case 4:
			log = "Dice";
			lines = SingletonInputOutputManager::getInstance()->readFileLineByLine(DiceController::getInstance()->getPath());
			break;
		}
		
		system("CLS");

		cout << log +" Controller log: \n";
		for (int i = 0; i < lines.size(); i++)
			cout << lines[i] << endl;

		cout << "End of File.\n";
		system("pause");
	}
};