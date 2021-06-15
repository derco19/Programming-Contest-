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

    vector <ll> sq;
    vector <ll> adj[200005];
    for(ll i=1;i<200005;i++)
    {
        
        sq.PB(i*i);
        if(i*i>200005)
        continue;
        adj[1].PB(i*i);
    } 
    for(ll i=2;i<200004;i++)
    {
        for(ll j=0;j<sq.size();j++)
        {
            if(sq[j]/i>200004)
            break;
            if(sq[j]/i<i)
            continue;
            if(sq[j]%i==0)
            {
                adj[i].PB(sq[j]/i);
            }
        }
    }
    
    for(ll i=1;i<=10;i++)
    {
        for(auto u:adj[i])
        {
            if(u>100)
            break;
            cout<<u<<" ";
        }
        cout<<"\n";
    }



    ll t=1,t1=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n+1],q;
        vector <pair<ll,ll>> v;
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
            v.PB(MP(q,i+1));
        }
        for(ll i=1;i<=n;i++)
        {
            vector <ll> index,sorter;
            for(auto u:adj[i])
            {
                if(u>n)
                break;
                index.PB(u);
                sorter.PB(a[u]);
            }
            sort(all(sorter));
            ll c=0;
            for(auto u:index)
            {
                a[u]=sorter[c];
                c++;
            }
        }
        ll x=0;
        for(ll i=1;i<n;i++)
        {
            if(a[i]<a[i-1])
            x=1;
        }
        if(x==0)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }  
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

