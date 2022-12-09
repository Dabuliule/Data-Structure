#include "Assistance.h"
#include "LinkList.h"

int main()
{
    int n, m, k;
    cin >> n >> k >> m;
    LinkList<int> list;

    for(int i = 1; i <= n; ++i) {
        list.InsertElem(i);                 // 按顺序构造 n 份简历
    }

    int idx1 = 0, idx2 = n - 1;             // idx1 和 idx2 分别代表 HRX 和 HRY 的所在位置 - 1
    while (!list.IsEmpty()) {               // 如果简历未被取完则进入循环
        int x, y;                           // x, y 分别代表 HR: X 和 Y 取到的简历号

        //list.Traverse(Write<int>);
        //cout << ";";
        // 用单链表模拟循环链表
        idx1 = (idx1 + k - 1) % list.GetLength();
        idx2 = (idx2 - m + 1 + list.GetLength()) % list.GetLength();
        //cout << idx1 + 1 << " " << idx2 + 1 << endl;

        list.GetElem(idx1 + 1, x);          // 取 x
        list.GetElem(idx2 + 1, y);          // 取 y
        if (idx1 == idx2) {                 // 如果 x, y 是同一份简历
            cout << " " << x << ";";
            list.DeleteElem(idx1 + 1, x);       // 取走 x, HRX 逆时针向后走一位，在单链表中所在位置实际上不变
            if (!list.IsEmpty()) {              // 由于要对 list.GetLength() 取模
                idx2 = (idx2 - 1 + list.GetLength()) % list.GetLength();    // HRY 顺时针向后走一位，在单链表中所在位置向前减 1
            }
        }
        else {
            cout << " " << x << ", " << y << ";";
            if (idx1 < idx2) {
                list.DeleteElem(idx1 + 1, x);       // 取走 x, 由于 idx1 < idx2, HRX 逆时针向后走一位，在单链表中所在位置实际上不变
                list.DeleteElem(idx2, y);           // 取走 y, 由于 idx1 < idx2, x 先取走，故实际上 y 为单链表位置 idx2 处的值
                if (!list.IsEmpty()) {
                    idx2 = (idx2 - 2 + list.GetLength()) % list.GetLength();    // HRY 顺时针向后走一位，在单链表中所在位置向前减 2
                }
            }
            else {
                list.DeleteElem(idx1 + 1, x);           // 取走 x, 由于 idx1 > idx2, HRX 逆时针向后走一位，在单链表中所在位置向前减 1
                list.DeleteElem(idx2 + 1, y);           // 取走 y, 由于 idx1 > idx2, HRY 顺时针向后走一位，在单链表中所在位置向前减 1
                if (!list.IsEmpty()) idx2 = (idx2 - 1 + list.GetLength()) % list.GetLength();
                if (!list.IsEmpty()) idx1 = (idx1 - 1 + list.GetLength()) % list.GetLength();
            }
        }

        if (!list.IsEmpty()) {                      // 如果还没有被取完
            list.InsertElem(idx1 + 1, ++n);         // Z 拿来一份新简历,放在位置 idx1
            if (idx2 >= idx1) {                     // 如果 idx2 >= idx1
                idx2++;                             // idx2 就往后加 1
            }
        }
    }

    cout << endl;
    system("pause");
    return 0;
}