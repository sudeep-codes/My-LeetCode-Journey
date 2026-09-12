class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m=0;
        for(size_t i=1; i<prices.size(); i++){
            if(prices[i]>prices[i-1]) m+=prices[i]-prices[i-1];
        }
        return m;
    }
};