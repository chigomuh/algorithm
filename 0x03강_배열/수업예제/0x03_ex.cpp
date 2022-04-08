// // 배열 삽입, 삭제
// #include <bits/stdc++.h>
// using namespace std;

// void insert(int idx, int num, int arr[], int &len)
// {
//     for (int i = idx; i < len; i++)
//     {
//         arr[len + 1 - i] = arr[len - i];
//     }
//     arr[idx] = num;
//     len += 1;
// }

// void erase(int idx, int arr[], int &len)
// {
//     for (int i = idx; i < len - 1; i++)
//     {
//         arr[i] = arr[i + 1];
//     }
//     len -= 1;
// }

// void printArr(int arr[], int &len)
// {
//     for (int i = 0; i < len; i++)
//         cout << arr[i] << ' ';
//     cout << "\n\n";
// }

// void insert_test()
// {
//     cout << "***** insert_test *****\n";
//     int arr[10] = {10, 20, 30};
//     int len = 3;
//     insert(3, 40, arr, len); // 10 20 30 40
//     printArr(arr, len);
//     insert(1, 50, arr, len); // 10 50 20 30 40
//     printArr(arr, len);
//     insert(0, 15, arr, len); // 15 10 50 20 30 40
//     printArr(arr, len);
// }

// void erase_test()
// {
//     cout << "***** erase_test *****\n";
//     int arr[10] = {10, 50, 40, 30, 70, 20};
//     int len = 6;
//     erase(4, arr, len); // 10 50 40 30 20
//     printArr(arr, len);
//     erase(1, arr, len); // 10 40 30 20
//     printArr(arr, len);
//     erase(3, arr, len); // 10 40 30
//     printArr(arr, len);
// }

// int main(void)
// {
//     insert_test();
//     erase_test();
// }

// // STL vector
// #include <bits/stdc++.h>
// using namespace std;

// int main(void)
// {
//     vector<int> v1(3, 5);      // {5, 5, 5};
//     cout << v1.size() << "\n"; // 3
//     v1.push_back(7);           // {5, 5, 5, 7};

//     vector<int> v2(2);             // {0, 0};
//     v2.insert(v2.begin() + 1, +3); // {0, 3, 0};

//     vector<int> v3 = {1, 2, 3, 4};
//     v3.erase(v3.begin() + 2); // {1, 2, 4};

//     vector<int> v4;
//     v4 = v3;                                 // {1, 2, 4};
//     cout << v4[0] << v4[1] << v4[2] << '\n'; // 124
//     v4.pop_back();                           // {1, 2};
//     v4.clear();                              // {};
// }

// vector<int> v1 = {1,2,3,4,5,6};

// for(int e : v1)
// cout << e << ' ';