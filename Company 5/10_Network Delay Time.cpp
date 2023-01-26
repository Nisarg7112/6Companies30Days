class Solution {
public:
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    map<int,vector<pair<int,int>>> adjlist;
    for(int i=0;i<edges;i++)
    {
        int x=vec[i][0];
        int y=vec[i][1];
        int z=vec[i][2];
        adjlist[x-1].push_back({y-1,z});
        // adjlist[y].push_back({x,z});
    }
    // printadj(adjlist);
    vector<int> dis(vertices,INT_MAX);
    set<pair<int,int>> s;
    
    s.insert({0,source});
    dis[source]=0;
    
    while(!s.empty())
    {
        auto i=*(s.begin());
        int node=i.second;
        int distance=i.first;
        s.erase(i);
        for(auto j:adjlist[node])
        {
            if(distance+j.second<dis[j.first])
            {
                
                dis[j.first]=distance+j.second;
                s.insert({dis[j.first],j.first});
            }
           
        }
    }
    return dis;
}

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> ans=dijkstra(times,n,times.size(),k-1);
        int ans1=0;
        for(auto i:ans)
        {
            if(i==INT_MAX)
            {
                return -1;
            }
            ans1=max(ans1,i);
        }
        return ans1;
    }
};
