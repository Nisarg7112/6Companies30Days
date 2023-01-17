class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>v(n,vector<int>(n,INT_MAX));

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int x=edges[i][1];
            int w=edges[i][2];

            v[u][x]=w;
            v[x][u]=w;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(v[i][k]!=INT_MAX && v[k][j]!=INT_MAX && v[i][k] + v[k][j] < v[i][j]){
                        v[i][j]=v[i][k] + v[k][j];
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            v[i][i]=INT_MAX;
            for(int j=0;j<n;j++){
                cout<<v[i][j]<<" ";
            }cout<<endl;
        }

        int mini=INT_MAX;
        int index=-1;

        for(int i=0;i<n;i++){
            int x=0;
            for(int j=0;j<n;j++){
                if(v[i][j]<=distanceThreshold){
                    x++;
                }
            }

            if(x<=mini){
                mini=x;
                index=i;
            }
        }

        return index;
    }
};
