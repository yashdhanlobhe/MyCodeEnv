#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void o_p()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
#endif
}
bool lexo(string s, int i , int j)
{
     return s[i] < s[j];
}

void  solve()
{
     int n;
     cin >> n;
     string s ;
     cin >> s ;
     vector<int>v(n);
     for (int i{}; i < n; i++)
     {
          cin >> v[i];
     }
     vector<vector<int>>a(n + 1, vector<int>(n + 1));
     for (int i{1}; i <= n; i++)
     {
          a[i][i] = v[i - i] ;
     }
     for (int i{1}; i < n; i++)
     {
          for (int j{1}; j + i <= n; j++)
          {

               int ma = 0;
               ma = max(ma, v[i]);
               // if (j == 1 && j + i == n) {
               //      cout << ma << endl;;
               // }
               for (int k = j; k < j + i; k++)
               {
                    if (lexo( s , j - 1 , k))
                    {
                         int sum = a[j][k] + a[k + 1][j + i];
                         // if (j == 1 && j + i == n) {
                         //      // cout << j << " " << k + 1 << endl;
                         //      // cout << a[j][k] << " " << a[k + 1][j + i] << endl;
                         //      // cout << "SUm" << sum << endl;
                         // }
                         ma = max(sum, ma);
                    }
               }
               a[j][j + i] = max(a[j][j + i], ma);
          }
     }
     int ans = 0 ;
     for (int i{}; i <= n; i++) {
          for (int j{}; j <= n; j++)
          {
               ans = max(a[i][j], ans);
          }
          // cout << endl;
     }
     cout << ans << endl;
}

int32_t main()
{
     o_p() ;
     w(t) {
          solve() ;
     }
     return 0;
}