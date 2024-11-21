#include <iostream>
#include <vector>
#include <map>

using namespace std;

int rodCutRecursive(vector<int> prices, int n) {
    if (n == 0) {
        return 0;
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        answer = max(answer, rodCutRecursive(prices, n - i) + prices[i]);
    }
    return answer;
}

int rodCutMemo(vector<int> prices, int n, map<int, int> &sizePrice) {
    if (sizePrice.find(n) != sizePrice.end()) {
        return sizePrice[n];
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        answer = max(answer, rodCutMemo(prices, n - i, sizePrice) + prices[i]);
    }
    sizePrice[n] = answer;
    return answer;
}

int rodCutBottomUp(vector<int> prices, int n) {
    vector<int> bestPrices(n + 1);
    for (int i = 0; i <= n; i++) {
        bestPrices[i] = prices[i];
        for (int j = 1; j <= i; j++) {
            bestPrices[i] = max(bestPrices[i], bestPrices[i - j] + bestPrices[j]);
        }
    }

    return bestPrices[n];
}

int main() {
    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;

    vector<int> prices(n + 1);
    cout << "Enter the prices for each length: ";
    for (int i = 0; i < n + 1; i++) {
        cin >> prices[i];
    }

    cout << "Recursive: " <<  rodCutRecursive(prices, n) << endl;

    map<int, int> memo;
    memo[0] = 0;
    cout << "Memo: " << rodCutMemo(prices, n, memo) << endl;

    cout << "Bottom Up: " << rodCutBottomUp(prices, n);

    return 0;
}