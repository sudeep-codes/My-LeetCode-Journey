class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length()<10) return {};
        unordered_set<string_view> seen;
        unordered_set<string> repeats;
        for(size_t i=0; i<=s.length()-10;++i){
            string_view substring=string_view(s).substr(i,10);
            if(seen.count(substring)) repeats.insert(string(substring));
            else seen.insert(substring);
        }
        return vector<string>(repeats.begin(), repeats.end());
    }
};