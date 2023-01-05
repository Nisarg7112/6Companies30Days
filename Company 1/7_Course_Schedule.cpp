class Solution {
public:
     bool dfs(int v,unordered_map<int,list<int>>&adj,vector<bool>& vis,vector<bool>& dfsvis){
        vis[v]=true;
        dfsvis[v]=true;
        
        for(auto i:adj[v]){
            if(!vis[i]){
                if(dfs(i,adj,vis,dfsvis)){
                    return true;
                }
            }
            else if(dfsvis[i]){
                return true;
            }
        }
        
        dfsvis[v]=false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adj;
	    
	    for(int i=0;i<prerequisites.size();i++){
	        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
	    }
	    int N=numCourses;
	    vector<bool>vis(N,false);
        vector<bool>dfsvis(N,false);
        
        for(int i=0;i<N;i++){
            if(!vis[i]){
                // bool cd=dfs(i,adj,vis,dfsvis);
                if(dfs(i,adj,vis,dfsvis)){
                    return false;
                }
            }
        }
        
        
        return true;
    }
};
