#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

#include <numeric>
using std::accumulate;


struct Product {
	unsigned int identifier;
	unsigned int price;
	unsigned int quality;

	bool operator<(const Product& p) const {
        return (identifier < p.identifier);
    }
};

unsigned int accumulator(unsigned int sum, const Product& p) {
	return sum + p.price;
}

bool comparator(const vector<Product>& p1, const vector<Product>& p2) {
	if (p1.size() < p2.size()) {
		return true;
	}
	if (p1.size() == p2.size()) {
		unsigned int s1 = accumulate(p1.begin(), p1.end(), 0, &accumulator);
		unsigned int s2 = accumulate(p2.begin(), p2.end(), 0, &accumulator);
		if (s1 < s2) {
			return true;
		}
	}
	return false;
}


int main() {
	unsigned int n;
	cin >> n;
	vector<Product> products;
	for(unsigned int i = 0; i < n; i++) {
		Product p;
		cin >> p.identifier;
		cin >> p.price;
		cin >> p.quality;
		products.push_back(p);
	}
	sort(products.begin(), products.end());

	Product prev;
	vector<vector<Product>> subsets;
	unsigned int current_len = 0;
	for(unsigned int i = 0; i < n; i++) {
		vector<Product> sub;
		prev = products[i];
		sub.push_back(prev);
		for(unsigned int j = i+1; j < n; j++) {
			if(products[j].price > prev.price && products[j].quality < prev.quality) {
				sub.push_back(products[j]);
				prev = products[j];
			}
		}
		if(sub.size() >= current_len) {
			if(sub.size() > current_len) {
				subsets.clear();
				current_len = sub.size();
			}
			subsets.push_back(sub);
		}
	}
	sort(subsets.begin(), subsets.end(), &comparator);

	vector<Product> max_subset = subsets[subsets.size()-1];
	cout << max_subset.size() << endl;
	for(auto it = max_subset.begin(); it != max_subset.end(); it++) {
		cout << it->identifier << endl;
	}
	
	return 0;
}