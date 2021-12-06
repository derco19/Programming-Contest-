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

void dfs(int st,map<string,int> &m,vector <vector <int>> &v,vector <int> &visited){
    for(auto u:v[st]){
        if(visited[u]==0){
            visited[u]=1;
            dfs(u,m,v,visited);
        }
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
        ll n,m;
        cin>>n>>m;
        cin.ignore();
        map <string,int> ma;
        int c=1;
        vector <vector <int>> v(201);
        for(int j=0;j<n;j++){
            string s,s1="",s2="";
            getline(cin,s);
            // cout<<s<<"\n";
            for(int i=0;i<s.size();i++){
                if(s[i]==' ')
                break;
                s1=s1+s[i];
            }
            for(int i=s.size()-1;i>=0;i--){
                if(s[i]==' ')
                break;
                s2=s[i]+s2;
            }
            // cout<<s2<<" "<<s1<<"\n";
            if(ma[s2]==0){
                ma[s2]=c;
                c++;
            }   
            if(ma[s1]==0){
                ma[s1]=c;
                c++;
            } 
            //cout<<ma[s2]<<" "<<ma[s1]<<"\n";
            v[ma[s2]].PB(ma[s1]);
        }
        
        for(int j=0;j<m;j++){
            string s,s1="",s2="";
            getline(cin,s);
            //cin.ignore();
            for(int i=0;i<s.size();i++){
                if(s[i]==' ')
                break;
                s1=s1+s[i];
            }
            for(int i=s.size()-1;i>=0;i--){
                if(s[i]==' ')
                break;
                s2=s[i]+s2;
            }
            if(ma[s2]==0 || ma[s1]==0){
                cout<<"Pants on Fire\n";
                continue;
            }
            int x1=0;
            // cout<<s1<<" "<<s2<<"\n";
            vector <int> visited(2001,0);
            visited[ma[s2]]=1;
            dfs(ma[s2],ma,v,visited);
            if(visited[ma[s1]]==1){
                cout<<"Fact\n";
                x1=1;
                continue;
            }  
            if(x1==1)
            continue;  
            for(auto &u:visited)
            u=0;
            visited[ma[s1]]=1;
            dfs(ma[s1],ma,v,visited);
            if(visited[ma[s2]]==1){
                cout<<"Alternative Fact\n";
                x1=1;
                continue;
            }
            cout<<"Pants on Fire\n";

        }

    }  
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

