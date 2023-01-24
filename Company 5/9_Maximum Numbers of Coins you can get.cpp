class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end(),greater<int>());
        int ans=0;

        int i=0,j=piles.size()-1;

        while(j-i>=2){
            ans+=piles[i+1];
            i+=2;
            j--;
        }

        return ans;
    }
};
