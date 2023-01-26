class Solution {
public:
    int f(int i,int n,vector<int>vis,vector<vector<int>>& students,vector<vector<int>>& mentors){
        if(i>=mentors.size()){
            return 0;
        }

        int ans=0;
        for(int j=0;j<mentors.size();j++){
            if(vis[j]==0){
                int x=0;
                vis[j]=1;
                for(int k=0;k<n;k++){
                    if(students[i][k]==mentors[j][k]){
                        x++;
                    }
                }

                x+=f(i+1,n,vis,students,mentors);
                ans=max(ans,x);
                vis[j]=0;
            }
        }

        return ans;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m=mentors.size();
        int n=students[0].size();

        vector<int>vis(m,0);
        return f(0,n,vis,students,mentors);
    }
};
