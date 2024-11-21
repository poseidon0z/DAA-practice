#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixCostRecursive(vector<int> p, int start, int end) {
    if (start + 1 == end) {
        return 0;
    }

    int res = matrixCostRecursive(p, start, start + 1) + matrixCostRecursive(p, start + 1, end) + p[start] * p[start + 1] * p[end];

    for (int k = start + 1; k < end; k++) {
        int temp = matrixCostRecursive(p, start, k) + matrixCostRecursive(p, k, end) + p[start] * p[k] * p[end];

        res = min(temp, res);
    } 

    return res;
}

int matrixCostTopDown(vector<int> p, int start, int end, vector<vector<int>> &memo) {
    if (memo[start][end - 1] != -1) {
        return memo[start][end - 1];
    }

    if (start + 1 == end) {
        memo[start][end - 1] = 0;
        return 0;
    }

    int res = matrixCostTopDown(p, start, start + 1, memo) + matrixCostTopDown(p, start + 1, end, memo) + p[start] * p[start + 1] * p[end];

    for (int k = start + 1; k < end; k++) {
        int temp = matrixCostTopDown(p, start, k, memo) + matrixCostTopDown(p, k, end, memo) + p[start] * p[k] * p[end];
        res = min(temp, res);
    }

    memo[start][end - 1] = res;
    return res;
}

int matrixCostBottomUp(vector<int> p) {
    vector<vector<int>> stuff(p.size(), vector<int> (p.size(), 0));
    for (int i = 0; i < p.size(); i++) {
        stuff[i][i] = 0;
    }

    for (int length = 2; length < p.size(); length++) {
        for (int i = 0; i < p.size() - length; i++) {
            stuff[i][i + length] = INT_MAX;
            for (int j = i + 1; j < i + length; j++) {
                int temp = stuff[i][j] + stuff[j][i + length] + p[i] * p[j] * p[i + length];
                stuff[i][i + length] = min(stuff[i][i + length], temp);
            }

        }
    }
    
    return stuff[0][p.size() - 1];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    vector<int> p;
    cout << "Enter the vector p: ";

    for (int i = 0; i <= n; i++) {
        int temp;
        cin >> temp;
        p.push_back(temp);
    }

    vector<vector<int>> memo(n, vector<int> (n, -1));

    cout << "Recursive: " << matrixCostRecursive(p, 0, n) << endl;
    cout << "Top Down: " << matrixCostTopDown(p, 0, n, memo) << endl;
    cout << "Bottom Up: " << matrixCostBottomUp(p) << endl;
}