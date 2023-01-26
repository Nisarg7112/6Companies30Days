class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> pre(m,vector<int>(n,-1));
        vector<vector<int>> ans(m,vector<int>(n,0)); 
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                {
                    pre[i][j]=mat[i][j];
                }
                else
                {
                    pre[i][j]=pre[i][j-1]+mat[i][j];
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int w,x,y,z;
                w=max(i-k,0);
                x=min(i+k,m-1);
                y=max(j-k,0);
                z=min(j+k,n-1);
                // cout<<w<<x<<y<<z<<endl;
                for(int l=w;l<=x;l++)
                {
                    ans[i][j]+=pre[l][z]-pre[l][y]+mat[l][y];
                }
            }
        }
        return ans;
    }
};
