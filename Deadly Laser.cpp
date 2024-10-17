#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define pivalue 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define per(i,n,a) for(int i=n;i>=a;--i)
#define all(x) (x).begin(), (x).end()
#define allrev(x) (x).rbegin(), (x).rend()
#define fast_io() ios_base::sync_with_stdio(false),cin.tie(0);
#define ar array
#define ff 
#define ss second
#define printvec(v) for(auto &it: v) cout<<it<<" ";
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define ppb pop_back
const int INF= INT_MAX;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef array<ll,3> tri;
#define google(i,x)  cout<<"Case #"<<i<<": "<<x<<endl
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const int m= 1e9+7;
const int p = 31;
const int m1 = 1e9 + 9;
const int p1=29;
#define eps 1e-6
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

vi dtob(int n){
    vi a;
    while(n!= 0){
        a.push_back(n%2);
        n/= 2;
    }
    return a;
}
int digsum(int x){
    int sum=0;
    while(x != 0){
        sum+= x%10;
        x/=10;
    }
    return sum;
}
bool isPalindrome(string &s, int n){
    int i=0, j=s.size()-1;
    while(i<j) if(s[i++] != s[j--]) return false;
    return true;
}

vector<int> p11;
vector<int> vis(20,0);
ll ans= 1e18;

void f(int ind, vector<int> &a,ll totalsum){
   if(ind >= a.size()){
       ll sum1=0;
       for(auto &it: p11)
         sum1+= it;
        ans= min(ans,max(sum1,totalsum-sum1));
        return;
   }
   p11.push_back(a[ind]);
   f(ind+1,a,totalsum);
   p11.pop_back();
   f(ind+1,a,totalsum);
   
}

const int Mod= 1e9+7;

void solve(){
   ll n,m,sx,sy,d;
   cin>>n>>m>>sx>>sy>>d;

   ll minDis= n+m-2;
   bool possible1= true;
   bool possible2= true;
   
   ll top= sx-d;
   ll right= sy+d;

   if(top <= 1 or right >= m)
      possible1= false;

   ll left= sy-d;
   ll bottom= sx+d;

   if(left <= 1 or bottom >= n)
      possible2= false;
   
   if(possible1 or possible2)
      cout<<minDis<<endl;

   else
      cout<<-1<<endl;
}
int main()
{ 
   int t=1;
   cin>>t;
   while(t--)
       solve();
}
