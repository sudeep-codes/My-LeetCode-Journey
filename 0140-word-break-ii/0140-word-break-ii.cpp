class Solution {
public:
    unordered_map<int, vector<string>> memo;
    unordered_set<string> wordSet;


    vector<string> wordBreak(string s, vector<string>& wordDict) {
        wordSet=unordered_set<string>(wordDict.begin(), wordDict.end());
        return backtrack(s,0);        
    }
    vector<string> backtrack(const string& s, int start){
        if(memo.count(start)) return memo[start];
        vector<string> res;
        if(start==s.length()){
            res.push_back("");
            return res;
        }

        for(int end=start+1; end<=s.length();++end){
            string prefix=s.substr(start, end-start);
            if(wordSet.count(prefix)){
                vector<string> suffixes=backtrack(s,end);
                for(const string& suffix:suffixes){
                    if(suffix.empty()){
                        res.push_back(prefix);
                    }
                    else{
                        res.push_back(prefix+" "+suffix);
                    }
                }
            }
        }
        memo[start]=res;
        return res;
    }
};