#include <iostream>
#include<string>
using namespace std;

// Function taking arguments of different data types
void getInfo(string name, int age, double height) {
   cout << name <<" is " << age << " years old and " << height << " meters tall. "<< endl;
}

int main() {
   getInfo("Aman", 26, 1.78);
   getInfo("Naman", 32, 1.65);
  
}
