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

ll func1(ll x){
    if(x==0)
        return 1;
    ll k=x,ct=0;
    while(k){
        k/=2;
        ct++;
    }
    if(1<<(ct-1)==x)
        return x-1;
    return (1<<(ct))-x-1;
}
int main()
{
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
    map<ll,ll> mat;
    string s,st1;
    cin>>s>>st1;
    ll vec1=0,vec2=0;
    for(auto it:s){
        vec1*=2;
        vec1+=it-'0';
    }
    for(auto it:st1){
        vec2*=2;
        vec2+=it-'0';
    }
    if(vec1==vec2){
        cout<<"Case #"<<t1<<": 0";
        cout<<"\n";
        t1++;
        continue;
    }
    queue<pair<ll,ll>> q;
    q.push({vec1,0});
    while(!q.empty()){
        pair<ll,ll> y=q.front();
        q.pop();
        if(mat[y.first]!=0ll && mat[y.first]<y.second)
            continue;
        if(y.first>(1<<16))
            continue;
        if(mat[vec2]!=0 && mat[vec2]<y.second)
            continue;
        mat[y.first]=y.second;
        q.push({y.first*2,y.second+1});
        q.push({func1(y.first),y.second+1});
    }
    if(mat[vec2]!=0)
        cout<<"Case #"<<t1<<": "<<mat[vec2];
    else
        cout<<"Case #"<<t1<<": IMPOSSIBLE";
    cout<<"\n";
    t1++;
    }
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/