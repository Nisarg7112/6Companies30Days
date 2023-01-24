class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ans=0;
        sort(special.begin(),special.end());
        if(special[0]!=bottom){
            ans=max(ans,special[0]-bottom);
        }
        if(special[special.size()-1]!=top){
            ans=max(ans,top-special[special.size()-1]);
        }

        for(int i=1;i<special.size();i++){
            ans=max(ans,special[i]-special[i-1]-1);
        }

        return ans;
    }
};
