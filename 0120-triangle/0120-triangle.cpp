class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int row=triangle.size()-2; row>=0; --row){
            for(int col=0; col<=row;++col){
                int next_left=triangle[row+1][col];
                int next_right=triangle[row+1][col+1];
                triangle[row][col]+=min(next_left,next_right);
            }
        }
        return triangle[0][0];
    }
};