class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adj=new ArrayList<>();
        for(int i=0; i<numCourses; i++){
            adj.add(new ArrayList<>());
        }

        int[] inDegree=new int[numCourses];
        for(int[] req: prerequisites){
            int dest=req[0];
            int src=req[1];
            adj.get(src).add(dest);
            inDegree[dest]++;
        }
        Queue<Integer> queue=new LinkedList<>();
        for(int i=0; i<numCourses; i++){
            if(inDegree[i]==0){
                queue.offer(i);
            }
        }

        int visitedCount=0;

        while(!queue.isEmpty()){
            int node=queue.poll();
            visitedCount++;
            for(int neighbor:adj.get(node)){
                inDegree[neighbor]--;
                if(inDegree[neighbor]==0){
                    queue.offer(neighbor);
                }
            }
        }
        return visitedCount==numCourses;
        
    }
}