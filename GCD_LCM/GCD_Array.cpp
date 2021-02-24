/*****************************************************************************************************************************************

GCD_Array.cpp
Created on: 23-Feb-2021
Author: Malkeet Mehra

Given an array of numbers, find GCD of the array elements. In a previous post we find GCD of two number.

Examples:

Input  : arr[] = {1, 2, 3}
Output : 1

Input  : arr[] = {2, 4, 6, 8}
Output : 2

Using following equation -
GCD(a,b,c,d,...) = GCD(a,GCD(b,c,d...))

******************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;


int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int gcd_array(int a[], int n)
{
    // Number of elements less than 2, return -1
    if(n < 2)
        return -1;

    int ans = a[0];
    for(int i = 1; i < n; i++)
    {
        ans = gcd(ans, a[i]);
        // Since GCD(1,n) = 1;
        if(ans == 1)
            return 1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << gcd_array(a, n);
    return 0;
}
