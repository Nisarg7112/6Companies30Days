class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int>m;
        map<char,int>pos;
        for(int i=0;i<order.length();i++){
            m[order[i]]++;
            pos[order[i]]=i;
        }

        string ans;
        vector<pair<int,char>>v;
        for(int i=0;i<s.length();i++){
            if(m[s[i]]==1){
                v.push_back({pos[s[i]],s[i]});
            }
            else{
                ans+=s[i];
            }
        }

        sort(v.begin(),v.end());

        for(int i=0;i<v.size();i++){
            ans+=v[i].second;
        }

        return ans;
    }
};
