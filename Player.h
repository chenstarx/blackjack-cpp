#include "Card.h"

class Player
{
	friend void gameplay(Player &player, Player &dealer, Deck &controller);
	friend void gameinfo(Player &player, Player &dealer, Deck &controller);
	friend void showinfo(Player &player, Player &dealer, Deck &controller);

private:
	string Name;
	int Money;
	int Bet;
	Card Hand;	//player or dealer's hand.

public:
	Player(string name, int money, int bet);
	Player();
	void win();	//player win a round
	void lose();//player lose a round
	int money();//return player's money
	int bet();	//return player's wager
	void reset(Deck &controller);//reset player or dealer's hand
	void Stand(Player &player, Player &dealer, Deck &controller);//player's Stand
};