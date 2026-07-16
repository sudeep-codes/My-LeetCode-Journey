class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows>s.length()||numRows==1) return s;
        vector<string> rows(numRows);
        int current_row=0;
        bool down=false;
        for(char c:s){
            rows[current_row]+=c;
            if(current_row==0||current_row==numRows-1){
                down=!down;
            }
            current_row+=down?1:-1;
        }
        string result;
        for(const string& row:rows){
            result+=row;
        }
        return result;
    }
};