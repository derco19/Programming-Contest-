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


    ll combine(ll a, ll b){
        return a+b;
    }

    void build(ll v, ll tl, ll tr,vector <ll>&  t,vector <ll> &A) {
        if (tl == tr) {
            t[v] = A[tl];
        } else {
            ll tm = (tl + tr) / 2;
            build(v*2, tl, tm , t ,A);
            build(v*2+1, tm+1, tr,t,A);
            t[v] = combine(t[v*2],t[v*2+1]);
        }
    }

    ll query(ll v, ll tl, ll tr, ll l, ll r,vector <ll>&  t,vector <ll> &A) {
        if (l > r) 
            return 0;
            
        if (l == tl && r == tr) {
            return t[v];
        }
        ll tm = (tl + tr) / 2;
        return combine(query(v*2, tl, tm, l, min(r, tm),t,A)
               ,query(v*2+1, tm+1, tr, max(l, tm+1), r,t,A));
    }

    void update(ll v, ll tl, ll tr, ll pos, ll new_val,vector <ll>&  t,vector <ll> &A) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            ll tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val,t,A);
            else
                update(v*2+1, tm+1, tr, pos, new_val,t,A);
            t[v] = combine(t[v*2],t[v*2+1]);
        }
    }





int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  

    // freopen("ladder.in", "r", stdin);   // name of input file
	// freopen("ladder.out", "w", stdout); // name of output file

    // ifstream fin("art.in");
    // ofstream fout("art.out");
    
    // fstream file, output;
	// file.open(R"()", ios::in);        // add the address of local input file
	// output.open(R"()", ios::out);  // add the address of local output file
    


    ll t=1;
    cin>>t;
    while(t--)
    {
        vector <ll> a(1000006,0);
        vector <ll> b(1000006,0);
        vector <ll> t1(4000006,0);
        vector <ll> t2(4000006,0);
        ll n;
        cin>>n;
        while(n--)
        {
        ll x,y,v;
        cin>>x>>y>>v;
        x+=500001;
        y+=500001;
        a[x]+=v;
        b[y]+=v;
        update(1,1,1000001,x,a[x],t1,a);
        update(1,1,1000001,y,b[y],t2,b);
        ll a1=query(1,1,1000001,1,x-1,t1,a);
        ll a2=query(1,1,1000001,x,1000001,t1,a);
        ll b1=query(1,1,1000001,1,y-1,t2,b);
        ll b2=query(1,1,1000001,y,1000001,t2,b);
        ll ans1=(b2+a2-b1-a1)/2;
        // for(ll i=1;i<4000006;i++)
        // {
        //     if(t1[i]==2)
        //     {
        //         cout<<i<<"\n";
        //     }
        // }
        cout<<ans1<<"\n";
        }


    }  
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

