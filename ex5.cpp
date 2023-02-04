#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <map>
using std::map;


bool attempt_find_cipher(map<char, char>& cipher, unsigned int offset, string& decrypted, string& message) {
	map<char, char> inverse;
	cipher.clear();
	for(unsigned int i = 0; i < decrypted.size(); i++) {
		unsigned int j = i + offset;
		if(inverse.count(decrypted[i]) == 0) {
			inverse[decrypted[i]] = message[j];
		} else if(inverse[decrypted[i]] != message[j]) {
			return false;
		}
	}
	for(auto it = inverse.begin(); it != inverse.end(); it++) {
		cipher[it->second] = it->first;
	}
	return true;
}


int main() {
	string decrypted;
	string message;
	std::getline(cin, decrypted);
	std::getline(cin, message);

	map<char, char> cipher;
	unsigned int offset = 0;
	while(!attempt_find_cipher(cipher, offset, decrypted, message)) {
		offset++;
	}

	for(unsigned int i = 0; i < message.length(); i++) {
		if(cipher.count(message[i]) == 1) {
			message[i] = cipher[message[i]];
		}
	}

	cout << message << endl;

	return 0;
}