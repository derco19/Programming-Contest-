#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rf(i, a, b) for (ll i = a; i >= b; i--)
typedef std::vector<long long> vi;
#define F first
#define S second
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mod 1000000007
#define PB push_back
#define MP make_pair
#define PI 3.14159265358979323846
#define all(a) a.begin(), a.end()
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
// const ll INF = LLONG_MAX / 2;
const ll N = 2e5 + 1;
using namespace std;
vi a[26];
int main()
{
    fast;
    ll t = 1;
    // std::cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        fr(i, 0, k)
        {
            fr(j, 0, k)
            {
                a[i].PB(j);
            }
        }
        if(k==1)
        {
            for(ll i=0;i<n;i++)
             cout<<"a";
             cout<<"\n";
             continue;
        }
        string s = "";
        ll j = 0, c = k * (k);
        fr(i, 1, c + 1)
        {
            // if (a[j].size() == 0)
            //     break;
            ll next = a[j].back();
            s = s + (char)('a' + next);
            a[j].pop_back();
            j = next;
            // cout << j << " ";
        }
        // cout << "\n";
        c++;
        for(ll i=0;i<n;i++){
            cout<<s[i/(s.size())];
        }
        cout << "\n";
    }
}