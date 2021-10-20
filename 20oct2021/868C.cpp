//created by Shivam Varshney
#include<bits/stdc++.h>
#pragma GCC optimise("Ofast")
#pragma GCC target("avx","avx2","fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define int long long

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



string solve(){
   int n,k;
   cin>>n>>k;
   vector<int> arr;
   for(int i = 0 ; i < n ; i++){
        int temp = 0;
        for(int j = 0 ; j < k ; j++){
            int c;
            cin>>c;
            temp = (temp << 1) + c;
        }
        debug(temp);
        arr.push_back(temp);
   }
   debug(arr);
   sort(arr.begin(),arr.end());
   arr.erase(unique(arr.begin(),arr.end()),arr.end());
   debug(arr);
   if(arr.size() == 1){
        return (arr[0] == 0)?"YES":"NO";
   }
   for(int i = 0 ; i < arr.size() ; i++){
        for(int j = i + 1 ; j < arr.size() ; j++){
            if((arr[i] & arr[j]) == 0){
                return "YES";
            }
        }
   }

   return "NO";
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
    // int T;
    // cin>>T;
    // while(T--){
    //     solve();
    // }
    cout<<solve()<<"\n";
    return 0;
}

