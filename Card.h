#include "Deck.h"

class Card
{
private:
	vector <int> CardInHand;
	//use vector to store cards.
	bool AllUsed;
	//if all the 52 cards are used.
public:
	void UserHit(Deck &controller);
	//Player's Hit
	void DealerHit(Deck &controller);
	//Dealer's Hit
	/*Player and Dealer's Hit are seperated because that the system need to
	set flag for whether Player or Dealer got BlackJack or Bust seperately.*/
	void getHand(int a);
	//show all the cards in hand.
	void reset(Deck &controller);
	//reset the cards. called when start a new round.
	int total();
	//return the total value of cards in hand.
	int generate();
	/*get a card from the 52 cards, each card can only be used one time.
	which means there is only one deck of cards (52 cards) in this game.
	game will over when all the cards are used.*/
	Card();
	//constructor.
};