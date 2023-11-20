#include <iostream>
#include <string>
#include <list>
using namespace std;

void Solve(list<char>& li, list<char>::iterator& OutCursor, int M)
{
    for (int i = 0; i < M; i++)
    {
        char cmd, c;
        cin >> cmd;

        if (cmd == 'L')
        {
            if (OutCursor != li.begin())
                OutCursor--;
        }
        else if (cmd == 'D')
        {
            if (OutCursor != li.end())
                OutCursor++;
        }
        else if (cmd == 'B')
        {
            if (OutCursor != li.begin()) // �� ������ �ƴ϶��
            {
                OutCursor--;
                OutCursor = li.erase(OutCursor); // ����
            }
        }
        else if (cmd == 'P')
        {
            cin >> c;
            li.insert(OutCursor, c); // ���� c ����
        }
    }

}
int main()
{
    int M;
    string s = "";

    cin >> s;

    list<char> li(s.begin(), s.end());

    // Ŀ����ġ�� �Էµ� ���� ���� ���� ��ġ
    cin >> M;
    auto cursor = li.end();
    Solve(li, cursor, M);

    // ���Ḯ��Ʈ ���
    for (cursor = li.begin(); cursor != li.end(); cursor++)
        cout << *cursor;
}