class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long x=mass;
        sort(asteroids.begin(),asteroids.end());
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>x){
                return false;
            }
            x+=asteroids[i];
        }

        return true;
    }
};
