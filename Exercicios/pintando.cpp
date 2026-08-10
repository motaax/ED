#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    float l1, l2, l3;
    cin >> l1 >> l2 >> l3;

    float p = (l1 + l2 + l3) / 2.0;

    float area = sqrt(p*(p-l1)*(p-l2)*(p-l3));

    cout << fixed << setprecision(2) << area << "\n";

    return 0;
}