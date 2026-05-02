#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> makeRandomVector(int N)
{
    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        int randomNumber = rand();
        v.push_back(randomNumber);
    }

    return v;
}

void naiveSort(vector<int>& v)
{
    int N = v.size();

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (v[j] < v[i])
            {
                swap(v[i], v[j]);
            }
        }
    }
}

int main()
{
    srand(time(0));   

    int N = 10000;   
   
    vector<int> original = makeRandomVector(N);

    vector<int> copyVector = original;

    auto start1 = chrono::high_resolution_clock::now();

    sort(original.begin(), original.end());

    auto end1 = chrono::high_resolution_clock::now();

    auto duration1 =
        chrono::duration_cast<chrono::nanoseconds>(end1 - start1);

    cout << "std::sort time: " << duration1.count() << " ns" << "\n";

    auto start2 = chrono::high_resolution_clock::now();

    naiveSort(copyVector);

    auto end2 = chrono::high_resolution_clock::now();

    auto duration2 =
        chrono::duration_cast<chrono::nanoseconds>(end2 - start2);

    cout << "naiveSort time: " << duration2.count() << " ns" << "\n";

    return 0;
}