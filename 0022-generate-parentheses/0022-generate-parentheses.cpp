class Solution {
public:
    void backtrack(vector<string>& result, string& current_str, int open_count, int close_count, int n){
        if(current_str.length()==2*n){
            result.push_back(current_str);
            return;
        }
        if(open_count<n){
            current_str.push_back('(');
            backtrack(result, current_str, open_count+1,close_count,n);
            current_str.pop_back();
        }
        if(close_count<open_count){
            current_str.push_back(')');
            backtrack(result,current_str, open_count, close_count+1, n);
            current_str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current_str="";
        backtrack(result, current_str, 0, 0, n);
        return result;
    }
};