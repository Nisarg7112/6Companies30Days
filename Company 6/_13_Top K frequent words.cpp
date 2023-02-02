class Solution {
public:
    static bool sortbysecdesc(const pair<int,string> &a,
                    const pair<int,string> &b)
    {
        if(a.first==b.first){
            return a.second<b.second;
        }
        
        return a.first>b.first;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>m;
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }

        vector<pair<int,string>>v;
        for(auto i:m){
            v.push_back({i.second,i.first});
        }

        sort(v.begin(),v.end(),sortbysecdesc);
        vector<string>ans;
        int x=v.size();
        for(int i=0;i<min(k,x);i++){
            ans.push_back(v[i].second);
        }

        return ans;
    }
};
