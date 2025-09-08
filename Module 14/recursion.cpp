#include<bits/stdc++.h>
using namespace std;

int rec(int n)
{
    if(n>5)
        return 0;
    int sum = rec(n+1);
    return sum + n;
}

int main()
{
    cout << rec(1) << endl;
    return 0;
}