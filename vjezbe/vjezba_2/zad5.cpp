#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include <climits>
#include <ctime>  

using namespace std;

typedef long long ll;

int main()
{
    freopen("ulaz3.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    random_device rand;
    mt19937 gen(rand());
    uniform_int_distribution<> distr(-10, 10);

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        numbers[i] = distr(gen);
    }
    
    int t1 = INT_MIN, t2 = INT_MIN, t3 = INT_MIN;

    //O(n^3)
    clock_t start1 = clock();
    for(int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int temp_sum = 0;
            for (int k = i; k <= j; k++)
            {
                temp_sum += numbers[k];
            }

            if (temp_sum > t1)
            {
                t1 = temp_sum;
            }
        }
    }
    clock_t end1 = clock();
    double duration1 = double(end1 - start1) / CLOCKS_PER_SEC;
    cout << "O(n^3):" << duration1 << " s" << endl;

    //O(n^2)
    clock_t start2 = clock();
    for (int i = 0; i < n; i++)
    {
        int temp_sum = 0;
        for (int j = i; j < n; j++)
        {
            temp_sum += numbers[j];

            if (temp_sum > t2)
            {
                t2 = temp_sum;
            }
        }
    }
    clock_t end2 = clock();
    double duration2 = double(end2 - start2) / CLOCKS_PER_SEC;
    cout << "O(n^2):" << duration2 << " s" << endl;

    //O(n)
    clock_t start3 = clock();
    int temp_sum = 0;

    for (int i = 0; i < n; i++)
    {
        temp_sum += numbers[i];
        if (temp_sum > t3)
        {
            t3 = temp_sum;
        }
        if (temp_sum < 0)
        {
            temp_sum = 0;
        }
    }
    clock_t end3 = clock();
    double duration3 = double(end3 - start3) / CLOCKS_PER_SEC;
    cout << "O(n):" << duration3 << " s" << endl;

    return 0;
}
