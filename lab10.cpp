#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define ld long double
#define N 100001
//int mid= start + (end  -  start)/2 to handle  edge cases where they overflow
#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
const ll M = 1e9+7;
const ll maxN = 200001;
ll fact[maxN] = {}, smallestPrimeFactor[maxN] = {}, isPrimeSieve[maxN] = {};
mt19937_64 my_rand(chrono::steady_clock::now().time_since_epoch().count());
inline bool comp(ll x,ll y) { return x<y; } // INITIALLY IN DEFAULT INCREASING ORDER (SMALL TO BIG)
inline ll mod(ll x) {ll a1=(x%M); if(a1<0){a1+=M;} return a1;}
inline ll power(ll x, unsigned ll y, ll p = LLONG_MAX) {ll res=1; x=x%p; if(x==0) {return 0;} while(y>0){ if(y&1){res=(res*x)%p;} y=y>>1; x=(x*x)%p;} return res;} // CALCULATING POWER IN LOG(Y) TIME COMPLEXITY
inline ll inversePrimeModular(ll a, ll p) {return power(a,p-2,p);}
inline void calcFact(ll n = maxN-1) { fact[0] = 1; for(ll i=1; i<=n; i++){ fact[i] = fact[i-1]*i; fact[i] = mod(fact[i]); }}
inline ll ncr(ll n, ll r) { if(n<r) return 0; return mod(inversePrimeModular(mod(fact[n-r]*fact[r]),M)*fact[n]); }
inline ll ceil(ll a, ll b) { if(b==0) return LLONG_MAX; ll ans = (a+b-1)/b; return ans; }
void sieve(ll n = maxN-1) { for(ll i=1; i<=n; i++) smallestPrimeFactor[i] = i; for(ll i=2; (i*i)<=n; i++) { if(smallestPrimeFactor[i]==i) { for(ll j=(i*i); j<=n; j+=i) { smallestPrimeFactor[j] = min(smallestPrimeFactor[j], i); } } } for(ll i=2; i<=n; i++) { if(smallestPrimeFactor[i]==i) isPrimeSieve[i] = 1; } }

#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " : "; _print_(x);cerr << endl;
#else
#define dbg(x)
#endif
void _print_(ll t) {cerr << t;}
void _print_(int t) {cerr << t;}
void _print_(string t) {cerr << t;}
void _print_(char t) {cerr << t;}
void _print_(ld t) {cerr << t;}
void _print_(double t) {cerr << t;}
template <class T, class V> void _print_(pair <T, V> p);
template <class T> void _print_(vector <T> v);
template <class T> void _print_(set <T> v);
template <class T, class V> void _print_(map <T, V> v);
template <class T> void _print_(multiset <T> v);
template <class T, class V> void _print_(pair <T, V> p) {cerr << "{"; _print_(p.ff); cerr << ","; _print_(p.ss); cerr << "}";}
template <class T> void _print_(vector <T> v) {cerr << "[ "; for (T i : v) {_print_(i); cerr << " ";} cerr << "]";}
template <class T> void _print_(set <T> v) {cerr << "[ "; for (T i : v) {_print_(i); cerr << " ";} cerr << "]";}
template <class T> void _print_(multiset <T> v) {cerr << "[ "; for (T i : v) {_print_(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print_(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print_(i); cerr << " ";} cerr << "]";}

void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif 
}
vector<char>A={'A','B','C','D','E','F'};
vector<string>RES;
unordered_map<char,char>S;
int j=0;
void MOV(char a,char b){
    string temp="MOV ";
    temp+=b;
    temp+=char(32);
    temp+=a;
    RES.push_back(temp);
}
void DIV(char a,char b){
    string temp="DIV ";
    temp+=a;
    temp+=char(32);
    temp+=b;
    RES.push_back(temp);
}
void MULT(char a,char b){
    string temp="MUL ";
    temp+=a;
    temp+=char(32);
    temp+=b;
    RES.push_back(temp);
}
void ADD(char a,char b){
    string temp="ADD ";
    temp+=b;
    temp+=char(32);
    temp+=a;
    RES.push_back(temp);
}
void SUB(char a,char b){
    string temp="SUB ";
    temp+=b;
    temp+=char(32);
    temp+=a;
    RES.push_back(temp);
    // RES.push_back("SUB "+a+' '+b);
}
void convert(string s){
    for(int i=0;i<s.length();i++){
        if(int(s[i])>=97&&int(s[i])<=122){
            S[s[i]]=A[j];
            j++;
            cout<<S[s[i]]<<"<----"<<s[i]<<endl;
        }
        
    }
    cout<<endl;
    for(int i=0;i<s.length();i++){
        if(s[i]=='/'){
            MOV(s[i-1],S[s[i-1]]);
            MOV(s[i+1],S[s[i+1]]);
            DIV(S[s[i-1]],S[s[i+1]]);
        }
        
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='*'){
            MOV(s[i-1],S[s[i-1]]);
            MOV(s[i+1],S[s[i+1]]);
            MULT(S[s[i-1]],S[s[i+1]]);
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='+'){
            MOV(s[i-1],S[s[i-1]]);
            MOV(s[i+1],S[s[i+1]]);
            ADD(S[s[i-1]],S[s[i+1]]);
        }
        
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='-'){
            MOV(s[i-1],S[s[i-1]]);
            MOV(s[i+1],S[s[i+1]]);
            SUB(S[s[i-1]],S[s[i+1]]);
        }
    }
    MOV(s[0],S[s[0]]);
}
void show(){
    for(int i=0;i<RES.size();i++){
        bool b=false;
        for(int j=0;j<i;j++){
            if(RES[j]==RES[i])
              b=true;
        }
        if(b==false){
            cout<<RES[i]<<endl;
        }
    }
}
int main(){
    init_code();
    // cout<<"Enter a expression: "<<endl;
    string s;
    cin>>s;
    convert(s);
    show();
    
    return 0;

}