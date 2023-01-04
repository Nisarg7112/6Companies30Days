#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        string s1="+",s2="-",s3="*",s4="/";
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!=s1 && tokens[i]!=s2 && tokens[i]!=s3 && tokens[i]!=s4){
                int x=0,end=0;
                int n=tokens[i].length();
                if(tokens[i][0]=='-'){
                    end=1;
                }
                for(int j=n-1,k=0;j>=end;j--,k++){
                    char c=tokens[i][j];
                    int a=c-'0';
                    x+=a*(pow(10,k));

                }

                if(tokens[i][0]=='-'){
                    s.push(-x);
                }
                else{
                    s.push(x);
                }
            }
            else{
                int y=s.top();
                s.pop();
                int x=s.top();
                s.pop();

                int z;
                if(tokens[i]==s1){
                    z=x+y;
                }
                else if(tokens[i]==s2){
                    z=x-y;
                }
                else if(tokens[i]==s3){
                    z=x*y;
                }
                else{
                    z=x/y;
                }

                s.push(z);
            }
        }

        int ans=s.top();

        return ans;
    }
};
