#include <iostream>
using namespace std;

void countSort(int A[], int n, int k)
{
    int B[n + 1];
    int C[k + 1];

    for (int i = 0; i <= k; i++)
        C[i] = 0;

    for (int j = 1; j <= n; j++)
        C[A[j]] = C[A[j]] + 1;

    for (int i = 1; i <= k; i++)
        C[i] = C[i] + C[i - 1];

    for (int j = n; j >= 1; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    for (int i = 1; i <= n; i++)
        A[i] = B[i];
}

int main()
{
    int n;
    cin >> n;

    int A[n + 1];

    for (int i = 1; i <= n; i++)
        cin >> A[i];

    int k = A[1];
    for (int i = 2; i <= n; i++)
        if (A[i] > k)
            k = A[i];

    countSort(A, n, k);

    for (int i = 1; i <= n; i++)
        cout << A[i] << " ";

    return 0;
}