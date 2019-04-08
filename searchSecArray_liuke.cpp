#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
     bool Find(int target, vector<vector<int> > array)
     {
        unsigned rows = array.size();
        unsigned cols = array[0].size();
        if (array.size() > 0 && rows > 0 && cols > 0)
        {
            int row = 0;
            int col = cols - 1;
            while(row < rows && col >= 0)
            {
                if (array[row][col] == target) {
                   return true; 
                }
                else if (array[row][col] > target) {
                    --col;
                }
                else {
                    row++;
                }
            }
        }
        return false;
     }
};

int main()
{
    vector<vector<int> > v;
    v.push_back({1,2,8,9});
    v.push_back({2,4,9,12});
    v.push_back({4,7,10,13});
    v.push_back({6,8,11,15});

    Solution s;
    if (s.Find(0, v))
    {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }


    if (s.Find(9, v))
    {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    return 0;
}






