class Solution {
public:
    int gcd(int a, int b)
    {
    if (a == 0)
        return b;
    return gcd(b % a, a);
    }
 
// Function to find gcd of array of
// numbers
    int findGCD(vector<int>& numsDivide, int n)
    {
        int result = numsDivide[0];
        for (int i = 1; i < n; i++)
        {
        result = gcd(numsDivide[i], result);
    
        if(result == 1)
        {
        return 1;
        }
        }
    return result;
    }

    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(numsDivide.begin(),numsDivide.end());
        int n=numsDivide.size();
        int x=findGCD(numsDivide,n);

        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(x%nums[i]==0){
                return i;
            }
        }
        return -1;
        // cout<<x<<endl;
        return 0;
    }
};
