class Solution {
public:
typedef long long int;
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        unordered_set<int> mp;
        for(int x:nums)mp.insert(x);
        for(int x:  mp){
           
            if(mp.count(x-1)){
               // mp[x]++;
                continue;
            }
            else{
                int cnt=0;
                while(mp.count(x)){
                    cnt++;
                    ans=max(ans,cnt);
                    x++;
                }
            }
        }
        return ans;
    }
};