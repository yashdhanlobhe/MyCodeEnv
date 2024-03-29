class SGTree {
	vector<int> seg;
public:
	SGTree(int n) {
		seg.resize(4 * n + 1);
	}

	void build(int ind, int low, int high, int arr[]) {
		if (low == high) {
			seg[ind] = arr[low];
			return;
		}

		int mid = (low + high) / 2;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);
		seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
	}

	int query(int ind, int low, int high, int l, int r) {
		// no overlap
		// l r low high or low high l r
		if (r < low || high < l) return INT_MAX;

		// complete overlap
		// [l low high r]
		if (low >= l && high <= r) return seg[ind];

		int mid = (low + high) >> 1;
		int left = query(2 * ind + 1, low, mid, l, r);
		int right = query(2 * ind + 2, mid + 1, high, l, r);
		return min(left, right);
	}
	void update(int ind, int low, int high, int i, int val) {
		if (low == high) {
			seg[ind] = val;
			return;
		}

		int mid = (low + high) >> 1;
		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val);
		seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
	}
};


class ST {
		vector<int> seg, lazy; 
	public: 
		ST(int n) {
			seg.resize(4 * n); 
			lazy.resize(4 * n); 
		}
	public: 
		void build(int ind, int low, int high, int arr[]) {
			if(low == high) {
				seg[ind] = arr[low];
				return; 
			}
			int mid = (low + high) >> 1; 
			build(2*ind+1, low, mid, arr); 
			build(2*ind+2, mid+1, high, arr); 
			seg[ind] = seg[2*ind+1] + seg[2*ind+2];
		}
	public:
		void update(int ind, int low, int high, int l, int r, 
			int val) {
			// update the previous remaining updates 
			// and propogate downwards 
			if(lazy[ind] != 0) {
				seg[ind] += (high - low + 1) * lazy[ind]; 
				// propogate the lazy update downwards
				// for the remaining nodes to get updated 
				if(low != high) {
					lazy[2*ind+1] += lazy[ind]; 
					lazy[2*ind+2] += lazy[ind]; 
				}

				lazy[ind] = 0; 
			}

			// no overlap 
			// we don't do anything and return 
			// low high l r or l r low high 
			if(high < l or r < low) {
				return; 
			}

			// complete overlap 
			// l low high r 
			if(low>=l && high <= r) {
				seg[ind] += (high - low + 1) * val; 
				// if a leaf node, it will have childrens
				if(low != high) {
					lazy[2*ind+1] += val; 
					lazy[2*ind+2] += val; 
				}
				return; 
			}
			// last case has to be no overlap case
			int mid = (low + high) >> 1; 
			update(2*ind+1, low, mid, l, r, val);
			update(2*ind+2, mid+1, high, l, r, val); 
			seg[ind] = seg[2*ind+1] + seg[2*ind+2]; 
		}
	public: 
		int query(int ind, int low, int high, int l, int r) {

			// update if any updates are remaining 
			// as the node will stay fresh and updated 
			if(lazy[ind] != 0) {
				seg[ind] += (high - low + 1) * lazy[ind]; 
				// propogate the lazy update downwards
				// for the remaining nodes to get updated 
				if(low != high) {
					lazy[2*ind+1] += lazy[ind]; 
					lazy[2*ind+2] += lazy[ind]; 
				}

				lazy[ind] = 0; 
			}

			// no overlap return 0; 
			if(high < l or r < low) {
				return 0; 
			}

			// complete overlap 
			if(low>=l && high <= r) return seg[ind]; 

			int mid = (low + high) >> 1; 
			int left = query(2*ind+1, low, mid, l, r);
			int right = query(2*ind+2, mid+1, high, l, r);
			return left + right; 
		}
};



// Lazy Propogation
class ST {
	vector<int> seg, lazy; 
public: 
	ST(int n) {
		seg.resize(4 * n); 
		lazy.resize(4 * n); 
	}
public: 
	void build(int ind, int low, int high, int arr[]) {
		if(low == high) {
			seg[ind] = arr[low];
			return; 
		}
		int mid = (low + high) >> 1; 
		build(2*ind+1, low, mid, arr); 
		build(2*ind+2, mid+1, high, arr); 
		seg[ind] = seg[2*ind+1] + seg[2*ind+2];
	}
public:
	void update(int ind, int low, int high, int l, int r, 
		int val) {
		// update the previous remaining updates 
		// and propogate downwards 
		if(lazy[ind] != 0) {
			seg[ind] = (high - low + 1) - seg[ind]; 
			// propogate the lazy update downwards
			// for the remaining nodes to get updated 
			if(low != high) {
				lazy[2*ind+1] = !lazy[2*ind + 1]; 
				lazy[2*ind+2] = !lazy[2*ind + 2]; 
			}

			lazy[ind] = 0; 
		}

		// no overlap 
		// we don't do anything and return 
		// low high l r or l r low high 
		if(high < l or r < low) {
			return; 
		}

		// complete overlap 
		// l low high r 
		if(low>=l && high <= r) {
			seg[ind] = (high - low + 1) - val; 
			// if a leaf node, it will have childrens
			if(low != high) {
				lazy[2*ind+1] = !lazy[2*ind + 1]; 
				lazy[2*ind+2] = !lazy[2*ind + 2]; 
			}
			return; 
		}
		// last case has to be no overlap case
		int mid = (low + high) >> 1; 
		update(2*ind+1, low, mid, l, r, val);
		update(2*ind+2, mid+1, high, l, r, val); 
		seg[ind] = seg[2*ind+1] + seg[2*ind+2]; 
	}
public: 
	int query(int ind, int low, int high, int l, int r) {

		// update if any updates are remaining 
		// as the node will stay fresh and updated 
		if(lazy[ind] != 0) {
			seg[ind] = (high - low + 1) - seg[ind]; 
			// propogate the lazy update downwards
			// for the remaining nodes to get updated 
			if(low != high) {
				lazy[2*ind+1] = !lazy[2*ind + 1]; 
				lazy[2*ind+2] = !lazy[2*ind + 2]; 
			}

			lazy[ind] = 0; 
		}

		// no overlap return 0; 
		if(high < l or r < low) {
			return 0; 
		}

		// complete overlap 
		if(low>=l && high <= r) return seg[ind]; 

		int mid = (low + high) >> 1; 
		int left = query(2*ind+1, low, mid, l, r);
		int right = query(2*ind+2, mid+1, high, l, r);
		return left + right; 
	}
};







