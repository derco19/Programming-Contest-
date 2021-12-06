// C++ program to print print all primes smaller than
// n using segmented sieve
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

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



void simpleSieve(ll limit, vector<ll> &prime)
{
	
	vector<bool> mark(limit + 1, true);

	for (ll p=2; p*p<limit; p++)
	{
		if (mark[p] == true)
		{
			for (ll i=p*p; i<limit; i+=p)
				mark[i] = false;
		}
	}
	for (ll p=2; p<limit; p++)
	{
		if (mark[p] == true)
		{
			prime.push_back(p);
		}
	}
}

vector <ll> v;
ll n1;

ll check()
{
    ll p=0;
    for(ll i=1;i<v.size()-1;i++)
    {
        p=i+1;
        if(v[i]*v[i+1]>n1)
        break;
    }
    return p;
}

void segmentedSieve(ll n)
{
	
	ll limit = floor(sqrt(n))+1;
	vector<ll> prime;
	prime.reserve(limit);
	simpleSieve(limit, prime);
    v.PB(-1);

    
    ll p1=floor(sqrt(n1))+1;

	ll low = max(p1-limit/2,1LL);
	ll high = p1+limit/2;

		
		
		bool mark[high-low+1];
		memset(mark, true, sizeof(mark));

		// Use the found primes by simpleSieve() to find
		// primes in current range
		for (ll i = 0; i < prime.size(); i++)
		{
			// Find the minimum number in [low..high] that is
			// a multiple of prime[i] (divisible by prime[i])
			// For example, if low is 31 and prime[i] is 3,
			// we start with 33.
			ll loLim = floor(low/prime[i]) * prime[i];
			if (loLim < low)
				loLim += prime[i];

			/* Mark multiples of prime[i] in [low..high]:
				We are marking j - low for j, i.e. each number
				in range [low, high] is mapped to [0, high-low]
				so if range is [50, 100] marking 50 corresponds
				to marking 0, marking 51 corresponds to 1 and
				so on. In this way we need to allocate space only
				for range */
			for (ll j=loLim; j<high; j+=prime[i])
				mark[j-low] = false;
		}
        
		// Numbers which are not marked as false are prime

        for (int i = low; i<high; i++)
            if (mark[i - low] == true)
               { v.PB(i);}
        for(auto u:v)
        cout<<u<<"\n";
        ll s=check();
            cout<<v[s-1]*v[s-2];
            return ;

		// Update low and high for next segment
		low = low + limit;
		high = high + limit;
}

// Driver program to test above function
int main()
{
	ll n = 1000000000;
    ll t=1,t1=1;
    cin>>t;
    while(t--)
    {
        v.clear();
        cout<<"Case #"<<t1<<": ";

        cin>>n1;
        segmentedSieve(n);


        cout<<"\n";
        t1++;
    } 
}
