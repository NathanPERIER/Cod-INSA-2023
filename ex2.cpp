#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
	unsigned int x;
	unsigned int y;
	unsigned int z;

	cin >> x;
	cin >> y;
	cin >> z;

	if(x <= y * z) {
		cout << "Apero" << endl;
	} else {
		cout << "Pas apero" << endl;
	}

	return 0;
}