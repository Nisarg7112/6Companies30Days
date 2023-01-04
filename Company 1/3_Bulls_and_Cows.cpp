#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        map<int,int>pos;
        map<char,int>dig;
        int x=0,y=0;
        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                x++;
                pos[i]++;
            }
            else{
                dig[guess[i]]++;
            }
        }

        for(int i=0;i<secret.length();i++){
            if(pos[i]==0 && dig[secret[i]]>0){
                y++;
                dig[secret[i]]--;
            }
        }

        cout<<x<<" "<<y<<endl;
        string s1,s2;
        if(x==0){
            s1+='0';
        }
        if(y==0){
            s2+='0';
        }

        while(x>0){
            int temp=x%10;
            char c=temp+'0';
            s1+=c;
            x=x/10;
        }
        reverse(s1.begin(),s1.end());

        while(y>0){
            int temp=y%10;
            char c=temp+'0';
            s2+=c;
            y=y/10;
        }
        reverse(s2.begin(),s2.end());
        
        cout<<s1<<" "<<s2<<endl;
        string s="";
        s+=s1;
        s+='A';
        s+=s2;
        s+='B';
        return s;
    }
};