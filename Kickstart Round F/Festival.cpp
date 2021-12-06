#include<bits/stdc++.h>


using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Pair vector<pair<ll,ll>>
#define vec vector <ll> 
#define all(a) a.begin(),a.end()
#define mo 1000000007
#define decimal(i,n) fixed << setprecision(i) << n
#define show(a) for(auto xyz:a)cout<<xyz<<" ";cout<<endl;
#define show_nl(a) for(auto xyz:a)cout<<xyz<<endl;
#define MAX (ll)(pow(2,63)-1)
#define fill(a,b) memset(a, b, sizeof(a))
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

//modular inverse
void eea(ll a,ll b,ll &x,ll &y)
{
    if (a == 1)
    {
        x = 1; y = 0;
        return;
    }
    ll x1, y1;
    eea(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
}
ll mi(ll a,ll m)
{
    ll x,y;
    eea(a,m,x,y);
    x= (x%m+m)%m;
    return x;
}
//complete

vector <ll> prime(1000006,0);
void Sieve(int n) 
{ 
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == 0) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = 1; 
        } 
    } 
}

ll pow1(ll n, ll p)
{
    if (p == 0)
        return 1;
    ll x = pow1(n, p / 2);
    x = (x * x) % mo;
    if (p % 2 == 0)
        return x;
    else
        return (x * n) % mo;
}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  


    // freopen("input.txt", "r", stdin);   // name of input file
	// freopen("output.txt", "w", stdout); // name of output file
    
    // fstream file, output;
	// file.open(R"(input.txt)", ios::in);        // add the address of local input file
	// output.open(R"(output.txt)", ios::out);  // add the address of local output file
    
    

    ll t=1,t1=1;
     cin>>t;
    while(t--)
    {
        ll d,n,k;
        cin>>d>>n>>k;
        vector <pair<ll,ll>> v;
        ll h,p,q,s=0;
        multiset <ll> ms,ms2;
        for(ll i=0;i<n;i++){
            cin>>h>>p>>q;
            v.PB({p,-h});
            v.PB({q,h});
        }
        sort(all(v));
        ll ma=0,c=0;
        for(ll i=0;i<v.size();i++){
            if(v[i].S>0){
                std::multiset<ll>::iterator hit(ms.find(v[i].S));
                if (hit!= ms.end()) {
                    ms.erase(hit);
                    if(c>0){
                        if(ms2.size()>0){
                            auto u=ms2.end();
                            u--;
                            ms.insert(*u);
                            s=s+*u;
                            ms2.erase(u);
                            c--;
                            
                        }    
                    }
                    s=s-v[i].S;
                }    
                else{
                    std::multiset<ll>::iterator u1(ms2.find(v[i].S));
                    if(u1!=ms2.end()) {
                        ms2.erase(u1);
                        c--;
                    }
                }
                // auto u=ms.lower_bound(v[i].S);
                // ms.erase(u);
                
                ma=max(ma,s);
            }
            else{
                if(ms.size()==k){
                    std::multiset<ll>::iterator u=ms.begin();
                    if(u!=ms.end() && *u<-v[i].S){
                        s=s-(*u);
                        ms2.insert(*u);
                        c++;
                        ms.erase(u);
                        ms.insert(-v[i].S);
                        s=s-v[i].S;
                    }
                    else{
                        ms2.insert(-v[i].S);
                        c++;
                    }
                    
                }
                else{
                    ms.insert(-v[i].S);
                    s=s-v[i].S;
                }
                ma=max(ma,s);
            }
        }
        cout<<"Case #"<<t1<<": "<<ma<<"\n";
        t1++;

    }  
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

