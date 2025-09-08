#include<bits/stdc++.h>
using namespace std;      // O(N)

long long int dp[1005];
int fibo(long long int n)
{
    if(n<2)
        return n;
    if(dp[n] != -1)
        return dp[n];
    dp[n] = fibo(n-1) + fibo(n-2); 
    return dp[n];
}

int main()
{
    memset(dp,-1,sizeof(dp));
    long long int n;
    cin >> n;
    cout << fibo(n);
    return 0;
}