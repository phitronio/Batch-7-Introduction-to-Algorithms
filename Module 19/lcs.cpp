#include<bits/stdc++.h>
using namespace std;
string a,b;
int dp[1005][1005];
int mx=0, endidx;
int lcs(int i, int j)
{
    if(i<0 || j<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(a[i] == b[j])
    {
        int val = lcs(i-1,j-1) + 1;
        if(val > mx)
        {
            mx = val;
            endidx = i;
        }
        dp[i][j] = val;
    }
    else
    {
        return dp[i][j] = 0;
    }
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    cout << lcs(n-1, m-1);
    return 0;
}