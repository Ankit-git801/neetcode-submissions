class Solution {
public:
    bool solve(string &s,int i,int j,vector<vector<bool>>&dp){
        if(i>=j)return true;
        if(dp[i][j])return dp[i][j];
        if(s[i]==s[j]){
           return dp[i][j]= solve(s,i+1,j-1,dp);
        }
        return false;

    }

    string longestPalindrome(string s) {
        int maxlen=0;
        int sp=0;
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(solve(s,i,j,dp)){
                    if(j-i+1>maxlen){
                    maxlen=j-i+1;
                    sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxlen);
    }
};