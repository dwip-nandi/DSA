#include <iostream>
using namespace std;

bool isKthBitSet(int n, int k) {
    int mask = 1 << k;
    return (n & mask) != 0;
}

int main() {
    int n, k;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Enter the bit position to check (0-based): ";
    cin >> k;

    if (isKthBitSet(n, k)) {
        cout << "The " << k << "-th bit is set." << endl;
    } else {
        cout << "The " << k << "-th bit is not set." << endl;
    }

    return 0;
}
