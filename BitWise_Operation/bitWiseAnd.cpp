#include <bits/stdc++.h>
using namespace std;
int main()
{
    // a number wven or odd check
    long long n;
    cin >> n;

    long long result = n & 1;
    cout << (result == 1 ? " The number is ODD" : "The number is EVEN");
}