#include <string>
#include <cassert>
#include <iostream>
using namespace std;

void next(int* n,string p) {
	int m = p.length();
	assert(m > 0);
	assert(n != 0);
	n[0] = 0;
	for (int i = 1;i < m;i++) {
		int k = n[i - 1];
		while (k > 0 && p[i] != p[k]) {
			k = n[k - 1];
		}
		if (p[i] == p[k]) {
			n[i] = k + 1;
		}
		else {
			n[i] = 0;
		}
	}
}

int kmp(string t, string p, int* n, int start) {
	int lastIndex = t.length() - p.length();
	if ((lastIndex - start) < 0) {
		return -1;
	}
	unsigned int i;
	int j = 0;
	for (i = start;i < t.length();i++) {
		while (p[j] != t[i] && j > 0) {
			j = n[j - 1];
		}
		if (p[j] == t[i]) {
			j++;
		}
		if (j == p.length()) {
			return i - j + 1;
		}
	}
	return -1;
}

int main() {
	string s1 = "aaabaccbdababcdba";
	string s2 = "cc";
	int *n = new int[s2.length()];
	next(n, s2);
	int result = kmp(s1, s2, n, 0);
	cout << result << endl;
}