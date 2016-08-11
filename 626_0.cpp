#include <vector>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <set>
using namespace std;
typedef char data;



struct node
{
    data val;
    struct node* next;
    struct node* prev;
};
struct node* insertafter(struct node* cur, data dat)
{
    struct node* ne = (struct node*)malloc(sizeof(struct node));
    ne->val = dat;
    ne->next = cur;
    ne->prev = cur->prev;
    cur->prev = ne;
    return ne;
}
struct node* insertbefore(struct node* cur, data dat)
{
    struct node* ne = (struct node*)malloc(sizeof(struct node));
    ne->val = dat;
    ne->next = cur->next;
    ne->prev = cur;
    cur->next = ne;
    return ne;
}
void print(struct node* cur)
{
    struct node* tmp = cur;
    while(1 > 0)
    {
        cout << tmp->val;
        tmp = tmp->next;
        if(tmp == cur)
            break;
    }
    cout << endl;
}

int main(void)
{
    set< pair<char, char> > pr;
    pair<char, char> pa;

    int n;
    cin >> n;
    string tmp, s;

    for(size_t i = 0; i < n; i++)
    {
        cin >> tmp;
        pr.insert(make_pair(tmp[0], tmp[1]));
    }
    cin >> s;
    struct node* li = (struct node*)malloc(sizeof(struct node));
    li->val = '*';
    li->next = li;
    li->prev = li;
    for(size_t i = 0; i < s.length(); i++)
        li = insertbefore(li, s[i]);
    bool flag = true;

    int len = s.length();
    int bad = 0;

    while(bad <= len)
    {
        pa = make_pair(li->val, li->next->val);
        if(pr.find(pa) != pr.end())
        {
            li->prev->next = li->next->next;
            li->next->next->prev = li->prev;
            li = li->prev;
            bad = 0;
        }
        else
        {
            li = li->next;
            bad++;
        }

    }
    while(li->val != '*')
        li = li->next;
    li = li->next;
    while(li->val != '*')
    {
        cout << li->val;
        li = li->next;
    }
    cout << endl;
    return 0;
}
