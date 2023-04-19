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
bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
vector<string> items;
bool flag = true;
int priority(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/' ) {
        return 2;
    } else {
        return 0;
    }
}
int tt = 1;
string put_parentheses(string expr, int cnt) {
    int len = expr.length();
    if (len == 1) {
        return expr;
    } else {
        int op_index = -1;
        int op_priority = 0;
        int parentheses = 0;
        for (int i = len-1; i >= 0; i--) {
            char c = expr[i];
            if (c == ')') {
                parentheses++;
            } else if (c == '(') {
                parentheses--;
            } else if (is_operator(c)) {
                int p = priority(c) + parentheses * 2;
                if (op_index == -1 || p <= op_priority) {
                    op_index = i;
                    op_priority = p;
                }
            }
        }
        string curr;
        string opn = expr.substr(op_index, 1);
        if (op_index == -1) {
        	curr = put_parentheses(expr.substr(1, len-2), cnt+1);
        	items.pb(curr);
            return curr;
        } else {
        	curr = "(" + put_parentheses(expr.substr(0, op_index), cnt+1) +
                   expr.substr(op_index, 1) +
                   put_parentheses(expr.substr(op_index+1), cnt + 1) + ")";
                
            items.pb(curr);
            return curr;
        }
    }
}

string ans;
void replace(string& temp, string curr, int i){
	string nxt = "T"+to_string(i);
	int len = curr.size();
	string s = temp;
	for(int j=0; j< s.size() - len; j++){
        if(s.substr(j, len) == curr){
        	temp.replace(j, len, nxt);
        }
    }
    cout << temp<<endl;
}

string T(int i){
	return "T"+to_string(i);
}
vector<string> generateVector(string input) {
    stack<string> st;
    int cnt = 1;
    vector<string> result;

    for (int i = 0; i < input.size(); ++i) {
        string c;
        c += input[i];

        if (c == "(" || c == "+" || c == "-" || c == "*" || c == "/") {
            // push operator onto the stack
            st.push(c);
        }
        else if (c == ")") {
            string curr = T(cnt), pre;
            while(st.top() != "("){
            	pre += st.top();
            	st.pop();
            }
         	st.pop();
         	reverse(all(curr));
         	st.push(curr);
         	reverse(all(pre));
         	
         	reverse(all(curr));
         	cout << curr <<" = "<<pre<<endl;
         	cnt++;
         }
        else {
            st.push(c);
        }
    }

    return result;
}

int main(){
	init_code();
	string s;
	cin >> s;
	int n = s.size();
	cout << put_parentheses(s, 1)<<endl;
	string temp = put_parentheses(s, 1);
	for (int i = 0; i < items.size(); ++i)
	{
		cout << items[i]<< endl;
	}

	// string temp = "(-(3+2)*(a+c) + d)";
	vector<string> fin = generateVector(temp);
	for(auto x: fin) cout << x <<endl;
	// dbg(fin);
	return 0;
}