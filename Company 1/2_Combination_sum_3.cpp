#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    void combination(int ind,vector<int>&v,int k,int n,vector<vector<int>>& ans,vector<int>&q){
        if(ind==9 || q.size()==k){
            if(q.size()==k){
                int sum=0;
                for(int i=0;i<q.size();i++){
                    sum+=q[i];
                }
                if(sum==n){
                    ans.push_back(q);
                }
            }

            return;
        }

        combination(ind+1,v,k,n,ans,q);
        q.push_back(v[ind]);
        combination(ind+1,v,k,n,ans,q);
        q.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>v;
        for(int i=1;i<=9;i++){
            v.push_back(i);
        }

        vector<int>q;
        combination(0,v,k,n,ans,q);

        return ans;
    }
};