// StudyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


//用两个栈实现队列
class Solution
{
public:
    void push(int node) {
        if (stack1.empty() && stack2.empty())
        {
            stack2.push(node);
        }
        else
        {
            while (!stack2.empty())
            {
                auto n = stack2.top();
                stack2.pop();
                stack1.push(n);
            }
            stack1.push(node);
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }
    int pop() {
        if (stack2.empty()) return -1;
        int res = stack2.top();
        stack2.pop();
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

class queue
{
public:
    bool Find(int target, vector<vector<int> > arr)
    {
        int row = arr.size();
        int col = arr[0].size();
        int i = 0, j = col - 1;
        while (i < row && j >= 0)
        {
            if (arr[i][j] > target) j--;
            else if (arr[i][j] < target) i++;
            else return true;
        }
        return false;
    }

    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
        int n = 1;
        vector<int> retMul;
        for (int i = 0; i < len; i++)
        {
            n = 1;
            for (int j = 0; j < len; j++)
            {
                if (j != i)
                {
                    n *= A[j];
                }
            }
            retMul.push_back(n);
        }
        return retMul;
    }

    int CutRope(int number)
    {
        if (2 == number) return 2;
        if (3 == number) return 3;
        if (0 == number % 3) return pow(3, number / 3);
        else if (1 == number % 3) return 4 * pow(3, (number - 4) / 3);
        else return 2 * pow(3, (number - 2) / 3);
    }

    bool findRepeatNum(int numbers[], int length, int* duplication)
    {
        vector<bool> flag(length, false);
        for (int i = 0; i < length; i++)
        {
            if (!flag[numbers[i]]) flag[numbers[i]] = true;
            else
            {
                duplication[0] = numbers[i];
                return true;
            }
        }
        return false;
    }
};

//剑指offer调用类
class sword
{
private:
    Solution myque;
    queue que;

public:
    void stack2queue()
    {
        myque.push(1);
        myque.push(2);
        myque.push(3);
        myque.push(4);
        int n = myque.pop();
        for (int i = 0; i < 4; i++)
        {
            cout << n << "  ";
            n = myque.pop();
        }
    }

    void findNum()
    {
        vector<vector<int>> nums = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
        int tar = 7;
        bool myresult = que.Find(tar, nums);
        cout << "二维数组查找结果：" << myresult;
    }

    void multiply()
    {
        vector<int> mul = { 1, 2, 3, 4, 5 };
        vector<int> retmul;
        retmul = que.multiply(mul);
        for (int i = 0; i < retmul.size();i++)
        {
            cout << retmul[i]<<"  ";
        }
    }

    void CutRope()
    {
        int number;
        cout << "输入绳子长度";
        cin >> number;
        cout<<"最大面积："<<que.CutRope(number);
    }

    void RepeatNum()
    {
        int nums[] = { 2,3,1,0,2,5,3 };
        int length = 7;
        int num[] = { 0 };
        cout<<que.findRepeatNum(nums, length, num);
    }
};


int main()
{
    sword s;
    s.RepeatNum();
    //system("pause");
    return 0;
}

