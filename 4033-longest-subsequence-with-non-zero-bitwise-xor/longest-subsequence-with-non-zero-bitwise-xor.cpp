class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans=0;
        int cnt=0;
        for(int x:nums){
            ans^=x;
            if(x==0)cnt++;
        }
        if(ans!=0)return nums.size();
        if(cnt==nums.size())return 0;
        return nums.size()-1;
        
    }
};