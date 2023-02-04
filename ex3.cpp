#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::find;


struct Point {
	unsigned int x;
	unsigned int y;
};

void next_pos(Point& pt, unsigned int ax, unsigned int cx, unsigned int ay, unsigned int cy, unsigned int n) {
	pt.x = (ax * pt.x + cx) % n;
	pt.y = (ay * pt.y + cy) % n;
}


int main() {
	unsigned int n;
	unsigned int m;
	cin >> n;
	cin >> m;

	vector<vector<string>> region(n);
	for(unsigned int i = 0; i < n; i++) {
		string word;
		for(unsigned int j = 0; j < n; j++) {
			cin >> word;
			region[i].push_back(word);
		}
	}
	Point p;
	cin >> p.x;
	cin >> p.y;

	unsigned int ax;
	unsigned int cx;
	unsigned int ay;
	unsigned int cy;
	cin >> ax;
	cin >> cx;
	cin >> ay;
	cin >> cy;

	vector<string> res;
	for(unsigned int i = 0; i < m; i++) {
		next_pos(p, ax, cx, ay, cy, n);
		if(find(res.begin(), res.end(), region[p.x][p.y]) == res.end()) {
			res.push_back(region[p.x][p.y]);
		}
	}

	for(auto it = res.begin(); it != res.end(); it++) {
		cout << *it << endl;
	}

	return 0;
}
