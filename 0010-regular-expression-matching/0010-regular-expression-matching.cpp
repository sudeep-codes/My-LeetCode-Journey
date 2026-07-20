class Solution {
public:
    vector<vector<int>> memo;
    bool dfs(int i,int j, const string& s, const string& p){
        if(j==p.length()){
            return i==s.length();
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        bool current_match=(i<s.length())&&(s[i]==p[j] || p[j]=='.');
        bool result =false;
        if(j+1<p.length() && p[j+1] == '*'){
            result=dfs(i,j+2,s,p)||(current_match && dfs(i+1,j,s,p));
        }
        else{
            result=current_match && dfs(i+1, j+1, s, p);
        }
        return memo[i][j]=result;
    }
    bool isMatch(string s, string p) {
        memo.assign(s.length()+1, vector<int>(p.length()+1,-1));
        return dfs(0,0,s,p);
    }
};