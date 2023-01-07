#ifndef __TIRETREE_H__
#define __TIRETREE_H__

#include "LinkList.h"
#include <functional>

char to_lower(char &c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    return c;
}

class Tire_Node
{
public:
    Tire_Node();

    int count;           // 统计单词个数
    LinkList<int> rows;  // 记录出现该单词的行号
    Tire_Node *next[26]; // 指向各个子树的指针
};

Tire_Node::Tire_Node()
{
    this->count = 0;
    for (int i = 0; i < 26; ++i)
        next[i] = NULL;
}

class Tire_Tree
{
public:
    Tire_Tree();
    ~Tire_Tree();
    void Insert(char *str, int row); // 插入单词
    void InsertRow(char *str, int row); // 插入一行
    void Query(char *str);           // 查询单词

private:
    Tire_Node *root;
};

Tire_Tree::Tire_Tree()
{
    root = new Tire_Node();
}

Tire_Tree::~Tire_Tree()
{
    function<void(Tire_Node *)> destroy = [&](Tire_Node *cur) -> void
    {
        for (int i = 0; i < 26; ++i)
        {
            if (cur->next[i] != NULL)
                destroy(cur->next[i]);
        }
        delete cur;
    };
    destroy(root);
}

void Tire_Tree::Insert(char *str, int row)
{
    Tire_Node *temp = root;
    for (int i = 0; i < strlen(str); ++i)
    {
        int j = to_lower(str[i]) - 'a';
        if (root->next[j] == NULL)
            root->next[j] = new Tire_Node();
        root = root->next[j];
    }
    root->count++;
    root->rows.InsertElem(row);
    root = temp;
}

void Tire_Tree::InsertRow(char *str, int row) {
    char word[20];
    for (int i = 0; i < strlen(str); ++i) {
        if (isalpha(str[i])) {
            int j = 0;
            while (i < strlen(str) && isalpha(str[i])) {
                word[j++] = str[i++];
            }
            word[j] = '\0';
            Insert(word, row);
        }
    }
}

void Tire_Tree::Query(char *str)
{
    Tire_Node *p = root;
    for (int i = 0; i < strlen(str); ++i)
    {
        int j = to_lower(str[i]) - 'a';
        if (p->next[j] == NULL) {
            cout << "单词 " << str << " 出现次数为：" << p->count << endl;
            return;
        }
        p = p->next[j];
    }
    cout << "单词 " << str << " 出现次数为：" << p->count << endl;
    cout << "出现位置所在的行号为：";
    p->rows.Traverse(Write<int>);
    cout << endl;
}

#endif
