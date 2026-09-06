class Solution {
public:
bool solve(vector<int>&nums,int i,int cur,int sum,vector<vector<int>>&dp){
    if(cur>sum || i>nums.size()-1)return false;
    if(cur==sum)return true;
    if(dp[i][cur]!=-1)return dp[i][cur];
    return dp[i][cur]=solve(nums,i+1,cur+nums[i],sum,dp)||solve(nums,i+1,cur,sum,dp);
}

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int &x:nums){
            sum+=x;
        }
        vector<vector<int>>dp(nums.size(),vector<int>(sum/2,-1));
        if(sum%2!=0)return false;
        return solve(nums,0,0,sum/2,dp);
    }
};