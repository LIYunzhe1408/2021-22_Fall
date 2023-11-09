// PlayerTestTest.cpp   
//@author 20123101 李昀哲
#include "Link.h"
#include "SoccerPlayer.h"
#include <conio.h>
using namespace std;


template <typename T>
void Search(LinkList<FB_player>& link, const T& t)
{
    int n = 0;
    Node<FB_player>* p;
    p = link.Locate(t, true);
    while (p != NULL)
    {
        n++;
        cout << link.CurData() << endl;
        p = link.Locate(t);
    }
    cout << endl;
    cout << "找到 " << n << " 个球员" << endl;
}

void Info(LinkList<FB_player>& link, int flag)
{
    char str[80], name[80];
    char id[80];
    Node<FB_player>*p = link.CurNode();
    FB_player xUser;
    CR xCR;
    Node<FB_player>* cur_node;
    int choice, year, month, day, goal;
    int n = 0;
    system("cls");
    switch (flag)
    {
    case '1':	
        cout << "请输入查询的俱乐部: ";
        cin >> str;
        Search(link, string(str));
        //link.CurData().Show(cout);			
        break;

    case '2':	
        cout << "请输入查询的ID: ";
        cin >> id;
        Search(link, atoi(id));
        p = link.Locate(atoi(id), true);
        if (p == NULL)
        {
            cout << "输入球员ID有误。" << endl;
            break;
        }
        
        while (true)
        {
            system("cls");
            link.CurData().Show(cout);
            cout << "1 -- 进球信息Goals" << endl;
            cout << "2 -- 查询search" << endl;
            cout << "0 -- 返回return" << endl;
            cout << "Choose:";
            cin >> choice;
            cout << endl;
            if (choice <= 0) break;
            switch (choice)
            {
            case 1:
                while (true)
                {
                    cout << "Year/month/day/goal:";
                    cin >> year >> month >> day >> goal;

                    if (year < 2000 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
                    {
                        cout << "请输入正确日期" << endl;
                        continue;
                    }
                    else if (month == 4 || month == 6 || month == 9 || month == 11)
                    {
                        if (day > 30)
                        {
                            cout << "请输入正确日期" << endl;
                        }
                        continue;
                    }
                    else if (month == 2)
                    {
                        if (day > 29)
                        {
                            cout << "请输入正确日期" << endl;
                        }
                        continue;
                    }
                    break;
                }

                if (goal < 1)
                {
                    cout << "该球员没有进球，无法添加进球信息" << endl;
                    system("pause");
                    system("cls");
                    break;
                }
                xCR.Set(year, month, day, goal);
                link.CurData().AppendCR(xCR);
                cout << link.CurData() << endl;
                system("pause");
                //uLink.Save(filename);
                break;
            case 2:	cout << link.CurData() << endl;
                system("pause");
                break;
            }
        }
        break;
    case '3':
        cout << "请输入需要退役球员的ID和姓名: ";
        cin >> id;
        cin >> name;
        p = link.Locate(atoi(id), true);
        if (p == NULL)
        {
            cout << "输入球员ID有误。" << endl;
            break;
        }
        xUser.Set_Retirment(name);
        link.ModifyData(xUser);
        cout << link.CurData() << endl;
        system("pause");
        break;
    }
}






void PlayerTest()
{
    LinkList<FB_player> uLink;
    FB_player xUser;
    Node<FB_player>* pU;
    CR xCR;
    char club[80], name[80], str[80];
    int choice, year, month, day, goal, k, total_goal, id = 0;
    double money;
    char filename[80] = "FB_players.txt";
    int n = uLink.Load(filename);
    n = 0;

    while (true)
    {
        if (n == 0)
        {
            cout << "A Brand New Account." << endl;
            cout << "新建球员个数：";
            int num = 0;
            cin >> num;
            for (int i = 0; i < num; i++)
            {
                while (true)
                {
                    cout << "输入第 " << i + 1 << " 个 players信息（姓名tab俱乐部（换行）） " << endl;
                    cin >> name; cin >> club;
                    if (atoi(name))
                    {
                        cout << "输入错误，输入必须为人名，请重新输入。" << endl;
                        system("pause");
                        system("cls");
                        continue;
                    }
                    else if (atoi(club))
                    {
                        cout << "输入错误，输入必须为俱乐部名，请重新输入。" << endl;
                        system("pause");
                        system("cls");
                        continue;
                    }
                    else 
                    {
                        break;
                    }
                }
                
                id = id + 1;
                xUser.Set(name, club, id);
                uLink.Append(xUser);
            }

           // n = uLink.Save(filename);
            n++;
            cout << uLink << endl;
        }
        system("pause");
        system("cls");

        cout << "1 -- 增加一个球员" << endl;
        cout << "2 -- 输出全部信息" << endl;
        cout << "3 -- 查询信息" << endl;
        cout << "4 -- 转会" << endl;
        cout << "5 -- 删除球员" << endl;
        cout << "0 -- 退出" << endl;
        cout << "Choose:";
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            
            while (true)
            {
                cout << "输入新增球员数据：姓名（tab）俱乐部（换行）";
                cin >> name; cin >> club;
                if (atoi(name))
                {
                    cout << "输入错误，输入必须为人名，请重新输入。" << endl;
                    system("pause");
                    system("cls");
                    continue;
                }
                else if (atoi(club))
                {
                    cout << "输入错误，输入必须为俱乐部名，请重新输入。" << endl;
                    system("pause");
                    system("cls");
                    continue;
                }
                else
                {
                    break;
                }
            }
            
           
            id = id + 1;
            xUser.Set(name, club, id);
            uLink.Append(xUser);
            //n = uLink.Save(filename);

            break;


        case 2:
            cout << uLink << endl;
            break;


        case 3:
            cout << "根据数据域数据查询。可根据如下三种方式查询。" << endl;
            cout << "1 查看某俱乐部全部球员信息;" << endl;
            cout << "2 选择一个球员增加进球信息; "<< endl;
            cout << "3 退役某球员" << endl;
            k = getche();
            Info(uLink, k);
            break;


        case 4:
            cout << "输入需要转会球员的ID和姓名:";
            cin >> str;
            cin >> name;
            id = atoi(str);
            pU = uLink.Locate(atoi(str), true);
            
            while (true)
            {
                cout << "输入转入俱乐部: ";
                cin >> str;
                if (atoi(str))
                {
                    cout << "输入错误，输入必须为俱乐部名，请重新输入。" << endl;
                    system("pause");
                    system("cls");
                    continue;
                }
                else
                {
                    break;
                }
            }
            xUser.Change_Club(name, str);
            uLink.ModifyData(xUser);
            break;

        case 5:
            cout << "输入需要删除球员的ID:";
            cin >> str;

            id = atoi(str);
            pU = uLink.Locate(atoi(str), true);
            if (pU == NULL)
            {
                cout << "输入球员ID有误。" << endl;
                break;
            }
            uLink.DeleteCurNode();
            break;
        default:
            break;
        }
        
    }
   
}
int main()
{
    void PlayerTestTest();
    PlayerTest();
    return 0;
}