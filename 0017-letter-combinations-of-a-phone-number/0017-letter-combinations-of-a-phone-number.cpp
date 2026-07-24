class Solution {
private:
    const vector<string> keypad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    void backtrack(string& digits, int index, string& current, vector<string>& result){
        if(index==digits.length()){
            result.push_back(current);
            return;
        }
        string letters=keypad[digits[index]-'0'];
        for(char c:letters){
            current.push_back(c);
            backtrack(digits, index+1, current, result);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) return result;
        string current="";
        backtrack(digits,0,current,result);
        return result;
    }
};