// Banking.h
//@author 20123101 ������
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
    int year, month, day;   //�����ꡢ�¡���
    int goal, total_goals;  //���ս����ܽ���
    double salary;          //н�ʣ���������������
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
    string  name, club;             //��Ա���������ֲ�
    int id;                         //������Ա��������
    LinkList<CR> link;              //����Ա������ġ�ְҵ���ı��桱����
};

#endif
