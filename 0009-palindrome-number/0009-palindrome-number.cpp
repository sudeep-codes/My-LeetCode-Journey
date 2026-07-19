class Solution {
public:
    bool isPalindrome(int x) {
        int y=x;
        if(x<0) return false;
        int r=0;
        while(x!=0){
            int d=x%10;
            if(r>INT_MAX/10 || (r==INT_MAX/10 && d>7)) return 0;
            if(r<INT_MIN/10 || (r==INT_MIN/10 && d<-8 )) return 0;
            r=r*10+d;
            x=x/10;
        }
        return r==y;
    }
};