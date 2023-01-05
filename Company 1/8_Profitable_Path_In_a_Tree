class Solution {
public:
    int f(int ind,int dep,vector<vector<int>>& adj,map<int,int>& par,vector<int>& mov,vector<int>& amount){
        if(adj[ind].size()==1 && ind!=0){
            // cout<<dep<<endl;
            if(dep>mov[ind]){
                return 0;
            }
            else if(dep==mov[ind]){
                return amount[ind]/2;
            }
            else{
                return amount[ind];
            }
        }

        int ans=INT_MIN;
        int reward;
        if(dep>mov[ind]){
            reward=0;
        }
        else if(dep==mov[ind]){
            reward=amount[ind]/2;
        }
        else{
            reward=amount[ind];
        }

        // cout<<reward<<endl;
        dep++;
        for(int i=0;i<adj[ind].size();i++){
            if(adj[ind][i]!=par[ind]){
                ans=max(ans,reward+f(adj[ind][i],dep,adj,par,mov,amount));
            }
        }

        return ans;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1;
        sort(edges.begin(),edges.end());
        vector<vector<int>>adj(n);
        for(int i=0;i<n-1;i++){
           adj[edges[i][0]].push_back(edges[i][1]);
           adj[edges[i][1]].push_back(edges[i][0]);
        }

        map<int,int>par;
        queue<int>q;
        q.push(0);
        par[0]=-1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i=0;i<adj[x].size();i++){
                if(adj[x][i]!=par[x]){
                    par[adj[x][i]]=x;
                    q.push(adj[x][i]);
                }
            }
        }

        vector<int>mov(n,INT_MAX);
        // for(int i=0;i<n;i++){
        //     cout<<par[i]<<endl;
        // }
        int x=0;
        while(bob!=-1){
            mov[bob]=x;
            x++;
            bob=par[bob];
        }

        // for(int i=0;i<n;i++){
        //     cout<<mov[i]<<endl;
        // }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<adj[i].size();j++){
        //         cout<<adj[i][j]<<" ";
        //     }cout<<endl;
        // }

        int profit=f(0,0,adj,par,mov,amount);
        return profit;   
    }
};
