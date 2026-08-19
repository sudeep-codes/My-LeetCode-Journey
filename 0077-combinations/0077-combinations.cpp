class Solution {
public:
    void backtrack(int start, int n, int k, vector<int>& current_combination, vector<vector<int>>& result) {
        if(current_combination.size()==k){
            result.push_back(current_combination);
            return;
        }
        int need=k-current_combination.size();
        int remain=n-start+1;
        if(remain<need){
            return;
        }
        for(int i=start; i<=n; ++i){
            current_combination.push_back(i);
            backtrack(i+1, n, k, current_combination, result);
            current_combination.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current_combination;
        backtrack(1, n, k, current_combination, result);
        return result;
    }
};