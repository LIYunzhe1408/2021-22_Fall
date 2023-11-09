// Banking.h
//@author 20123101 李昀哲
#ifndef BANKING_H
#define BANKING_H
#include "Link.h"
#include <iomanip>



class FB_player;

class CR
{
public:
    CR(int Year = 2020, int Month = 1, int Day = 1, double Goal = 0, double Salary = 5000);
    void Set(int Year, int Month, int Day, int Goal);
    void Bonus(const double &Salary);
    operator double() const;
    friend ostream& operator<<(ostream& out, const CR& b);
    friend class FB_player;


private:
    int year, month, day;   //进球年、月、日
    int goal, total_goals;  //当日进球、总进球
    double salary;          //薪资（会随进球而浮动）
};

class FB_player
{
public:
    FB_player(const char* Name = "NoName", const char* Club = "FreePlayer", const int Id = 0);
    string Get_name();
    void Set(const char* Name, const char* Club, const int Id);
    void Change_Club(const char* Name, const char* Club);
    void Set_Retirment(const char* Name);
    operator string() const;
    operator int() const;
    void AppendCR(const CR& b);
   
    void Show(ostream& out) const;
    friend ostream& operator<<(ostream& out, const FB_player& u);
    friend istream& operator>>(istream& in, FB_player& a)
    {
        char str[80];
        in >> str;	a.name = str;
        in >> str ;	a.club = str;
        return in;
    }
private:
    string  name, club;             //球员姓名、俱乐部
    int id;                         //创建球员分配的序号
    LinkList<CR> link;              //“球员”链表的“职业生涯报告”链表
};

#endif
