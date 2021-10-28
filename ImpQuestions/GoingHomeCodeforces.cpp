//created by Shivam Varshney
//Going TO Home --- Good Quesion
#include<bits/stdc++.h>
#pragma GCC optimise("Ofast")
#pragma GCC target("avx","avx2","fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define int long long

#define pi pair<int,int>

#define ff first
#define ss second

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << "\n";
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



void solve(){
   int n;
   cin>>n;
   vector<pi> v(n);
   for(int i = 0 ; i < n ; i++){
       cin>>v[i].ff;
       v[i].ss = i+1;
   }

   sort(v.begin(),v.end());
   debug(v);
   map<int,pi> Map;
   for(int i = 1 ; i < n ; i++){
        int diff = abs(v[i].ff-v[i-1].ff);
        debug(diff);
        if(Map.count(diff) != 0){
            unordered_set<int> S;
            S.insert(v[i].ss);
            S.insert(v[i-1].ss);
            S.insert(Map[diff].ff);
            S.insert(Map[diff].ss);
            if(S.size() < 4)
                continue;

            cout<<"YES\n";
            cout<<v[i].ss<<" "<<Map[diff].ff<<" "<<v[i-1].ss<<" "<<Map[diff].ss<<"\n";
            return;
        }else{
            Map.insert({diff,{v[i-1].ss,v[i].ss}});
        }
   }


   unordered_map<int,pi> Diff;
   for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            int diff = abs(v[j].ff-v[i].ff);
            Diff[diff] = {v[j].ss,v[i].ss};
        }
        for(int j = i + 2 ; j < n ; j++){
            int diff = v[j].ff-v[i+1].ff;
            debug(i+1);
            debug(j);
            if(Diff.count(diff) != 0){
                cout<<"YES\n";
                cout<<v[i+1].ss<<" "<<Diff[diff].ss<<" "<<v[j].ss<<" "<<Diff[diff].ff<<"\n";
                return;
            }
        }
   }
   cout<<"NO\n";
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("Error.txt", "w", stderr);
    #endif

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

