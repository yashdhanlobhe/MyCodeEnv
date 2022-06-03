#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
// #define mp make_pair
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

long long binpowMOD(long long a, long long b) { a %= 998244353; long long res = 1; while (b > 0) { if (b & 1) res = res * a %998244353 ; a = a * a %998244353;b >>= 1;}return res;}
void primeFact(vector<ll> &ans, ll n ){for (int i = 2; i*i <= n; ++i){  while(n%i == 0){ ans.pb(i); n/=i; }}if(n>1) ans.push_back(n);}
template <class T> void takeInput(vector<T> &v){ for(int i = 0 ; i < v.size() ; i++) cin>>v[i];};
template <class T> void printVector(vector<T> &v){ for(int i = 0 ; i < v.size() ; i++) cout<<v[i]<<" ";};

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



struct compareStruct{
    bool operator()(int a , int b){
        return a > b;
    }  
};


bool compare(int a , int b){
    return  a < b;
}


// vector<ll> lis(vector<ll> v){
//     if(v.size() == 0) return {};
//     vector<ll> lis = {v[0]};

//     for(ll i = 1 ; i < v.size() ; i++){
//         ll cur = v[i];
//         auto idx = upper_bound(lis.begin() , lis.end() , cur);
        

//                 if(idx == lis.end()){
//                     lis.push_back(cur);
//                 }else{
//                     *idx = cur;
//                 }
//     }
//     debug(lis);
//     return lis;

// }




class compareClass{
public:
    bool operator()(pair<ll , ll> &p1 , pair<ll , ll> &p2){
        ll b1 = p1.first;
        ll c1 = p1.second;
        ll b2 = p2.first;
        ll c2 = p2.second;
        return (double)c1/(double)b1 < (double)c2/(double)b2;
    }
};


// ll getSumDivisors(ll n )
// {
//     ll ans = 0;
//     for (ll i=1; i<=sqrt(n); i++)
//     {
//         if (n%i == 0)
//         {
//             if (n/i == i)
//                 ans += i;
            
//             else 
//                 ans += (i + n/i);
//         }
//         // if(ans > x) return INT_MAX;
//     }
//     return ans;
// }

// void getDivisors(ll n)
// {
//     ll ans = 0;
//     for (ll i=1; i<=sqrt(n); i++)
//     {
//         if (n%i == 0)
//         {
//             // cout<<i<<" ";
//            string temp = to_string(i);
//            pali(temp);
//            temp = to_string(n/i);
//            pali(temp);
//         }
//     }
    
//     return;
// }



int mod = 998244353;


 
 
bool cmp(vector<ll> &a , vector<ll> &b){
    return (a[1]*1.0)/(a[0]*a[2]*1.0) > (b[1]*1.0)/(b[0]*b[2]*1.0); 
}


ll fact(ll x)
{
    if (x == 0)
        return 1;
    return x * fact(x - 1);
}



ll nmod(ll &a , ll &n){
    return a - n * floor((a*1.0)/(1.0*n));
}

ll amod(ll n, ll mod){
    if(n >= 0) return n%mod;
    return nmod(n , mod);
} 
 

vector<int>pre; 
vector<int>after;
vector<vector<int>> tree;
int n,e;

int help(vector<bool> &vis , int cur){
    if(vis[cur]) return 0;
    vis[cur] = true;
    int ans = 0;
    for(auto x : tree[cur]){
        ans += help(vis , x);
        if(pre[cur] != after[cur]) ans++;
    }

    vis[cur] = false;
    return ans;
}

void getPrevBig(vector<int> &prev , vector<int> &v){
    stack<int> st;
    for (int i = 0; i < v.size(); ++i)
    {
        while(!st.empty() && v[st.top()] <= v[i]){
            st.pop();
        }
        if(!st.empty()) prev[i]= st.top();
        st.push(i);
    }
}
void getNextBig(vector<int> &prev , vector<int> &v){
    stack<int> st;
    for (int i = v.size()-1; i >= 0; --i)
    {
        while(!st.empty() && v[st.top()] <= v[i]){
            st.pop();
        }
        if(!st.empty()) prev[i]= st.top();
        else prev[i] = v.size()-1;
        st.push(i);
    }
}


class SGTree {
public:
        vector<int> seg;

    SGTree(int n) {
        seg.resize(4 * n + 1);
    }

    void build(int ind, int low, int high, vector<int>arr) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        int l = seg[2 * ind + 1];
        int r = seg[2 * ind + 2];
        seg[ind] = max(l , (l + r));
    }

    int query(int ind, int low, int high, int l, int r) {
        // no overlap
        // l r low high or low high l r
        if (r < low || high < l) return INT_MIN;

        // complete overlap
        // [l low high r]
        if (low >= l && high <= r) return seg[ind];

        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return max(l, l+r);
    }
};


class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> getPre(vector<int>& v){
        vector<int> ans;
        ans.push_back(v[0]);
        for(int i = 1 ; i < v.size() ; i++){
            ans.push_back((ans[i-1] + v[i]));
        }
        return ans;
    }
    vector<int> getPre2(vector<int>& v){
        vector<int> ans;
        ans.push_back(0);
        for(int i = 0 ; i < v.size() ; i++){
            ans.push_back((ans[i] + v[i]));
        }
        return ans;
    }
    vector<int> getLeft(vector<int> &v){
        vector<int> ans(v.size() , 0);
        stack<int> st;
        for (int i = 0; i < v.size(); ++i)
        {
            while(!st.empty() && v[st.top()] > v[i]){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top()+1; 
            st.push(i);
        }
        return ans;
    }

    vector<int> getRight(vector<int> &v){
        vector<int> ans(v.size() , v.size()-1);
        stack<int> st;
        for (int i = v.size()-1; i >= 0; --i)
        {
            while(!st.empty() && v[st.top()] > v[i]){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top()-1; 
            st.push(i);
        }
        return ans;
    }


    int totalStrength(vector<int>& v) {
        vector<int> prefix = getPre(v);
        debug(prefix);
        vector<int> sos = getPre2(prefix);
        debug(sos);
        // for(auto x : prefix) cout<<x<<" ";
        auto l = getLeft(v);
        debug(l);
        auto r = getRight(v);
        debug(r);
        int ans = 0;

        for (int i = 0; i < v.size(); ++i)
        {
            int cur = v[i];
            int left = l[i];
            int right = r[i];
            // debug(i);
            if(left == right) {
                ans += (v[left]*v[left]);
            }else{
                // debug(left);
                int rNum = r[i]-i+1;
                int lNum = i-l[i]+1;
                // debug(rNum);
                // debug(lNum);
                ans+=rNum*(sos[right+1] - sos[i]);
                ans-=lNum*(sos[i+1] - sos[left]);
            }

        }
        return ans;
    }
};



void solve(ll caseNum){
    vector<int> v(8);
    takeInput(v);
    debug(v);
    Solution* sp= new Solution();
    cout<<(sp->totalStrength(v));
}   


void precompute(int &cases){
     // cin>>cases;    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    int cases=1;       
    precompute(cases);

    int total = cases;
    // cout<<total;

    while(cases--){

        solve(total-cases);
    }  
    
    return 0;
}
    
//APPROACHING A QUESTION
//+ Do dry run
//+ Think of binary search (max of min etc also if n<=2*10^5)
//+ Think of common dp states (Even if it appears as maths but constraints are small)
//+ Check constraints
//+ Keep calm and enjoy the question
//+ Be sure to remove MOD from binpow (if needed)
//+ Try bidirectional analysis for constructive questions
//+ If given some sequence try thinking of prefix sums
//+ If constraints are too large maybe its simple maths
//+ In questions with binary operations think of bits independently and also the change pattern
//+ If two or more binary operations are given mostly there is a relation between them and an arithmatic operator
//+ If it is getting complicated and unable to solve for 1/2 hour change the approch think differently
