#include <iostream>
using namespace std;

int main() {
    int i = 0;

    while (true) {   // infinite loop
        cout << i << endl;
        i++;

        if (i > 5) {
            break;   // stop the loop
        }
    }

    return 0;
}