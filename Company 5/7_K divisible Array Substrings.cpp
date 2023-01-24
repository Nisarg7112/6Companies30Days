class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        map<vector<int>,int>m;

        for(int i=0;i<nums.size();i++){
            vector<int>temp;
            temp.push_back(nums[i]);
            m[temp]++;
            int x=0;
            if(nums[i]%p==0){
                x++;
            }
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]%p==0){
                    x++;
                }

                if(x>k){
                    break;
                }
                temp.push_back(nums[j]);
                m[temp]++;
            }

            // cout<<m.size()<<endl;
        }
        return m.size();
        // return 0;
    }
};
