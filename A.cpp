
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

int t;
ll n, A[18];
vl v;

int main() {
	freopen("Task.in","r",stdin);freopen("Task.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	for(int tc=1 ; tc<=t ; tc++) {
		v.clear();
		cin>>n;
		ll n2 = n;
		while(n2) {
			v.pb(n2%10);
			n2 /= 10;
		}
		int dig = sz(v);
		A[0] = 1;
		for(int i=1 ; i<18 ; i++) A[i] = A[i-1]*10;
		reverse(all(v));
		int pos = -1;
		ll num1 = 0, num2 = 0;
		for(int i=0 ; i<sz(v) ; i++) {
			if(v[i]&1) {
				pos = i;
				break;
			}
			num1 = num1+A[dig-i-1]*v[i];
			num2 = num2+A[dig-i-1]*v[i];
		}
		// cout<<num1<<" "<<num2<<endl;
		if(pos==-1) {
			cout<<"Case #"<<tc<<": ";
			cout<<"0\n";
			continue;
		}
		num1 = num1+A[dig-pos-1]*(v[pos]+1);
		num2 = num2+A[dig-pos-1]*(v[pos]-1);
		if(v[pos]==9) {
			num1 = 1e18;
		} 
		for(int i=pos+1 ; i<sz(v) ; i++) {
			num2 = num2+A[dig-i-1]*8;
		}
		// cout<<num1<<" "<<num2<<endl;
		cout<<"Case #"<<tc<<": ";
		cout<<min(abs(num1-n), abs(num2-n))<<"\n";
	}
}