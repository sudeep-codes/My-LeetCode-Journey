class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        if(n<=1) return 0;
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        vector<int> cuts(n);
        for(int i=0; i<n; ++i){
            cuts[i]=i;
            for(int j=0; j<=i; ++j){
                if(s[j]==s[i] && (i-j<=2 || isPal[j+1][i-1])){
                    isPal[j][i]=true;
                    if(j==0){
                        cuts[i]=0;
                    }
                    else{
                        cuts[i]=min(cuts[i], cuts[j-1]+1);
                    }
                }
            }
        }
        return cuts[n-1];
    }
};