#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    bool isPowerof2 = (n > 0 && (n & (n - 1))==0);

    cout << (isPowerof2 ? " The number is posible power of 2." : "The number is not posible power of 2") << endl;
}