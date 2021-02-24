/*****************************************************************************************************************************************

GCD_1st_Large_Number.cpp
Created on: 23-Feb-2021
Author: Malkeet Mehra

Given two numbers ‘a’ and ‘b’ such that (0 <= a <= 10^12 and b <= b < 10^250). Find the GCD of two given numbers.

Examples :

Input: a = 978
       b = 89798763754892653453379597352537489494736
Output: 6

Input: a = 1221
       b = 1234567891011121314151617181920212223242526272829
Output: 3


******************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Smaller Number's GCD Handler
ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

//Converting Large String to smaller Number by moduling each digit with Smaller Number and then using above handler
ll gcd_large(int a, string b)
{
    ll mod = 0;
    for(int i = 0; b[i]; i++)
        mod = (mod * 10 + (b[i] - '0'))%a;

    return gcd(mod, a);
}

//Main Handler
int main()
{
    ll a;
    string b;
    cin >> a;
    cin.ignore();
    getline(cin, b);
    cout << gcd_large(a, b);
    return 0;
}
