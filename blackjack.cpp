#include<iostream>
#include<vector>
#include <algorithm>
#include <random>
//#include <cstdlib>
#include <ctime>

using namespace std;
typedef struct card{
    string name_card;
    string type_card;
    int value;
}card;
// class BlackjackGame {
// public:
//     Player player;
//     Dealer dealer;
//     void check_win(){
//         if((player.is_black_jack()&& dealer.is_black_jack())|| (dealer.get_score()== player.get_score())){
//             cout<<"Tie";
//         }
//         else if (dealer.is_black_jack()|| (dealer.get_score()>player.get_score())){
//             cout<<"Dealer Win";
//         }
//         else if (player.is_black_jack()||(dealer.get_score()<player.get_score())){
//             cout<<"You Win";
//         }
//     }

// };
class Hand {
    protected:
     vector<card> hand;
     int score=0;
    public:
        int get_score(){
            return score;
        }
        void add_card( card c) {
            hand.push_back(c);
            if(c.name_card == "A" && score +c.value >21){
                score+=c.value-10;
            }
            else{
            score+=c.value;
            }
            //cout<<player_card[0].name_card;
        }
        void show_card(){
            cout<<"Your cards:"<<endl;
            for (auto x:hand){
                cout<<x.name_card<<" "<<x.type_card<<" "<<x.value<<endl;
            }
        }
        bool is_bust(){
            cout<<score<<endl;
            return score>21;
        }
        bool is_black_jack(){
            return (hand[0].value ==10 && hand[1].value==11)||((hand[0].value ==11 && hand[1].value==10));
        }
};
class Deck {
    protected:
    vector<card> deck;

    public:
        Deck(){
        deck.push_back({"A","Hearts",11});
        deck.push_back({"2","Hearts",2});
        deck.push_back({"3","Hearts",3});
        deck.push_back({"4","Hearts",4});
        deck.push_back({"5","Hearts",5});
        deck.push_back({"6","Hearts",6});
        deck.push_back({"7","Hearts",7});
        deck.push_back({"8","Hearts",8});
        deck.push_back({"9","Hearts",9});
        deck.push_back({"10","Hearts",10});
        deck.push_back({"J","Hearts",10});
        deck.push_back({"Q","Hearts",10});
        deck.push_back({"K","Hearts",10});

        deck.push_back({"A","Hearts",11});
        deck.push_back({"2","Hearts",2});
        deck.push_back({"3","Hearts",3});
        deck.push_back({"4","Hearts",4});
        deck.push_back({"5","Hearts",5});
        deck.push_back({"6","Hearts",6});
        deck.push_back({"7","Hearts",7});
        deck.push_back({"8","Hearts",8});
        deck.push_back({"9","Hearts",9});
        deck.push_back({"10","Hearts",10});
        deck.push_back({"J","Hearts",10});
        deck.push_back({"Q","Hearts",10});
        deck.push_back({"K","Hearts",10});

        deck.push_back({"A","Diamonds",11});
        deck.push_back({"2","Diamonds",2});
        deck.push_back({"3","Diamonds",3});
        deck.push_back({"4","Diamonds",4});
        deck.push_back({"5","Diamonds",5});
        deck.push_back({"6","Diamonds",6});
        deck.push_back({"7","Diamonds",7});
        deck.push_back({"8","Diamonds",8});
        deck.push_back({"9","Diamonds",9});
        deck.push_back({"10","Diamonds",10});
        deck.push_back({"J","Diamonds",10});
        deck.push_back({"Q","Diamonds",10});
        deck.push_back({"K","Diamonds",10});

        deck.push_back({"A","Clubs",11});
        deck.push_back({"2","Clubs",2});
        deck.push_back({"3","Clubs",3});
        deck.push_back({"4","Clubs",4});
        deck.push_back({"5","Clubs",5});
        deck.push_back({"6","Clubs",6});
        deck.push_back({"7","Clubs",7});
        deck.push_back({"8","Clubs",8});
        deck.push_back({"9","Clubs",9});
        deck.push_back({"10","Clubs",10});
        deck.push_back({"J","Clubs",10});
        deck.push_back({"Q","Clubs",10});
        deck.push_back({"K","Clubs",10});

        }
        void show_card(){
            for (int i=0;i<deck.size();i++){
                cout<<deck[i].name_card<<" "<<deck[i].type_card<<" "<<deck[i].value<<endl;
            }
            
        }
        
        card draw(){
            int r = rand() % deck.size();
            card c=deck[r];
             deck.erase(deck.begin()+r);
            return c;
        }
        
};
class Player: public Hand {
    private:
        double balance;
    public:
        Player(double balance){
            this->balance=balance;
            
        }
        
        

};
class Dealer: public Hand{
    public:
       bool check_greater_than_17(){
            return score>=17;
       }
};
int main (){
    srand(time(0));
    Deck d1;
    //  cout<<"\tBefore suffle"<<endl;
    //  d1.show_card();
    cout<<"\tAfter suffle"<<endl;
    d1.show_card();
    Player p1(5000);
     cout<<"\tPlayer Card"<<endl;
      p1.add_card(d1.draw());
      //p1.show_card();
     // p1.draw_a_card();
      p1.add_card(d1.draw());
      

      p1.show_card();
       cout<<p1.is_bust();
       cout<<"\n Black Jack \n";
       cout<<p1.is_black_jack();
}