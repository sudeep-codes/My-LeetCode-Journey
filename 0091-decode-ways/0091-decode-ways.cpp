class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0]=='0') return 0;
        int prev2=1;
        int prev1=1;
        for(size_t i=1;i<s.length(); ++i){
            int current=0;
            if (s[i]!='0'){
                current+=prev1;
            }
            int two_digit=stoi(s.substr(i-1,2));
            if (two_digit>=10 && two_digit<=26){
                current+=prev2;
            }
            if(current==0) return 0;
            prev2=prev1;
            prev1=current;
        }
        return prev1;
    }
};