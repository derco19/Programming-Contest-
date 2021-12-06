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
const ll INF = LLONG_MAX / 2;
const ll N = 2e5 + 1;
using namespace std;
ll k;
ll xoor(ll a, ll b)
{
    ll c = a, d = b, p = 0;
    if (a < b)
        swap(c, d), swap(a, b);
    while (a > 0 && b > 0)
    {
        ll e = (ll)pow((ll)k, (ll)p), f = a % k, g = b % k;
        c = c - e * f;
        f = (f + g) % k;
        a /= k;
        b /= k;
        c = c + e * f;
        p++;
    }
    return c;
}
void solve()
{
    ll n, i, j = 1;
    std::cin >> n >> k;
    ll flag;
    ll prevxor = 0, d = 0;
    // if (k != 2)
    // {
    //     cout << d << endl;
    //     ll r;
    //     cin >> r;
    //     if (r == 1)
    //         return;
    // }
    // cout<<endl;
    fr(i, 1, n)
    {
        ll c = xoor(prevxor, j);
        cout << c << endl;
        d = xoor(d, c);
        // prevxor = xoor(c, prevxor);
        prevxor = d;
        j++;
        ll r;
        cin >> r;
        if (r == 1)
        {
            cout << endl;
            return;
        }
    }
    if (1)
    {
        cout << d << endl;
        ll r;
        cin >> r;
        cout << endl;
    }
    return;
}
int main()
{
    fast;
    ll _ = 1, counti = 0;
    std::cin >> _;
    while (_--)
    {
        // counti++;
        // cout << "Case #" << counti << ": ";
        solve();
    }
}