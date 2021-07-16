#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

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
	vector<float> percentsAboveAverage;

	int cases;
	string casesIn;
	getline(cin, casesIn);
	cases = stoi(casesIn);

	while(cases--) {
		string rawInput;
		vector<string> splitInput;

		getline(cin, rawInput);
		splitInput = splitString(rawInput, ' ');

		int classSize = stoi(splitInput.front());
		int sum = 0;

		for (int x = 1; x < splitInput.size(); x++) {
			sum += stoi(splitInput[x]);
		}

		float avg = (sum / classSize);
		int numAboveAvg = 0;

		for (int x = 1; x < splitInput.size(); x++) {
			if (stof(splitInput[x]) > avg) {
				numAboveAvg++;
			}
		}

		float percentAboveAvg = (((float)numAboveAvg / (float)classSize) * 100);
		percentsAboveAverage.push_back(percentAboveAvg);
	}

	for (int x = 0; x < percentsAboveAverage.size(); x++) {
		cout << setprecision(3) << fixed << percentsAboveAverage[x];
		cout << "%" << endl;
	}
}