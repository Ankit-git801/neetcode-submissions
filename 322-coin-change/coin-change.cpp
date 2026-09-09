class Solution {
public:
int n;
vector<int> coins;
vector<vector<int>> dp;
    int fun(int i,int am){
        if(i==n-1){
            if(am%coins[i]==0){
                return am/coins[i];
            }
            return 1e9;
        }
        if(dp[i][am]!=-1)return dp[i][am];
        int dt=fun(i+1,am);
        int tk=1e9;
        if(am>=coins[i]){
            tk=1+fun(i,am-coins[i]);
        }
        return dp[i][am]= min(dt,tk);
    }
    int coinChange(vector<int>& c, int amount) {
        coins=c;
        n=c.size();
        dp.resize(n,vector<int>(amount+1,-1));
        int ans=fun(0,amount);
        if(ans==1e9)return -1;
        return ans;
    }
};