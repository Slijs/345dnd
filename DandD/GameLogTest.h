#include "DiceController.h"
#include "MapController.h"
#include "CharacterController.h"
#include "GameController.h"

struct GameLogTest{
	static void gameLogTest()
	{
		cout << "Test for Game Log" << endl;
		DiceController* dc = DiceController::getInstance();
		GameController* gc = GameController::getInstance();
		CharacterController* cc = CharacterController::getInstance();
		MapController* mc = MapController::getInstance();

		int input;

		cout << "Which log to write to?\n";
		cout << "1. Game\n2. Map\n3. Character\n4. Dice\n";

		cin >> input;

		while (cin.fail() || (input > 4 && input < 1))
		{
			cout << "Not a valid option. Try again.\n";
			cin.clear();
			cin.ignore(256, '\n');
		}

		string msg = "";
		string newmsg = "";
		while (newmsg.compare("0") != 0)
		{
			cout << "What would you like to write? (0: Stop)";
			cin >> newmsg;
			if (newmsg.compare("0")!=0)
				msg += newmsg+"\n";
		}

		switch (input)
		{
		case 1:
			gc->log(msg);
			cout << "Game Controller Log: \n";
			displayLogChanges(gc);
			break;
		case 2:
			mc->log(msg);
			cout << "Map Controller log: \n";
			displayLogChanges(mc);
			break;
		case 3:
			cc->log(msg);
			cout << "Character Controller log: \n";
			displayLogChanges(cc);
			break;
		case 4:
			dc->log(msg);
			cout << "Dice Controller log: \n";
			displayLogChanges(dc);
			break;
		}

		int in2;
		cout << "Would you like to continue? (0: No) ";
		cin >> in2;
		while (cin.fail() || in2 != 0)
		{
			cin.clear();
			cin.ignore(256, '\n');
			gameLogTest();
		}

		delete dc;
		delete gc;
		delete cc;
		delete mc;
		dc = nullptr;
		gc = nullptr;
		cc = nullptr;
		mc = nullptr;
	}

	static void displayLogChanges(GameLog* log)
	{
		vector<string> lines = SingletonInputOutputManager::getInstance()->readFileLineByLine(log->getPath());
		system("CLS");

		for (int i = 0; i < lines.size(); i++)
			cout << lines[i] << endl;

		cout << "End of File.";
		system("pause");
	}
};