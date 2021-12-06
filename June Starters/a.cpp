struct movie{
    int price,shop,mov;
    movie(int price,int shop,int mov): price(price),shop(shop),mov(mov){}
    bool operator<(const movie&a)const
    {
        if(price!=a.price)return price<a.price;
        return shop<a.shop;
        // return mov<a.mov;
    }
};
struct movie1{
    int price,shop,mov;
    movie1(int price,int shop,int mov): price(price),shop(shop),mov(mov){}
    bool operator<(const movie1&a)const
    {
        if(price!=a.price)return price<a.price;
        if(shop!=a.shop) return shop<a.shop;
        return mov<a.mov;
    }
};


class MovieRentingSystem {
public:
    map<int,set<movie>>unrented;
    set<movie1>allrented;
    map<pair<int,int>,int>mp;//for a movie and shop the price
    
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        mp.clear();
        allrented.clear();
        unrented.clear();
        // for(int i=0;i<n;i+)
        for(int i=0;i<entries.size();i++)
        {
            int shop=entries[i][0],mov=entries[i][1],price=entries[i][2];
            mp[{shop,mov}]=price;
            unrented[mov].insert(movie(price,shop,mov));
        }
    }
    
    vector<int> search(int movi) {
        vector<int>res;
        if(unrented.find(movi)==unrented.end())return res;
        int co=0;
        if(unrented[movi].size()==0)return res;
        for(auto it=unrented[movi].begin();co<5&&it!=unrented[movi].end();it++)
        {
            co++;
            movie m=*it;
            res.push_back(m.shop);
        }
        return res;
    }
    
    void rent(int shop, int movi) {
        allrented.insert(movie1(mp[{shop,movi}],shop,movi));
        cout<<mp[{shop,movi}]<<" "<<shop<<" "<<movi<<" "<<allrented.size()<<"\n";
        unrented[movi].erase(unrented[movi].find(movie(mp[{shop,movi}],shop,movi)));
    }
    
    void drop(int shop, int movi) {
        allrented.erase(allrented.find(movie1(mp[{shop,movi}],shop,movi)));
        unrented[movi].insert(movie(mp[{shop,movi}],shop,movi));        
    }
    
    vector<vector<int>> report() {
        
        vector<vector<int>>res;
        int co=0;
        if(allrented.size()==0)return res;
        for(auto it=allrented.begin();co<5&&it!=allrented.end();it++)
        {
            co++;
            movie1 m=*it;
            vector<int>v;
            v.push_back(m.shop);
            v.push_back(m.mov);
            res.push_back(v);
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */