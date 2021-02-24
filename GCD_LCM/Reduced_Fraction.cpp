/*****************************************************************************************************************************************

Reduced_Fraction.cpp
Created on: 23-Feb-2021
Author: Malkeet Mehra

Given the Numerator and Denominator of N fractions. The task is to find the product of N fraction and output the answer in reduced form.

Examples:

Input : N = 3
        num[] = { 1, 2, 5 }
        den[] = { 2, 1, 6 }
Output : 5/6
Product of 1/2 * 2/1 * 5/6 is 10/12.
Reduced form of 10/12 is 5/6.

Input : N = 4
        num[] = { 1, 2, 5, 9 }
        den[] = { 2, 1, 6, 27 }
Output : 5/18

******************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct fraction
{
    long long int nu;
    long long int de;
};

long long int gcd(long long int a,long long int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

/***** This might overflow for larger numbers *****/
struct fraction reduced(int a[], int b[], int n)
{
    long long int num = 1, den = 1;
    for(int i = 0; i < n; i++)
    {
        num *= a[i];
        den *= b[i];
    }
    if(den == 0)
    {
        cout << "Undefined Number\n";
        return {num,0};
    }
    if(num == 0)
        return {0, den};
    long long int gc = gcd(num, den);
    return {num/gc, den/gc};
}


/******* To handle Larger Numbers ********/

//Prime Factors of Array Elements
vector<int> prime_factors(int arr[], int n, int ma)
{
    vector<int> m1;
    for(int i = 0; i <= ma; i++)
        m1.push_back(0);
    for(int j = 0; j < n; j++)
    {
        while(arr[j] % 2 == 0)
        {
            m1[2]++;
            arr[j] /= 2;
        }
        for(int i = 3; i <= sqrt(arr[j]); i = i+2)
        {
            while(arr[j] % i == 0)
            {
                m1[i]++;
                arr[j] /= i;
            }
        }
        if(arr[j] > 2)
            m1[arr[j]]++;
    }
    return m1;
}

//Handler
struct fraction reduced_2(int a[], int b[], int n)
{
    int ma1 = *max_element(a, a+n);
    int ma2 = *max_element(b, b+n);
    int ma = max(ma1, ma2);
    vector<int> num = prime_factors(a, n, ma);
    vector<int> den = prime_factors(b, n, ma);
    for(int i = 1; i <= ma; i++)
    {
        int mi = min(num[i], den[i]);
        num[i] -= mi;
        den[i] -= mi;
    }
    int nu = 1, de = 1;
    for(int i = 1; i <= ma; i++)
    {
        nu *= pow(i, num[i]);
        de *= pow(i, den[i]);
    }
    return {nu, de};
}

// Main Handler
int main()
{
    int n;
    cin >> n;
    int num[n];
    int den[n];
    for(int i = 0; i < n; i++)
        cin >> num[i];
    for(int i = 0; i < n; i++)
        cin >> den[i];
    struct fraction f = reduced(num, den, n);
    struct fraction f = reduced_2(num, den, n);
    cout << f.nu << "/" << f.de;
    return 0;
}
