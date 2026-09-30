class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int n=height.size();
        int i=0,j=n-1;
        while(i<j){
            int water=0;
            if(height[i]<height[j]){
                water=(j-i)*height[i];
                ans=max(ans,water);
                i++;
            }
            else if(height[i]>height[j]){
                water=(j-i)*height[j];
                ans=max(ans,water);
                j--;
            }
            else{
                water=(j-i)*height[i];
                ans=max(water,ans);
                i++;
            }
        }
        return ans;
    }
};