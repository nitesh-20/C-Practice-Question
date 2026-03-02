#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <string>
using namespace std;

// Segment Tree (range sum, point update) - simple DSA example
struct SegTree {
	int n;
	vector<long long> st;
	SegTree() = default;
	SegTree(const vector<long long>& a) { init(a); }
	void init(const vector<long long>& a) {
		n = (int)a.size();
		st.assign(4*n, 0);
		if(n) build(1,0,n-1,a);
	}
	void build(int p,int l,int r,const vector<long long>& a){
		if(l==r){ st[p]=a[l]; return; }
		int m=(l+r)/2;
		build(p*2,l,m,a);
		build(p*2+1,m+1,r,a);
		st[p]=st[p*2]+st[p*2+1];
	}
	void update(int idx,long long val){ update(1,0,n-1,idx,val); }
	void update(int p,int l,int r,int idx,long long val){
		if(l==r){ st[p]=val; return; }
		int m=(l+r)/2;
		if(idx<=m) update(p*2,l,m,idx,val);
		else update(p*2+1,m+1,r,idx,val);
		st[p]=st[p*2]+st[p*2+1];
	}
	long long query(int L,int R){ return query(1,0,n-1,L,R); }
	long long query(int p,int l,int r,int L,int R){
		if(R<l||r<L) return 0;
		if(L<=l&&r<=R) return st[p];
		int m=(l+r)/2;
		return query(p*2,l,m,L,R)+query(p*2+1,m+1,r,L,R);
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Demo array
	vector<long long> a = {1, 3, 5, 7, 9, 11};
	SegTree st(a);

	cout << "Initial array: ";
	for(auto v: a) cout << v << ' ';
	cout << '\n';

	cout << "Sum(1,3) = " << st.query(1,3) << "  (expected 15)\n";
	cout << "Update index 1 -> 10\n";
	st.update(1, 10);
	cout << "Sum(1,3) = " << st.query(1,3) << "  (expected 22)\n";

	// Short interactive example: if user provides n and array on stdin, run queries
	// Format:
	// n q
	// a0 a1 ... a{n-1}
	// then q lines: "q l r" (1 for query) or "u idx val" (u for update)
	// We'll only enter this mode if there's more input available.
	if(!cin.eof()){
		// try to read an int from stdin without blocking
		int n;
		if(cin >> n){
			int q;
			if(!(cin >> q)) return 0;
			vector<long long> b(n);
			for(int i=0;i<n;i++) cin >> b[i];
			SegTree st2(b);
			while(q--){
				char type;
				cin >> type;
				if(type=='q'){
					int l,r; cin>>l>>r; // 0-indexed expected
					cout << st2.query(l,r) << '\n';
				} else if(type=='u'){
					int idx; long long val; cin>>idx>>val;
					st2.update(idx,val);
				}
			}
		}
	}

	return 0;
}
