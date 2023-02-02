class Solution {
public:
    static bool sortbysec(const pair<string,int> &a,const pair<string,int> &b)
    {
        if(a.second==b.second){
            return a.first < b.first;
        }
        return (a.second > b.second);
    }

    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        vector<pair<string,pair<string,int>>>v;
        map<string,vector<pair<string,int>> >m;
        map<string,long long >m1;
        long long  maxi=0;
        for(int i=0;i<creators.size();i++){
            v.push_back({creators[i],{ids[i],views[i]}});
            m1[creators[i]]+=views[i];
            m[creators[i]].push_back({ids[i],views[i]});
        }

        for(auto i:m1){
            maxi=max(i.second,maxi);
        }        
        vector<vector<string>>ans;

        for(auto i:m){
            if(m1[i.first]==maxi){
                vector<string>temp;
                temp.push_back(i.first);

                sort(i.second.begin(),i.second.end(),sortbysec);

                temp.push_back(i.second[0].first);

                ans.push_back(temp);
            }
        }
        return ans;   
    }
};
