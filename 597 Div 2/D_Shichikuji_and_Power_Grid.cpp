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
    // cin>>t;
    while(t--)
    {
       ll n;
       cin>>n;
       vector <pair<ll,ll>> coordinates;
       ll p,q,m1=mo,c1=0;
       for(ll i=0;i<n;i++)
       {
           cin>>p>>q;
           coordinates.PB(MP(p,q));
       } 
       vector <ll> cost,km;
       for(ll i=0;i<n;i++)
       {
           cin>>p;
           cost.PB(p);
       }
       for(ll i=0;i<n;i++)
       {
           cin>>p;
           km.PB(p);
       }
       ll p_city=0,total_sum=0;
       pair<ll,ll> min_per_city[n];
       vector <ll> pg;
       fill(min_per_city,0);
       ll po[n]={0},p1,x=0;
       for(ll i=0;i<n;i++)
       {
           m1=mo,p1=0;
           for(ll j=0;j<n;j++)
           {
               if(m1>cost[j] && po[j]==0)
               {
                   m1=cost[j];
                   p1=j;
               }
           }
           po[p1]=1;
           x++;
           p=cost[i];
           if(min_per_city[p1].F==0)
           {
           min_per_city[p1].S=p1+1;
           min_per_city[p1].F=m1;
           }
           else
           {
               if(min_per_city[p1].F>m1)
               {
                   min_per_city[p1].S=p1+1;
                   min_per_city[p1].F=m1;
               }
           }
           for(ll j=0;j<n;j++)
           {
               if(j==p1 || po[j]==1)
               continue;
               else{
                   ll imcost=((abs(coordinates[p1].F-coordinates[j].F)+abs(coordinates[p1].F-coordinates[j].F))*(km[p1]+km[j]));
                   if(imcost<min_per_city[j].F || min_per_city[j].F==0)
                   {
                       min_per_city[j].F=imcost;
                       min_per_city[j].S=p1+1;
                   }
               }
           }
       }
       vector <pair<ll,ll>> v12;
       for(ll i=0;i<n;i++)
       {
           total_sum+=min_per_city[i].F;
           if(min_per_city[i].S==i+1)
           {
               pg.PB(i+1);
           }
           else
           {
               v12.PB(MP(min_per_city[i].S,i+1));
           }
       }
       cout<<total_sum<<"\n";
       cout<<pg.size()<<"\n";
       for(auto u:pg)
       cout<<u<<" ";
       cout<<"\n";
       cout<<v12.size()<<"\n";
       for(auto u: v12)
       {
           cout<<u.F<<" "<<u.S<<"\n";
       }
    }
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

