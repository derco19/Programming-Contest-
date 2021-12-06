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
        string s;
        cin>>s;
        ll a[26]={0},p=-1;
        for(ll i=0;i<s.size();i++){
            a[(ll)(s[i]-'a')]++;
            if(a[(ll)(s[i]-'a')]>0 && p==-1) {
                p=(ll)(s[i]-'a');
            }
        }

        for(ll i=0;i<26;i++){
            if((a[i]<a[p] || (a[i]==a[p] && p>i)) && a[i]!=0)
            p=i;
        }

        sort(all(s));

        vector <char> ans;
        ans.PB((char)(p+'a'));
        a[p]-=1;
        for(ll i=1;i<s.size();i++){
            ll x=0;
            for(ll j=0;j<26;j++){
                if(a[j]>0){
                if(j==p && a[j]>0 && x%2==0){
                    ans.PB((char)(j+'a'));
                    a[j]--;
                    x++;
                    break;
                }
                else if(j!=p && a[j]>0){
                    ans.PB((char)(j+'a'));
                    a[j]--;
                    break;
                }
                else{
                    x++;
                    ll x1=0;
                    for(ll k=j+1;k<26;k++){
                        if(a[k]>0){
                            ans.PB((char)(k+'a'));
                            a[k]--;
                            x1=1;
                            break;
                        }
                    }
                    if(x1==1)
                    continue;
                    ans.PB((char)(j+'a'));
                    a[j]--;
                }
                break;
                }
            }
        }
        for(auto u:ans)
        cout<<u;
        cout<<"\n";
        
    }  
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

