#include <iostream>
using namespace std;

int main() {
    char input[5];

    cout << "Enter text: ";
    cin >> input;

    char *p = input;

    while (*p != '\0') {
        if (*p >= 'a' && *p <= 'z') {
            *p = *p - 'a' + 'A';
        }
        else if (*p >= 'A' && *p <= 'Z') {
            *p = *p - 'A' + 'a';
        }
        p++;
    }

    cout << "Output = " << input << endl;

    return 0;
}
