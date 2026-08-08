class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        int p=s.length()-1;
        while(p>=0 && s[p]==' '){
            p--;
        }
        while(p>=0 && s[p]!=' '){
            p--;
            count++;
        }
        
        return count;
    }
};