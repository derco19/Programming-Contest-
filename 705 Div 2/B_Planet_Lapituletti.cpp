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
        ll h,m,h1,m1;
        cin>>h>>m;
        string s;
        cin>>s;
        ll c=0,p,q,x=0,y1,z1;
        ll a[]={1,2,5,8,0};
        while(true)
        {
            if(c==0)
            {
                h1=(ll)(s[0]-48)*10+(ll)(s[1]-48);
                m1=(ll)(s[3]-48)*10+(ll)(s[4]-48);
            }
            else
            {
                h1=0;m1=0;
            }    
            for(ll i=h1;i<h;i++)
            {
                if(i!=h1)
                m1=0;
                for(ll j=m1;j<m;j++)
                {
                    ll r=0;
                    for(ll k=0;k<5;k++)
                    {
                        if(i%10==a[k])
                        {r++; break;}
                    }
                    for(ll k=0;k<5;k++)
                    {
                        if((i/10)%10==a[k])
                        {r++; break;}
                    }
                    for(ll k=0;k<5;k++)
                    {
                        if(j%10==a[k])
                        {r++; break;}
                    }
                    for(ll k=0;k<5;k++)
                    {
                        if((j/10)%10==a[k])
                        {r++; break;}
                    }
                    if(r==4)
                    {
                        p=i;
                        q=j;
                        if(p<10)
                        {
                            if(p==5)
                            p=2;
                            else if(p==2)
                            p=5;
                            p=p*10;
                        }    
                        else
                        {
                            ll r1=p%10;
                            if(r1==5)
                            r1=2;
                            else if(r1==2)
                            r1=5;
                            p=p/10;
                            if(p==5)
                            p=2;
                            else if(p==2)
                            p=5;
                            p=p+r1*10;
                        }
                        if(q<10)
                        {
                            if(q==5)
                            q=2;
                            else if(q==2)
                            q=5;
                            q=q*10;
                        }    
                        else
                        {
                            ll r1=q%10;
                            if(r1==5)
                            r1=2;
                            else if(r1==2)
                            r1=5;
                            q=q/10;
                            if(q==5)
                            q=2;
                            else if(q==2)
                            q=5;
                            q=q+r1*10;
                        }
                        if(q<h && p<m)
                        {
                            y1=i;
                            z1=j;
                            x=1;
                            break;
                        }
                    }
                }
                if(x==1)
                break;
            }
            if(x==1)
            break;
            c++;
        }
        string ans="";
        if(y1<10)
        {
            ans='0'+to_string(y1)+':';
        }    
        else
        {
            ans=ans+to_string(y1)+':';
        }
        if(z1<10)
        {
            ans=ans+'0'+to_string(z1);
        }    
        else
        {
            ans=ans+to_string(z1);
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

