class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.length()){
            return false;
        }

        int x=pow(2,k);
        string s1="";
        map<string,int>m;
        for(int i=0;i<k-1;i++){
            s1+=s[i];
        }

        for(int i=k-1;i<s.length();i++){
            s1+=s[i];
            // cout<<s1<<" ";
            m[s1]++;
            s1.erase(s1.begin(),s1.end()-k+1);
        }

        if(m.size()!=x){
            return false;
        }
        return true;
    }
};
