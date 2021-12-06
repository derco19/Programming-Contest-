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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll L, ll R)
{
    return uniform_int_distribution<ll>(L, R)(rng);
}
ll d;

bool check(vector<ll> v, ll k, ll larg)
{
    ll n = v.size();
    if (n == 0)
        return true;
    // reverse(all(v));
    if (k < 0)
        return false;
    if (v[n - 1] < larg && k == 0)
        return true;
    map<ll, ll> mp;
    ll ans = 0;
    fr(i, 0, n)
    {
        mp[v[i]]++;
        ans = max(ans, mp[v[i]]);
    }
    // if (ans == 1 && k == 0)
    //     return true;
    if (ans <= k)
    {
        return true;
    }
    return false;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    d = k;
    // n = rand(4, 10);
    // k = rand(1, n);
    // cout << n << " " << k << "\n";
    ll a[n];
    map<ll, ll> mp;
    ll maxi = 0, val;
    fr(i, 0, n)
    {
        cin >> a[i];
        // a[i] = rand(1, 10);
        mp[a[i]]++;
        if (maxi < mp[a[i]])
            maxi = mp[a[i]], val = a[i];
    }
    sort(a, a + n);
    // fr(i, 0, n)
    //         cout
    //     << a[i] << " ";
    // cout << "\n****\n";
    ll res[n], i = 0;
    vi ans;
    if (maxi > k)
    {
        cout << "-1\n";
        return;
    }
    ll m = 0;
    while (m < n)
    {
        auto it = mp.begin();
        vector<ll> c;
        auto tmp = it;
        for (; tmp != mp.end(); tmp++)
        {
            fr(k, 0, tmp->S)
            {
                c.PB(tmp->F);
            }
        }
        fr(j, 0, c.size())
        {
            vi temp;
            fr(l, 0, c.size())
            {
                if (l == j)
                    continue;
                temp.PB(c[l]);
            }
            if ((m > 0 && check(temp, k, a[n - 1]) && ans[m - 1] > c[j]))
            {

                ans.PB(c[j]);
                mp[c[j]]--;
                m++;
                break;
            }
            else if (check(temp, k - 1, a[n - 1]))
            {
                ans.PB(c[j]);
                mp[c[j]]--;
                k--;
                m++;
                break;
            }
        }
    }
    // while (it != mp.end())
    // {
    //     ll ind = it->F;
    //     if (mp[ind] < k)
    //     {
    //         ll j = 0;
    //         while (mp[ind] > 0)
    //         {
    //             // j++;
    //             vector<ll> c;
    //             auto tmp = it;
    //             fr(i, 0, mp[ind] - 1)
    //                 c.PB(tmp->F);
    //             tmp++;
    //             for (; tmp != mp.end(); tmp++)
    //             {
    //                 fr(k, 0, tmp->S)
    //                 {
    //                     c.PB(tmp->F);
    //                 }
    //             }
    //             if (check(c, k - 1))
    //             {
    //                 mp[ind]--;
    //                 k--;
    //                 ans.PB(ind);
    //             }
    //             else
    //                 break;
    //         }
    //         it++;
    //     }
    //     else
    //         it++;
    //     j++;
    // }
    // fr(j, 0, ans.size())
    //         cout
    //     << ans[i] << " ";
    // cout << "\n";
    // rf(i, n - 1, 0)
    // {
    //     while (mp[a[i]] > 0)
    //     {
    //         mp[a[i]]--;
    //         ans.PB(a[i]);
    //     }
    // }
    fr(i, 0, m) cout << ans[i] << " ";
    cout << "\n";
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