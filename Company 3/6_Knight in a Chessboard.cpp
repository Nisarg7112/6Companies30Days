class Solution {
public:
    double f(int i,int j,int n,int k,vector<vector<vector<double>>>& dp){
        if(i<0 || j<0 || i>=n || j>=n){
            return 0;
        }

        if(k==0){
            return 1;
        }

        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }

        double ans=0;
        ans=(f(i-1,j-2,n,k-1,dp) + 
            f(i-2,j-1,n,k-1,dp) +
            f(i-1,j+2,n,k-1,dp) +
            f(i-2,j+1,n,k-1,dp) +
            f(i+1,j-2,n,k-1,dp) +
            f(i+2,j-1,n,k-1,dp) + 
            f(i+1,j+2,n,k-1,dp) + 
            f(i+2,j+1,n,k-1,dp))/double(8);
     
        return dp[i][j][k]=ans;
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n+1, vector<vector<double >>(n+1, vector<double>(k+1,-1)));
        
        double o=f(row,column,n,k,dp);
        return o;       
    }
};
