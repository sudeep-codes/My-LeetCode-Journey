class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string_view> wordSet;
        size_t max_len=0;

        for (const auto& word: wordDict){
            wordSet.insert(word);
            max_len=max(max_len, word.length());
        }
        int n=s.length();
        vector<bool> dp(n+1, false);
        dp[0]=true;
        string_view s_view(s);
        for(int i=1; i<=n; ++i){
            int min_j=max(0, i-static_cast<int>(max_len));
            for(int j=i-1; j>=min_j;--j){
                if(dp[j]){
                    string_view sub=s_view.substr(j,i-j);
                    if(wordSet.count(sub)){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};