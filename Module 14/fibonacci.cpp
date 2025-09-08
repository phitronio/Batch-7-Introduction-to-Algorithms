#include<bits/stdc++.h>
using namespace std;    // O(2^N)

int fibo(int n)
{
    if(n<2)
        return n;
    return fibo(n-1) + fibo(n-2); 
}

int main()
{
    int n;
    cin >> n;
    cout << fibo(n);
    return 0;
}