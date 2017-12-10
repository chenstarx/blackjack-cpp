#include "Card.h"

int AllCard[53]
{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,
28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52};
//a pair of card, to realize that one card can only be used one time. 
//0 is set to make AllCard[1] = 1 rather than 2.

int Card::generate()
//generate a number which between 1-52 and it is not concluded in Hand of player and dealer before.
{
	int num;
	int tempnum;
	int count = 0;
	bool flag = true;
	while (flag)
	{
		tempnum = (rand() % 51) + 1;
		//generate a random number between 1 and 52
		if (AllCard[tempnum] != NULL)
		{
			num = AllCard[tempnum];
			AllCard[tempnum] = NULL;
			//after getting a card, delete it from the AllCard[]
			flag = false;
		}
		count ++;
		if (count >= 52)
		{
			flag = false;
			AllUsed = true;
			num = 0;
		}
		//all the card are used
	}
	return num;
}

void Card::getHand(int a)
{
	//show all the cards in hand
	//int a is the position where this function start showwing the card.
	//getHand(0) can show all the card in hand, getHand(1) dosen't show the first card in hand.
	string result;
	string CardBoard[53] =
	{ " ( ) ","A(S) ","2(S) " ,"3(S) ","4(S) ","5(S) ","6(S) ","7(S) ","8(S) ","9(S) ","10(S) ","J(S) ","Q(S) ","K(S) ",
		"A(C) ","2(C) " ,"3(C) ","4(C) ","5(C) ","6(C) ","7(C) ","8(C) ","9(C) ","10(C) ","J(C) ","Q(C) ","K(C) ",
		"A(H) ","2(H) " ,"3(H) ","4(H) ","5(H) ","6(H) ","7(H) ","8(H) ","9(H) ","10(H) ","J(H) ","Q(H) ","K(H) ",
		"A(D) ","2(D) " ,"3(D) ","4(D) ","5(D) ","6(D) ","7(D) ","8(D) ","9(D) ","10(D) ","J(D) ","Q(D) ","K(D) " };
	for (int i = a; i < CardInHand.size(); i++)
		result = result + CardBoard[CardInHand[i]];
	cout << left;
	cout << setw(25);
	cout << result;
}

Card::Card()
{
	CardInHand.push_back(generate());
	CardInHand.push_back(generate());
	AllUsed = false;
	//52 Cards, every card is identified uniquely by a number between 1 and 52.
}

void Card::reset(Deck &controller)
{
	CardInHand.clear();
	CardInHand.push_back(generate());
	CardInHand.push_back(generate());
	if (AllUsed)
		controller.SetCardOver();
	//used when it is starting a new round.
}

void Card::UserHit(Deck &controller)
{
	//User's Hit
	CardInHand.push_back(generate());
	if (AllUsed)
		controller.SetCardOver();
	if (total() == 21)
		controller.SetUserBJ();
	if (total() > 21)
	{
		controller.SetUserBust();
		controller.DealerWin();
		controller.RoundOver();
	}
}

void Card::DealerHit(Deck &controller)
{
	//Dealer's Hit
	CardInHand.push_back(generate());
	if (AllUsed)
		controller.SetCardOver();
	if (total() == 21)
		controller.SetDealerBJ();
	if (total() > 21)
	{
		controller.SetDealerBust();
		controller.UserWin();
		controller.RoundOver();
	}
}

int Card::total()
//count the total number of cards
{
	int Total = 0;
	int AceNum = 0;
	//count the number of Ace
	for (int i = 0; i < CardInHand.size(); i++)
	//get all the card
	{
		if (CardInHand[i] % 13 == 1)
		{
			Total = Total + 11;
			AceNum ++;
		}
		//Ace count 11
		if (CardInHand[i] % 13 == 11 || CardInHand[i] % 13 == 12 
			|| CardInHand[i] % 13 == 10 || (CardInHand[i] % 13 == 0 && CardInHand[i] != 0))
			Total = Total + 10;
		//J, K, Q, 10
		if (CardInHand[i] % 13 > 1 && CardInHand[i] % 13 < 10)
			Total = Total + CardInHand[i] % 13;
		//Card 1-9
		if (AceNum > 0 && Total > 21)
		{
			Total = Total - 10;
			AceNum --;
		}
		//Ace count 1 when total > 21
	}
	return Total;
}