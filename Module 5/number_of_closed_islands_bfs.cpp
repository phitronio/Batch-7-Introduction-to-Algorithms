class Solution {
public:
    bool vis[105][105];
    vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
    int n,m;
    bool flag;

    bool valid(int i, int j)
    {
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        return true;
    }

    void bfs(int si, int sj, vector<vector<int>>& grid)
    {
        queue<pair<int,int>> q;
        q.push({si,sj});
        vis[si][sj] = true;
        while(!q.empty())
        {
            pair<int,int> par = q.front();
            q.pop();
            int par_i = par.first;
            int par_j = par.second;
            for(int i=0;i<4;i++)
            {
                int ci = par_i + d[i].first;
                int cj = par_j + d[i].second;
                if(!valid(ci,cj))
                    flag = false;
                if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj]==0)
                {
                    q.push({ci,cj});
                    vis[ci][cj] = true;
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int cnt = 0;
        n = grid.size();
        m = grid[0].size();
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!vis[i][j] && grid[i][j]==0)
                {
                    flag = true;
                    bfs(i,j,grid);
                    if(flag)
                        cnt++;
                }
        return cnt; 
    }
};