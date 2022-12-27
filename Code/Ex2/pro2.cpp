#include "Assistance.h" // 辅助软件包
#include "SeqStack.h"   // 循环队列类

int main(void)
{
   SeqStack<int> stk;
   int n, x, d, No;

   cout << "输入车厢数：";
   cin >> n;
   No = 1; //  No表示当前应该进入主轨道右边车厢编号，初始值为1.
   cout << "输入 " << n << " 节车厢的入站顺序：";
   for (int i = 1; i <= n; i++)
   {
      cin >> d;
      if (d == No)
         cout << "第 " << No++ << " 号车厢从主轨道左边进入主轨道右边." << endl;
      else {
         while (stk.Top(x) == SUCCESS && x == No) {
            cout << "第 " << No++ << " 号车厢从辅轨道进入主轨道右边." << endl;
            stk.Pop(x);
         }
         if (d == No)
            cout << "第 " << No++ << " 号车厢从主轨道左边进入主轨道右边." << endl;
         else {
            cout << "第 " << d << " 号车厢从主轨道左边进入辅轨道." << endl;
            stk.Push(d);
         }
      }
   }
   while (stk.Top(x) == SUCCESS && x == No) {
      cout << "第 " << No++ << " 号车厢从辅轨道进入主轨道右边." << endl;
      stk.Pop(x);
   }
   if (stk.IsEmpty())
      cout << "调度完成." << endl;
   else
      cout << "调度无法完成." << endl;

   system("PAUSE");
   return 0;
}