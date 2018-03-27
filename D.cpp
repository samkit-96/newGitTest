
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define clr(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector< int > vi;
typedef vector< ll > vl;
typedef vector< pii > vpii;
typedef vector< pll > vpll;

const int MOD = 1e9+7;

ll power(ll a, ll b) {ll ret=1;while(b) {if(b&1) ret*=a;a*=a;if(ret>=MOD) ret%=MOD;if(a>=MOD)a%=MOD;b>>=1;}return ret;}
ll inv(ll x) {return power(x,MOD-2);}

const int N = 1e5+5;

int n, deg[N];
vi adj[N];
vpii v;
int vis[N];

void dfs(int cur) {
	vis[cur] = 1;
	for(int i=0 ; i<sz(adj[cur]) ; i++) {
		int nod = adj[cur][i];
		if(vis[nod]) continue;
		dfs(nod);
		if(vis[nod]!=2) {
			vis[nod] = 2;
			cout<<cur<<" "<<nod<<"\n";
		}
	}
}

int main() {
	freopen("Task.in","r",stdin);freopen("Task.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1 ; i<=n ; i++) {
		int p;
		cin>>p;
		adj[i].pb(p);
	}
	for(int i=1 ; i<=n ; i++) {
		for(int j=0 ; j<sz(adj[i]) ; j++) {
			deg[adj[i][j]]++;
		}
	}
	for(int i=1 ; i<=n ; i++) {
		v.pb(mp(deg[i], i));
	}
	sort(all(v));
	// reverse(all(v));
	for(int i=0 ; i<sz(v) ; i++) {
		if(vis[v[i].ss]) continue;
		dfs(v[i].ss);
	}
}