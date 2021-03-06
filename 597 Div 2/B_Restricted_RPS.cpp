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
        ll n;
        cin>>n;
        ll r,p,s;
        cin>>r>>p>>s;
        string st;
        cin>>st;
        ll r1=0,p1=0,s1=0;
        for(ll i=0;i<n;i++)
        {
            if(st[i]=='P')
            p1++;
            else if(st[i]=='R')
            r1++;
            else
            s1++;
        }
        r1=r1-min(r1,p);
        p1=p1-min(p1,s);
        s1=s1-min(s1,r);
        if(2*(r1+p1+s1)>n)
        cout<<"NO\n";
        else
        {
            string s2=st;
            for(ll i=0;i<n;i++)
            {
                if(st[i]=='R' && p>0)
                {s2[i]='P'; p--;}
                else if(st[i]=='P' && s>0)
                {s2[i]='S'; s--;}
                else if(st[i]=='S' && r>0)
                {
                    s2[i]='R'; r--;
                }
            }
            for(ll i=0;i<n;i++)
            {
                if(st[i]==s2[i])
                {
                    if(r>0)
                    {s2[i]='R'; r--;}
                    else if(p>0)
                    {s2[i]='P'; p--;}
                    else if(s>0)
                    {s2[i]='S'; s--;}
                }
            }
            cout<<"YES\n";
            cout<<s2<<"\n";
        }
    }
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

