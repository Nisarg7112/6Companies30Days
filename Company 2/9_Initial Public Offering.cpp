class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>p;
        int n=capital.size();
        for(int i=0;i<profits.size();i++){
            p.push_back({capital[i],profits[i]});
        }
        sort(p.begin(),p.end());
        sort(capital.begin(),capital.end());

        priority_queue<int> q;
        int w_old=0;
        int flag=0;
        if(w<capital[0]){
            return w;
        }
        else{
            int x=lower_bound(capital.begin(),capital.end(),w_old)-capital.begin();
            int y=upper_bound(capital.begin(),capital.end(),w)-capital.begin();
            cout<<x<<" "<<y<<endl;  
            for(int i=x;i<y;i++){
                q.push(p[i].second);
            }
            if(y==n){
                flag=1;
            }
        }
        while(!q.empty() && k>0){
           int profit=q.top();
           q.pop();
           w_old=w+1;
           w=w+profit;
            k--;
            
            if(flag!=1){
               int x=lower_bound(capital.begin(),capital.end(),w_old)-capital.begin();
               int y=upper_bound(capital.begin(),capital.end(),w)-capital.begin();
                cout<<x<<" "<<y<<endl; 
                for(int i=x;i<y;i++){
                     q.push(p[i].second);
                }
                
                if(y==n){
                    flag=1;
                }
            }  
        }

        return w;   
    }
};
