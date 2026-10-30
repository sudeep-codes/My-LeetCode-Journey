class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        for(const auto& req:prerequisites){
            int course=req[0];
            int prereq=req[1];
            adj[prereq].push_back(course);
            inDegree[course]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; ++i){
            if(inDegree[i]==0) q.push(i);
        }
        vector<int> order;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            order.push_back(node);
            for(int neighbor: adj[node]){
                inDegree[neighbor]--;
                if(inDegree[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }
        if(order.size()==numCourses){
            return order;
        }
        return {};
    }
};