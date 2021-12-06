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
       ll n,p,k;
       cin>>n;
       priority_queue <ll> q;
       ll ans=0;
       for(ll i=0;i<n;i++){
           cin>>k;
           vector <ll> v;
           for(ll j=0;j<k;j++){
               cin>>p;
               v.push_back(p);
            }
            vector <ll> temp;
            ll m1=-1;
            for(ll j=0;j<v.size();j++){
                if(v[j]<m1){
                    temp.push_back(j);
                    m1=v[j];
                }    
                else{
                    m1=v[j];
                }
            }
            // cout<<i<<"a\n";
            // for(auto u:temp)
            // cout<<u<<" ";
            // cout<<"\n";
            ll p1=temp.size()-1, s1=0,e1=v.size();
            for(ll j=0;j<=p1;j++){
                if(temp[j]-s1<e1-temp[p1]){
                    q.push(-(temp[j]-s1));
                    ans=ans+temp[j]-s1;
                    s1=temp[j];
                }
                else{
                    q.push(-(e1-temp[p1]));
                    ans=ans+e1-temp[p1];
                    e1=temp[p1]+1;
                    j--;
                    p1--;
                }
            }
       }

        //cout<<q.size()<<"\n";
        ll a12 = ans;
        while(q.size() >1)
        {
            a12 += -1*q.top();
            ll a = q.top();
            q.pop();
            a12+=-1*q.top();
            ll b = q.top();
            q.pop();
            q.push(a+b);
        }
        cout<<a12<<"\n";

    }  
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

