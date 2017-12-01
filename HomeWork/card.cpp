
#include <string>

class Card {
  public:
    static const int totalFaces = 13;
    static const int totalSuits = 4;

    Card(int cardFace, int cardSuit);
    std::string toString() const;

    int getFace() const;
    int getSuit() const;
    
  private:
    int face;
    int suit;
    static const char* faceNames[totalFaces];
    static const char* suitNames[totalSuits];
};

#include <vector>

class DeckOfCards {
  public:
    DeckOfCards();
    Card dealCard();
    bool moreCards() const;
  private:
    std::vector<Card> deck;
    int currentCard;
};

#include <string>
const char* Card::faceNames[totalFaces] =  {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const char* Card::suitNames[totalSuits] = {"Hearts", "Diamonds", "Clubs", "Spades"};
Card::Card(int cardFace, int cardSuit): face(cardFace), suit(cardSuit) { }
std::string Card::toString() const { 
  std::string ret = std::string(faceNames[face]) + " of " + std::string(suitNames[totalSuits]);
  return ret;
}
int Card::getFace()const { return face;}
int Card::getSuit() const { return suit;}

DeckOfCards::DeckOfCards() {
  currentCard = 0;
  for (int i = 0; i < Card::totalFaces; ++i) {
     for (int j = 0; j < Card::totalSuits; ++j){
           deck.push_back(Card(i, j));
         }
   }
}

bool DeckOfCards::moreCards() const { return currentCard < deck.size();}
Card DeckOfCards::dealCard() {
  return deck[currentCard++];
}

#include <iostream>
#include <iomanip>

void RunAllTests() {
  int count;
  std::cin >> count;

  DeckOfCards myDeckOfCards;
  for (int i = 0; myDeckOfCards.moreCards() && i < count; ++i) {
    std::cout << std::left << std::setw(19)
      << myDeckOfCards.dealCard().toString();
    if (i % 4 == 3)
      std::cout << std::endl;
  }
}

int main() {
  RunAllTests();
  return 0;
}

