#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        int current = vec[i];
        int j = i - 1;

        while (j >= 0 && vec[j] > current) {
            vec[j + 1] = vec[j];
            j--;
        }
        
        vec[j + 1] = current;
    }
}

int main() {
    int n;
    cout << "Enter the number of items in the array:";
    cin >> n;

    cout << "Enter the items of the array, space separated: ";
    vector<int> vals;
    while (n--) {
        int temp;
        cin >> temp;
        vals.push_back(temp);
    }

    insertionSort(vals);

    for (int i : vals) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}