class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int f1=fruits[0],f2=-1;
        int st=0;
        int nw=0;
        int ans=1;

        for(int i=1;i<fruits.size();i++){
            if(fruits[i]!=f1 && f2==-1){
                f2=fruits[i];
            }
            else if(fruits[i]!=f1 && fruits[i]!=f2){
                ans=max(ans,i-st);
                f1=fruits[i-1];
                f2=fruits[i];
                st=nw;
            }

            if(fruits[i]!=fruits[i-1]){
                nw=i;
            }
        }

        ans=max(ans,int(fruits.size()-st));

        return ans;
    }
};
