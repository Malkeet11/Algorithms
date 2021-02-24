/*****************************************************************************************************************************************

GCD.cpp
Created on: 23-Feb-2021
Author: Malkeet Mehra

GCD (Greatest Common Divisor) or HCF (Highest Common Factor) of two numbers is the largest number that divides both of them.
For example GCD of 20 and 28 is 4 and GCD of 98 and 56 is 14.


******************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int gcd_stl(int a, int b)
{
    return __gcd(a, b);
}

int gcd_1(int a, int b)
{
    if(b == 0)
        return a;
    return gcd_1(b, a % b);
}

int gcd_2(int a, int b)
{
    if(a == b)
        return a;
    if(a == 0 || b == 0)
        return 1;
    if(a < b)
        return gcd_2(a, b-a);
    else
        return gcd_2(a-b, b);
}

int gcd_3(int a, int b)
{
    if(a == 0 || b == 0 || a == 1 || b == 1)
        return 1;
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
        int mi = min(m1[i], m2[i]);
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
    cout << gcd_1(a, b) <<"\n";
    cout << gcd_stl(a, b) <<"\n";
    cout << gcd_2(a, b) <<"\n";
    cout << gcd_3(a, b) <<"\n";
    finish = clock();

    time = double(finish - start)/double(CLOCKS_PER_SEC);
    cout << time <<"\n";
    return 0;
}
