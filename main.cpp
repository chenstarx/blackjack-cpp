#include "Player.h"

//Author: Liqi.Chen15
//ID: 1508274

void showresult(Player &player, Deck &controller);
void checkCard(Player &player, Deck &controller);
void DisplayRule();

void main()
{
	string playerName = "";
	char choice = ' ';
	
	//Game guide.
	cout << "\nWelcome to Liqi.Chen's BlackJack Game!" <<endl;
	cout << "--------------------------------------------" << endl;

	cout << "For the rules of this game enter (R/r)" << endl;
	cout << "Enter (S/s) to Start Game directly: ";

	while (!(cin >> choice) || !(choice == 'R' || choice == 'r' 
			|| choice == 'S' || choice == 's'))
	//Checking the validity of the input, if invalid, input again.
	{
		cout << "Please input R/r or P/p, try again: ";
		cin.clear();
		cin.ignore();
	}

	if (choice == 'R' || choice == 'r')
		DisplayRule();

	cout << "\nPlease enter your name:";
	cin >> playerName;

	Deck *Controller = new Deck();
	//set up the game controller
	Player *player = new Player(playerName, 100, 10);
	//money $100, wager $10.
	Player *dealer = new Player();
	//dealer is also a instance of class player, who has his Hand.

	cout << "\nWelcome " << playerName << "!" << endl << endl;
	cout << "Now you have $"<< player->money() <<", Game Start." << endl << endl;
	system("pause");

	srand((unsigned)time(NULL));
	//set up the randdom generator

	while (!(Controller->IsGameOver()))
	//the game start
	{
		Controller->reset();
		//reset the game controller when start a new round.
		system("cls");
		//clear the screen.

		showinfo(*player, *dealer, *Controller);
		//show player's money and wager, where player can change wager, deal or quit the game.
		if (Controller->IsGameOver())
			return;
		//player choose to quit the game

		while(!(Controller->IsRoundOver() || Controller->IsGameOver()))
		//a round
		{
			system("cls");
			gameinfo(*player, *dealer, *Controller);
			//show the game information, for example, player and dealer's cards.
			gameplay(*player, *dealer, *Controller);
			//play a round, where player can Hit or Stand.
			checkCard(*player, *Controller);
			//Check if all cards are used. game will get to end if all 52 cards are used.
		}
		if(!(Controller->IsCardOver()))
			showresult(*player, *Controller);
		//show result after a round, if all cards are used before, no result will be shown, game ended directly.

		player->reset(*Controller);
		dealer->reset(*Controller);
		//reset the card for player and dealer

		checkCard(*player, *Controller);
		//if the card is not enough to start a new round, game over.
	}
	system("pause");
}

void checkCard(Player &player, Deck &controller)//check if all 52 cards are used.
{
	if (controller.IsCardOver())
	{
		system("cls");
		cout << "\nAll the 52 Cards have been used, Game Over." << endl << endl;
		cout << "You have $" << player.money() << " at last." << endl << endl;
		controller.GameOver();
	}
}

void showresult(Player &player, Deck &controller)
//A Decition Trees to show result, called after finishing a round.
{
	if (controller.IsUserWin())
	{
		player.win();
		if (controller.IsUserBJ())
		{
			cout << "Congratulations! you got a BlackJack and win." << endl << endl;
			cout << "You have earned $" << 2 * player.bet() << " in this round." << endl << endl;
		}
		else{
			if (controller.IsDealerBust())
			{
				cout << "Congratulations! Dealer Bust." << endl << endl;
				cout << "You have earned $" << 2 * player.bet() << " in this round." << endl << endl;
			}
			else {
				cout << "Congratulations! you win." << endl << endl;
				cout << "You have earned $" << 2 * player.bet() << " in this round." << endl << endl;
			}
		}
	}

	if (controller.IsDealerWin())
	{
		player.lose();
		if (controller.IsDealerBJ())
		{
			cout << "Sorry, dealer got a BlackJack." << endl << endl;
			cout << "You have lost your wager in this round." << endl << endl;
		}
		else {
			if (controller.IsUserBust())
			{
				cout << "Sorry, your card Bust." << endl << endl;
				cout << "You have lost your wager in this round." << endl << endl;
			}
			else {
				cout << "Sorry, you lost." << endl << endl;
				cout << "You have lost your wager in this round." << endl << endl;
			}
		}
	}

	if (controller.IsDraw())
	{
		if (controller.IsUserBJ() && controller.IsDealerBJ())
		{
			cout << "Dealer also got a BlackJack, round over." << endl << endl;
		}
		else{
			cout << "You got the same point with dealer, round over." << endl << endl;
		}
	}

	if (player.money() <= 0)
	{
		controller.GameOver();
		cout << "You have lost all your money, Game Over." << endl << endl;
		return; //avoid two system pause.
	}
	system("pause");
}

void DisplayRule()
{
	system("cls");
	cout << "\nWelcome to Liqi.Chen's BlackJack Game." << endl << endl;
	cout << "Key point:" << endl << endl;
	cout << "* It is a BlackJack game with only one player, where computer act as a dealer." << endl << endl;
	cout << "* There is only one deck of card (52 cards), each card can only be used one time," << endl;
	cout << "  after all the 52 cards are used, Game Over." << endl << endl;
	cout << "* Your property consists of your money and your wager." << endl << endl;
	cout << "* Game will over if you loses all your properties." << endl << endl;
	cout << "* Dealer will show his hidden card in these cases:" << endl;
	cout << "  1. You choose to Stand." << endl;
	cout << "  2. Your card Bust." << endl;
	cout << "  3. You get a BlackJack." << endl;
	cout << "  4. Game Over." << endl << endl;
	cout << "Please enjoy the game, have fun!" << endl << endl;
	cout << "Game start." << endl << endl;
	system("pause");
	system("cls");
}