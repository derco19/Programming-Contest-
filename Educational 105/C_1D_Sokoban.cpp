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

void Sieve(int n) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p=2; p<=n; p++) 
    {
        
    }       
}

ll count(vector <ll> vecb,vector <ll> vecs)
{
    vector <ll> psum;
    psum.PB(0);
    ll n=vecb.size();
    for(ll i=0;i<vecb.size();i++)
    {
        if(binary_search(all(vecs),vecb[i]))
        {psum.PB(psum[i]+1);}
        else
        psum.PB(psum[i]);
    }
    ll ma=psum[n];
    ll c=0,r,p=0;
    for(ll i=0;i<vecb.size();i++)
    {
        c++;
        r=vecb[i];
        p=lower_bound(all(vecs),vecb[i])-vecs.begin();
        for(ll j=p;j<vecs.size();j++)
        {
            if(i<n-1)
            {
            if(vecs[j]<vecb[i+1])
            {
                ll q=lower_bound(all(vecs),vecs[j]-c+1)-vecs.begin();
                ll temp=j-q+1+psum[n]-psum[i+1];
                ma=max(temp,ma);
            }
            else
            {
                break;
            }
            }
            else
            {
                ll q=lower_bound(all(vecs),vecs[j]-c+1)-vecs.begin();
                ll temp=j-q+1+psum[n]-psum[i+1];
                ma=max(temp,ma);
                continue;
            }
        }
    }
    return ma;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  

    // freopen("div7.in", "r", stdin);   // name of input file
	// freopen("div7.out", "w", stdout); // name of output file

    // ifstream fin("art.in");
    // ofstream fout("art.out");
    
    // fstream file, output;
	// file.open(R"()", ios::in);        // add the address of local input file
	// output.open(R"()", ios::out);  // add the address of local output file
      
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector <ll> negb,posb,negs,poss;
        ll b[n],sp[m];
        for(ll i=0;i<n;i++)
        {
            cin>>b[i];
            if(b[i]<0)
            negb.PB(-1*b[i]);
            else
            posb.PB(b[i]);
        }
        sort(all(negb));
        for(ll i=0;i<m;i++)
        {
            cin>>sp[i];
            if(sp[i]<0)
            negs.PB(-1*sp[i]);
            else
            poss.PB(sp[i]);
        }
        sort(all(negs));
        cout<<count(posb,poss)+count(negb,negs)<<"\n";
    }
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

