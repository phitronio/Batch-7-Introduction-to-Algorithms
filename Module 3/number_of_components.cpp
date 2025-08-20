#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];

void dfs(int src)
{
    vis[src] = true;
    for(int child : adj_list[src])
        if(!vis[child])
            dfs(child);
}

int main()
{
    int n,e;
    cin >> n >> e;
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false)
        {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}