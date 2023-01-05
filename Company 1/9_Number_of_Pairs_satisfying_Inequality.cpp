#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        faster;
        ordered_set s;
        for(int i=1;i<nums1.size();i++){
            int x=nums1[i]-nums2[i];
            s.insert({x,i});
        } 

        long long ans=0;
        for(int i=0;i<nums1.size()-1;i++){
            int x=nums1[i]-nums2[i]-diff;
            cout<<x<<endl;
            int y = s.order_of_key({x,i});
            int n=s.size();
            cout<<n<<endl;
            ans+=(n-y);
            s.erase({nums1[i+1]-nums2[i+1],i+1});
        }
        return ans;
    }
};
