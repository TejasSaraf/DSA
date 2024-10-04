#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubArraySum0(int a[], int n)
{

    unordered_map<int, int> m;
    int len = 0;
    int pre = 0;

    for (int i = 0; i < n; ++i)
    {
        pre += a[i];

        if (pre == 0)
        {
            len = max(len, i + 1);
        }
        else if (m.find(pre) != m.end())
        {
            len = max(len, i - m[pre]);
        }
        m[pre] = i;
    }
    return len;
}

int main()
{
    int a[] = {0, -1, -1, 2, 5, 6};
    cout << longestSubArraySum0(a, 6);
}