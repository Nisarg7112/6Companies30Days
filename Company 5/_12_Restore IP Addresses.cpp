class Solution {
public:
    void f(int i,int k,string s1,string s2,string s,vector<string>& ans){
        if(i==s.length()-1 ){
            s1+=s[i];
            s2+=s[i];
            stringstream geek(s2);
            long long x=0;
            geek >> x;
            if(k==3 && x<=255){
                ans.push_back(s1);
            }
            return;
        }

            s1+=s[i];
            s2+=s[i];
            stringstream geek(s2);
            long long x=0;
            geek >> x;

            if(x>0){
                f(i+1,k,s1,s2,s,ans);
            }

            if(k<3 && x<=255){
                f(i+1,k+1,s1+'.',"",s,ans);
            }
        // }
        return ;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        if(s.length()<4 || s.length()>12){
            return ans;
        }

        string s1,s2;
        f(0,0,s1,s2,s,ans);
        return ans;
    }
};
