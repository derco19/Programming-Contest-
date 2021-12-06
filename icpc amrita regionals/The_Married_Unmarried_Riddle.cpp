#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define fr(i,a,b) for(ll i=a; i<b; i++)
#define rf(i,a,b) for(ll i=a; i>=b; i--)
#define PB push_back
#define MP make_pair
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define Pair vector<pair<ll,ll>>
#define vec vector <ll> 
#define ff first
#define ss second
#define pairv vector<pair<ll,ll>>
#define all(a) a.begin(),a.end()
#define mo 1000000007
#define decimal(i,n) fixed << setprecision(i) << n
#define fam(v,i) for(auto i=v.begin();i!=v.end();i++)
#define fai(v,i) for(auto i : v)
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
       string s;
       cin>>s;
       ll x=0;
       for(int i=0;i<s.size();i++){
           if(i<s.size()-2){
               if(s[i]=='M' && s[i+1]=='?' && s[i+2]=='U')
               x=1;
           }
           else if(i<s.size()-1){
               if(s[i]=='M' && s[i+1]=='U')
               x=1;
           }
       }
       if(x==1)
       cout<<"Yes\n";
       else
       cout<<"No\n";
       
    }  
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

