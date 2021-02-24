/*****************************************************************************************************************************************

LCM_Array.cpp
Created on: 23-Feb-2021
Author: Malkeet Mehra

Given an array of n numbers, find LCM of it.

Input : {1, 2, 8, 3}
Output : 24

Input : {2, 7, 3, 9, 4}
Output : 252

Using following equation -
LCM(a,b,c,d,...) = LCM(a,LCM(b,c,d...))

******************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;


int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm_array(int a[], int n)
{
    int ans = a[0];
    for(int i = 1; i < n; i++)
        ans = (ans * a[i])/gcd(ans, a[i]);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << lcm_array(a, n);
    return 0;
}
