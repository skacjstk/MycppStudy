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
            if (OutCursor != li.begin()) // 맨 왼쪽이 아니라면
            {
                OutCursor--;
                OutCursor = li.erase(OutCursor); // 삭제
            }
        }
        else if (cmd == 'P')
        {
            cin >> c;
            li.insert(OutCursor, c); // 문자 c 삽입
        }
    }

}
int main()
{
    int M;
    string s = "";

    cin >> s;

    list<char> li(s.begin(), s.end());

    // 커서위치를 입력된 문자 제일 끝에 위치
    cin >> M;
    auto cursor = li.end();
    Solve(li, cursor, M);

    // 연결리스트 출력
    for (cursor = li.begin(); cursor != li.end(); cursor++)
        cout << *cursor;
}