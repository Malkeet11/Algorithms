
/*****************************************************************************************************************************************

LCM.cpp
Created on: 23-Feb-2021
Author: Malkeet Mehra

LCM (Least Common Multiple) of two numbers is the smallest number which can be divided by both numbers.
For example, LCM of 15 and 20 is 60, and LCM of 5 and 7 is 35.

Method 1 : Find all prime factors of both numbers, then find union of all factors present in both numbers.
Finally, return the product of elements in union.

Method 2 : Find GCD(a,b) and LCM(a,b) = (a*b)/GCD(a,b)

******************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int lcm(int a)
{
    int l = sqrt(a);
    int m = l;
    int m1[l] = {0};
    while(a % 2 == 0)
    {
        m1[2]++;
        a /= 2;
    }
    for(int i = 3; i <= sqrt(a); i = i+2)
    {
        while(a % i == 0)
        {
            m1[i]++;
            a /= i;
        }
    }
    if(a > 2)
        m1[a]++;
    for(auto i : m1)
        cout << i << " ";
}

int main()
{
    int a;
    cin >> a;
    cout << lcm(a);
    return 0;
}
