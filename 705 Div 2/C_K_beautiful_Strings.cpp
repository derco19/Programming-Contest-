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
ll n,m;
string ans="";
ll a[100005],ab[27];
string s;


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
    for(ll z=0;z<t;z++)
    {
        
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        if(n%k!=0)
        {
            cout<<"-1\n";
            continue;
        }
        ll a[26]={0};
        for(ll i=0;i<n;i++)
        {
            a[(ll)(s[i]-'a')]++;
        }
        ll st=0,y1=0;
        for(ll j=0;j<26;j++)
        {
            st=(k-a[j]%k)%k;
            if(st%k!=0)
            y1=1;
        }
        if(y1==0)
        {cout<<s<<"\n";
        continue;}
        for(ll i=n-1;i>=0;i--)
        {
            a[(ll)(s[i]-'a')]--;
            ll sum=0;
            vector <ll> v;
            for(ll j=0;j<26;j++)
            {
                sum=sum+(k-a[j]%k)%k;
                v.PB((k-a[j]%k)%k);
            }
            if(sum<=n-i)
            {
                ll y=0,p=i;
                string ans=s;
                y=0;
                for(ll l=0;l<26;l++)
                {
                    if(v[l]>0 && ans[i]<(char)('a'+l))
                    {
                        y=2;
                        break;
                    }
                }         
                if(y==2)
                {
                    ll sum2=sum,l1;
                    for(ll l=0;l<26;l++)
                    {
                        if(v[l]>0 && ans[p]+1==(char)('a'+l))
                        {
                            sum--;
                            ans[p]++;
                            v[l]--;
                            y=3;
                            break;
                        }
                        else if(v[l]>0 && ans[p]<(char)('a'+l))
                        {
                            l1=l;
                            y=2;
                            break;
                        }
                    }
                    if(y==2)
                    {
                        if(sum+k-1<=n-(p+1))
                        {
                            y=0;
                        }
                        else
                        {
                            sum--;
                            ans[p]=(char)('a'+l1);
                            v[l1]--;
                        }
                    }
                }
                if(y==0)
                {
                    if(ans[p]=='z')
                    continue;
                    sum=sum+k-1;
                    ans[p]++;
                    v[(ll)(ans[p]-'a')]=k-1;
                    if(sum>n-(p+1))
                    continue;
                }
                p++;
                v[0]=mo;
                for(ll j=n-1;j>=p;j--)
                {
                    for(ll l=25;l>=0;l--)
                    {
                        if(v[l]>0)
                        {ans[j]=(char)('a'+l);
                        v[l]--;
                        break;}
                    }
                }
                cout<<ans<<"\n";
                break;
            }
        }
    }
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

