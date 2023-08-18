#include <iostream>
#include <vector>

using namespace std;

class SubsetSum {
private:
    void backtrack(vector<int>& set, int index, int currentSum, int targetSum, vector<int>& currentSubset, vector<vector<int>>& result) {
        if (currentSum == targetSum) {
            result.push_back(currentSubset);
            return;
        }

        for (int i = index; i < set.size(); ++i) {
            if (currentSum + set[i] <= targetSum) {
                currentSubset.push_back(set[i]);
                backtrack(set, i + 1, currentSum + set[i], targetSum, currentSubset, result);
                currentSubset.pop_back();  // Backtrack
            }
        }
    }

public:
    vector<vector<int>> findSubsetsWithSum(vector<int>& set, int targetSum) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        backtrack(set, 0, 0, targetSum, currentSubset, result);
        return result;
    }
};

int main() {
    SubsetSum subsetSum;
    vector<int> set = {1, 2, 3, 4, 5};
    int targetSum = 7;

    vector<vector<int>> subsets = subsetSum.findSubsetsWithSum(set, targetSum);

    if (subsets.empty()) {
        cout << "No subsets found with the given sum." << endl;
    } else {
        cout << "Subsets with sum " << targetSum << " are:" << endl;
        for (const vector<int>& subset : subsets) {
            cout << "{ ";
            for (int num : subset) {
                cout << num << " ";
            }
            cout << "}" << endl;
        }
    }

    return 0;
}
