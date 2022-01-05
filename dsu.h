#include <bits/stdc++.h>
using namespace std;

//Disjoint Set Union
//The two techniques complement each other. The time complexity of each
//operation becomes even smaller than O(Logn).
//In fact, amortized time complexity effectively becomes small constant. 
class DSU
{
	private:
		vector<int> parent;
		vector<int> rank;
		DSU(){}
	public:
		//at intial the parent of each node will be same as itsel
		//and rank is zero
		DSU(int size){
			parent.clear();
			rank.clear();
			for(int i = 0; i <= size; i++){
				parent.push_back(i);
				rank.push_back(0);
			}
		}
		//to find the parent of the specific number
		int getParent(int node);
		//to merget two set
		void makeUnion(int u , int v);
};


//here while returning we are assigning that value to the child
//means next time it will have the direct parent
//ex
//       1         1
//		/         / \
//	   2         2   3
//    /
//	 3	
//if we are  finding the parent of 3
int DSU :: getParent(int node){
	if(node == parent[node]){
		return node;
	}
	return parent[node] = getParent(parent[node]);
}


//we are also taking the count of the rank becuase
//if we will attach big tree under lower (subset) then it will increase complexity
//ex.
// 1     2
//      / \
//     3   4                       
//              2                       1
//   better   / | \   than this        /
//           3  4  1                  2
//                                   / \
//                                  3   4

//and also we will only increase rank if the ranks are equal becuase otherwise hight of tree
//is not goint to increase
//like in above case hight will remain two if the hight of the both tree will become same then 
//hight will increase so rank will increase

void DSU :: makeUnion(int  u , int v){
	u = getParent(u);
	v = getParent(v);

	if(rank[u] < rank[v]){
		parent[u] = v;
	}else if(rank[u] > rank[v]){
		parent[v] = u;
	}else{
		parent[v] = u;
		rank[u]++;
	}
}	