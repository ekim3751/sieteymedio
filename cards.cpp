#include "cards.h"
#include <cstdlib>
#include <iostream>

/* 
You might or might not need these two extra libraries 
#include <iomanip>
#include <algorithm>
*/


/* *************************************************
   Card class
   ************************************************* */

/* 
   Default constructor for the Card class.
   It could give repeated cards. This is OK.
   Most variations of Blackjack are played with 
   several decks of cards at the same time.
*/
Card::Card(){
   int r = 1 + rand() % 4;
   switch (r) {
      case 1: suit = OROS; break;
      case 2: suit = COPAS; break; 
      case 3: suit = ESPADAS; break;
      case 4: suit = BASTOS; break; 
      default: break;
   }

   r = 1 + rand() % 10;  
   switch (r) {
      case  1: rank = AS; break; 
      case  2: rank = DOS; break; 
      case  3: rank = TRES; break; 
      case  4: rank = CUATRO; break; 
      case  5: rank = CINCO; break; 
      case  6: rank = SEIS; break; 
      case  7: rank = SIETE; break; 
      case  8: rank = SOTA; break; 
      case  9: rank = CABALLO; break; 
      case 10: rank = REY; break; 
      default: break;
   }
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const { 
   string suitName;
   switch (suit) {
      case OROS: 
         suitName = "oros"; 
	 break;
      case COPAS: 
         suitName = "copas"; 
	 break; 
      case ESPADAS: 
         suitName = "espadas"; 
	 break;
      case BASTOS: 
         suitName = "bastos"; 
	 break; 
      default: break;
   }
   return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const { 
   string rankName;
   switch (rank) {
      case AS:
         rankName = "As"; 
	 break; 
      case DOS: 
         rankName = "Dos"; 
	 break; 
      case TRES: 
         rankName = "Tres"; 
	 break; 
      case CUATRO: 
         rankName = "Cuatro"; 
	 break; 
      case CINCO: 
         rankName = "Cinco"; 
	 break; 
      case SEIS: 
         rankName = "Seis"; 
	 break; 
      case SIETE: 
         rankName = "Siete"; 
	 break; 
      case SOTA: 
         rankName = "Sota"; 
	 break; 
      case CABALLO: 
         rankName = "Caballo"; 
	 break; 
      case REY: 
         rankName = "Rey"; 
	 break; 
      default: break;
   }
   return rankName;
}

string Card::get_english_suit() const { 
   string suitName;
   switch (suit) {
      case OROS: 
         suitName = "golds"; 
	 break;
      case COPAS: 
         suitName = "cups"; 
	 break; 
      case ESPADAS: 
         suitName = "swords"; 
	 break;
      case BASTOS: 
         suitName = "clubs"; 
	 break; 
      default: break;
   }
   return suitName;
}

// Accessor: returns a string with the rank of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const { 
   string rankName;
   switch (rank) {
      case AS:
         rankName = "One"; 
	 break; 
      case DOS: 
         rankName = "Two"; 
	 break; 
      case TRES: 
         rankName = "Three"; 
	 break; 
      case CUATRO: 
         rankName = "Four"; 
	 break; 
      case CINCO: 
         rankName = "Five"; 
	 break; 
      case SEIS: 
         rankName = "Six"; 
	 break; 
      case SIETE: 
         rankName = "Seven"; 
	 break; 
      case SOTA: 
         rankName = "Jack"; 
	 break; 
      case CABALLO: 
         rankName = "Horse"; 
	 break; 
      case REY: 
         rankName = "King"; 
	 break; 
      default: break;
   }
   return rankName;
}


// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
   return static_cast<int>(rank) + 1 ;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
   return rank < card2.rank;
}



/* *************************************************
   Hand class
   ************************************************* */
// Implemente the member functions of the Hand class here.
Hand::Hand(){}
void Hand::drawCard(){
   Card c;
   foot.push_back(c);
}
void Hand::newHand(){
   foot.clear();
}
double Hand::sumHand(){
   double count = 0;
   for(int i = 0; i < foot.size(); ++i){
	double r = foot[i].get_rank();
   	if(r == 10 || r == 11 || r == 12){r = 0.5;}
	count += r;
   }
   return count;
}
void Hand::getHand(ostream& os)const{
   for(int i = 0; i < foot.size(); ++i){
     os << "\t" << foot[i].get_spanish_rank() << " de " << foot[i].get_spanish_suit() << "\t" << "(" << foot[i].get_english_rank() << " of " << foot[i].get_english_suit() << "\n";
   }
}


/* *************************************************
   Player class
   ************************************************* */
// Implemente the member functions of the Player class here.
Player::Player(int m){
   money = m;
}
int Player::getMoney(){
   return money;
}
void Player::newMoney(int bet, bool win){
   if(win == true){
	money += bet;
   } else {
	money -= bet;
   }
}
