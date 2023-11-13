#include <iostream>
#include <vector>


void merge(std::vector<int> arr1, std::vector<int> arr2, std::vector<int> &arr3){
    int i = 0;
    int j = 0;
    int k = 0;
    while ((i < arr1.size()) && (j < arr2.size())) {
        std::cout << "1 " << arr1[i] << " " << arr2[j] << "\n";
        std::cout.flush();
        std::string s;
        std::cin >> s;
        if (s == "YES") {
            arr3[k] = arr1[i];
            i++;
        } else {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < arr1.size()) {
        arr3[k++] = arr1[i++];
    }
    while (j < arr2.size()) {
        arr3[k++] = arr2[j++];
    }
}

std::vector<int> mergeSort(std::vector<int> arr) {
    if (arr.size() == 1) {
        return arr;
    }
    std::vector<int> arr1(arr.size() / 2);
    std::vector<int> arr2(arr.size() - arr.size() / 2);
    for (int i = 0; i < arr1.size(); i++) {
        arr1[i] = arr[i];
    }
    for (int i = 0; i < arr2.size(); i++) {
        arr2[i] = arr[arr.size() / 2 + i];
    }
    arr1 = mergeSort(arr1);
    arr2 = mergeSort(arr2);
    merge(arr1, arr2, arr);
    return arr;
}


int main() {
    int n;
    std::cin >> n;
    std::vector<int> array(n);
    for (int i = 1; i <= n; i++)
    {
        array[i - 1] = i;
    }
    array = mergeSort(array);
    std::cout << "0 ";
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
    return 0;
}
