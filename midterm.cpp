#include<iostream>
using namespace std;
bool is_leap_year(int year){
    return (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
}

int main (){
    int month,year;
    //cout<<is_leap_year(2016); // check the function working true or false with the year
    cout<<"Please enter Month 1 - 12"<<endl;
    cin>>month;
    switch (month)
    {
    case 1:
        cout<<"31 days in January"<<endl;
        break;
    case 2:
        {
            cout<<"Please enter the year"<<endl;
            cin>>year;
            if(is_leap_year(year))
                cout<<year<<" was a leap year and contains 29 Days";
            else 
                cout<<year<<" was not a leap year and contains 28 Days"; 
            break;
        }
        
    case 3:
        cout<<"31 days in March"<<endl;
        break;
    case 4:
        cout<<"30 days in April"<<endl;
        break;
    case 5:
        cout<<"31 days in May"<<endl;
        break;
    case 6:
        cout<<"30 days in June"<<endl;
        break;
    case 7:
        cout<<"31 days in July"<<endl;
        break;
    case 8:
        cout<<"31 days in August"<<endl;
        break;
    case 9:
        cout<<"30 days in September"<<endl;
        break;
    case 10:
        cout<<"31 days in October"<<endl;
        break;
    case 11:
        cout<<"30 days in November"<<endl;
        break;
    case 12:
        cout<<"31 days in December"<<endl;
        break;
    default:
        cout<<"Invalid Month"<<endl;
        break;
    }
}