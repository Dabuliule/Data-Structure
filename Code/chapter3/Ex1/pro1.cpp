#include <iostream>
#include "SeqList.h"
using namespace std;

int main()
{
    int n, k, m;
    cin >> n >> k >> m;

    SeqList<int> list(n);
    for (int i = 1; i <= n; ++i){
        list.InsertElem(i);
    }

    int idx1 = 0, idx2 = n - 1;
    while (!list.IsEmpty()) {
        int x, y;                           // x, y 分别代表 HR: X 和 Y 取到的简历号

        idx1 = (idx1 + k - 1) % list.GetLength();
        idx2 = (idx2 - m + 1 + list.GetLength()) % list.GetLength();

        list.GetElem(idx1 + 1, x);          // 取 x
        list.GetElem(idx2 + 1, y);          // 取 y
        if (idx1 == idx2) {                 // 如果 x, y 是同一份简历
            cout << " " << x;
            list.DeleteElem(idx1 + 1, x);       // 取走 x, HRX 逆时针向后走一位，在顺序表中所在位置实际上不变
            if (!list.IsEmpty()) {              // 由于要对 list.GetLength() 取模
                idx2 = (idx2 - 1 + list.GetLength()) % list.GetLength();    // HRY 顺时针向后走一位，在顺序表中所在位置向前减 1
            }
        }
        else {
            cout << " " << x << ", " << y;
            if (idx1 < idx2) {
                list.DeleteElem(idx1 + 1, x);       // 取走 x, 由于 idx1 < idx2, HRX 逆时针向后走一位，在顺序表中所在位置实际上不变
                list.DeleteElem(idx2, y);           // 取走 y, 由于 idx1 < idx2, x 先取走，故实际上 y 为顺序表位置 idx2 处的值
                if (!list.IsEmpty()) {
                    idx2 = (idx2 - 2 + list.GetLength()) % list.GetLength();    // HRY 顺时针向后走一位，在顺序表中所在位置向前减 2
                }
            }
            else {
                list.DeleteElem(idx1 + 1, x);           // 取走 x, 由于 idx1 > idx2, HRX 逆时针向后走一位，在顺序表中所在位置向前减 1
                list.DeleteElem(idx2 + 1, y);           // 取走 y, 由于 idx1 > idx2, HRY 顺时针向后走一位，在顺序表中所在位置向前减 1
                if (!list.IsEmpty()) idx2 = (idx2 - 1 + list.GetLength()) % list.GetLength();
                if (!list.IsEmpty()) idx1 = (idx1 - 1 + list.GetLength()) % list.GetLength();
            }
        }

        if (!list.IsEmpty()) cout << ";";
    }

    cout << endl;

    system("pause");
    return 0;
}