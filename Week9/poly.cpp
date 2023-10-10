#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <complex>
#include <math.h>
#include <assert.h>

using namespace std;
using namespace complex_literals;

typedef complex<double> cd;

vector<cd> ifft(vector<cd> &);
vector<cd> fft(vector<cd> &, int);

vector<cd> ifft(vector<cd> &a)
{
    int n = a.size();

    vector<cd> y = fft(a, -1);

    for (int i = 0; i < n; ++i)
    {
        y[i] /= n;
    }

    return y;
}

vector<cd> fft(vector<cd> &a, int wf = 1)
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

vector<cd> mult(vector<cd>& A, vector<cd>& B) 
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

int main()
{
    vector<cd> A;
    vector<cd> B;

    int i = 0;
    while (!cin.eof())
    {
        int a, b; cin >> a >> b;

        A.push_back(a);
        B.push_back(b);
    }

    // 10
    // 16

    while (A.size() & (A.size() - 1) != 0) {
        A.push_back(0);
        B.push_back(0);
    }

    vector<cd> C = mult(A, B);

    for (int i = 0; i < C.size(); ++i) {
        cout << (int)C[i].real() << endl;
    }
}