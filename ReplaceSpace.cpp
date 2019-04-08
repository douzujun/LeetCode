#include <iostream>
using namespace std;

class Solution {
    public:
        void replaceSpace(char *str,int length) {
            //length为字符数组的string的总容量
            if (str == nullptr || length <= 0)
                return;
            
            int originalLen = 0;    //string的实际长度
            int numOfBlack = 0;     //space的个数
            int i = 0;
            while(str[i] != '\0')
            {
                ++originalLen;
                if (str[i] == ' ')
                    ++numOfBlack;
                i++;
            }

            int newLength = originalLen + numOfBlack*2;
            if (newLength > length) 
            {
                return;
            }

            int indexOfOriginal = originalLen;
            int indexOfNew = newLength;
            while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
            {
                if (str[indexOfOriginal] == ' ')
                {
                    str[indexOfNew--] = '0';
                    str[indexOfNew--]= '2';
                    str[indexOfNew--] = '%';
                }
                else {
                    str[indexOfNew--] = str[indexOfOriginal];
                }
                --indexOfOriginal;
            }

        }

};

int main()
{
    Solution s;

    char str[] = " helloworld";
    int len = 20;
    s.replaceSpace(str, len);
    
    int i = 0;
    while (str[i])
    {
        cout << str[i];
        i++;
    }
    cout << endl;

    return 0;

}






