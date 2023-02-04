#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <set>
using std::set;

#include <algorithm>
using std::sort;


struct Box {
	unsigned int num;
	set<unsigned int> access;
};

bool comparator(const Box& b1, const Box& b2) {
	return b1.access.size() < b2.access.size();
}

void make_containing(unsigned int i, const vector<unsigned int>& boxes, vector<set<unsigned int>>& containing) {
	if(containing[i].size() > 0) {
		return;
	}
	containing[i].insert(i+1);
	for(unsigned int j = 0; j < boxes.size(); j++) {
		if(boxes[j] == i+1) {
			containing[i].insert(j+1);
			make_containing(j, boxes, containing);
			for(auto it = containing[j].begin(); it != containing[j].end(); it++) {
				containing[i].insert(*it);
			}
		}
	}
}

unsigned int find_smaller_box(unsigned int b1, unsigned int b2, const vector<Box>& containing_boxes) {
	for(unsigned int i = 0; i < containing_boxes.size(); i++) {
		if(containing_boxes[i].access.find(b1) != containing_boxes[i].access.end() && containing_boxes[i].access.find(b2) != containing_boxes[i].access.end()) {
			return containing_boxes[i].num;
		}
	}
	return 0;
}


int main() {
	unsigned int n;
	vector<unsigned int> boxes;
	cin >> n;
	for(unsigned int i = 0; i < n; i++) {
		int x;
		cin >> x;
		boxes.push_back(x);
	}

	vector<set<unsigned int>> containing(n);
	for(unsigned int i = 0; i < n; i++) {
		make_containing(i, boxes, containing);
	}

	vector<Box> containing_boxes;
	for(unsigned int i = 0; i < n; i++) {
		containing_boxes.push_back({i+1, containing[i]});
	}
	sort(containing_boxes.begin(), containing_boxes.end(), comparator);

	unsigned int n_trials;
	unsigned int b1;
	unsigned int b2;
	unsigned int res;
	cin >> n_trials;
	for(unsigned int i = 0; i < n_trials; i++) {
		cin >> b1;
		cin >> b2;
		res = find_smaller_box(b1, b2, containing_boxes);
		cout << res << endl;
	}

	return 0;
}