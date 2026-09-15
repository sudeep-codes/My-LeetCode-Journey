class Solution {
public:

    bool isPalin(const string& s, int left, int right){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void backtrack(const string& s, int start, vector<string>& currentPath, vector<vector<string>>& result){
        if(start==s.length()){
            result.push_back(currentPath);
            return;
        }
        for(int end=start; end<s.length(); ++end){
            if(isPalin(s,start,end)){
                currentPath.push_back(s.substr(start, end-start+1));
                backtrack(s,end+1,currentPath, result);
                currentPath.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentPath;
        backtrack(s,0,currentPath, result);
        return result;
    }
};