## 第一章 C++编程基础
---
### 第一节 如何撰写c++程序
1. main函数是程序的入口
2. `string user_name;`变量声明语句
3. `int main()`函数包含四个部分，返回值（如`int`），表示返回一个整型的变量，名称（如`main`）函数名称最好反映其提供的作用，参数列表（如`()`）括号内提供函数所需的相关参数
4. C++的输入输出由C++标准库提供
5. 包含库文件的目的是为了提供相关类的定义
> 字符分为可打印字符和不可打印字符，如'a'既为可打印字符，'\n'为不可打印字符
---
### 第二节 对象的定义和初始化
1. C++提供了两种初始化对象的方式，使用范围不同，例如：
```C++
{
    int val = 10;
    int val(10);//构造函数语法
}
```
2. 提供两种方法的原因是：
    - = 沿袭于C语言
    - 当对象需要多值进行初始化的时候，我们就要采用构造函数语法进行初始化（进行多值初始化）
3. 各种内置数据类型
---
### 第三节 撰写表达式
1. 算术，关系，逻辑，复合赋值运算符
2. 需要注意整数除法/，与余数运算%，下面一段程序可以帮助理解余数运算：
```C++
{
    //我们希望每行最多输出八个字符串，每个字符串之间含有空格
    const int line_size = 8;
    int cnt = 1;

    // 以下语句被执行多次，且每次执行后cnt+1
    cout << a_string
        << (cnt % line_size == 0)
                        ? '\n'
                        : ' ';
}
```
3. const用来修饰变量，表示常量，如在进行初始化后再次进行更改，会在编译期给出警告
4. `条件 ？ Y值 : N值`是条件表达式，推荐采用上述程序中的写法
5. 运算符的优先级：不知道，套括号
---
### 第四节 条件语句和循环语句
1. 单个if语句，多个if语句，if-else if 语句，嵌套if语句
2. if-else if语句形成了一种非你即我的关系
3. switch语法
```C++
{
 switch(整型表达式)
    case 常量表达式:
    ...
    default:
    ...
}
```
4. switch提供了一种向下穿越的行为模式，即当前的case值匹配成功后，之后的所有case,default语句会直接执行,原因如下段代码：
```C++
{
// 匹配字符，成功cnt自增
switch(next_char)
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        ++cnt;
        break;
    default:
        ...
}
```
5. while循环，for循环，嵌套循环（必须要提供退出循环的条件）
---
### 第五节 如何运用Array和Vector
1. Array必须在定义时指定容器的大小，Vector则不用
2. 可以用Array初始化Vector
### 第六节 指针带来弹性（灵活度）
1. 指针对象可以储存内存地址
2. `&对象` 取地址
3. `*指针` 提领，即找到指针所指的内存地址所在的对象
4. null指针，在对null指针提领时很可能会发生错误，故我们要在这之前进行判断
```C++
{
    if(p)//当p不为空时继续执行
}
```
5. 生成随机数：
```C++
{
    #include<cstdlib.h>

    srand(time(0));//生成随机数种子
    rand()%n;//生成[0,n)的伪随机数
}
```
---
### 第七节 文件的读写
1. `#include<fstream>`提供文件读写对象的定义
2. `ofstream outfile("data.txt",ios_base::out)`定义outfile对象，进行写操作,以丢弃文件内容的方式打开文件
3. `ofstream outfile("data.txt",ios_base::app)`定义outfile对象，进行写操作,以追加的方式打开文件
4. `ifstream infile("data.txt",ios::in)`定义infile对象，进行读操作
5. `fstream iofile("data.txt,ios::in | ios::app")`定义iofile对象，同时进行读写操作
> 文件的默认打开方式是追加，故在进行读操作之前，先要进行iofile.seekg(0)操作，将iofile重新定位至文件开头
6. 通过判断class object的真伪来判断文件是否打开成功
7. `cerr` 标准错误设备
<br><br>

## 第二章 面向过程的编程风格
---
### 第一节 如何编写函数
1. 函数独立的优势：
    - 用函数调用操作取代一大堆代码，使程序简单易读
    - 复用代码
    - 容易分配工作
2. 函数声明时必须写出函数原型，函数原型包括：
    - 返回值类型
    - 函数名称
    - 参数列表
3. 先声明再定义的原因是让调用方可以匹配到函数原型
4. 可以通过 by reference 的方式增加函数的返回值
5. 函数体中必须在每一个可能的退出点提供`return语句`，函数的最后一句结束为其隐式退出点
---
### 第二节 调用函数
1. pass by value 和 pass by reference 的区别：
    - pass by value 复制传入的对象
    - pass by reference 并不复制对象本身，而是复制对象的地址
2. 将参数声明为 reference 的两个理由:
    1. 希望对传入的对象直接进行修改
    2. 降低复制大型对象的额外负担，此时一般声明为    reference to const
3. reference与pointer的差异：
    - 用法不同,reference代表某个对象，pointer指向某个对象的地址
    - 指针需要判断是否为空，引用则无需
4. 内置类型推荐采用pass by value
5. 对象的存活时间（内存的分配）被称为储存期或者范围：
    - local extent
    - file extent
    - dynamic extent
6. 对象的存活区域被称为作用域:
    - local scope
    - static scope
---
### 第三节 提供默认参数
1. 以“参数传递”作为函数沟通的方式比“直接将对象定义在file extent”更适当
2. 提供默认参数的两个规则
    - 提供默认参数的参数及其右边参数必须都要有默认参数
    - 默认参数只能存在与声明或定义其中之一，一般我们将它放在声明中
---
### 第四节 适用局部静态对象
1. local static object 拥有 local scope 以及 file extent
---
### 第五节 声明inline函数
1. 将函数声明为inline,表示要求编译器在每个函数调用点上，将函数的内容展开，编译器可将该函数的调用操作改为以一份函数代码副本代替
2. 声明inline函数是一种空间换时间的做法，通过增大代码体积减少了函数之间的跳转时间
3. 声明inline函数也减少了栈空间的使用
4. 我们通常可以把代码体积小，频繁调用的一些函数声明为inline
5. inline函数一般在头文件中就已经定义好了
---
### 第六节 提供重载函数
1. 重载函数必须有不同的参数列表
2. 将一组实现代码不同但工作内容相似的函数加以重载，可以让用户更容易适用这些函数
---
### 第七节 定义并使用模板函数
1. 模板函数定义示例如下：
```C++
{
    template<typename elemType>
    void display_message(const string& msg,cosnt vector<elemType>& vec);
}
```
2. function template 的参数列表通常都由两种类型构成，一类是明确的类型，另一类是暂缓决定的类型
3. function template 和重载函数有一定的关联，某种意义上，我们可以把function template 视为程序代码的主体不变，仅改变数据类型的重载函数
---
### 第八节 函数指针带来更大的弹性
1. 函数指针即 pointer to function
2. 函数指针的声明：
```C++
{
   const vector<int>* *seq_ptr(int); × //seq_ptr会被认为是一个返回值为指向一个指向const vector<int>类型变量的指针的指针
   const vector<int>* (*seq_ptr)(int); √ //通过小括号改变运算的优先级
}
```
3. 函数指针数组的声明：
```C++
{
   const vector<int>* (*seq_ptr[])(int) = {
        fibon_seq,lucas_seq,pell_seq,
        tring_seq,square_seq,pent_seq
   }
}
```
4. enumerated type的使用：
```C++
{
   enum ns_type{
        ns_fibon,ns_lucas,ns_pell,
        ns_tring,ns_square,ns_pent
   }
}
```
---
### 第九节 设定头文件
1. 多文件编写调用时，我们要把函数声明，以及具有 static scope 的变量声明放在头文件中
2. 函数和变量都是---“只定义一次”，可以有许多份声明
3. 具有 static scope 的变量在头文件作声明时需要加上 extern 关键字（`int a; //a == 0`）
>\> 函数"只定义一次”规则下的例外 ：inline 函数, inline函数的定义要放在头文件中，原因是编译器需要在每个调用点对inline函数展开
>\> 变量“只定义一次”规则下的例外 ：const变量，const变量定义在头文件中，不需要加extern关键字，原因是const变量一出文件外便不可见

<br><br>

## 第三章 泛型编程风格
> 前情提要：STL主要由容器（container）和泛型算法（generic algorithm）构成
> 1. vector 和 list 是 sequential container
> 2. map 和 set 是 associative container
> map是一对对键值对的组合
> set 其中仅含有key
> 3. 泛型算法：
> function template => 与操作对象的类型相互独立；
> iterator( first and last ) => 与容器无关
---
### 第一节 指针的算术运算
1. 我们传入array做参数，传入的并不是数组的副本，而是数组的首地址
2. `*(arr + 7) = arr[7]`
---
### 第二节 了解Itertor（泛型指针） 
1. 泛型指针实质上是一个一个重载了相关运算的运算符的类，每一个容器有属于它们自己的泛型指针
2. 定义iterator需要：
1）迭代器对象的类型 => 决定如何访问下一个元素
2）iterator所指元素的类型 => 决定iterator提领操作的返回值
3. 函数指针和funtion object
---
### 第三节 所有容器的共通操作
- == !=
- =
- empty()
- size()
- clear()
> insert() 和 erase() 的行为视容器为  sequential container 还是 associative container 而定
---
### 第四节 使用顺序性容器
- vector
- list
- deque

1. 产生顺序性容器
```C++
{
    list<string> slist;

    list<int> ilist(1024);//以元素类型的默认值初始化

    list<int> ilist(100,1);

    int ia[8] = {1,2,3,4,5,6,7,8};
    vector<int> ivecr(ia,ia + 8);//通过一对iterator产生容器

    vector<int> ivecr1(ivecr);//通过某个容器产生出新容器
}
```
2. 插入和删除
```C++
{
    特殊化操作：
    push_back();
    pop_back();//三种都提供

    push_front();
    pop_front();//vector不提供

    //pop_back(),pop_front()不会返回被删除的元素值，此时需要
    back();
    front();

    1. 插入操作
    insert(elemType value); //通用

    iterator insert(iterator positon,elemType value);

    void insert(iterator position,int count,elemType value);

    void insert(iterator position,iterator2 first,iterator2 last);

    iterator insert(iterator position);

    2. 删除操作
    erase();

    iterator erase(iterator posit);

    iterator erase(iterator first,iterator last);
}
```
---
### 第五节 使用泛型算法
常用泛型算法：
```C++
{
    //搜索算法
    iterator find(iterator first,iterator last,elemType elem); //适用于无序查找

    bool binary_search(iterator first,iterator last,elemType elem);//适用于有序查找

    int count(iterator first,iterator last,elemType elem);//返回数值相符的元素数目

    search();//查找子序列

    //其他算法
    copy(iterator first,iterator last,iterator2 first);

    sort(iterator first,iterator last);
}
```
---
### 第六节 如何设计一个泛型算法
1. 与操作对象的类型无关 => 使用 funtion template 
2. 与容器无关 => 使用 iterator
3. 与比较操作无关 => 使用 funtion object 或者 pointer to funtion
4. funtion object 是指重载了()运算符的类的对象，在类内编写可以实现内联，效率相较 pointer to funtion 更好
5. binder adapter : 
    - bind1st --- 绑定 binary func 的第一个操作数
    - bind2ed --- 绑定 binary func 的第二个操作数
6. 为什么我们需要 binder adptor,在目前认知中，我认为 binder adptor 的作用是帮助函数减少一个参数
7. negetor adapter :
    - not1 --- 对 unary func 取非
    - not2 --- 对 binary func 取非
---
### 第七节 使用Map
1. map 是键值对（pair）的集合：`map<key_type,value_type> m`
2. map 中添加一个键值对最简单的方法：`map[key] = value`
3. map 对每个键值对查询 key 和 value:`iter->first,iter->second`
4. map 查看某key是否存在的三种方法：
1）直接当作索引使用（有缺点）
2）find()
3）count(),查询键值个数,map中的相同的key最多存在一个（multimap）
--- 
### 第八节 使用Set
1. set 是键值的集合
2. set 中不允许存在相同的键值（multiset）
3. set 的插入，删除，遍历和 sequential continer 类似
4. 与 set 相关的泛型算法:
```C++
{
    set_difference();

    set_intersection();

    set_symmetric_difference();//对称差集

    set_union();
}
```
---
### 第九节 如何使用Iterator Inserter
1. 标准库提供了三个 insertion adaptor
- back_inserter()
- inserter()
- front_inserter()
---
### 第十节 如何使用 iostream iterator
1. 标准库为我们提供了 istream_iterator 和 ostream_iterator 用来进行输入和输出
2. 如何表示end of file:`istream_iterator eof`
3. 使用 iostream iterator:
```C++
{
    istream_iterator is(输入设备);

    ostream_iterator os(输入设备,分隔符);
}
```
4. 可以利用 copy() 进行输入和输出
<br><br>

## 第四章 基于对象的编程风格
---
### 第一节 如何实现一个类
1. 从抽象入手，得到一个类的操作行为（member funtion）以及操作对象（data member）
2. class 定义由两部分组成：class 的声明，以及紧接在声明后的主体
3. pubic : 公开的操作函数和运算符，可以在程序的任何地方被使用；
private : 私有的实现细节，只能在 member funciton 和 friend 里被访问
4. member funtion 定义在类主体时被视为内联函数
5. `::` class scope resolution 运算符
6. 类的定义和相关成员函数的定义一般分别放在头文件和源文件中
---
### 第二节 什么是构造函数和析构函数
1. 构造函数（初始化函数），析构函数（终止函数）
2. 构造函数中应该做的事情是对 data member 进行初始化
3. 构造函数没有返回值，也不需要返回值类型；它的名称和类的名称相同；构造函数可以有参数，故其可以发生重载
3. default constructor，就像基本数据类型定义在 file extent 不进行初始化时编译器给它们提供默认值一样，default constructor 的出现也是提供给类对象的 data member 以默认值。
>`"Triangular t(); " × 会被认为是函数的声明><br>
>"Triangular t;" √`
5. 成员初始化列表（Member initialization list）
```C++
{
    //我们提供如下的 constructor
    Triangular(int len,int beg_pos);//len是数列的长度，beg_pos是该数列的起始位置

    //实现
    Triangular(int len,int beg_pos) 
    : _len(len),_beg_pos(beg_pos),
    _next(beg_pos - 1){}//就像初始化语法中的构造函数语法一样，这种初始化列表通常是为 member class object 提供的
}
```
6. 析构函数：在大多数情况下，我们不需要亲自来写析构函数，编译器在对象的生存周期结束时，会自动调用默认的析构函数来进行内存的释放；析构函数语法：`~类名();`析构函数没有返回值和参数，不存在重载（data member 具有 类对象的 local extent）
7. 当我们在 constructor 中使用 new 在 heap 中开辟内存时，我们需要编写析构函数，来释放这一部分堆中的内存
8. 成员逐一初始化（Memberwise initialization）
```C++
{
    //Matrix类的构造函数
    Matrix(int row,int col)
    :_row(row),_col(col)
    {
        _pmat = new double[row * col];
    }

    {
        Matrix m1(10,5);
        {
           Matrix m2(m1); 
        }
    }
    //此时我们如果直接采用上面的编译器为我们提供的默认拷贝构造函数进行初始化时，m1 的数据成员会逐一拷贝到 m2 中，也就是说，此时在拷贝构造函数中会出现如下语句：
    _pmat = m1._pmat;
    //此时m1._pmat 与 m2._pmat指向堆区的同一块内存，而此时m2 又先于m1 终止，堆中开辟的内存我们要在析构函数中进行手动释放，则当m2释放堆中内存后，m1的_pmat指针依然指向那片内存，此时会发生严重的错误

    //这时我们需要重写拷贝构造函数
    Matrix(const Matrix& m)
    :_row(m._row),_col(m._cal)
    {
        _pmat = new double(_row*_col);//重新在heap中开辟一块内存

        for(int i = 0;i < _row*_col;i++)
        {
            _pamt[i] = m._pmat[i];
        }
    }
}
```
---
### 第三节 何谓 mutable 和 const
1. 常函数的定义语法:
`int length() const{return _length;}`
> 我们需要在成员函数的声明和定义中都加上 const 关键字，拥有 const 关键字的成员函数，编译器会帮助我们检查是否在常函数中对数据成员进行改变
2. `int& length() const{return _length;}`
上述虽为常函数，但通过返回引用值将数据成员_length暴露了出去，允许程序在其他地方修改（和普通函数返回引用值是不同的，普通函数一般不可以返回在函数体内定义的变量的引用值），解决方案：
`const int& length() const{return _length;};`
`int& length(){return _length;}`
提供两份定义，一份为const（常对象调用）,一份为non-const（非常对象调用）
3. 常对象只能调用常函数
4. mutable：可以将要在常函数中改变的那些不改变class object 的常量性的数据成员定义为可变的



