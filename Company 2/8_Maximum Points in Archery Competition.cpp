class Solution {
public:
    int f(int x,int left,vector<int>& aliceArrows){
        if(x<0 || left==0){
            return 0;
        }

        int nottake=f(x-1,left,aliceArrows);
        int take=0;
        if(left>aliceArrows[x]){
            left=left-aliceArrows[x]-1;
            take=x+f(x-1,left,aliceArrows);
        }

        return max(take,nottake);
    }

    void f(int x,int left,int sum,int curr,vector<int>& aliceArrows,vector<int>& v,vector<int>&ans){
        if(x<0 || left==0){
            if(curr==sum){
                v[0]+=left;
                ans=v;
            }
            return;
        }

        f(x-1,left,sum,curr,aliceArrows,v,ans);
        if(left>aliceArrows[x]){
            left=left-aliceArrows[x]-1;
            v[x]=aliceArrows[x]+1;
            f(x-1,left,sum,curr+x,aliceArrows,v,ans);
            v[x]=0;
        }

        return;
    }

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>ans(12,0);
        vector<int>v(12,0);
        int x=f(11,numArrows,aliceArrows);
        cout<<x<<endl;
        f(11,numArrows,x,0,aliceArrows,v,ans);
        return ans;
    }
};
