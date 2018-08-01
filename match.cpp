
#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

bool match(char a, char b);
char get_output(char a, char k);

int main(int argc, char** argv){

	string key = "fff";
	cout << "Using key: " << key << endl;

	string del = ",";

	ifstream inFile;
	inFile.open("cipher.txt");

	char x;

	string temp;
	getline(inFile, temp);
	
	//cout << line << endl;


	string token;
	size_t pos = 0;

	int key_index = 0;	

	for (int in = 33; in < 127; in++){
	int broken = 0;

	string line = temp;
	while ((pos = line.find(del)) != string::npos){
		token = line.substr(0, pos);
		line.erase(0, pos+1);
		//cout << "!!" << endl;
		key_index %=3;

		if (key_index != 2){
			key_index++;
			continue;
		}

		int t;

		stringstream ss(token);
		ss >> t;
		char o = get_output(t, in);
		//cout << "Mod " << t << " " << in << endl;

		//cout << o;
		if (o < 32 || o > 122){
			broken = 1;
			//cout << "bad " << (int)o << " " << in << endl;
			break;
		}		

		key_index++;

	}

	if (broken == 0){
		cout << in << endl;	
	}

	}
	cout << endl;

	cout << get_output('k', '*') << endl;

}


string apply_xor(string line, string key){

	

}

char get_output(char a, char k){

	return a^k;

}


bool match(char a, char b){
	return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
}
