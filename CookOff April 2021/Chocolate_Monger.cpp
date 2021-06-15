#include <iostream>
#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	ll n,k,p;
        cin>>n>>k;
        set <ll> s;
        for(ll i=0;i<n;i++)
        {
            cin>>p;
            s.insert(p);
        }
        ll q=s.size();
        if(n-k>=q)
        cout<<q<<"\n";
        else
        cout<<n-k<<"\n";
	    
	}
	return 0;
}