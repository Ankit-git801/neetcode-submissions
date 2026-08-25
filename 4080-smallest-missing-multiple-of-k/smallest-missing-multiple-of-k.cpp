class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%k==0)mpp[nums[i]]++;
        }
        for(int i=1;i<=nums.size();i++){
            if(mpp.find(k*i)==mpp.end()){
                return k*i;
            }
        }
        return k*(nums.size()+1);
    }
};