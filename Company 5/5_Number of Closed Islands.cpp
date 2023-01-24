class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid,int x,map<int,vector<pair<int,int>>>&isl){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
            return;
        }

        if(vis[i][j]){
            return;
        }

        if(grid[i][j]==0){
            vis[i][j]=1;
            isl[x].push_back({i,j});
            dfs(i-1,j,vis,grid,x,isl);
            dfs(i+1,j,vis,grid,x,isl);
            dfs(i,j-1,vis,grid,x,isl);
            dfs(i,j+1,vis,grid,x,isl);
        }

        return;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        int x=0;
        map<int,vector<pair<int,int>>>isl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && vis[i][j]==0){
                    dfs(i,j,vis,grid,x,isl);
                    x++;
                }
            }
        }

        int ans=0;
        for(auto i:isl){
            // cout<<i.first<<" ";
            // cout<<i.second.size()<<" ";
            sort(i.second.begin(),i.second.end());
            int st=i.second[0].first;
            int end=i.second[i.second.size()-1].first;
            int flag=0;
            if(i.second[0].second-1<0 || grid[st][i.second[0].second-1]!=1){
                flag=1;
            }

            for(int j=1;j<i.second.size();j++){
                if(i.second[j].first!=i.second[j-1].first){
                    if(i.second[j-1].second + 1>=m || grid[i.second[j-1].first][i.second[j-1].second+1]!=1){
                        flag=1;
                    }
                    if(i.second[j].second-1<0 || grid[i.second[j].first][i.second[j].second-1]!=1){
                        flag=1;
                    } 
                }
            }

            if(i.second[i.second.size()-1].second + 1>=m || grid[i.second[i.second.size()-1].first][i.second[i.second.size()-1].second+1]!=1){
                flag=1;
            }

            for(auto j:i.second){
                if(j.first==st){
                    if(j.first -1<0 || grid[j.first-1][j.second]!=1){
                        flag=1;
                    }
                }
                if(j.first==end){
                    if(j.first + 1>=n || grid[j.first+1][j.second]!=1){
                        flag=1;
                    }
                }
            }

            if(flag==0){
                ans++;
            }
            // cout<<flag<<endl;
        }
        return ans;
    }
};
