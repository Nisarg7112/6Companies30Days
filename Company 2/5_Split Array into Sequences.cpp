class Solution {
public:
    bool isPossible(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
        int i=1;
        q.push({nums[0],1});

        while(i<nums.size()){
            pair<int,int>x=q.top();
            while(x.first+1<nums[i]){
                if(x.second<3){
                    return false;
                }
                q.pop();
                if(!q.empty()){
                    x=q.top();
                }
                else{
                    break;
                }
            }
            cout<<x.first<<" "<<x.second<<endl;
            if(q.empty()){
                q.push({nums[i],1});
            }
            else if(x.first==nums[i]){
                q.push({nums[i],1});
            }
            else if((x.first+1)==nums[i]){
                q.pop();
                q.push({nums[i],x.second+1});
            }
            else{
                return false;
            }
            i++;
        }

        while(!q.empty()){
            pair<int,int>x=q.top();
            q.pop();
            cout<<x.second<<endl;
            if(x.second<3){
                return false;
            }
        }
        return true;
    }
};
