#include <iostream>
#include <vector>

using namespace std;

// 병합하는 과정
void merge(vector<int>& v, int l, int m, int r) {
    vector<int> sorted;
    int i = l;
    int j = m + 1;
    while (i <= m && j <= r) {
        if (v[i] < v[j]) {
            sorted.push_back(v[i]);
            i++;
        }
        else {
            sorted.push_back(v[j]);
            j++;
        }
    }

    while (i <= m) {
        sorted.push_back(v[i]);
        i++;
    }

    while (j <= r) {
        sorted.push_back(v[j]);
        j++;
    }

    // 정렬된 결과를 원본 벡터에 반영
    for (int k = 0; k < sorted.size(); k++) {
        v[l + k] = sorted[k];
    }
}

// 원소 낱개로 쪼갠다.
void mergeSort(vector<int>& v, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        merge(v, l, m, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    mergeSort(v, 0, v.size() - 1);

    for (int i = 0; i < n; i++) {
        cout << v[i] << "\n";
    }
}
