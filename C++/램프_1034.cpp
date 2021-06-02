#include <bits/stdc++.h>
using namespace std;

int main()
{
    int height, width;
    int ans = -1;
    string arr[50];

    cin >> height >> width;

    for (int y = 0; y < height; y++)
    {
        cin >> arr[y];
    }

    int k;
    cin >> k;

    for (int i = 0; i < height; i++)
    {
        int zeroCount = 0;
        for (int h = 0; h < width; h++)
        {
            if (arr[i][h] == '0')
            {
                zeroCount++;
            }
        }
        int sum = 0;
        if (zeroCount <= k && zeroCount % 2 == k % 2)
        {
            for (int y = 0; y < height; y++)
            {
                if (arr[i] == arr[y])
                {
                    sum++;
                }
            }
        }
        ans = max(sum, ans);
    }
    cout << ans;
}
