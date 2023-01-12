class Solution {
public:
    int dif(string s1,string s2){
        int x=0;
        for(int i=0;i<8;i++){
            if(s1[i]!=s2[i]){
                x++;
            }
        }
        return x;
    }

    void bfs(int x,int i,string s1,string s2,vector<bool>& vis,vector<string>& bank,int &ans){
        if(s1==s2){
            ans=min(x,ans);
        }

        vis[i]=1;
        for(int i=0;i<bank.size();i++){
            if(!vis[i+1] && dif(s1,bank[i])==1){
                bfs(x+1,i+1,bank[i],s2,vis,bank,ans);
            }
        }
        vis[i]=0;
        return;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<bool>vis(11,0);

        int ans=INT_MAX;
        bfs(0,0,startGene,endGene,vis,bank,ans);
        
        if(ans==INT_MAX){
            return -1;
        }

        return ans;
    }
};
