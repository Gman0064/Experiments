#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> variables;
vector<string> operators {"+", "-", "="};

string findVarName(int value) {
	string name = "unknown";
	for (auto it = variables.begin(); it != variables.end(); ++it) {
		if (it->second == value)
        	name = it->first;
	}
	return name;
}

vector<string> splitString(string grades, char token) {
	vector<string> out;
	stringstream ss(grades);
	string buff;
	while(getline(ss, buff, token)) {
		out.push_back(buff);
	}
	return out;
}

int main() {
	string line;
	while(getline(cin, line)) {
		vector<string> lineVec = splitString(line, ' ');
		if (lineVec[0] == "def") {
			if (variables.count(lineVec[1])) {
				variables.at(lineVec[1]) = stoi(lineVec[2]);
			} else {
				variables.insert(pair<string, int>(lineVec[1], stoi(lineVec[2])));
			}
		}
		else if (lineVec[0] == "calc") {
			int result = 0;
			bool invalidVar = false;
			string cachedOp;
			for (int x = 1; x < lineVec.size(); x++) {
				auto varItr = variables.find(lineVec[x]);
				auto opItr = find(operators.begin(), operators.end(), lineVec[x]);
				if (varItr != variables.end()) {
					//the value exists in our map
					if (x == 1) {
						result = varItr->second;
					} else { 
						if (cachedOp == "+") {
							result += varItr->second;
						}
						else if (cachedOp == "-") {
							result -= varItr->second;
						}
					}
				} 
				else if (opItr != operators.end()) {
					if (lineVec[x] == "=") {
						for (int x = 1; x < lineVec.size(); x++) {
							cout << lineVec[x] << " ";
						}
						if (invalidVar) {
							cout << "unknown" << endl;
						}
						else {
							string resultVar = findVarName(result);
							cout << resultVar << endl;
						}
					} else {
						cachedOp = lineVec[x];
					}
				}
				else {
					invalidVar = true;
				}
			}
		}
		else if (lineVec[0] == "clear") {
			map<string, int> newVars;
			variables = newVars;
		}
	}
	return 0;
}
