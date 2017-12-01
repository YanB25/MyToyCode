 #include <iostream>
 #include <sstream>
#include <cctype>
#include <string>
using namespace std;
int main(){
	string input;
	while(getline(cin, input)){
		if (input == "x") break;
		char lastChar = '\0';
		int times;
		//cout << input;
		istringstream strm(input);
		string output;	
		while (strm) {
			if (!isdigit(strm.peek()) && strm.peek() != EOF){
				strm >> lastChar;
				if (strm.peek() != '0')
					output += lastChar;
			} else if (isdigit(strm.peek())){
				strm >> times;
				if (times >= 1 && lastChar != '\0') {
					output += string(times - 1, lastChar);
				}
			}
		}
		cout << output << endl;
	}
}
