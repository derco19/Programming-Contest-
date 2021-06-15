#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
#include<vector>
#include<string>
#include<cstring>
#include<ctype.h>

using namespace std;


//   <<implemented_sorted_vector>>  new_data_set p;
//   <<insert_like_set>>           insert(key):log(n)
//<<accessing_iterator_by_index>> find_by_order(idx):log(n)
//        <<accessing_by_value>>   order_of_key(key):log(n)
// << replace less<int> by greater<int> for descending order>>
// find(key), erase(find(key)) works the same!

typedef long long ll;
typedef long l;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ERR(x) cout<<#x<<"="<<x<<endl
#define ERR2(x,y) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define show(v) for(auto e: v) cout<<e<<" ";
#define showArr(A,n) for(int i=0;i<n;i++) cout<<A[i]<<" ";
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define mp make_pair
#define ff first
#define ss second
#define unique(A) sort(A.begin(), A.end()); A.resize(unique(A.begin(), A.end()) - A.begin());
#define umpit unordered_map<ll,ll>::iterator
#define mpit map<ll,ll>::iterator
#define setit set<ll>::iterator
#define all(v) v.begin(),v.end()
/**
 * All divisors of 1 to n
   vector<int> divisors(n + 1);
   for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
     divisors[j].push_back(i);
    }
  }
**/
void primeFactors(ll n)
{
    vector<ll>temp;
    while (n % 2 == 0)
    {
        temp.pb(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            temp.pb(i);
            n = n/i;
        }
    }
    if (n > 2)
        temp.pb(n);

    //do what you want with vector<ll>
}

vector<ll> divisors(ll x)//O( sqrt(n) )
{
    vector<ll>divs;
    for(int i=1;i*i<=x;i++)
    {
        if(x%i == 0)
        {
            if(i*i == x)
            {
                divs.pb(i);
            }
            else
            {
                divs.pb(i);
                divs.pb(x/i);
            }
        }
    }
    return divs;
}//sort if you want

/**
 *lcm and gcd are distributive*
 * use __gcd(x,y)
 **/


int main()
{
    

    int t;
    cin >> t;
    int Case = 0;
    while(t--)
    {
        ll n,m; cin >> n >> m;
        vector<ll>p(m);
        FOR(i,0,m) {
            cin >> p[i];
        }
        ll gcd = p[0];
        FOR(i,1,m){
            gcd = __gcd(gcd, p[i]);
        }
        // find greatest divisor < n
        auto gd = [&](ll x){
            vector<ll>divs = divisors(x);
            sort(all(divs));
            auto item = upper_bound(all(divs), n);
            item--;
            cout<<*item<<"\n";
            return *item;
        };
        cout << n - gd(gcd) << "\n";
    }
    return 0;
}
