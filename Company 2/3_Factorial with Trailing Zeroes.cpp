class Solution {
public:
    int trailingZeroes(int n) {
        int two=0,five=0;

        for(int i=1;i<=n;i++){
            int x=i;
            while(x%2==0){
                two++;
                x=x/2;
            }

            x=i;
            while(x%5==0){
                five++;
                x=x/5;
            }
        }

        return min(two,five);   
    }
};
