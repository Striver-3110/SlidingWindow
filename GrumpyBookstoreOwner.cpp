#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& NotGrumpy, vector<int>& grumpy, int minutes) {
        vector<pair<pair<int, int>, int>> windowDiff;
        if (NotGrumpy.size() == 1) {
            return NotGrumpy[0];
        }
        vector<int> Grumpy;
        int grumpySum = 0, NotGrumpySum = 0, totalSum = 0;
        for (int i = 0; i < NotGrumpy.size(); i++) {
            totalSum += NotGrumpy[i];
            if (grumpy[i] == 0) {
                Grumpy.push_back(NotGrumpy[i]);
            } else {
                Grumpy.push_back(0);
            }
            if (i < minutes) {
                NotGrumpySum += NotGrumpy[i];
                grumpySum += Grumpy[i];
            }
        }

        windowDiff.push_back({{0, minutes - 1}, NotGrumpySum - grumpySum});
        int i = 1, j = minutes;

        int n = NotGrumpy.size();

        while (j < n) {
            NotGrumpySum = NotGrumpySum - NotGrumpy[i - 1] + NotGrumpy[j];
            grumpySum = grumpySum - Grumpy[i - 1] + Grumpy[j];
            windowDiff.push_back({{i, j}, NotGrumpySum - grumpySum});
            i++;
            j++;
        }

        sort(windowDiff.begin(), windowDiff.end(), [](pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) {
            return a.second > b.second;
        });

        i = windowDiff[0].first.first;
        j = windowDiff[0].first.second;
        int ans = 0;

        for (int k = 0; k < n; k++) {
            if (k < i || k > j)
                ans += Grumpy[k];
            else {
                ans += NotGrumpy[k];
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> NotGrumpy = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;

    int result = solution.maxSatisfied(NotGrumpy, grumpy, minutes);

    cout << "Maximum number of satisfied customers: " << result << endl;

    return 0;
}
