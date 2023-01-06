class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0;
        int ans=0;
        map<char,int>m;
        int n=s.length();
        while(j<n){
            m[s[j]]++;

            if(m['a']>0 && m['b']>0 && m['c']>0){
                ans+=n-j;
                m[s[i]]--;
                i++;
                m[s[j]]--;                
            }
            else{
                j++;
            }    
        }

        return ans;
    }
};
