class Solution {
    public:
        int dp[305][5005];
    
        int subset_sum(int i, int sum, vector<int>& coins)
        {
            if(i<0)
            {
                if(sum==0) return 1;
                else return 0;
            }
            if(dp[i][sum] != -1)
                return dp[i][sum];
    
            if(coins[i]<=sum)
            {
                int op1 = subset_sum(i,sum-coins[i],coins);
                int op2 = subset_sum(i-1,sum,coins);
                dp[i][sum] = op1 + op2;
                return dp[i][sum];
            }
            else
            {
                dp[i][sum] = subset_sum(i-1,sum,coins);
                return dp[i][sum];
            }
        }
    
        int change(int amount, vector<int>& coins) {
            int n = coins.size();
    
            for(int i=0;i<=n;i++)
                for(int j=0;j<=amount;j++)
                    dp[i][j] = -1;
    
            return subset_sum(n-1,amount,coins);
        }
    };