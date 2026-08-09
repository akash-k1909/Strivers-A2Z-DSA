#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
void solve(){
    int n,s,x;
    cin >>n>>s>>x;
    int c_sum=0;
    int val;
    for (int i = 0;i<n;i++){
        cin>>val;
        c_sum+=val;
    }
    if (s >= c_sum && (s-c_sum) % x==0){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}