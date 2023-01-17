class Solution {
public:
    int findTheWinner(int n, int k) {
        int i=0;
        vector<int>v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }

        n--;
        while(n--){
            int x=(i+k-1)%v.size();
            v.erase(v.begin()+x);
            i=x;
        }

        return v[0];
    }
};
