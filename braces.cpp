
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool match(char a, char b);

int main(int argc, char** argv){
	
	if (argc < 2){
		cout << "Please enter string with braces" << endl;
	}


	cout << "You entered: " << argv[1] << endl;

	stack <char> stk;

	string s = argv[1];

	for (int i = 0; i < s.length(); i++){
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			stk.push(s[i]);
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}'){
			if (stk.empty() || !match(stk.top(), s[i])){
					cout << "No match " << endl;
					return 0;
			}
			stk.pop();
		}		

	}
	if (stk.empty()){
		cout << "Match!" << endl;
		return 1;
	}
	cout << "No Match!" << endl;
}


bool match(char a, char b){
	return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
}
