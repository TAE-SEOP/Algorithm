#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
    long long int n;
    long long int a[3003];
    int b[3003];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
  
    int max = 1;
    for (int i = 0; i < n; i++) { // LIS
        b[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] <= a[i] && b[j] + 1 > b[i]) {
                b[i] = b[j] + 1;
                if (max < b[i]) max = b[i];
            }
        }
    }
    cout << max<<endl;
    return 0;
}

// n^2으로 품.. nlogn인 방식으로 해야함...