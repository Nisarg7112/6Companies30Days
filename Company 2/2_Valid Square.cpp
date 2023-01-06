class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        double d1=sqrt(pow(p1[0]-p3[0],2) + pow(p1[1]-p3[1],2));
        double d2=sqrt(pow(p2[0]-p4[0],2) + pow(p2[1]-p4[1],2));
        double d3=sqrt(pow(p1[0]-p4[0],2) + pow(p1[1]-p4[1],2));
        double d4=sqrt(pow(p2[0]-p3[0],2) + pow(p2[1]-p3[1],2));
        double d5=sqrt(pow(p1[0]-p2[0],2) + pow(p1[1]-p2[1],2));
        double d6=sqrt(pow(p3[0]-p4[0],2) + pow(p3[1]-p4[1],2));

        if(d1==0 || d2==0 || d3==0 || d4==0 || d5==0 || d6==0){
            return false;
        }
        
        if(d1==d2 && d3==d4 && d3==d5 && d3==d6){
            return true;
        }
        else if(d3==d4 && d1==d2 && d1==d5 && d1==d6){
            return true;
        }
        else if(d5==d6 && d1==d2 && d1==d3 && d1==d4){
            return true;
        }

        return false;
    }
};
