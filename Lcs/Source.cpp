#include<iostream>
#include "Header.h"

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> seq1(n), seq2(m);
	for (int i = 0; i < n; i++)
		cin >> seq1[i];
	for (int i = 0; i < m; i++)
		cin >> seq2[i];
	lcs(seq1, seq2);
	return 0;
}