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
    int prime[n+1];
    fill(prime,-1);
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == -1) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = 0; 
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
    // cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll a[n+1]={0};
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n+1);
        pair <ll,ll> dp[n+1][10];
        ll ma[10],ma2[10],co[n+1][10]={0};
        for(ll i=0;i<=9;i++)
        {
            ma[i]=0;
            ma2[i]=0;
        }    
        if(k==0)
        {
            ll x=0,y=0,z=0;
            for(ll i=1;i<=n;i++)
            {
                if(a[i]%2==0)
                x++;
                if(a[i]%10==5)
                y++;
                if(a[i]%10==0)
                z++;
            }
            if(z>0 || (x>0 && y>0))
            {
                cout<<n<<"\n";
                for(ll i=1;i<=n;i++)
                cout<<a[i]<<" ";
                cout<<"\n";
                continue;
            }
        }
        fill(dp,-1);
        for(ll i=1;i<=n;i++)
        {
            for(ll j=0;j<10;j++)
            {
                if(dp[i-1][j].F!=-1)
                {
                    if(dp[i][j].F==-1)
                    dp[i][j]=dp[i-1][j];
                }
                if(a[i]%10==j)
                {
                    if(ma[j]<=a[i])
                    {
                        ma2[j]=max(ma2[j],a[i]);
                        dp[i][j].F=i;
                        dp[i][j].S=j;
                        co[i][j]=1;
                    }
                    else if(dp[i-1][j].F==-1)
                    {
                        dp[i][j].F=i;
                        dp[i][j].S=j;
                        ma2[j]=max(ma2[j],a[i]);
                        co[i][j]=1;
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j];
                        co[i][j]=0;
                    }
                }    
                    ll p=((a[i]%10)*j)%10;
                    if(dp[i-1][j].F==-1)
                    {
                        continue;
                    }
                    else
                    {
                        ll ma1=ma[j]*a[i];
                        if(ma[p]<=ma1)
                        {
                            if(ma[j]>1000)
                            ma2[p]=1001;
                            else
                            ma2[p]=max(ma1,ma2[p]);
                            if(co[i-1][j]==1)
                            {
                                dp[i][p].F=i-1;
                                dp[i][p].S=j;
                            }    
                            else
                            {
                                dp[i][p].F=dp[i-1][j].F;
                                dp[i][p].S=dp[i-1][j].S;
                            }    
                            co[i][p]=1;
                        }
                        else
                        {
                            dp[i][p]=dp[i-1][p];
                            co[i][p]=0;
                        }
                    }
            }
            for(ll i=0;i<10;i++)
            {
                ma[i]=ma2[i];
                ma2[i]=0;
            }
            
        }
        // for(ll i=1;i<=n;i++)
        // {
        //     for(ll j=0;j<10;j++)
        //     cout<<dp[i][j].F<<" ";
        //     cout<<"\n";
        // }
        if(dp[n][k].F==-1)
        {
            cout<<-1<<"\n";
            continue;
        }
        vector <ll> ans;
        if(co[n][k]>0)
        ans.PB(a[n]);
        ll i=n;
        while(dp[i][k].F!=i)
        {
            ll ti=i;
            i=dp[ti][k].F;
            k=dp[ti][k].S;
            if(co[i][k]>0)
            ans.PB(a[i]);
        }
        cout<<ans.size()<<"\n";
        for(auto u:ans)
        cout<<u<<" ";
        cout<<"\n";
    }  
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

