#include <iostream>
using namespace std;
int f(int n) {
    if (n <= 0) return 0;
    if (n % 2 == 0)
        return n + f(n - 1);
    else
        return f(n - 1);
}


int main() {
   cout<< f(6);
    return 0;
}
