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

//剑指offer调用类
class sword
{
private:
    Solution myque;

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
};


int main()
{
    sword answer;
    answer.stack2queue();
    //system("pause");
    return 0;
}

