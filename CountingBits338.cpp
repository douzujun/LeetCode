#include <iostream>
#include <vector>
using namespace std;

/**
0 1 2   3   4   5
0 1 10  11  100 101
0 1 1   2   1   2
*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for (int i = 1; i <= num; ++i)
        {
        	/*
			    1   2   3  4   5
				0   1   1  2   2
 			   0+1 1+0 1+1 1  1+1 
			*/
        	res[i] = res[i >> 1] + (i & 1);    // i/2
		}
		return res;
    }
};

void test_data()
{
	Solution s;
	vector<int> res;
	res = s.countBits(5);
	for (auto e : res) {
		cout << e << " ";
	}
	cout << endl;
}

int main()
{

	cout << (3 & 1) << endl;      // 11 & 01 == 01
	cout << (8 >> 1) << endl;     // 8 / (1^2)
	
    test_data();

    return 0;

}
