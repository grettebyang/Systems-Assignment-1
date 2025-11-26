#include <iostream>
#include <vector>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    srand(time(0));
    int sum = 0;
    int multSum = 0;
    int bsSum = 0;
    int subSum = 0;
    int A[1000000000] = {};
    int B[1000000000] = {};

    for (int i = 0; i < 1000000000; i++)
    {
        A[i] = rand();
        B[i] = rand();
    }

    //Measure from here
    auto start = high_resolution_clock::now();
    for (int i = 0; i < 1000000000; i++)
    {
        if(A[i] < 500000)
        {
            continue;
        }
        sum += (A[i] + B[i]) * (A[i] - B[i]);
    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Time: " << duration.count() << " nanoseconds" << endl;
}