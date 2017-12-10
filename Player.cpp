#include "Player.h"

Player::Player() {}
//default constructor, called when set up dealer.

Player::Player(string name, int money,int bet)
{
	Name = name;
	Money = money;
	Bet = bet;
}

int Player::money()//player's money
{
	return Money;
}

int Player::bet()//player's wager
{
	return Bet;
}

void Player::win()//called when player win a round
{
	Money = Money + Bet;
}

void Player::lose()//called when player lose a round
{
	Money = Money - Bet;
}

void Player::reset(Deck &controller)//reset the player or dealer's hand
{
	Hand.reset(controller);
}

void Player::Stand(Player &player, Player &dealer, Deck &controller)
//player Stand
{
	controller.ShowCard();
	//tell the system that dealer's cards can be shown.
	system("cls");
	gameinfo(player, dealer, controller);
	//refresh game information and show dealer's cards.

	while (dealer.Hand.total() < 17 && !(controller.IsCardOver()))
	//dealer Hit until he got 17 or more than 17
	{
		cout << "Dealer Hit." << endl << endl;
		system("pause");
		dealer.Hand.DealerHit(controller);
		system("cls");
		gameinfo(player, dealer, controller);
	}
	if (dealer.Hand.total() == 21)
		controller.SetDealerBJ();
	//dealer's BlackJack
	if(dealer.Hand.total() <= 21)
	//comparing the cards of player and dealer
	{
		if (Hand.total() > dealer.Hand.total())
		{
			controller.UserWin();
			controller.RoundOver();
		}
		if (Hand.total() == dealer.Hand.total())
		{
			controller.Draw();
			controller.RoundOver();
		}
		if (Hand.total() < dealer.Hand.total())
		{
			controller.DealerWin();
			controller.RoundOver();
		}
	}
}

void gameinfo(Player &player, Player &dealer, Deck &controller)
{
	cout << left;
	//set left Justified
	cout << "------------------------------------------------------------" << endl;
	cout << setw(12) << player.Name << "                         Dealer" << endl << endl;
	cout << "Card in Hand:                        Card in Hand:" << endl << endl;
	if (!controller.IsCardShow())
	//one card of dealer is not shown
	{
		player.Hand.getHand(0);
		cout << "            *(*) ";
		dealer.Hand.getHand(1);
		cout << "\n\nTotal: " << setw(2) << player.Hand.total() 
			 << "                            Total: *" << endl;
	}
	else {
	//all cards of dealer is shown
		player.Hand.getHand(0);
		cout << "            ";
		dealer.Hand.getHand(0);
		cout << "\n\nTotal: " << setw(2) << player.Hand.total() 
			<< "                            Total: " << dealer.Hand.total() << endl;
	}
	cout << "------------------------------------------------------------" << endl << endl;
}

void gameplay(Player &player, Player &dealer, Deck &controller)
{
	if (player.Hand.total() == 21)
	//player got BlackJack at first two cards
	{
		cout << "You got a BlackJack!" << endl << endl;
		if (dealer.Hand.total() == 21 && controller.IsCardShow())
		{
			//Dealer also got a BlackJack at first two cards, round over.
			controller.SetUserBJ();
			controller.SetDealerBJ();
			controller.Draw();
			controller.RoundOver();
			return;
		}
		if (dealer.Hand.total() != 21 && controller.IsCardShow())
		{
			//BlackJack
			controller.SetUserBJ();
			controller.UserWin();
			controller.RoundOver();
			return;
		}
		controller.ShowCard();
		system("pause");
	}
	else{
		cout << "Your Money: $" << player.Money - player.Bet << endl << endl;
		cout << "Your Wager: $" << player.Bet << endl << endl;
		cout << "(H/h): Hit." << endl;
		cout << "(S/s): Stand." << endl << endl;
		cout << "Please input a command: ";

		char choice = ' ';
		while (!(cin >> choice) || !(choice == 'H' || choice == 'h'
			|| choice == 'S' || choice == 's'))
			//Check the validity of the input, if invalid, input again.
		{
			cout << "Please input H/h or S/s, try again: ";
			cin.clear();
			cin.ignore();
		}

		if (choice == 'H' || choice == 'h')
		//player Hit
		{
			player.Hand.UserHit(controller);
			if (controller.IsUserBJ())
			//if player got 21 points after Hitting, the system will stand for player.
			{
				system("cls");
				gameinfo(player, dealer, controller);
				cout << "You got a BlackJack!" << endl << endl;
				system("pause");
				player.Stand(player, dealer, controller);
			}
			if (controller.IsUserBust())
				controller.ShowCard();
			//if player bust, the cards of dealer will be shown
			system("cls");
			gameinfo(player, dealer, controller);	
		}

		if (choice == 'S' || choice == 's')//player Stand
			player.Stand(player, dealer, controller);
	}
}

void showinfo(Player &player, Player &dealer, Deck &controller)
{
	char choice = ' ';
	cout << "\nYour Money: $" << player.Money - player.Bet << endl << endl;
	cout << "Your Wager: $" << player.Bet << endl << endl;

	cout << "(Q/q): Quit the game." << endl;
	cout << "(C/c): Change Wager." << endl;
	cout << "(A/a): All in." << endl;
	cout << "(D/d): Deal." << endl << endl;

	cout << "Please input a command: ";

	while (!(cin >> choice) || !(choice == 'C' || choice == 'c' || choice == 'Q' || choice == 'q'
		|| choice == 'A' || choice == 'a' || choice == 'D' || choice == 'd'))
		//Checking the validity of the input, if invalid, input again.
	{
		cout << "Please input Q/q or C/c or A/a or D/d, try again: ";
		cin.clear();
		cin.ignore();
	}

	if (choice == 'C' || choice == 'c')
	//change the wager
	{
		int changewager;
		cout << "\nPlease input the wager you want to change to: ";
		while (!(cin >> changewager) || changewager > player.Money || changewager < 0)
		//Checking the validity of the input, if invalid, input again.
		{
			cout << "Please input a valid number Between 0 and " << player.Money << ", try again: ";
			cin.clear();
			cin.ignore();
		}
		player.Bet = changewager;
		cout << "\nNow your Wager is $" << player.Bet << endl << endl;
		cout << "Deal start." << endl << endl;
		system("pause");
		return;
	}

	if (choice == 'A' || choice == 'a')
	//all in
	{
		player.Bet = player.Money;
		cout << "\nNow your Wager is $" << player.Bet << endl << endl;
		cout << "Deal start."<< endl << endl;
		system("pause");
		return;
	}

	if (choice == 'Q' || choice == 'q')
	//quit the game
	{
		system("cls");
		cout << "\nYou have $" << player.Money << " at last!" << endl << endl;
		cout << "Game Over." << endl << endl;
		controller.GameOver();
		//set the gameover flag true and the routine will get to its end in main function.
		system("pause");
		return;
	}

	//no extral action is taken when D or d is inputted, 
	//because routine will continue in the main function.
}