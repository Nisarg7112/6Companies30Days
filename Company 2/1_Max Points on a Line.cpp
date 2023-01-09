class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1){
            return 1;
        }
        map<pair<double,double>,set<pair<double,double>>>m1;
        int n=points.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                double x1=points[i][0],y1=points[i][1],x2=points[j][0],y2=points[j][1];
                double m,c;
                if(x2-x1!=0){
                    m=(y2-y1)/(x2-x1);
                    c=y1-(m*x1);
                }
                else{
                    m=INT_MAX;
                    c=x1;
                }
                cout<<m<<" "<<c<<endl;
                m1[{m,c}].insert({x1,y1});
                m1[{m,c}].insert({x2,y2});
            }
        }

        int ans=0;
        for(auto i:m1){
            int x=i.second.size();
            ans=max(ans,x);
        }
        return ans;
    }
};
