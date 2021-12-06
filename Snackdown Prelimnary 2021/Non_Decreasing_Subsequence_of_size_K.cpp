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

vector <pair<ll,ll>> ans;
0 0
2 1
2 2
void frame(ll nu,ll ti,ll k){
    if(ans.size()==0){
        ans.PB({0,0});
        for(int i=0;i<ti;i++){
            ans.PB({nu,i+1});
        }
        return;
    }
    vector <pair<ll,ll>> temp=ans;
    for(ll i=1;i<temp.size();i++){
        if(temp[i].S+ti>k){
            temp.insert(temp.begin()+i,{nu,temp[i-1].S+1});
            ti--;
        }
        if(ti==0)
        break;
    }
    for(ll i=0;i<ti;i++){
        temp.push_back({nu,temp.back().S+1});
    }
    ans=temp;

}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  


    // freopen("input.txt", "r", stdin);   // name of input file
	// freopen("output.txt", "w", stdout); // name of output file
    
    // fstream file, output;
	// file.open(R"(input.txt)", ios::in);        // add the address of local input file
	// output.open(R"(output.txt)", ios::out);  // add the address of local output file
    
    ll t,t1=1;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll a[n];
        ans.clear();
        vector <ll> b(201,0);
        for(ll i=0;i<n;i++){
            cin>>a[i];
            b[a[i]]++;
        }
        ll x=0;
        for(ll i=1;i<=200;i++){
            if(b[i]>k){
                cout<<"-1\n";
                x=1;
                break;
            }
            if(b[i]>0)
            frame(i,b[i],k);
        }
        if(x==0){
            for(ll i=1;i<ans.size();i++)
            cout<<ans[i].F<<" ";
            cout<<"\n";
        }
        
    }

    
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

