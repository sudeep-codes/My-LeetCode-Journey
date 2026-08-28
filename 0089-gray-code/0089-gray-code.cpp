class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int totalEle= 1<<n;
        result.reserve(totalEle);
        for(int i=0;i<totalEle;++i){
            result.push_back(i^(i>>1));
        }
        return result;
    }
    
};