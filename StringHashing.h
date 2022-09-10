#include<iostream>
typedef long long ll;

using namespace std;

class StringHashing{
public:
    string str , rstr;
    ll stringLength;
    
    ll mod1 = 1e9 + 7 , prime1 = 53 , mod2 = 31  , prime2 = 998244353;

    vector<ll> hash1 , hash2;
    vector<ll> rhash1 , rhash2;



    StringHashing(string &s){
        str = s;
        rstr = s;
        reverse(rstr.begin() , rstr.end());

        stringLength = str.length();

        //Two Hashes are used to avoid collison
        hash1 = createHash(mod1 , prime1 , str);
        hash2 = createHash(mod2 , prime2, str);
        rhash1 = createHash(mod1 , prime1, rstr);
        rhash2 = createHash(mod2 , prime2, rstr);
    }


    ll binpowMOD(ll a, ll b , ll mod) { 
        a %= mod; 
        ll res = 1; 
        while (b > 0) { 
            if (b & 1) 
                res = res * a % mod ; 
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }


    vector<ll> createHash(ll mod , ll prime , string &str){
        vector<ll> hash;
        hash.resize(stringLength + 1);
        
        hash[0] = 0;
        ll primePow = prime;

        for (ll i = 1; i <= stringLength; ++i)
        {
            hash[i] = (hash[i-1]%mod + ((str[i-1] - 'a' + 1)*primePow)%mod)%mod;
            primePow = (primePow*prime)%mod;
        }

        return hash;
    }

    
    ll getHashes(ll l , ll r , ll mod , ll prime , vector<ll> &hash){
        ll extraPow = binpowMOD(prime , (stringLength - l - 1), mod);
        ll hashVal = hash[r+1] - hash[l];
        hashVal = (hashVal%mod + mod)%mod;
        hashVal = (hashVal*extraPow)%mod;
        return hashVal;
    }
    
    pair<ll , ll> getTwoHashes(ll l , ll r ){
        pair<ll , ll> h;
        // if(l == r) return {0 , 0};
        h.first = getHashes(l , r , mod1 , prime1 , hash1);
        h.second = getHashes(l , r , mod2 , prime2 , hash2);

        return h;
    }

    pair<ll , ll> rgetTwoHashes(ll l , ll r ){
        pair<ll , ll> h;
        // if(l == r) return {0 , 0};
        h.first = getHashes(l , r , mod1 , prime1 , rhash1);
        h.second = getHashes(l , r , mod2 , prime2 , rhash2);

        return h;
    }

    bool chekPalindrome(ll l , ll r){
        
        ll sz = (r - l + 1);
        if(sz <= 1) return true;
        // 3 7 = 3 5   5 7   sz = 5
      
        // 3 8 = 3 5   6 8   sz = 6
        // cout<<l<<r<<endl;
        ll l1 = l ;
        ll r1 = l + sz/2 - (!(sz&1));
        ll l2 = r;
        ll r2 = l + sz/2;
        l2 = stringLength - l2-1;
        r2 = stringLength - r2-1;
        // cout<<l1<<r1;
        // cout<<l2<<r2;
        // cout<<endl;
        auto f = getTwoHashes(l1 , r1);
        auto s = rgetTwoHashes(l2 , r2);
        cout<<f.first<<" "<<f.second<<endl;
        cout<<s.first<<" "<<s.second<<endl;
        return ((f.first==s.first)&&(f.second==s.second));
    }

};
