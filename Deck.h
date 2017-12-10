#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h> 
#include <time.h>
#include <iomanip>
#include <fstream>

using namespace std;

class Deck //This class works as the game controller.
{
private:
	bool OverFlag;	//flag of gameover.
	bool RoundFlag; //whether a round is over.
	bool WinFlag;	//whether player is win.
	bool DrawFlag;	//whether it is draw.
	bool LoseFlag;	//whether dealer is win.
	bool UserBJ;	//whether player got BlackJack.
	bool DealerBJ;	//whether dealer got BlackJack.
	bool UserBust;	//whether player got Bust.
	bool DealerBust;//whether dealer got Bust.
	bool CardOver;  //whether all the cards are used.
	bool CardShow;		//whether dealer's hidden card can be shown.

public:
	bool IsGameOver();
	bool IsRoundOver();
	bool IsUserWin();
	bool IsDraw();
	bool IsDealerWin();
	bool IsUserBJ();
	bool IsDealerBJ();
	bool IsUserBust();
	bool IsDealerBust();
	bool IsCardOver();
	bool IsCardShow();

	void GameOver();	 //tell the system that gameover.
	void RoundOver();	 //tell the system that a round over.
	void UserWin();		 //tell the system that user win a round.
	void Draw();		 //tell the system that the round is draw.
	void DealerWin(); 	 //tell the system that dealer win a round.
	void SetUserBJ();	 //tell the system that user got BlackJack.
	void SetDealerBJ();	 //tell the system that dealer got BlackJack.
	void SetUserBust();	 //tell the system that user got bust.
	void SetDealerBust();//tell the system that delaer got bust.
	void ShowCard();	 //tell the system that dealer's card can be shown next.
	void SetCardOver();	 //tell the system that all the 52 cards are used.
	void reset();		 //reset the game controller, initialize all the flag.
	Deck();				 //constructor
};