class StockPrice {
public:
        map<int,int>prev;
        set<pair<int,int> >s;
        set<pair<int,int> >c;
        set<pair<int,int> > :: iterator itr;
    StockPrice() {
        // set<pair<int,int> >s;
        // set<pair<int,int> > :: iterator itr;
    }
    
    void update(int timestamp, int price) {
        if(prev[timestamp]!=0){
            s.erase({prev[timestamp],timestamp});
            c.erase({timestamp,prev[timestamp]});
        }
        s.insert({price,timestamp});
        c.insert({timestamp,price});
        prev[timestamp]=price;
    }
    
    int current() {
        itr=c.end();
        itr--;
        return itr->second;
    }
    
    int maximum() {
        cout<<s.size()<<endl;
        itr=s.end();
        itr--;
        return itr->first;
    }
    
    int minimum() {
        cout<<s.size()<<endl;
        itr=s.begin();
        return itr->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
