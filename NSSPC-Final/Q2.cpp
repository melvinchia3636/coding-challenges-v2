#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int min = *min_element(arr.begin(), arr.end());
    int max = *max_element(arr.begin(), arr.end());
    int min_count = count(arr.begin(), arr.end(), min);
    int max_count = count(arr.begin(), arr.end(), max);

    arr.erase(remove_if(arr.begin(), arr.end(), [min, max](int i)
                        { return i == min || i == max; }),
              arr.end());

    vector<int> min_vector = vector<int>(min_count, min);
    vector<int> max_vector = vector<int>(max_count, max);

    arr.insert(arr.begin(), min_vector.begin(), min_vector.end());
    arr.insert(arr.end(), max_vector.begin(), max_vector.end());

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}