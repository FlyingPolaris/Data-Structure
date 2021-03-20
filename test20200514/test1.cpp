// test1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_DEPRECATE
#include<cstdio>
constexpr int nmax = 200000, mmax = 100000;
int n, m;
int find11;
struct set {
	int x;
	int y;
	int z;
};
set* read1;
bool findroot[nmax] = { 0 };
class binary_tree {
public:
	struct nodeq {
		int number;
		nodeq* lchild;
		nodeq* rchild;
		nodeq(int i = 0) {
			number = i;
			lchild = 0;
			rchild = 0;
		}
		nodeq(set* arr, int now) {
			number = arr[now].x;
			if (arr[now].y) {
				lchild = new nodeq(arr, arr[now].y);
			}
			if (arr[now].z) {
				rchild = new nodeq(arr, arr[now].z);
			}
			else rchild = 0;
		}
		~nodeq() {
			if (lchild)delete lchild;
			if (rchild)delete rchild;
		}
	};
	nodeq* root;
	void deletenode(int i, nodeq*& ptr) {
		if (ptr->number < i)deletenode(i, ptr->rchild);
		else {
			if (ptr->number > i)deletenode(i, ptr->lchild);
			else {
				if (ptr->lchild && ptr->rchild) {
					nodeq* tmp = ptr->rchild;
					if (tmp->lchild == 0) {
						ptr->number = ptr->rchild->number;
						ptr->rchild = ptr->rchild->rchild;
					}
					else {
						while (tmp->lchild->lchild) {
							tmp = tmp->lchild;
						}
						ptr->number = tmp->lchild->number;
						tmp->lchild = tmp->lchild->rchild;
					}
				}
				else {
					if (ptr->lchild) {
						ptr = ptr->lchild;
					}
					else {
						ptr = ptr->rchild;
					}
				}
			}
		}
	}
	void insert(int i, nodeq*& ptr) {
		if (ptr == 0) {
			ptr = new nodeq(i);
			return;
		}
		else {
			if (i > ptr->number)insert(i, ptr->rchild);
			else insert(i, ptr->lchild);
		}
	}
public:
	binary_tree(set* arr, int root1) {
		root = new nodeq(arr, root1);
	}
	void deletenode(int i) {
		deletenode(i, root);
	}
	void insert(int i) {
		insert(i, root);
	}
	void find(int i, int& arr) {
		nodeq* tmp = root;
		while (tmp->number != i) {
			if (tmp->number < i) {
				tmp = tmp->rchild;
			}
			else {
				tmp = tmp->lchild;
			}
		}
		if (tmp->lchild || tmp->rchild) {
			arr = 1;
		}
		else arr = 0;
		return;
	}
};
void quicksort(set* arr, int left1, int right1) {
	if (left1 >= right1)return;
	set tmp = arr[left1];
	int left = left1, right = right1;
	do {
		while (left<right && arr[right].x>tmp.x)--right;
		if (left < right)arr[left] = arr[right];
		while (left < right && arr[left].x < tmp.x)++left;
		if (left < right)arr[right] = arr[left];
	} while (left < right);
	arr[left] = tmp;
	quicksort(arr, left1, left - 1);
	quicksort(arr, left + 1, right1);
}
bool s(char* a, char* b) {
	int tmp = 0;
	while (a[tmp] && b[tmp]) {
		if (a[tmp] != b[tmp])return false;
		++tmp;
	}
	if (a[tmp] == 0 && b[tmp] == 0)return true;
	else return false;
}
binary_tree* tree;
int main() {
	scanf("%d%d", &n, &m);
	read1 = new set[n];
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &(read1[i].x), &(read1[i].y));
		scanf("%d", &(read1[i].z));
		findroot[read1[i].y] = findroot[read1[i].z] = true;
	}
	int root2 = 2;
	for (int i = 1; i <= n; ++i) {
		if (!findroot[i]) {
			root2 = i;
			break;
		}
	}
	quicksort(read1, 1, n);
	tree = new binary_tree(read1, root2);
	int get1 = 0;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &get1);
		tree->find(get1, find11);
		tree->deletenode(get1);
		tree->insert(get1);
		if (find11)printf("1\n");
		else {
			printf("0\n");
		}
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
