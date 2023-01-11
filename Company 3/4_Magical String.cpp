class Solution {
public:
    int magicalString(int n) {
        string s1="1",s2="11",s3="2",s4="22",s="122";
        int x=2,flag=0;

        while(s.length()<n){
            if(flag==0){
                if(s[x]=='2'){
                    s+=s2;
                }
                else{
                    s+=s1;
                }
                flag=1;
            }
            else{
                if(s[x]=='2'){
                    s+=s4;
                }
                else{
                    s+=s3;
                }
                flag=0;
            }

            x++;
        }

        int o=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                o++;
            }
        }
        return o;
    }
};
