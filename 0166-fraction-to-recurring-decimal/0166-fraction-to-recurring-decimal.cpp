class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator ==0) return "0";
        if(denominator==1) return to_string(numerator);
        string res="";
        if((numerator<0)^(denominator<0)){
            res="-";
        }
        long long num=abs(static_cast<long long>(numerator));
        long long den=abs(static_cast<long long>(denominator));
        res+=to_string(num/den);
        long long remainder=num%den;
        if(remainder==0){
            return res;
        }
        res+=".";
        unordered_map<long long, int> seen_remainders;
        while(remainder!=0){
            if(seen_remainders.find(remainder)!=seen_remainders.end()){
                res.insert(seen_remainders[remainder],"(");
                res+=")";
                break;
            }
            seen_remainders[remainder]=res.length();
            remainder *=10;
            res+=to_string(remainder/den);
            remainder%=den;
        }
        return res;
    }
};