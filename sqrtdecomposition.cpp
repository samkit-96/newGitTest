#include<bits/stdc++.h>

#define X first
#define Y second
#define eb push_back
#define siz(a) int(a.size())
		
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;

using namespace std;

typedef long long int ll;
typedef vector < int > vi;
typedef vector < ll > vll;

const int mod=1e9+7;
const int maxn=2.5e5 + 5;
const int limit = 5e4+5;
const int bsize = 1000;

int block[maxn], arr[maxn], tree[bsize][limit], start[bsize], end1[bsize];

void update(int no, int idx, int change){
	
	while(idx < limit){
		tree[no][idx] += change;
		idx += (idx & (-idx));
	}
	
}

int query(int no, int idx){
	int ret = 0;
	
	while(idx){
		ret += tree[no][idx];
		idx -= (idx & (-idx));
	}
	return ret;
}

int get(int l, int r, int val){
	
	int ret = 0;
	
	for(int i = block[l]; i <= block[r]; i++){
//		trace5(i, l, r, start[i], end1[i]);
		if( l <= start[i] && end1[i] <= r){
			
			ret += query(i, val);
			
		} else{
			
			for(int j = max(l, start[i]); j <= min(r, end1[i]); j++){
				
				ret += (arr[j] <= val);
				
			}
			
		}
		
	}
	
	return ret;
}

int main(){
	// comment
//	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, i, j, x, y;
	
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		scanf("%d", arr+i);
	}
	
	scanf("%d", &m);
	
	int curr = 1;
	i = 1;
	
	while(i<=n){
		start[curr] = i;
		
		j = i;
		while(j <= n && j < bsize + i){
			block[j] = curr;
			update(block[j], arr[j], 1);
			j++;
		}
//		trace5(i, start[curr-1], block[i], j, end1[j-1]);
		end1[curr++] = j-1;
		
		i = j;
	}
	
	ll ans = 0;
	
	for(i=n; i>0; i--){
//		trace4(i, ans, query(0, arr[i]-1), arr[i]);
		ans += 1LL*query(0, arr[i]-1);
		update(0, arr[i], 1);
	}
	while(m--){
		scanf("%d %d", &x, &y);
		
		ans = ans - 1LL*(x - 1 - 1LL*get(1, x-1, arr[x]));
		ans = ans - 1LL*get(x+1, n, arr[x]-1);
		
//		trace5(x, y, get(1, x-1, arr[x]-1), get(x+1, n, arr[x]-1), ans);
		
		update(block[x], arr[x], -1);
		
		arr[x] = y;
		
		update(block[x], arr[x], 1);
		
		ans = ans + 1LL*(x - 1 - 1LL*get(1, x-1, arr[x]));
		
		ans = ans + 1LL*get(x+1, n, arr[x]-1);
		
		printf("%lld\n", ans);
	}
	
	return 0;
}
