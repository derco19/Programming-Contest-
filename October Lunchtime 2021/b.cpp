#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


ll maxSquare(vector <ll> h){
    stack <int> s;
    ll i=0;
    ll ma=0;
    while(i<h.size()){
        while(!s.empty() && h[i]<h[s.top()]){

            ll idx=s.top();
            s.pop();
            ll width=s.empty() ? i: i-s.top()-1;
            ll edge=min(width,h[idx]);
            ma = max(ma,edge*edge);
        }
        s.push(i++);
    }
    while(!s.empty()){

        ll idx=s.top();
        s.pop();
        ll width=s.empty() ? i : i-s.top()-1;
        ll edge=min(width,h[idx]);
        ma=max(ma,edge*edge);

    }
    return ma;
}

int main(){
    cout<<maxSquare({1,2,3,2,1});
}