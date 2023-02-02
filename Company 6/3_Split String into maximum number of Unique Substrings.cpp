class Solution {
public:
    void f(int i,string curr, string s,map<string,int> m,int &ans){
        if(i==s.length()){
            if(m[curr]==0){
                int y=m.size()-1;
                ans=max(ans,y);
            }
            else{
                int y=m.size();
                ans=max(ans,y);
            }
            return;
        }

        curr+=s[i];

        if(m[curr]==0){
            m[curr]++;
            f(i+1,"",s,m,ans);
        }

        return;
    }
    int maxUniqueSplit(string s) {
        map<string,int>m;
        int ans=0;
        f(0,"",s,m,ans);

        return ans;
    }
};
