#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

int main() {
	int cases;
	string casesIn;
	getline(cin, casesIn);
	cases = stoi(casesIn);

	while(cases--) {
		string soundsIn;
		vector<string> sounds;

		getline(cin, soundsIn);

		stringstream ss(soundsIn);
		string buff;
		while(getline(ss, buff, ' ')) {
			sounds.push_back(buff);
		}
		
		bool otherAnimals = true;
		while(otherAnimals) {
			string animalIn;
			getline(cin, animalIn);
			if (animalIn.find("?") != string::npos) {
				otherAnimals = false;
				string foxSays;
				for(int i=0; i<sounds.size(); ++i)
				{
					foxSays += sounds[i];
					if (i < (sounds.size() - 1))
					{
						foxSays += " ";
					}
				}
				cout << foxSays << endl;
			}
			else {
				vector<string> sentence;
				string animalSound;

				stringstream ss(animalIn);
				string buff;
				while(getline(ss, buff, ' ')) {
					sentence.push_back(buff);
				}
				if(find(sounds.begin(), sounds.end(), sentence.back()) != sounds.end()) {
					sounds.erase(remove(sounds.begin(), sounds.end(), sentence.back()), sounds.end());
				}
			}
		}
	}
}