class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(nums.empty())return 0;
        unordered_set<int>st;
        for(int &x:nums)st.insert(x);
        int ans=1;
        for(int x:st){
            int cnt=1;
            if(!st.count(x+1)){
                while(st.count(x)){
                    ans=max(ans,cnt);
                    cnt++;
                    x--;
                }
            }
        }
        return ans;
    }
};