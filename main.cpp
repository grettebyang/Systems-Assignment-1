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
    int A[1000000] = {};
    int B[1000000] = {};

    for (int i = 0; i < 1000000; i++)
    {
        A[i] = rand();
        B[i] = rand();
    }

    //Measure from here
    auto start = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++)
    {
        sum += A[i] + B[i];
    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time: " << duration.count() << " microseconds" << endl;
}