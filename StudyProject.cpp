// StudyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int pi = 3.14;

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
        int res = stack2.top();
        stack2.pop();
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
int main()
{

    Solution s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    int n = s.pop();
    for (int i = 0;i<4;i++)
    {
        cout << n<<"  ";
        n = s.pop();
    }

    //system("pause");
    return 0;
}

