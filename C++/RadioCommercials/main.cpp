#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string n_p;
    string i;
    string np_str;
    string i_str;
    vector<int> n_p_v;
    vector<int> i_v;

    getline(cin, n_p);
    stringstream n_p_ss(n_p);
    while(getline(n_p_ss, np_str, ' ')) {
        n_p_v.push_back(stoi(np_str));
    }

    getline(cin, i);
    stringstream i_ss(i);
    while(getline(i_ss, i_str, ' ')) {
        i_v.push_back(stoi(i_str));
    }

    int best_profit = 0;
    int current_profit = 0;
    for (int i : i_v) {
        current_profit = max(0, current_profit + (i - n_p_v.at(1)));
        best_profit = max(best_profit, current_profit);
    }

    cout << best_profit;

    return 0;
}