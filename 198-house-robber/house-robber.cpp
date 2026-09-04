class Solution {
public:
int solve(int i,vector<int>&nums,vector<int>&robed){
    if(i>=nums.size())return 0;
    if(robed[i]!=-1)return robed[i];
    return robed[i]= max(nums[i]+solve(i+2,nums,robed),solve(i+1,nums,robed));
}
    int rob(vector<int>& nums) {
        vector<int>robed(nums.size(),-1);
        return solve(0,nums,robed);
    }
};