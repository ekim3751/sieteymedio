#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)


// Non member functions implementations (if any)


// Stub for main
int main(){
   int bet;
   int gamen = 0;
   int playerM = 100;
   int dealerM = 900;
   Player p(playerM);
   Player d(dealerM);
   Hand ph;
   Hand dh;
   bool pwin = 0;
   bool dwin = 0;
   ofstream os("gamelog.txt", ios::app);
   while(p.getMoney() != 0 || d.getMoney() != 0){
	string option;
	++gamen;
	cout << "Enter the desired bet: ";
	do{
            cin >> bet;
	}
	while(bet > p.getMoney || bet < 1)
	ph.drawCard();
	dh.drawCard();
	do{
	    cout << "Draw a card? (y or n)"
	    cin >> option;
	    if(option == 'y'){ph.drawCard()}
	}
	while(ph.sumHand() < 7.5 && option != 'n')
	while(dh.sumHand() < 5.5){dh.drawCard();}
	if(ph.sumHand() > 7.5 && dh.sumHand() > 7.5){
	    pwin = 0;
	    dwin = 1;
	    p.newMoney(bet,pwin);
	    d.newMoney(bet,dwin);
	} else if(dh.sumHand() < 7.5 && (ph.sumHand() > 7.5 || dh.sumHand() > ph.sumHand())){
	    pwin = 0;
	    dwin = 1;
	    p.newMoney(bet,pwin);
	    d.newMoney(bet,dwin);
	} else if(ph.sumHand() < 7.5 && (dh.sumHand() > 7.5 || dh.sumHand() < ph.sumHand())){
	    pwin = 1;
	    dwin = 0;
	    p.newMoney(bet,pwin);
	    d.newMoney(bet,dwin);
	} else if(ph.sumHand() == dh.sumHand()){
	    pwin = 0;
	    dwin = 0;
	}
	os << "-----------------------------------------------\n\nGame number: " << gamen << "\tMoney left: $" << p.getMoney << "\nBet: " << bet << "\n\nYour cards:\n";
	ph.getHand(os)
	os << "Your total: " << ph.sumHand() << "\n\n";
	dh.getHand(os)
	os << "Dealer total: " << dh.sumHand() << "\n\n";
   }
   return 0;
}
