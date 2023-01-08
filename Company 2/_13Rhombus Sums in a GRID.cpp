class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>r(n,vector<int>(m,0));
        vector<vector<int>>l(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                r[i][j]=grid[i][j];
                if(i-1>=0 && j-1>=0){
                    r[i][j]+=r[i-1][j-1];
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                l[i][j]=grid[i][j];
                if(i-1>=0 && j+1<m){
                    l[i][j]+=l[i-1][j+1];
                }
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<r[i][j]<<" ";
        //     }cout<<endl;
        // }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<l[i][j]<<" ";
        //     }cout<<endl;
        // }
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x=grid[i][j];
                ans.push_back(x);
                for(int k=i+1,p=1;k<n;k++,p++){
                    if(j-p>=0 && j+p<m && 2*k-i<n){
                        int sum=x+r[k][j+p]-r[i][j];
                        sum+=l[k][j-p]-l[i][j];
                        sum+=r[2*k-i][j]-r[k][j-p];
                        sum+=l[2*k-i][j]-l[k][j+p]-grid[2*k-i][j];
                        ans.push_back(sum);
                    }
                    else{
                        break;
                    }
                }
            }
        }
        sort(ans.begin(),ans.end(),greater<int>());
        vector<int>diff;
        diff.push_back(ans[0]);
        for(int i=1;i<ans.size();i++){
            if(ans[i]!=ans[i-1]){
                diff.push_back(ans[i]);
            }
            if(diff.size()==3){
                break;
            }
        }
        return diff;
    }
};
