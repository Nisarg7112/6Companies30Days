class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int x=-1,mini=INT_MAX,y=-1,maxi=INT_MIN;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                if(nums[i]<mini){
                    x=upper_bound(nums.begin(),nums.end()-(n-i),nums[i])-nums.begin();
                    mini=nums[i];
                }
            }
        }
        // cout<<x<<endl;

        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                // cout<<i<<" "<<nums[i]<<endl;
                if(nums[i]>maxi){
                    int z=lower_bound(nums.begin()+i+1,nums.end(),nums[i])-nums.begin();
                    // cout<<z<<endl;
                    y=z-1;
                    maxi=nums[i];
                }
            }
        }
        // cout<<y<<endl;
        if(x==-1){
            return 0;
        }
        return y-x+1;
    }
};
