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
        set <ll> v[k+1];
        ll p,q;
        map <ll,ll> m;
        ll r;
        set <ll> s2;
        for(ll i=1;i<=k;i++)
        {
            cin>>p;
            for(ll j=0;j<p;j++)
            {
                cin>>q;
                v[i].insert(q);
                m[q]++;
                if(m[q]>=(k+1)/2)
                {
                    s2.insert(q);
                }
            }
        }
        ll a[k+1]={0};
        ll c=0;
        while(true)
        {
            fill(a,0);
            if(s2.empty())
            break;
            r=*(s2.begin());
            
            for(ll i=1;i<=k;i++)
            {
                if(v[i].size()==1)
                {
                    if(binary_search(all(v[i]),r))
                    {
                        a[i]=r;
                        c++;
                    }
                }
            }
            if(c>(k+1)/2)
            {
                s2.erase(r);
                continue;
            }   
            else
            break;
        }
        ll x=0;
        for(ll i=1;i<=k;i++)
        {
            if(a[i]==0)
            {
                if(c<(k+1)/2)
                {
                    if(binary_search(all(v[i]),r))
                    {
                        a[i]=r;
                        c++;
                    }
                    else
                    {
                        a[i]=*(v[i].begin());
                    }
                }
                else
                {
                    if(v[i].size()==1 && *(v[i].begin())==r)
                    x=1;
                    else
                    {
                        if(binary_search(all(v[i]),r));
                        v[i].erase(r);
                        a[i]=*(v[i].begin());
                    }    
                }
            }
        }
        if(x==0)
        {
            cout<<"YES\n";
            for(ll i=1;i<=k;i++)
            cout<<a[i]<<" ";
            cout<<"\n";
        }
        else
        no
        

    }
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/
