class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,int>m;
        int mini=INT_MAX;
        for(int i=0;i<cards.size();i++){
            if(m[cards[i]]>0){
                mini=min(mini,i+1-m[cards[i]]+1);
            }
            m[cards[i]]=i+1;
        }
        if(mini==INT_MAX){
            return -1;
        }

        return mini;
    }
};
