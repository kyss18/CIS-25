#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string user_name;
    double account_balance;
    double amount;

    cout << "Input your name: ";
    getline(cin, user_name);
    cout << "Input your balance: ";
    cin >> account_balance;
    cout << fixed << setprecision(2);
    cout << "Input your deposit : ";
    cin >> amount;
    cout << "Deposit amount: " << amount << endl;
    account_balance += amount;
    cout << "New balance: " << account_balance << endl;
    cout << "Input your withdrawal amount: ";
    cin >> amount;
    cout << "Withdrawal: " << amount << endl;
    account_balance -= amount;
    cout << "Final balance: " << account_balance << endl;
    return 0;
}
