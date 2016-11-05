#include<iostream>
#include "Header.h"
int max(int a, int b) {
	return a > b ? a : b;
}
void lcs(const vector<int>& seq1, const vector<int>& seq2) {
	int n = seq1.size(), m = seq2.size();
	vector<vector<int>> lcsm(n + 1, vector<int>(m + 1,0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (seq1[i]==seq2[j]) {
				lcsm[i][j] = 1 + lcsm[i - 1][j - 1];
			}
			else {
				lcsm[i][j] = max(lcsm[i-1][j],lcsm[i][j-1]);
			}
		}
	}
	printLcs(seq1, seq2, lcsm, n, m);
}

void printLcs(const vector<int>& seq1, const vector<int>& seq2, const vector<vector<int>>& dp, int i, int j) {
	if (!i || !j) {
		return;
	}
	if (seq1[i]==seq2[j]) {
		printLcs(seq1, seq2, dp, i-1, j-1);
		cout << seq1[i] << " ";
	}
	else {
		if (dp[i-1][j]>dp[i][j-1]) {
			printLcs(seq1, seq2, dp, i - 1, j);
		}
		else {
			printLcs(seq1, seq2, dp, i, j-1);
		}
	}
}