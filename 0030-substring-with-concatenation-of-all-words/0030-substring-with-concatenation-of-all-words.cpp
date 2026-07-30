class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(s.empty()|| words.empty()) return result;
        int wordLen=words[0].length();
        int numWords=words.size();
        int sLen=s.length();
        int totalLen=wordLen*numWords;
        unordered_map<string, int> wordCount;
        for(const string& word:words){
            wordCount[word]++;
        }
        for(int i=0; i<wordLen; ++i){
            int left=i;
            int right=i;
            unordered_map<string, int> currentCount;
            int matchedWords=0;
            while(right+wordLen<=sLen){
                string word = s.substr(right, wordLen);
                right+=wordLen;
                if(wordCount.count(word)){
                    currentCount[word]++;
                    matchedWords++;
                    while(currentCount[word]>wordCount[word]){
                        string leftWord=s.substr(left, wordLen);
                        currentCount[leftWord]--;
                        matchedWords--;
                        left+=wordLen;
                    }
                    if(matchedWords==numWords){
                        result.push_back(left);
                    }
                }
                else{
                        currentCount.clear();
                        matchedWords=0;
                        left=right;
                    }
            }
        }
        return result;
    }
};