class Solution {
public:
    double finddis(vector<int>& v1,vector<int>& v2){
        return sqrt(pow(v1[0]-v2[0],2)+ pow(v1[1]-v2[1],2));
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans=0;
        for(int i=0;i<points.size();i++){
            vector<double> dis;
            for(int j=0;j<points.size();j++){
                double x=finddis(points[i],points[j]);
                dis.push_back(x);
            }

            sort(dis.begin(),dis.end());
            int x=1;
            // for(int j=0;j<dis.size();j++){
            //     cout<<dis[j]<<" ";
            // }cout<<endl;
            for(int j=1;j<dis.size();j++){
                if(dis[j]!=dis[j-1]){
                    ans+=(x*(x-1))/2;
                    x=1;
                }
                else{
                    x++;
                }
            }
            ans+=(x*(x-1))/2;
        }
        return ans*2;
    }
};
