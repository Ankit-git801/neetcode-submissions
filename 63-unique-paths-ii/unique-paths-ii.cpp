class Solution {
public:
int solve(int m,int n,int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(i<0 || i>=n || j<0 || j>=m)return 0;
    if(grid[i][j]==1)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(i==n-1 && j==m-1)return 1;
    return dp[i][j]= solve(m,n,i+1,j,grid,dp)+solve(m,n,i,j+1,grid,dp);
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(m,n,0,0,obstacleGrid,dp);
    }
};