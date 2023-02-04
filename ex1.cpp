#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::max_element;

int main() {
	vector<unsigned int> n;
	vector<unsigned int> t;
	unsigned int val;
	vector<double> prop(7);

	for(unsigned int i = 0; i < 7; i++) {
		cin >> val;
		n.push_back(val);
	}
	for(unsigned int i = 0; i < 7; i++) {
		cin >> val;
		t.push_back(val);
	}

	for(unsigned int i = 0; i < 7; i++) {
		prop[i] = ((double)n[i]) / ((double)t[i]);
	}

	unsigned int max = max_element(prop.begin(), prop.end()) - prop.begin();
	switch (max) {
		case 0:
			cout << "CVL";
			break;
		
		case 1:
			cout << "HDF";
			break;

		case 2:
			cout << "Lyon";
			break;

		case 3:
			cout << "Rennes";
			break;

		case 4:
			cout << "Rouen";
			break;

		case 5:
			cout << "Strasbourg";
			break;
		
		default:
			cout << "Toulouse";
			break;
	}
	cout << endl;

	return 0;
}