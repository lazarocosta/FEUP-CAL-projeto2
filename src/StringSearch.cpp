#include "StringSearch.h"

int EditDistance(string name1, string name2) {

	unsigned int l1 = name1.size();
	unsigned int l2 = name2.size();
	vector<vector<int> > D(l1 + 1, vector<int>(l2 + 1));

	for (unsigned int i = 0; i <= l1; i++) {
		D[i][0] = i;
	}

	for (unsigned int j = 0; j <= l2; j++) {
		D[0][j] = j;
	}

	for (unsigned int i = 1; i <= l1; i++) {
		for (unsigned int j = 1; j <= l2; j++) {
			if (name1[i-1] == name2[j-1]) {
				D[i][j] = D[i - 1][j - 1];
			} else {
				D[i][j] = 1
						+ min(min(D[i - 1][j - 1], D[i - 1][j]), D[i][j - 1]);
			}
		}
	}

	return D[l1][l2];
}


string VerifyValidName(string name1, string name2) {

	int val = 0;

	val = EditDistance(name1, name2);

	if (val == 0)
		return name2;
	else
		return "";
}

int kmp(string text, string toSearch) {

	int num = 0;
	int m = toSearch.size();
	vector<int> prefix(m);

	pre_kmp(toSearch, prefix);

	int size = text.size();

	int k = -1;
	for (int i = 0; i < size; i++) {
		while (k > -1 && toSearch[k + 1] != text[i])
			k = prefix[k];
		if (toSearch[k + 1] == text[i])
			k++;
		if (k == m - 1) {
			num++;
			k = prefix[k];
		}
	}
	return num;
}

void pre_kmp(string toSearch, vector<int> & prefix) {

	int m = toSearch.size();
	prefix[0] = -1;
	int k = -1;
	for (int q = 1; q < m; q++) {
		while (k > -1 && toSearch[k + 1] != toSearch[q])
			k = prefix[k];
		if (toSearch[k + 1] == toSearch[q])
			k = k + 1;
		prefix[q] = k;
	}
}
