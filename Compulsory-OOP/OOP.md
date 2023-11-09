## Basic concept of Object Oriented Programming 

- objects which have common properties can be a class

- 封装：隐藏对象的外部细节
  - 只保留有限的对外接口，exp：电视，只有外壳、插口等
- 继承：意义在于软件的复用；改造扩展已有的类形成新的类
- 多态：同样的消息作用不同对象上可能引起不同的行为
- **java是可以半编译半解释，可以跨平台执行。**



## How a computer storage info ?

- basic function: 算术运算和逻辑运算
- info in cp: 
  - 控制信息
  - 数据信息：整数、实数
- 信息存储单位：
  - 位：bit 一位二进制信息
  - 字节： byte 8位二进制， 1 byte = 8 bit
  - 1kb =  1024 b
  - 1mb = 1024 kb
  - 1 g  = 1024 mb 



##  进制转化

R to 10：位权相加。

10 to R：除R取余，从下往上为从高到低

十进制小数 to R进制小数：乘R取整，一直乘R，直到小数部分为0. 从高到低



## 二进制编码

- 用零或一表示正负**（原码）**会导致零的表示不唯一

### 补码

exp：时针指在6，要想指向3可以顺时针转9小时，也可以逆时针转3小时。

此时，-3和9等价，一圈为12小时，12称为模。9 是-3以12为模的补数：

即：-3 = 9 mod 12

### 补码计算规则：

反码：（负整数）符号位不变，其余位0和1反转

补码：求反末尾+1



## 字符串

- 基本类型中没有字符串变量。只有字符串常量，即双引号中的内容
- 采用字符数组存储字符串，即**C-字符串**，双引号中末尾有\0
- string 类，c++风格字符串



## 初始化列表

```c++
int a = {0};
```

- 例如用double初始化int是不被允许的



## 浮点数是近似存储的，比较时一般比较他们的差是否充分小



## sizeof（）可以计算类或变量占多少字节



## 按位运算

- 按位与：exp：将最低位置为零：

  ```c++
  a = a & 0xfe;
  ```

- 按位或

- 按位异或：^  对应位相同结果为0，不同为1



## 强制转换

```c++
static_cast<int>(x);
```



## 输入输出

将数据从一个对象流动到另一个对象

<< 为插入运算符,  >> 为提取运算符



### 操纵符：

- dec, oct, hex
- ws提取空白符
- endl 插入换行符并刷新流
- stespercision(int)
- setw(int)设置宽度



## 范围for循环

用于遍历一个容器中的序列



## 为已有类型另外命名

using 等同于C中继承而来的typedef

```c++
using Area = double;
typedef double Area;
```



## 枚举类

- 此为自定义类型，已有类型无法满足使用需要

- exp: 星期，若将其作为整数类型，则任意输入一个整数对于星期来说都是合法的，但实际并非如此

- 因此，列出整数的一个子集，{1, 2, 3, 4, 5, 6, 7}

  将其定义为一个新的类型

- #### 定义方式：将全部可取值一一列举出来

- #### 语法形式：

  ```c++
  enum class 枚举类型名：底层类型{枚举值列表};
  枚举类型名::xx;
  
  
  enum class Side{Right, Left};
  enum class Thing{Wrong, Right};
  int main
  {
      Side s = Side::Right;
      Thing w = Thing::Right;
      //无法直接比较两个枚举类的值
  }
  ```

  可以避免枚举名重名

  - **不限定作用域的范围**

  ```C++
  enum Weekday
  {SUN, MON, TUE, WED, THU, FRI, SAT}
  //默认情况下SUN = 0, MON = 1, ...SAT = 6
  ```

     - 枚举类型是常量，不能再对他们进行赋值

     - 例如：不能写赋值表达式

       ```c++
       SUN = 0;
       ```

       - 可以在声明时另行指定枚举元素的值，如

       ```c++
       enum Weekday
       {SUN = 7, MON = 1, TUE = 2, WED = 3, THU = 4, FRI = 5, SAT = 6}
       ```

       - 枚举值可以进行关系运算
       - 但不能直接将整数值赋给枚举变量，强制类型转换

       exp：

       ```C++
       #include <iostream>
       enum GameResult{WIN, LOSE, TIE, CANCEL};
       
       int main
       {
           //可以直接定义也可以，enum GameResult定义
       	GameResult result, omit = CANCEL;
           //可以将枚举值赋给整型变量
       	for (int count = WIN; count <= CANCEL; count++)
       	{
       		result = GameResult(count);
       		if (result == omit)
       		{
       			std::cout << "The game was canceled" << std::endl;
       		}
       		else
       		{
       			std::cout << "The game was played";
       		
       			if (result == WIN)	std::cout << "and we won." <<std::endl;
       			if (result == LOSE)	std::cout << "and we lost." << std::endl;
       			std::cout << std::endl;
       		}
       	}
       	return 0;
       }
       ```

       

## auto 和 decltype类

#### auto：编译器通过初始值自动推断变量的类型

exp:

```c++
auto val = val1 + val2;
```

#### decltype: declation for type

```c++
double i;
//j将定义为oduble类型
decltype(i) j = 2;
```





p34

## 随机数

#### rand函数和srand函数

- srand：
  - 参数：seed产生随机数的种子
  - head file：<cstdlib>
  - 功能：为使rand()产生一序列伪随机整数而设置起始点。使用1作为seed参数，可以重新初始化rand()
- rand（void）
  - 功能：求出并返回一个伪随机数

```c++
#include <iostream>
#include <random>


unsigned int rolldice()
{
    //生成真随机数
    std::random_device random;
    unsigned int dice1 = 1 + random() % 6;
    unsigned int dice2 = 1 + random() % 6;
    std::cout << "The first dice is:" << dice1 << ", and the second dice is:" << dice2 << std::endl;
    unsigned int sum = dice1 + dice2;
    std::cout << "The sum is: " << sum << std::endl;
    return sum;
}

enum Status{WIN, LOSE, PLAYING};

int main()
{
    unsigned int myPoint;
    unsigned int sum = rolldice();
    Status status;

    switch(sum)
    {
        case 7:
        case 11:
            status = WIN;
            break;
        case 2:
        case 3:
        case 12:
            status = LOSE;
            break;
        default:
            status = PLAYING;
            myPoint = sum;
            std::cout << "You are still playing, your sum is:" << myPoint << std::endl;
            break;
    }
    while(status == PLAYING)
    {
        unsigned int temp_sum = 0;
        temp_sum = rolldice();
        if(temp_sum == myPoint) status = WIN;
        if(temp_sum == 7)   status = LOSE;
    }
    if (status == WIN)  std::cout << "You are win!" << std::endl;
    if (status == LOSE) std::cout << "You are lose" << std::endl;
    return 0;
}
```



## 带默认值的函数

- 注意，带默认值的参数必须在最右侧



## 函数重载

- 功能相近的函数在相同的作用域内以相同函数声明，从而形成重载
- 重载是**多态性**的一种体现
- 形参必须**个数不同**或者**类型不同**
- 返回值不能用来区分重载



# 类和对象

## 设计类就是设计类型（语法）

```c++
class xxx
{
//类与外部的接口
public:
//只允许本类中的函数访问（友元也可）
private:
//继承和派生会和private不同
protected:
};
```

## 类的成员函数

- 类中声明函数原型
- 在类外给出函数体的实现，并在函数名前使用类名加以限定
- 也可以直接在类中给出函数体，形成内联成员函数
- 允许声明重载函数和带默认参数值的函数



## 构造函数

- 用于描述初始化算法

### 构造函数形式：

- 函数名与类名相同
- 不能定义返回值类型
- 可以有形式参数， 也可以没有
- 可以是内联函数
- 可以重载
- 可以带默认参数值

**定义对象时会自动调用构造函数。**

隐含构造函数：用类内初始值，若没有，初始值就不可预知

```c++
class Clock
{
public:
    
    Clock(int newH, int newMin, int newSec);//构造函数
    Clock(); //默认构造函数
    
    void set_time(int newH = 0, int newMin = 0, int newSec = 0);
    void showtime();

private:
    int hour = 0, min = 0, sec = 0;
};

//构造函数的实现
Clock::Clock(int newH, int newMin, int newSec):hour(newH), min(newMin), sec(newSec){}//自定义
Clock::Clock():hour(0), min(0),sec(0){}//默认构造函数
```

**一般都会在定义类时加个默认构造函数**

```c++
Clock t1(12, 20, 34);//使用后自己的构造函数
Clock timer;//使用默认构造函数
```

p59

### 委托构造函数：

原代码：

```c++
Clock(int newH, int newM, int newS):
hour(newH), minute(newM), second(newS){}
Clock():hour(0), minute(0), second(0){}
```

委托构造函数代码：

```c++
Clock(int newH, int newM, int newS):
hour(newH), minute(newM), second(newS){}
Clock():Clock(0, 0, 0){}//直接使用有参数的构造函数
```

### 复制构造函数：

作用：用一个已经存在的对象去初始化对象

用引用作为参数。

编译器会生成一个默认的复制构造函数；

but，有时不尽如人意。只需要复制部分功能时

#### 定义：形参必须是同类对象的引用

```c++
class x{
public:
x(); //构造函数
x(const x &对象名)； //复制构造函数。加const会保障实参的安全性
...
}
x::x(const x &对象名){}//实现
```

使用情况：

	- 定义一个对象
	- 成员函数的形参是类的对象，调用函数时，将使用实参对象初始化形参对象
	- 函数的返回值是类的对象

指示编译器不要生成默认构造函数：

```c++
x(const x &p) =delete;
```



### 析构函数





## 类的组合

类中的成员是另一个类的对象

构造函数时，可能会不给部件对象传参数

```c++
#include <iostream>
#include <random>


class Point
{
public:
    Point():x(0), y(0){}
    Point(double xx, double yy):x(xx), y(yy){}
    Point(const Point &p):x(p.x), y(p.y){}
    double getX(){return x;};
    double getY(){return y;};
private:
    double x, y;
};

class Line
{
public:
    Line(Point xp1, Point xp2):p1(xp1), p2(xp2)
    {
        double x = p1.getX() - p2.getX();
        double y = p1.getY() - p2.getY();
        len = sqrt(x*x + y*y);}
    Line(const Line &l):p1(l.p1), p2(l.p2){len = l.len;}
    double getLen(){return len;};
private:
    Point p1, p2;
    double len;
};

int main()
{
    Point p(1, 1), q(4, 5);
    Line line(p, q);
    std::cout << line.getLen() << std::endl;

    return 0;
}
```



P73







P84

# 数组的存储

内存中顺次存放，地址是连续的。

数组名是数组首元素的内存地址







# **(lee_s)**

在类体中声明常量成员函数的函数原型为int GetHour() const;
在类体外定义常量成员函数的格式为：

```c++
 int Time::GetHour() const  // 定义常量成员函数
 {
    return h;
 }
```

相当于

```c++
int Time::GetHour(const Time *const this)   const // 常量成员函数中的隐含参数this为常量指针常量 
 {
    return h;
 }
```

#### 拷贝构造函数

同一类的常引用

```c++
Student(const Student &s);
```





构造函数时要用自己的资源，

对象的空间 = 基本空间 + 资源空间（how?)

使对象拥有独立的资源，修改构造函数：













