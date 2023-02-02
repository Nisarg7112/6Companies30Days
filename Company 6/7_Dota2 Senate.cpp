class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>r,q;
        map<int,int>m;
        int n=senate.size();
        for(int i=0;i<senate.length();i++){
            if(senate[i]=='R'){
               r.push(i);
            }
            else{
                q.push(i);
            }
        }

        int i=0;
        while(!r.empty() && !q.empty()){
            i=i%n;
            if(m[i]==0){
                if(senate[i]=='R'){
                    int y=q.front();
                    q.pop();
                    m[y]++;

                    y=r.front();
                    r.pop();
                    r.push(y);
                }
                else{
                    int y=r.front();
                    r.pop();
                    m[y]++;

                    y=q.front();
                    q.pop();
                    q.push(y);
                }
            }

            i++;
        }

        if(r.empty()){
            return "Dire";
        }

        return "Radiant";
    }
};
