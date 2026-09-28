class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = nums[0];
        int mn = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];
            int a = x;
            int b = x * mx;
            int c = x * mn;
            mx = max({a, b, c});
            mn = min({a, b, c});
            ans = max(ans, mx);
        }

        return ans;
    }
};