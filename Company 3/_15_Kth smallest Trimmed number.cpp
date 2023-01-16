class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        // sort(nums.begin(),nums.end());
        // cout<<nums[0]<<endl;
        vector<int>ans;

        for(int i=0;i<queries.size();i++){
            int k=queries[i][0];
            int trim=queries[i][1];

            vector<pair<string,int>>v;
            for(int j=0;j<nums.size();j++){
                string s;
                for(int l=nums[j].length()-1,x=0;x<trim;l--,x++){
                    s+=nums[j][l];
                }
                reverse(s.begin(),s.end());
                v.push_back({s,j});
            }
            sort(v.begin(),v.end());
            // for(int j=0;j<v.size();j++){
            //     cout<<v[j].first<<" ";
            // }cout<<endl;
            ans.push_back(v[k-1].second);
        }

        return ans;
    }
};
