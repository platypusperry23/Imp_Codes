#include <iostream>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                    cout << "*";
                else if (j <= (i / 2))
                    cout << " ";
                else
                    cout << "*";
            }
            else if (i == n - 1)
            {
                if (j == n - 1)
                    cout << "*";
                else if (j <= (i / 2))
                    cout << "*";
                else
                    cout << " ";
            }
            else if (i == (n / 2 + 1))
                cout << "*";
            else if (i <= n / 2)
            {
                if (j == 0)
                    cout << "*";
                else if (j < n / 2 + 1)
                    cout << " ";
                else if (j == (n / 2 + 1))
                    cout << "*";
                else
                    break;
            }
            else
            {
                if (j == n - 1)
                    cout << "*";
                else if (j < n / 2 + 1)
                    cout<<" ";
                else if (j == (n / 2 + 1))
                    cout << "*";
                else
                    cout << "*";
            }
        }
        cout << endl;
    }
    return 0;
}