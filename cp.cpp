#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#define debugarr(x , a) cerr << #x <<" "; _print(x , a); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T , class V> void _print(T arr[], V size) {cerr << "[ "; for (V i=0 ; i<size;i++) {_print(arr[i]); cerr << " ";} cerr << "]";}
 
 
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
 
void precision(int a) {cout << setprecision(a) << fixed;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a , b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3

ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}

bool revsort(ll a, ll b) {return a > b;}

void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}

void google(ll t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))

long long binpowMOD(long long a, long long b) { a %= 1000000007; long long res = 1; while (b > 0) { if (b & 1) res = res * a % 1000000007; a = a * a % 1000000007;b >>= 1;}return res;}
void primeFact(vector<ll> &ans, ll n ){for (int i = 2; i*i <= n; ++i){  while(n%i == 0){ ans.pb(i); n/=i; }}if(n>1) ans.push_back(n);}
template <class T> void takeInput(vector<T> &v){ for(int i = 0 ; i < v.size() ; i++) cin>>v[i];};
template <class T> void printVector(vector<T> &v){ for(int i = 0 ; i < v.size() ; i++) cout<<v[i];};

// ll dpForNcr[10000][10000];
//Initialise array elements with zero
// ll nCr(ll n, ll r)
// {
//        if(n==r) return dpForNcr[n][r] = 1; //Base Case
//        if(r==0) return dpForNcr[n][r] = 1; //Base Case
//        if(r==1) return dpForNcr[n][r] = n;
//        if(dpForNcr[n][r]) return dpForNcr[n][r]; // Using Subproblem Result
//        return dpForNcr[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
// }




//---------->>>Start Program<<<-------------//

int rand50(){
    return rand()&1;
}
int rand75(){
    return rand50()|rand50();
}

class compareClass{
public:
    bool operator()(int a , int b){
        return a > b;
    }
};

struct compareStruct{
    bool operator()(int a , int b){
        return a > b;
    }  
};


bool compare(int a , int b){
    return  a < b;
}


#include "bridges.h"

void solve(){
    int cases=1;    
    // cin>>cases;    
    while(cases--){
        Bridge  bridge;
        vector<vector<int>> graph = {{1 , 2 , 4},{0 , 2},{1 ,0 ,3},{2} , {0}};        
        debug(bridge.getBridges(graph));
    }
}
        
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    solve();
    return 0;
}
    
