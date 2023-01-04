#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int total=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            total+=(nums[i]*i);
        }

        int ans=total;

        for(int i=1;i<n;i++){
            int x=n-i;
            sum=sum-nums[x];
            total=total-(nums[x]*(n-1)) + sum;
            sum=sum+nums[x];

            ans=max(ans,total);
        }

        return ans;
    }
};