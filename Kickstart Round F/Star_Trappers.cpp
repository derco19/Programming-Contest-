#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
int main(){
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    stack <ll> s;
    ll ans=0;
    for(ll i=n-1;i>=0;i--){
        while(!s.empty() && a[s.top()]<a[i]){
            s.pop();
        }
        if(!s.empty()){
            if(s.top()-i>k)
            ans++;
        }
        else{
            ans++;
        }
        s.push(i);
    }
    cout<<ans<<"\n";
}