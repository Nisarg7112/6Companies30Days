class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m=0;
        int n=matrix.size();
        long long sum=0;
        long long mini=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0){
                    m++;
                }
                sum+=abs(matrix[i][j]);
                long long x=abs(matrix[i][j]);
                mini=min(mini,x);
            }
        }

        if(m%2==0){
            return sum;
        }
        
        cout<<sum<<" "<<mini<<endl;
        return sum-2*mini;
    }
};
