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

    // freopen("ladder.in", "r", stdin);   // name of input file
	// freopen("ladder.out", "w", stdout); // name of output file

    // ifstream fin("art.in");
    // ofstream fout("art.out");
    
    // fstream file, output;
	// file.open(R"()", ios::in);        // add the address of local input file
	// output.open(R"()", ios::out);  // add the address of local output file
    


    ll t=1,t1=1;
    cin>>t;
    while(t--)
    {
        cout<<"Case #"<<t1<<": ";
        ll n,m;
        cin>>n>>m;
        ll p,q;
        vector <pair<ll,ll>> vp;
        for(ll i=0;i<n;i++){
            cin>>p>>q;
            if(p!=q){
                vp.PB({p,1});
                vp.PB({q,-1});
            }        
        }    
        sort(all(vp));
        ll c=0;
        vector <pair<ll,ll>> vpp;
        for(ll i=0;i<vp.size()-1;i++){
            if(vp[i].S==-1)
            c--;
            if(vp[i].F==vp[i+1].F){
                if(i>0 && vp[i-1].F!=vp[i].F && vp[i].S==1)
                vpp.PB({c,1});
                if(vp[i].S!=vp[i+1].S)
                vpp.PB({c,1});
            }
            else if(i>0 && vp[i-1].F!=vp[i].F){
                vpp.PB({c,1});
            }
            else if(i>0 && vp[i-1].F==vp[i].F && vp[i].S==-1)
            vpp.PB({c,1});
            if(vp[i].S==1)
            c++;
            if(vp[i].F+2<=vp[i+1].F){
                vpp.PB({c,vp[i+1].F-vp[i].F-1});
            }
        }
        sort(all(vpp));
        ll ans=n;
        for(ll i=vpp.size()-1;i>=0;i--){
            if(m>vpp[i].S){
                m-=vpp[i].S;
                ans=ans+vpp[i].F*vpp[i].S;
            }
            else{
                ans=ans+vpp[i].F*m;
                break;
            }
        }
        
        cout<<ans;
        

        cout<<"\n";
        t1++;
    }  
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

