#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
double deposit(double account_balance,double amount){
    return account_balance + amount;
}
double withdrawal(double account_balance,double amount){
    return account_balance - amount;
}
void deposit_input(double &account_balance,double amount){
    int count=2;
    do {
    cout << "Input your deposit : ";
    cin >> amount;
    }while(amount<0&&count--);
        if (amount >0) {
            cout << "Deposit amount: " << amount << endl;
            account_balance=deposit(account_balance,amount);
        }
            else {
                cout<<"Deposit must be greater than 0";
            }
}
void withdrawal_input(double &account_balance,double amount){
        int count=2;
                do{
                cout << "Input your withdrawal amount: ";
                cin >> amount;
            }while((amount > account_balance || amount <0) && count-- );
                if (amount <= account_balance && amount >0 ){
                    cout << "Withdrawal: " << amount << endl;
                    account_balance=withdrawal(account_balance,amount);
                }
                else 
                    cout<<"Withdrawal must be smaller or equal and greater 0 than Account balance\n";
}
int main()
{
    string user_name;
    double account_balance;
    double amount;
    int choose_menu;
    int count=2;
    cout << "Input your name: ";
    getline(cin, user_name);
    do{
    cout << "Please enter your balance amount: ";
    cin >> account_balance;
    }while(account_balance<=0 && count--);
    if (account_balance >0) {
        while (true){
             cout<<user_name<<" Welcome to your account"<<endl;
            cout << fixed << setprecision(2);
            cout<<"Balance: $"<<account_balance<<endl;
        cout<<"1.Make a Deposit"<<endl;
        cout<<"2.Make a Withdrawal"<<endl;
        cout<<"3.Exit"<<endl;;
        cout<<"Your option:";
            cin>>choose_menu;
        switch (choose_menu){
            case 1:{
            deposit_input(account_balance,amount);
                break;
        }
        
            case 2:{
                withdrawal_input(account_balance,amount);
                break;
            }
            case 3:{
                cout<<"Final Balance:"<<account_balance;
                return 0;
            }
            default:
                cout<<"Wrong Option";
                return 0;

        }
    }}
    else
        cout<<"Account cannot be equal 0 or negative";

    return 0;
}

