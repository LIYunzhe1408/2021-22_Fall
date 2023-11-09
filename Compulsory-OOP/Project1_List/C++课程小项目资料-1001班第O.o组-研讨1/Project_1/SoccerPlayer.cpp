// Banking.cpp
//@author 20123101 ������
#include "SoccerPlayer.h"
#include <iomanip>

//���캯��
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


//���캯��
FB_player::FB_player(const char* Name, const char* Club, const int Id):name(Name), club(Club)
{
    id = id + 1;
}

string FB_player::Get_name()                //��ȡ��Ա����
{
    return name;
}

void FB_player::Set(const char* Name, const char* Club, const int Id)   //ͨ���ⲿ��Ϣ������Ա�����������ֲ���id
{
    name = Name;
    club = Club;
    id = Id;
}

void FB_player::Change_Club(const char * Name, const char* Club)       //ת�ắ��
{
    name = Name;
    club = Club;
}

void FB_player::Set_Retirment(const char* Name)     //��Ա���ۺ���
{
    name = Name;
    club = "Retirement";
    id = 0;
}

FB_player::operator string() const      //����string()�������������ʾһ�����ֲ�ȫ����Ա��Ϣ
{
    return club;
}

FB_player::operator int() const         //����int()�����
{
    return id;
}



void FB_player::AppendCR(const CR& b)   //�ڡ���Ա�������еĽڵ���롰���ı�������
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

void FB_player::Show(ostream& out) const    //��ʾ����Ա��������
{
    out << "Name: " << name << '\t' << "Club: " << club << '\t' <<"ID: " << id << endl;
}



ostream& operator<<(ostream& out, const FB_player& u)   //��ʾ�����ı��桱������
{
   
    out << "Name: "<< u.name << '\t' << "Club: " << u.club << '\t' << "ID: " << u.id << endl;
    cout << endl;
    out << "    Date\tGoals\tTotal\tSalary" << endl;
    u.link.PutList(out);
    return out;
}
