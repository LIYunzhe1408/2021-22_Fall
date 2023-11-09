// Banking.cpp
//@author 20123101 李昀哲
#include "SoccerPlayer.h"
#include <iomanip>

//构造函数
CR::CR(int Year, int Month, int Day, double Goal, double Salary) : year(Year), month(Month), day(Day), goal(Goal), total_goals(0), salary(5000)
{
}

void CR::Set(int Year, int Month, int Day, int Goal)
{
    year = Year;
    month = Month;
    day = Day;
    goal = Goal;
}

CR::operator double() const
{
    return salary;
}

void CR::Bonus(const double &Salary)
{
    salary = Salary *(1 + goal * 0.005);
}


ostream& operator<<(ostream& out, const CR& b)
{
    out << setfill('0');
    out << b.year << '-' << setw(2) << b.month << '-' << b.day << '\t';
    if (b.goal < 0)
        out << '\t' << -b.goal;
    else
        out << b.goal << '\t';
    out << b.total_goals << '\t' << b.salary <<setfill(' ');
    return out;
}
/////////////////////////////////////


//构造函数
FB_player::FB_player(const char* Name, const char* Club, const int Id):name(Name), club(Club)
{
    id = id + 1;
}

string FB_player::Get_name()                //获取球员姓名
{
    return name;
}

void FB_player::Set(const char* Name, const char* Club, const int Id)   //通过外部信息设置球员的姓名、俱乐部、id
{
    name = Name;
    club = Club;
    id = Id;
}

void FB_player::Change_Club(const char * Name, const char* Club)       //转会函数
{
    name = Name;
    club = Club;
}

void FB_player::Set_Retirment(const char* Name)     //球员退役函数
{
    name = Name;
    club = "Retirement";
    id = 0;
}

FB_player::operator string() const      //重载string()运算符，用于显示一个俱乐部全部球员信息
{
    return club;
}

FB_player::operator int() const         //重载int()运算符
{
    return id;
}



void FB_player::AppendCR(const CR& b)   //在“球员”链表中的节点加入“生涯报告链表”
{
    int x;
    double r;
    CR y(b);
    if (link.NumNodes() == 0)
    {
        x = 0;
    }
    else
    {
        link.GoBottom();
        x = link.CurData().total_goals;
    }
    
    y.total_goals = x + b.goal;
    y.Bonus(y.salary);
    link.Append(y);
}

void FB_player::Show(ostream& out) const    //显示“球员”链表函数
{
    out << "Name: " << name << '\t' << "Club: " << club << '\t' <<"ID: " << id << endl;
}



ostream& operator<<(ostream& out, const FB_player& u)   //显示“生涯报告”链表函数
{
   
    out << "Name: "<< u.name << '\t' << "Club: " << u.club << '\t' << "ID: " << u.id << endl;
    cout << endl;
    out << "    Date\tGoals\tTotal\tSalary" << endl;
    u.link.PutList(out);
    return out;
}
