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



void func(vector<vector<ll>> &a,vector<pair<ll,ll>> &v,ll p,ll q,ll n,ll k,ll i){
    ll m1=p,m2=p;
    if(a[p][i]!=a[p][q]){
        v[i].F=p;
        v[i].S=p;
        return;
    }
    for(ll j=p-1;j>p-k && j>0;j--){
        if(a[j][i]==a[j+1][i])
        m1--;
        else
        break;
    }
    for(ll j=p+1;j<p+k && j<=n;j++){
        if(a[j][i]==a[j-1][i])
        m2++;
        else
        break;
    }
    v[i].F=m1;
    v[i].S=m2;
    return;
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
        ll n,m,k;
        cin>>n>>m>>k;
        vector <vector<ll>> a(n+1,vector<ll>(m+1,0));
        ll t1=n*m,p,q,co=0,x=0,y2=0;
        vector<pair<ll,ll>> v(m+1);
        while(t1--){
            cin>>p>>q;
            if(y2==1)
                continue;
            if(co%2==0){
                a[p][q]=1;
            }
            else{
                a[p][q]=2;
            }
            
            ll m1=p,m2=p;
            func(a,v,p,q,n,k,q);

            for(ll i=q-1;i>q-k && i>0;i--){
                func(a,v,p,q,n,k,i);
                v[i].F=max(v[i+1].F,v[i].F);
                v[i].S=min(v[i+1].S,v[i].S);
            }
            for(ll i=q+1;i<q+k && i<=m;i++){
                func(a,v,p,q,n,k,i);
                v[i].F=max(v[i-1].F,v[i].F);
                v[i].S=min(v[i-1].S,v[i].S);
            }
            ll z1=max(q-k+1,1LL);
            x=0;
            for(int i=z1;i<=q;i++){
                if(i+k-1<=m){
                    ll x1=max(v[i].F,v[i+k-1].F);
                    ll x2=min(v[i].S,v[i+k-1].S);
                    if(x2-x1+1>=k){
                        if(co%2==0){
                            cout<<"Alice\n";
                            x=1;
                            break;
                        }
                        else{
                            cout<<"Bob\n";
                            x=1;
                            break;
                        }
                        
                    }
                }
            }
            if(x==1){
                y2=1;
            }
            co++;
        }
        if(y2==0)
        cout<<"Draw\n";
    }  
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

