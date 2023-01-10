#include "Tire_tree.h"

int main()
{
    Tire_Tree tire; // 创建字典树

    ifstream textfile, wordfile;
    textfile.open("text.txt", ios::in); // 读取文章
    wordfile.open("word.txt", ios::in); // 读取单词
    if (!textfile.is_open() || !wordfile.is_open())
    {
        cout << "读取文件失败" << endl;
        system("pause");
        return 0;
    }

    char str[1024];
    int row = 0;
    while (textfile.getline(str, sizeof(str))) // 按行读取
    {
        tire.InsertRow(str, ++row); // 将 str 中的每个单词都插入到字典树中
    }

    while (wordfile >> str) // 读取单词
    {
        tire.Query(str); // 查询单词
        cout << endl;
    }

    textfile.close(); // 关闭文件
    wordfile.close();

    system("pause");
    return 0;
}