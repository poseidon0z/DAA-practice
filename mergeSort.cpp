#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int start, int mid, int end) {
    vector<int> left_arr;
    vector<int> right_arr;

    for (int i = start; i <= mid; i++) {
        left_arr.push_back(arr[i]);
    }
    
    for (int i = mid + 1; i <= end; i++) {
        right_arr.push_back(arr[i]);
    }

    int left = 0;
    int right = 0;
    int k = start;

    while (left < left_arr.size() && right < right_arr.size()) {
        if (left_arr[left] < right_arr[right]) {
            arr[k++] = right_arr[right++];
        } else {
            arr[k++] = left_arr[left++];
        }
    }

    while (left < left_arr.size()) arr[k++] = left_arr[left++];
    
    while (right < right_arr.size()) arr[k++] = right_arr[right++];
}

void mergeSort(vector<int> &arr, int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = start + ((end - start) / 2);
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
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

    mergeSort(vals, 0, vals.size() - 1);

    for (int i : vals) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

