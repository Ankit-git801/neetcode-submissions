class Solution {
public:
void dfs(vector<vector<char>>& grid,vector<vector<int>>&vis,int r,int c){
    if(grid[r][c]=='0' || vis[r][c]!=-1)return;
    vis[r][c]=1;
    int dr[]={0,1,-1,0};
    int dc[]={1,0,0,-1};
    for(int i=0;i<4;i++){
        int nr= r+dr[i];
        int nc= c+dc[i];
        if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size()){
            dfs(grid,vis,nr,nc);
        }
    }
    return;
}

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),-1));
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && vis[i][j]==-1){
                    cnt++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return cnt;
    }
};