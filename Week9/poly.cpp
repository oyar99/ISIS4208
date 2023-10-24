#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <complex>
#include <math.h>
#include <assert.h>

using namespace std;
using namespace complex_literals;

typedef complex<double> cd;

vector<cd> ifft(const vector<cd> &);
vector<cd> fft(const vector<cd> &, int);
vector<cd> mult(const vector<cd> &A, const vector<cd> &B);

vector<cd> ifft(const vector<cd> &a)
{
    int n = a.size();

    vector<cd> y = fft(a, -1);

    for (int i = 0; i < n; ++i)
    {
        y[i] /= n;
    }

    return y;
}

vector<cd> fft(const vector<cd> &a, int wf = 1)
{
    int n = a.size();

    if (n == 1)
    {
        return a;
    }

    double alpha = (2 * M_PI / n) * wf;
    cd wn = cos(alpha) + sin(alpha) * 1i;
    cd w = 1.0;

    vector<cd> ao(n >> 1);
    vector<cd> ae(n >> 1);

    for (int i = 0; i < n; ++i)
    {
        if (i & 1)
        {
            ao[(i - 1) >> 1] = a[i];
        }
        else
        {
            ae[i >> 1] = a[i];
        }
    }

    vector<cd> yo = fft(ao, wf);
    vector<cd> ye = fft(ae, wf);

    vector<cd> y(n);

    for (int k = 0; k < n >> 1; ++k)
    {
        y[k] = ye[k] + w * yo[k];
        y[k + (n >> 1)] = ye[k] - w * yo[k];
        w *= wn;
    }

    return y;
}

vector<cd> mult(const vector<cd> &A, const vector<cd> &B)
{
    int n = A.size();
    assert(n == B.size());

    auto AP = fft(A);
    auto BP = fft(B);

    vector<cd> CP(n);

    for (int i = 0; i < n; ++i)
    {
        CP[i] = AP[i] * BP[i];
    }

    return ifft(CP);
}

int main(int argc, char *argv[])
{
    int useNormalMultAlgo = 0;
    if (argc >= 2)
    {
        if (argv[1][0] == 'M')
        {
            useNormalMultAlgo = 1;
        }
    }

    vector<cd> A;
    vector<cd> B;

    int i = 0;
    while (!cin.eof())
    {
        int a, b;
        cin >> a >> b;

        A.push_back(a);
        B.push_back(b);
    }

    if (useNormalMultAlgo == 1)
    {
        vector<cd> C;

        int n = A.size();
        int m = B.size();

        for (int j = 0; j < n + m; j++) {
            for (int k = 0; k < j; k++) {
                C[i] = A[k] * B[j - k];
            }
        }

        int x = C.size();

        for (int i = 0; i < x; ++i)
        {
            cout << C[i] << endl;
        }
    }
    else
    {
        while (A.size() & (A.size() - 1) != 0)
        {
            A.push_back(0);
            B.push_back(0);
        }

        vector<cd> C = mult(A, B);

        for (int i = 0; i < C.size(); ++i)
        {
            cout << (int)C[i].real() << endl;
        }
    }
}