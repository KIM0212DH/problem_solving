/*#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

struct Node
{
	int parent = 0;
	vector<int> children;
	int length = 0;
};
Node Tree[50000] = {};
int dir[50000] = {0};

void TreeTraversal(int u);

int main() {
	int T;
	int N;
	int A, B;
	string S;
	cin >> T;
	while (T--) {
		cin >> N;

		//Node *Tree = new Node[N];
		//int *dir = new int[N];
		for (int i{ 0 }; i < N - 1; i++) {
			cin >> A >> B;

			Tree[A].children.push_back(B);
			Tree[B].parent = A;
		}

		for (int i{ 1 }; i <= N; i++) {
			cin >> S;
			Tree[i].length = S.length();
		}
		TreeTraversal(1);
		for (int i{ 1 }; i <= N; i++) {
			cout << dir[i] << "\n";
		}

		for (int i{ 0 }; i < 50000; i++) {
			Tree[i].children.clear();
			Tree[i].length = 0;
			Tree[i].parent = 0;
			dir[i] = 0;
		}
		
	}
}

void TreeTraversal(int u) {
	if (u == 1) {
		dir[u] = 4;
	}
	else {
		dir[u] = dir[Tree[u].parent] + 1 + Tree[u].length;
	}

	for (unsigned int i{ 0 }; i < Tree[u].children.size(); i++) {
		TreeTraversal(Tree[u].children[i]);
	}
}
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int t;

struct Node {
	int parent = 0;
	vector<int> children;
	int length = 0;
};

void treeTraversal(int u, int* directory, Node* tree) {
	if (u == 1) {
		directory[u] = 4;
	}
	else {
		directory[u] = directory[tree[u].parent] + 1 + tree[u].length;	//중요
	}

	for (int i = 0; i < tree[u].children.size(); i++) {
		treeTraversal(tree[u].children[i], directory, tree);		//중요
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		int n; //디렉토리 개수
		cin >> n;
		Node* tree = new Node[n + 1];
		int* directory = new int[n + 1];

		for (int i = 1; i < n; i++) {	//루트 제외해야 하므로 n-1만큼 반복
			int a, b;
			cin >> a >> b;
			tree[a].children.push_back(b);
			tree[b].parent = a;
		}

		for (int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			tree[i].length = s.length();
		}

		//트리 순회
		treeTraversal(1, directory, tree);

		for (int i = 1; i <= n; i++) {
			cout << directory[i] << "\n";
		}
	}
}