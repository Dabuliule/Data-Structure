#include "Tire_tree.h"

int main()
{
    Tire_Tree tire;

    ifstream textfile, wordfile;
    textfile.open("text.txt", ios::in);
    wordfile.open("word.txt", ios::in);
    if (!textfile.is_open() || !wordfile.is_open())
    {
        cout << "读取文件失败" << endl;
        system("pause");
        return 0;
    }

    char str[1024];
    int row = 0;
    while (textfile.getline(str, sizeof(str)))
    {
        tire.InsertRow(str, ++row);
    }

    while (wordfile >> str)
    {
        tire.Query(str);
        cout << endl;
    }

    textfile.close();
    wordfile.close();

    system("pause");
    return 0;
}