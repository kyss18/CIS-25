#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
double deposit(double account_balance,double amount){
    return account_balance+amount;
}
double withdrawal(double account_balance,double amount){
    return account_balance-amount;
}
void deposit_input(double &account_balance,double amount){
    cout << "Input your deposit : ";
    cin >> amount;
        if (amount >0) {
            cout << "Deposit amount: " << amount << endl;
          
            cout << "New balance: " << deposit(account_balance,amount) << endl;
        }
            else {
                cout<<"Deposit must be greater than 0";
            }
}
void withdrawal_input(double &account_balance,double amount){
    cout << "Input your withdrawal amount: ";
            cin >> amount;
                if (amount <= account_balance && amount >0 ){
                    cout << "Withdrawal: " << amount << endl;
                    cout << "Final balance: " << withdrawal(account_balance,amount) << endl;
                }
                else 
                    cout<<"Withdrawal must be smaller or equal and greater 0 than Account balance";
}
int main()
{
    string user_name;
    double account_balance;
    double amount;
    int choose_menu;
    cout << "Input your name: ";
    getline(cin, user_name);
    cout << "Please enter your balance amount: ";
    cin >> account_balance;
    if (account_balance >0) {
        cout<<user_name<<" Welcome to your account"<<endl;
        cout << fixed << setprecision(2);
        cout<<"Balance: $"<<account_balance<<endl;
        cout<<"1.Make a Deposit"<<endl;
        cout<<"2.Make a Withdrawal"<<endl;
        cout<<"3.Exit"<<endl;
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
                break;
            }
            default:
                cout<<"Wrong Option";
                break;

        }
    }
    else
        cout<<"Account cannot be equal 0 or negative";
    return 0;
}

