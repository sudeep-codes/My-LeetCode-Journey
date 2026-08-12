class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows=obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1||obstacleGrid[rows-1][cols-1]==1) return 0;
        vector<long long> dp(cols,0);
        dp[0]=1;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(obstacleGrid[r][c]==1){
                    dp[c]=0;
                }
                else if(c>0){
                    dp[c]+=dp[c-1];
                }
            }
        }
        return dp[cols-1];
    }
};