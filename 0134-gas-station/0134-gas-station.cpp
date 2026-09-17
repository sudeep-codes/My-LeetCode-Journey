class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0, final_cost=0;
        for(int i=0;i<gas.size(); i++){
            total+=gas[i];
            final_cost+=cost[i];
        }
        if(total<final_cost) return -1;
        int total_tank=0, start_index=0;
        for(int i=0; i<gas.size(); i++){
            total_tank+=gas[i]-cost[i];
            if(total_tank<0){
                start_index=i+1;
                total_tank=0;
            }
        }
        return start_index;

    }
};