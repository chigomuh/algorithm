// // 개발(클린코드)
// #include <iostream>
// int main(void)
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     int n, x;
//     std::cin >> n >> x;
//     int *a = new int[n];
//     for (int i = 0; i < n; i++)
//     {
//         std::cin >> a[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] < x)
//         {
//             std::cout << a[i] << " ";
//         }
//     }
//     delete[] a;
// }
// // 코딩테스트-v1
// #include <bits/stdc++.h>
// using namespace std;
// int n, x, a[10005];
// int main(void)
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n >> x;
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     for (int i = 0; i < n; i++)
//         if (a[i] < x)
//             cout << a[i] << ' ';
// }
// 코딩테스트 v2
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, t;
    cin >> n >> x;
    while (n--)
    {
        cin >> t;
        if (t < x)
            cout << t << ' ';
    }
}