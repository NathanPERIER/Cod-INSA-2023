#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;


int main() {
	unsigned int v;
	unsigned int c;
	unsigned int h;
	unsigned int l;
	int m;
	cin >> v;
	cin >> c;
	cin >> h;
	cin >> l;
	cin >> m;
	double visc = ((double) v) / 100.0;
	double burnt = (double) m;
	double cooking = (double) c;

	vector<vector<double>> pan(h, vector<double>(l));
	for(unsigned int i = 0; i < h; i++) {
		for(unsigned int j = 0; j < l; j++) {
			pan[i][j] = 0.0;
		}
	}

	unsigned int n_louche;
	cin >> n_louche;
	for(unsigned int i = 0; i < n_louche; i++) {
		unsigned int x;
		unsigned int y;
		unsigned int qty;
		cin >> x;
		cin >> y;
		cin >> qty;
		pan[x][y] = qty;
	}

	bool cooked = false;
	vector<vector<double>> temp(h, vector<double>(l));
	double given;
	unsigned int counter = 0;
	while(!cooked) {
		counter++;
		cooked = true;
		for(unsigned int i = 0; i < h; i++) {
			for(unsigned int j = 0; j < l; j++) {
				temp[i][j] = 0.0;
			}
		}
		for(unsigned int i = 0; i < h; i++) {
			for(unsigned int j = 0; j < l; j++) {
				if(pan[i][j] != 0.0) {
					pan[i][j] -= cooking;
					if(pan[i][j] <= burnt) {
						cout << "la crepe est completement brulee en " << counter << " temps" << endl;
						return 0;
					} else if (pan[i][j] > 0.0) {
						cooked = false;
						given = 0.0;
						if(i > 0) {
							given += pan[i][j] * visc;
							temp[i-1][j] += pan[i][j] * visc;
						}
						if(i < h-1) {
							given += pan[i][j] * visc;
							temp[i+1][j] += pan[i][j] * visc;
						}
						if(j > 0) {
							given += pan[i][j] * visc;
							temp[i][j-1] += pan[i][j] * visc;
						}
						if(j < l-1) {
							given += pan[i][j] * visc;
							temp[i][j+1] += pan[i][j] * visc;
						}
						temp[i][j] += pan[i][j] - given;
					} else {
						temp[i][j] += pan[i][j];
					}
				}
				//cout << temp[i][j] << " ";
			}
			//cout << endl;
		}
		//cout << endl;
		for(unsigned int i = 0; i < h; i++) {
			for(unsigned int j = 0; j < l; j++) {
				pan[i][j] = temp[i][j];
			}
		}
	}

	cout << "la crepe est parfaitement cuite en " << counter << " temps" << endl;

	return 0;
}