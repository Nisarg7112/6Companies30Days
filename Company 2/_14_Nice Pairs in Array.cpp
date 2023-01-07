class Solution {
public:
    typedef long long ll;
    ll MOD = 1000000007;

    int reverseDigits(int num)
    {
        int rev_num = 0;
        while (num > 0) {
            rev_num = rev_num * 10 + num % 10;
            num = num / 10;
        }
        return rev_num;
    }

    int countNicePairs(vector<int>& nums) {
        vector<int>diff;
        for(int i=0;i<nums.size();i++){
            int x=reverseDigits(nums[i]);
            diff.push_back(x-nums[i]);
        }

        sort(diff.begin(),diff.end());
        ll x=1;
        ll ans=0;
        for(int i=1;i<diff.size();i++){
            if(diff[i]!=diff[i-1]){
                ll y=(x*(x-1))/2;
                ans=(ans+y)%MOD;
                x=1;
            }
            else{
                x++;
            }
        }
        ll y=(x*(x-1))/2;
        ans=(ans+y)%MOD;
        return ans;
    }

};
