class Solution {
public:
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
            return 0;
        }

        if(vis[i][j]==1 || grid[i][j]==0){
            return 0;
        }

        vis[i][j]=1;
        int area=1 + f(i-1,j,grid,vis);
        area+=f(i,j-1,grid,vis);
        area+=f(i+1,j,grid,vis);
        area+=f(i,j+1,grid,vis);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 || grid[i][j]==1){
                    ans=max(ans,f(i,j,grid,vis));
                }
            }
        }

        return ans;
    }
};
