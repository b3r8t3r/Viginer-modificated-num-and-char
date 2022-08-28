#include <iostream>
#include <vector>
#include <string>
#include<math.h>
using namespace std;

string Key_Encrypt(string message, int key) {

	vector <vector<char>> alphabet = {
		{'A','B','C','D','E','F','G','H','I','J'},
		{'K','L','M','N','O','P','Q','R','S','T'},
		{'U','V','W','X','Y','Z','A','B','C','D'},
		{'E','F','G','H','I','J','K','L','M','N'},
		{'O','P','Q','R','S','T','U','V','W','X'},
		{'Y','Z','A','B','C','D','E','F','G','H'},
		{'I','J','K','L','M','N','O','P','Q','R'},
		{'S','T','U','V','W','X','Y','Z','A','B'},
		{'C','D','E','F','G','H','I','J','K','L'},
		{'M','N','O','P','Q','R','S','T','U','V'}
	};
	int keyLen = 0;

	for (long long int temp = key; temp > 0; keyLen++) {
		temp /= 10;
	}


	for (int i = 0, t1, t2; i < message.size(); i++) {
		t2 = keyLen - 1 - i;
		if (t2 < 0)
			t2 = (t2 % keyLen + (keyLen)) % keyLen;

		t1 = pow(10, t2);

		int keyPart = ((key / t1) % 10);
		
		int messagePart = int(message[i]- '0');

		message[i] = alphabet[keyPart][messagePart];
	}

	return message;
}

string Key_Decrypt(string message, int key) {

	vector <vector<char>> alphabet = {
		{'A','B','C','D','E','F','G','H','I','J'},
		{'K','L','M','N','O','P','Q','R','S','T'},
		{'U','V','W','X','Y','Z','A','B','C','D'},
		{'E','F','G','H','I','J','K','L','M','N'},
		{'O','P','Q','R','S','T','U','V','W','X'},
		{'Y','Z','A','B','C','D','E','F','G','H'},
		{'I','J','K','L','M','N','O','P','Q','R'},
		{'S','T','U','V','W','X','Y','Z','A','B'},
		{'C','D','E','F','G','H','I','J','K','L'},
		{'M','N','O','P','Q','R','S','T','U','V'}
	};
	int keyLen = 0;

	for (long long int temp = key; temp > 0; keyLen++) {
		temp /= 10;
	}


	for (int i = 0, t1, t2; i < message.size(); i++) {
		t2 = keyLen - 1 - i;
		if (t2 < 0)
			t2 = (t2 % keyLen + (keyLen)) % keyLen;

		t1 = pow(10, t2);

		int keyPart = ((key / t1) % 10);

		for (int j = 0; j < alphabet[i].size()-1; j++) {
			if (message[i] == alphabet[keyPart][j]) message[i] = j + '0';
		}

	}

	return message;
}

int main() {
	string message = "111111";
	int key = 123987;
	message = Key_Encrypt(message, key);
	cout << message << endl;
	message = Key_Decrypt(message, key);
	cout << message << endl;

}