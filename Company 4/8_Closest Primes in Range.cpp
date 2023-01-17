#define MAXN   1000001
class Solution {
public:
int spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;

    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
    vector<int> closestPrimes(int left, int right) {
        vector<int>prime;
        vector<int>ans={-1,-1};
        sieve();
        for(int i=left;i<=right;i++){
            // cout<<spf[i]<<" ";
            if(spf[i]==i && i!=1){
                prime.push_back(i);
            }
        }

        // cout<<prime.size();
        for(int i=0;i<prime.size();i++){
            cout<<prime[i]<<" ";
        }

        if(prime.size()>=2){
            int dif=INT_MAX;
            for(int i=1;i<prime.size();i++){
                int x=prime[i]-prime[i-1];

                if(x<dif){
                    ans[0]=prime[i-1];
                    ans[1]=prime[i];
                    dif=x;
                }
            }
        }
        return ans;
    }
};
