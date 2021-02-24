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

int lcm_2(int a, int b)
{
    return (a*b)/__gcd(a, b);
}

int lcm_1(int a, int b)
{
    if(a == 0 || b == 0)
        return 0;
    if(a == 1)
        return b;
    if(b == 1)
        return a;
    int l = max(a, b);
    int m1[l+1] = {0};
    int m2[l+1] = {0};
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

    while(b % 2 == 0)
    {
        m2[2]++;
        b /= 2;
    }
    for(int i = 3; i <= sqrt(b); i = i+2)
    {
        while(b % i == 0)
        {
            m2[i]++;
            b /= i;
        }
    }
    if(b > 2)
        m2[b]++;

    int ans = 1;
    for(int i = 1; i <= l; i++)
    {
        int mi = max(m1[i], m2[i]);
        ans *= pow(i, mi);
    }
    return ans;
}

int main()
{
    int a, b;
    cin >> a >> b;
    clock_t start, finish;
    double time;

    start = clock();
    cout << lcm_2(a, b) <<"\n";
    cout << lcm_1(a, b) <<"\n";
    finish = clock();

    time = double(finish - start)/double(CLOCKS_PER_SEC);
    cout << time <<"\n";
    return 0;
}
