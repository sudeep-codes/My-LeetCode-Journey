class Solution {
public:

    void backtrack(const string& s, int start_idx, vector<string>& current_path, vector<string>& res){
        if(current_path.size()==4){
            if(start_idx==s.length()){
                res.push_back(current_path[0]+"."+current_path[1]+"."+current_path[2]+"."+current_path[3]);
            }
            return;
        }
        for(int length =1; length<=3; ++length){
            if(start_idx+length>s.length()){
                break;
            }
            string block_str=s.substr(start_idx, length);
            if(length>1 && block_str[0]=='0') continue;
            int block_val=stoi(block_str);
            if(block_val>255){
                continue;
            }
            current_path.push_back(block_str);
            backtrack(s,start_idx+length,current_path, res);
            current_path.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.length()<4||s.length()>12) return res;
        vector<string> current_path;
        backtrack(s,0,current_path, res);
        return res;
    }
};