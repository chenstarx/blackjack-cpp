#include "Deck.h"

Deck::Deck()//constructor, initialize all flag
{
	OverFlag = false;
	RoundFlag = false;
	WinFlag = false;
	DrawFlag = false;
	LoseFlag = false;
	UserBJ = false;
	DealerBJ = false;
	UserBust = false;
	DealerBust = false;
	CardOver = false;
	CardShow = false;
};

void Deck::reset()//reset the controller, initialize all flag.
{
	OverFlag = false;
	RoundFlag = false;
	WinFlag = false;
	DrawFlag = false;
	LoseFlag = false;
	UserBJ = false;
	DealerBJ = false;
	UserBust = false;
	DealerBust = false;
	CardOver = false;
	CardShow = false;
}

bool Deck::IsGameOver()
{
	return OverFlag;
}

bool Deck::IsRoundOver()
{
	return RoundFlag;
}

bool Deck::IsUserWin()
{
	return WinFlag;
}

bool Deck::IsDraw()
{
	return DrawFlag;
}

bool Deck::IsDealerWin()
{
	return LoseFlag;
}

bool Deck::IsUserBJ()
{
	return UserBJ;
}

bool Deck::IsDealerBJ()
{
	return DealerBJ;
}

bool Deck::IsUserBust()
{
	return UserBust;
}

bool Deck::IsDealerBust()
{
	return DealerBust;
}

bool Deck::IsCardOver()
{
	return CardOver;
}

bool Deck::IsCardShow()
{
	return CardShow;
}

void Deck::GameOver()
{
	OverFlag = true;
}

void Deck::RoundOver()
{
	RoundFlag = true;
}

void Deck::UserWin()
{
	WinFlag = true;
}

void Deck::Draw()
{
	DrawFlag = true;
}

void Deck::DealerWin()
{
	LoseFlag = true;
}

void Deck::SetUserBJ()
{
	UserBJ = true;
}

void Deck::SetDealerBJ()
{
	DealerBJ = true;
}

void Deck::SetUserBust()
{
	UserBust = true;
}

void Deck::SetDealerBust()
{
	DealerBust = true;
}

void Deck::SetCardOver()
{
	CardOver = true;
}

void Deck::ShowCard()
{
	CardShow = true;
}