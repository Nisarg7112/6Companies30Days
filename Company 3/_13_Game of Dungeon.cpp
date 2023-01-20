class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1){
                    if(dungeon[i][j]>=0)
                        dp[i][j]=0;
                    else
                        dp[i][j]=dungeon[i][j];
                }
                else if(i==n-1){
                    int x=dp[i][j+1]+dungeon[i][j];
                    if(x>=0)
                        dp[i][j]=0;
                    else
                        dp[i][j]=x;
                }       
                else if(j==m-1){
                    int x=dp[i+1][j]+dungeon[i][j];
                    if(x>=0)
                        dp[i][j]=0;
                    else
                        dp[i][j]=x;
                } 
                else{
                    int x1=dp[i+1][j]+dungeon[i][j];
                    int x2=dp[i][j+1]+dungeon[i][j];
                    int x=max(x1,x2);
                    if(x>=0)
                        dp[i][j]=0;
                    else
                        dp[i][j]=x;                    
                }     
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dp[i][j].first<<" "<<dp[i][j].second<<",,,";
        //     }cout<<endl;
        // }
        
        return -dp[0][0] + 1;
    }
};
