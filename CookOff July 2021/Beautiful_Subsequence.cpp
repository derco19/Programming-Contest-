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
        ll n,k;
        cin>>n>>k;
        vector <vector <ll>> v(n+1,vector <ll> (k+1,0));
        vector <vector <ll>> prev(n+1,vector <ll> (k+1,0));
        vector <ll> v1(n+1,-1),v2(n+1,-1);
        ll a[n+1];
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        for(ll i=1;i<=n;i++){
            for(ll j=i-1;j>=1;j--){
                if(a[j]!=a[i]){
                    v1[i]=j;
                    break;
                }    
            }
        }
        for(ll i=1;i<=n;i++){
            for(ll j=i-1;j>=1;j--){
                if(a[j]==a[i]){
                    v2[i]=j;
                    break;
                }    
            }
        }
        ll ans=0;
        for(ll i=1;i<=n;i++){
            v[i][0]=1;
            if(v2[i]!=-1)
            v[i][0]=v[v2[i]][0]+1;
            prev[i][0]=max(v[i][0],prev[i-1][0]);
            for(ll j=1;j<=k;j++){
                if(i==1)
                continue;
                v[i][j]=prev[i-1][j-1]+1;
                if(v2[i]!=-1){
                    v[i][j]=max(v[i][j],v[v2[i]][j]+1);
                }
                if(i>1){
                    prev[i][j]=max(v[i][j],prev[i-1][j]);
                }
                else{
                    prev[i][j]=v[i][j];
                }
                ans=max(ans,v[i][j]);
            }
        }
        for(ll i=1;i<=n;i++)
        for(ll j=0;j<=k;j++){
            ans=max(ans,v[i][j]);
        }
        
        cout<<ans<<"\n";


    }  
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

