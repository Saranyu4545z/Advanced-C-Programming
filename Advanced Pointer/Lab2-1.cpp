#include <iostream>
#include <string>
using namespace std;

int main() {
    char a[6] = {'a','b','c','d','e','f'};
    char b[6] = {'A','B','C','D','E','F'};
    char temp;
    char *ptrA, *ptrB;
    ptrA = &a[0];
    ptrB = &b[0];
     string mess = "AbbeF";

    for (int i = 0; i < mess.length(); i++) {
        temp = mess[i];
        if ((int)temp > 90) {
            cout << b[(int)temp - (int)'a'];
        } else {
            cout << a[(int)temp - (int)'A'];
        }
    }


    cout << endl;
    return 0;
}
