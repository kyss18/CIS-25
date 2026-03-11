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

class Hand {
    protected:
     vector<card> hand;
     int score=0;
     int ace_count=0;
    public:
        int get_score(){
            return score;
        }
        void add_card( card c) {
            hand.push_back(c);
            score+=c.value;
            if(c.name_card == "A")
        ace_count++;

    while(score > 21 && ace_count > 0)
    {
        score -= 10;
        ace_count--;
    }
            //cout<<player_card[0].name_card;
        }
        void show_card(){
            for (auto x:hand){
                cout<<x.name_card<<" "<<x.type_card<<" "<<x.value<<"|";
            }
        }
        bool is_bust(){
            return score>21;
        }
        bool is_black_jack(){
            return (hand[0].value ==10 && hand[1].value==11)||((hand[0].value ==11 && hand[1].value==10));
        }
        void clear_hand(){
            hand.clear();
            score=0;
            ace_count=0;
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
        void set_balance_win(int bet_amount){
             balance+=(bet_amount*2);
        }
        void take_balance (int bet_amount){
             balance-=bet_amount;
        }
        void return_balance(int bet_amount){
             balance +=bet_amount;
        }
         double  get_balance(){
             return balance;
        }
        bool is_less_than_16(){
            return score<16;
        }
        
        
        

};
class Dealer: public Hand{
    public:
       bool check_greater_than_17(){
            cout<<score<<endl;
            return score>=17;
       }
};
class BlackjackGame{
    private:
    int bet_amount;
public:
    void check_win(Player player,Dealer dealer){
        if((player.is_black_jack()&& dealer.is_black_jack())|| (dealer.get_score()== player.get_score())){
            cout<<"Tie";
        }
        else if (dealer.is_black_jack()|| (dealer.get_score()>player.get_score())){
            cout<<"Dealer Win";
        }
        else if (player.is_black_jack()||(dealer.get_score()<player.get_score())){
            cout<<"You Win";
        }
    }
    

};
 void Menu (){
    int balance;
    int choose_menu;
    do{
    cout<<"Input your balance: ";
    cin>>balance;
    }while(balance<=0);
    Player player(balance);
    while (true){
    cout<<"\n===== BLACKJACK =====\n";
    cout<<"Balance: $"<<player.get_balance()<<endl;
    cout<<"1. Play\n";
    cout<<"2. Deposit\n";
    cout<<"3. Check Balance\n";
    cout<<"4. Exit\n";
    cout<<"Your option: ";
    cin>>choose_menu;
    switch(choose_menu){
        case 1:
            if (player.get_balance() >=0)
                {
                int bet_amount;
                do{
                    cout<<"Input your bet Amount: ";
                    cin>>bet_amount;
                }while(bet_amount<0||bet_amount>player.get_balance());
                Deck d;
                //Player player(balance);
                Dealer dealer;
                BlackjackGame b;
                player.clear_hand();
                dealer.clear_hand();
                player.take_balance(bet_amount);
                cout<<"Your balance: "<<player.get_balance()<<endl;
                player.add_card(d.draw());
                dealer.add_card(d.draw());
                player.add_card(d.draw());
                dealer.add_card(d.draw());
                player.show_card();
                cout<<endl;
                if (dealer.is_black_jack() && player.is_black_jack()){
                    cout<<"Tie";
                }
                else if (dealer.is_black_jack()){
                    cout<<"Dealer win\n";
                    cout<<"Dealer card:";
                    dealer.show_card();
                }
                else if (player.is_black_jack()){
                    cout<<"You Win\n";
                    cout<<"Dealer card:";
                    dealer.show_card();
                    player.set_balance_win(bet_amount);
                }
                else {
                    bool playing=true;
                    int selection;
                    do
                    {
                        cout<<"1.Draw more\n";
                        cout<<"2.Skip\n";
                        cout<<"Your selection: ";
                        cin>>selection;
                        switch (selection)
                        {
                        case 1:
                            player.add_card(d.draw());
                            player.show_card();
                            cout<<endl;
                            break;
                        case 2:
                            playing=false;
                            if (player.is_less_than_16()){
                                cout<<"You lose";
                            }
                            break;
                        default:
                            break;
                        }
                    } while (playing && !player.is_bust());
                    if(player.is_bust()){
                        cout<<"You lose";
                        
                    }
                    else {
                        cout<<"Dealer\n";
                        while(!dealer.check_greater_than_17())
                        {
                            dealer.add_card(d.draw());
                            //dealer.show_card();
                        }
                        if (dealer.get_score()== player.get_score()){
                            dealer.show_card();
                            cout<<"Tie";
                            player.return_balance(bet_amount);
                        }
                        else if((dealer.get_score()>player.get_score())&& !dealer.is_bust()){
                            dealer.show_card();
                            cout<<"Dealer Win";
                            
                        }
                        else if ((dealer.get_score()<player.get_score()) && !player.is_bust()){
                            dealer.show_card();
                            cout<<"You Win";
                            player.set_balance_win(bet_amount);
                        }
                        else {
                            dealer.show_card();
                            cout<<"You Win";
                            player.set_balance_win(bet_amount);
                        }
                    }
                }
            }
            else {
                cout<<"Please deposit more money"<<endl;
            }
        break;
        case 2:
        {

        }
        break;
        case 3:
        {
            cout<<"Your balance:"<<balance<<endl;
        }
        break;
        case 4:
        {
            return;
        }
        break;
        default:
            cout<<"Wrong Option";
            break;
        }
    }
 }
int main (){
    srand(time(0));
    Menu();

    // Deck d1;
    // //  cout<<"\tBefore suffle"<<endl;
    // //  d1.show_card();
    // cout<<"\tAfter suffle"<<endl;
    // d1.show_card();
    // Player p1(5000);
    //  cout<<"\tPlayer Card"<<endl;
    //   p1.add_card(d1.draw());
    //   //p1.show_card();
    //  // p1.draw_a_card();
    //   p1.add_card(d1.draw());
      

    //   p1.show_card();
    //    cout<<p1.is_bust();
    //    cout<<"\n Black Jack \n";
    //    cout<<p1.is_black_jack();

}