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
    cin>>t;
    while(t--)
    {
        
        
        ll a,b,c;
        cin>>a>>b>>c;
        cout<<"Case #"<<t1<<": ";
        ll p=a,q=b,r=c;
        ll sv=0;
        for(ll i=0;i<((ll)(3600*12*(1e9)));i+=((ll)(1e9)))
        {
        a=(p-i+(ll)(3600*12*(1e9)))%((ll)(3600*12*(1e9)));
        b=(q-i+(ll)(3600*12*(1e9)))%((ll)(3600*12*(1e9)));
        c=(r-i+(ll)(3600*12*(1e9)))%((ll)(3600*12*(1e9)));
        
        ll ha=a/(ll)(3600*(1e9));
        ll ma=(a-ha*(ll)(3600*(1e9)))/((ll)(60*(1e9)));
        ll sa=(a-ha*(ll)(3600*(1e9))-ma*(ll)(60*(1e9)))/((ll)(1e9));
        ll na=(a-ha*(ll)(3600*(1e9))-ma*(ll)(60*(1e9))-sa*(ll)(1e9));

        ll hb=b/(ll)(3600*(1e9));
        ll mb=(b-hb*(ll)(3600*(1e9)))/((ll)(60*(1e9)));
        ll sb=(b-hb*(ll)(3600*(1e9))-mb*(ll)(60*(1e9)))/((ll)(1e9));
        ll nb=(b-hb*(ll)(3600*(1e9))-mb*(ll)(60*(1e9))-sb*(ll)(1e9));

        ll hc=c/(ll)(3600*(1e9));
        ll mc=(c-hc*(ll)(3600*(1e9)))/((ll)(60*(1e9)));
        ll sc=(c-hc*(ll)(3600*(1e9))-mc*(ll)(60*(1e9)))/((ll)(1e9));
        ll nc=(c-hc*(ll)(3600*(1e9))-mc*(ll)(60*(1e9))-sc*(ll)(1e9));

        ll da=a/((ll)(72*1e10));
        ll daa=(a-da*(((ll)(72*1e10))))/((ll)(12*1e9));
        ll db=b/((ll)(72*1e10));
        ll dbb=(b-db*(((ll)(72*1e10))))/((ll)(12*1e9));
        ll dc=c/((ll)(72*1e10));
        ll dcc=(c-dc*(((ll)(72*1e10))))/((ll)(12*1e9));

        if(ma==db && sa==dbb && sa==dc)
        {
            cout<<ha<<" "<<ma<<" "<<sa<<" "<<na<<"\n";
            break;
        }
        else if(ma==dc && sa==dcc && sa==db)
        {
            cout<<ha<<" "<<ma<<" "<<sa<<" "<<na<<"\n";
            break;
        }
        else if(mb==dc && sb==dcc && sb==da)
        {
            cout<<hb<<" "<<mb<<" "<<sb<<" "<<nb<<"\n";
            break;
        }
        else if(mb==da && sb==daa && sb==dc)
        {
            cout<<hb<<" "<<mb<<" "<<sb<<" "<<nb<<"\n";
            break;
        }
        else if(mc==da && sc==daa && sc==db)
        {
            cout<<hc<<" "<<mc<<" "<<sc<<" "<<nc<<"\n";
            break;
        }
        else if(mc==db && sc==dbb && sc==da)
        {
            cout<<hc<<" "<<mc<<" "<<sc<<" "<<nc<<"\n";
            break;
        }
        
        }
        t1++;
        
    }  
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/


