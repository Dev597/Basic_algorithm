# Basic_algorithm
青岛大学王卓视频代码实现

目前正在进行中。请稍等

-----
# 数据结构

## 1. 引入

- 数据的存储结构
  - 顺序结构*

  - 链式结构*

  - 散列存储结构

  - 索引存储结构

- 数据的运算
  - 检索
  - 插入
  - 排序
  - 删除
  - 修改

- 数据的逻辑结构
  - 线性结构
    - 线性表
    - 栈
    - 队列
    - 字符串
    - 数组
    - 广义表

  - 非线性 结构
    - 树形结构
    - 图形结构


- 时间复杂度  （数量级）

  - 一条语句的重复执行次数称作**语句频度**(FrequencyCount)
  - **基本语句：执行次数最多；对算法运行时间贡献最大；嵌套最深的语句。**

  分析方法：

  ​	1.找出语句频度最大的那条语句作为基本语句；

  ​	2.计算基本语句的频度，得到问题规模n的某一个函数；

  ​	3.取其数量级用O表示

- 空间复杂度

## 2. 线性表

|            |                            顺序表                            |                             链表                             |
| :--------: | :----------------------------------------------------------: | :----------------------------------------------------------: |
|  存储空间  |              预先分配，可能会导致空间闲置或溢出              |              动态分配，不会出现空间闲置或者溢出              |
|  存储密度  |       存储密度为1，逻辑关系等于存储关系，没有额外开销        |     存储密度小于1，要借助指针域来表示元素之间的逻辑关系      |
|  存取元素  |           随机存取，按位置访问元素的时间复杂度O(1)           |         顺序存取，访问某位置的元素的时间复杂度为O(n)         |
| 插入、删除 | 插入和删除都要移动大量的元素。平均移动元素约为表的一半。时间复杂度O(n) | 不需要移动元素，只需要改变指针位置，继而改变结点之间的链接关系。时间复杂度O(1) |
|  适用情况  | 1.表长变化不大，或者事先就能确定变化的范围 2.很少进行插入和删除，需要下标访问元素 |              1.长度变化较大 2.频繁的插入和删除               |
|            |                 *这不就是vector的使用特点吗*                 |                  *这不就是list的使用特点吗*                  |

### 线性表的定义和特点

定义：由n(n≥O)个数据特性相同的元素构成的有限序列称为线性表。

![image-20220621204411759](https://raw.githubusercontent.com/Dev597/mypic/master/image-20220621204411759.png)

特点：

- 线性表中元素的个数n(n≥O)定义为线性表的长度，n=0时称为空表。

- 将非空的线性表(n>0)记作(a1，a2，a3，...，an)

- 这里的数据元素ai(1≤i≤n)只是个抽象的符号，其具体含义在不同情况下可以不同。

- 在非空的线性表，有且仅有一个开始结点a1,它没有直接前趋，而仅有一个直接后继a2;

- 有且仅有一个终端结点an,它没有直接后继，而仅有一个直接前趋an-1;

- 其余的内部结点ai,(2<i<n-1)都有且仅有一个直接前趋ai-1和一个直接后继ai+1

顺序存储结构存在问题存储空间分配不灵活；运算的空间复杂度高

### 线性表的类型定义

```
ADT List{  //抽象数据集合
	数据对象
	数据关系
	基本操作
}ADT List
```

基本操作

InitList(&L)  构造一个空的线性表L

DestroyList(&L)  销毁线性表L    线性表存在

ClearList(&L) 将线性表置空    线性表存在

ListEmpty(&L)  判断线性表是否为空，是空返回TRUE   线性表存在

 ListLength(L)  返回线性表元素个数    线性表存在

GetElem(L,i,&e)  用e返回线性表L中的第i个元素   线性表存在，i大于1，小于L长度

LocateElem(L,e,compare())  返回线性表L中,第一个与e满足compare()数据元素的位序，不存在则返回0      线性表存在，compare()为数据元素判定函数

PriorElem(L,cur_e,&pre_e)    若cur是L的数据元素，且不是第一个，用pre返回他的前驱，否则操作失败，pre无意义      线性表存在

NextElem(L,cur_e,&next_e)    若cur是L的数据元素，且不是第一个，用next返回他的后继，否则操作失败，next无意义      线性表存在

ListInsert(&L,i,e) 在L的第i个位置之前插入e，L长度加一              线性表L已存在，i大于1，小于长度加一

ListDelete(&L,i,&e)  删除线性表中第i个元素，用e返回其值，L的长度减一     线性表存在，i大于1，小于长度

ListTraverse(&L,visited())  线性表遍历   线性表存在

### 线性表顺序表示和实现

线性表的第1个数据元素a1的存储位置称为线性表的起始位置或基地址

![image-20220621213621098](https://raw.githubusercontent.com/Dev597/mypic/master/image-20220621213621098.png)

计算地址只算一次与处理数据的规模无关数量级是O(1)这种运算叫随机存取。

线性表长度(length)：当前数据元素个数 

描述顺序存储结构需要三个属性：

- 存储空间的起始位置：数组data,它的存储位置就是存储空间的存储位置。
  线性表的最大存储容量：数组长度MaxSize。
  线性表的当前长度：length。

**特点：**

- 任一元素均可随机存取

- 依次存放

- 随机存取

- 类型相同

- 线性表长度可变（删除） Vector  ,用一变量表示顺序表的长度属性

线性表的第1个数据元素a1的存储位置称为线性表的起始位置或基地址

#### 顺序表

顺序存储结构:逻辑上相邻的数据元素存储在物理上相邻的存储单元中，占用一片连续的存储空间，数组

顺序表代码实现：

```
//SqList.h
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//函数结果状态代码 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status 是函数的类型，其值是函数结果状态代码
typedef int Status;
typedef char ElemType;

#define MAXSIZE 100
//typedef  int  ElemType;

typedef struct
{
	ElemType *elem;//动态分配内存
	//ElemType elem[MAXSIZE];//静态分配内存
	int length;
}SqList;

//动态创建SqList
/**
C语言操作：
	malloc,free
		SqList L;
		L.elem = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
		free(L.elem);
C++语言操作：
	new,delete
	int *p1 = new int(10);
L.elem = new ElemType[MAXSIZE];
*/

//顺序表L的初始化
Status InitList_Sq(SqList &L);

//销毁顺序表L
void DestroyList(SqList &L);

//清空线性表L
void ClearList(SqList &L);

//求线性表L的长度
int GetLength(SqList L);

//判断线性表L是否为空
int IsEmpty(SqList L);

//顺序表的取值（根据位置i获取相应位置数据元素的内容
int GetElem(SqList L, int i, ElemType &e);

//顺序表的查找
int LocateELem(SqList L, ElemType e);

//在线性表L中第i个位置插入新元素e
Status Listlnsert_Sq(SqList &L, int i, ElemType e);

//删除线性表L中第个位置元素，用e返回
Status ListDelete_Sq(SqList &L, int i, ElemType e);

//输出顺序表
Status ListShow_Sq(SqList L);
```



```
//Sqlist.cpp
#include "SqList.h"

//顺序表L的初始化
Status InitList_Sq(SqList &L)
{
	//构造一个空的顺序表
	L.elem = new ElemType[MAXSIZE];//为顺序表分配空间
	if (!L.elem)
		exit(OVERFLOW);
	//存储分配失败
	L.length = 0;
	//空表长度为0
	return OK;
}

//销毁顺序表L
void DestroyList(SqList &L)
{
	if (L.elem)
		delete L.elem;//释放存储空间
}

//清空线性表L
void ClearList(SqList &L)
{
	L.length = 0;
	//将线性表的长度置为0
}

//求线性表L的长度
int GetLength(SqList L)
{
	return(L.length);
}

//判断线性表L是否为空
int IsEmpty(SqList L)
{
	if (L.length == 0)
		return 1;
	else
		return 0;
}

//顺序表的取值（根据位置i获取相应位置数据元素的内容
int GetElem(SqList L, int i, ElemType &e)
{
	if (i<1 || i>L.length)//判断i值是否合理，若不合理，返回ERROR
		return ERROR;
	e = L.elem[i - 1];//第i-1的单元存储着第1个数据
	return OK;
}

//顺序表的查找
/**
	在线性表L中查找与指定值e相同的数据元素的位置
	从表的一端开始，逐个进行记录的关键字和给定值的比较。找到，返
	回该元素的位置序号，未找到，返回0。

	顺序表的查找算法分析
	基本操作：关键字同给定值比较,求平均查找次数
	平均查找长度ASL(Average Search Length):为确定记录在表中的位置，需要与给定值进行比较的关键字的个数的期望值叫做查找算法的平均查找长度。
	
 */
int LocateELem(SqList L, ElemType e)
{
	//在线性表L中查找值为e的数据元素，返回其序号（是第几个元素）
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
			return i + 1;//查找成功，返回序号
	}
	return FALSE;//查找失败，返回0
}

//在线性表L中第i个位置插入新元素e
/**
算法思想：
	①判断插入位置i是否合法。
	②判断顺序表的存储空间是否已满，若已满返回ERROR。
	③将第n至第i位的元素依次向后移动一个位置，空出第个位置。
	④将要插入的新元素e放入第个位置。
	⑤表长加1,插入成功返回OK。
*/
Status Listlnsert_Sq(SqList &L, int i, ElemType e)
{
	if (i < 1 || i > L.length + 1 ) 
		return ERROR;
	if (L.length == MAXSIZE)
		return ERROR;
	for (int j = L.length - 1; j >= i-1 ; --j)
	{
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i-1] = e;
	L.length++;
	return OK;
}

//删除线性表L中第个位置元素，用e返回
/**
	算法思想：
	①判断删除位置i是否合法（合法值为1≤i≤n)。
	②将欲删除的元素保留在e中。
	③将第i+1至第n位的元素依次向前移动一个位置。
	④表长减1,删除成功返回OK。 
 */
Status ListDelete_Sq(SqList &L, int i, ElemType e)
{
	if (i < 1 || i > L.length)
		return ERROR;
	e = L.elem[i - 1];
	for (int j = i; j <= L.length - 1; ++j)
	{
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}

Status ListShow_Sq(SqList L)
{
	if (L.length > 0)
	{
		for (int i = 0; i < L.length ; i++)
		{
			printf("%c  ", L.elem[i]);
		}
		printf("\n");
		return OK;
	}
	else
	{
		return ERROR;
	}
	
}
	
void test01()  
{ 
	//初始化顺序表
	SqList L;
	ElemType elem;
	Status isinit = InitList_Sq(L);
	if (isinit)
	{
		Listlnsert_Sq(L,1,'a');
		Listlnsert_Sq(L, 2, 'b');
		Listlnsert_Sq(L, 3, 'c');
		Listlnsert_Sq(L, 4, 'd');
		Listlnsert_Sq(L, 5, 'e');
	}
	
	ListShow_Sq(L);
	printf("顺序表的长度为%d\n", GetLength(L));
	if (!IsEmpty(L))
	{
		int i = 5;
		if (GetElem(L, i, elem))
		{
			printf("L[%d]值为%c\n", i,elem);
		}
	}

	ListDelete_Sq(L, 1, elem);
	printf("删除1后L 为");
	ListShow_Sq(L);

	printf("在1插入a L为");
	Listlnsert_Sq(L, 1, 'a');
	ListShow_Sq(L);

	ListDelete_Sq(L, 2, elem);
	printf("删除2后L 为");
	ListShow_Sq(L);

	ListDelete_Sq(L, 3, elem);
	printf("删除3后L 为");
	ListShow_Sq(L);

	printf("在2插入V L为");
	Listlnsert_Sq(L, 2, 'V');
	ListShow_Sq(L);

		
	int n = LocateELem(L, 'c');
	printf("c的位置是%d\n", n);



	printf("清空L\n");
	ClearList(L);
	ListShow_Sq(L);

	DestroyList(L);

}

int main()
{
	test01();//测试代码
	system("pause");
	return EXIT_SUCCESS;
	
}
```

1. **查找**算法的算法分析

查找算法的基本操作:将记录的关键字同给定值进行比较(L.elem==e)

![image-20220621215405386](https://raw.githubusercontent.com/Dev597/mypic/master/image-20220621215405386.png)

比较的次数与输入的定值e有关(假设7个数字出现的概率均为1/7)
当e=a，1次；当e=b，2次；当e=c，3次；...e=g,7次
平均比较次数(1+2+3+...+7)/7=4

在查找时，为确定元素在顺序表中的位置，需和给定值进行比较的数据元素个数的期望值称为查找算法在查找成功时的**平均查找长度(AverageSearch Length, ASL)**。

![image-20220621215538549](https://raw.githubusercontent.com/Dev597/mypic/master/image-20220621215538549.png)



查找第一个元素仅需比较一次；而查找表中最后一个记录时，则需比较n次。一般情况下C,等于
假设每个元素的查找概率相等，即
P1=1/n
![image-20220621215641449](https://raw.githubusercontent.com/Dev597/mypic/master/image-20220621215641449.png)

由此可见，顺序表按值查找算法的平均时间复杂度为O(n)。

![image-20220625153016290](https://raw.githubusercontent.com/Dev597/mypic/master/image-20220625153016290.png)



2.插入算法

插入位置在最后在线性表的最后添加一个元素不需要移动直接添加
插入位置在最前在原线性表的第1个元素之前插入一个新的元素，线性表的所有元素都要移动移动次数最多

![image-20220621215833758](https://raw.githubusercontent.com/Dev597/mypic/master/image-20220621215833758.png)

![image-20220625153035867](https://raw.githubusercontent.com/Dev597/mypic/master/image-20220625153035867.png)



3.删除算法

![image-20220621215942534](https://raw.githubusercontent.com/Dev597/mypic/master/image-20220621215942534.png)

![image-20220625153051316](https://raw.githubusercontent.com/Dev597/mypic/master/image-20220625153051316.png)

线性表小结：

查找、插入、删除的平均算法复杂度为O(n)

空间复杂度显然顺序表操作没有占用辅助空间算法的空间复杂度O(1)

线性表的优缺点：

- 优点

​		存储密度大(结点本身所占用的空间/结点结构所占存储量=1)无需为表示表中元素之间的逻辑关系，而增加额外的存储空间

​		可以随机存取表中任意位置的元素

- 缺点

​		插入、删除某一元素需移动大量元素

​		当线性表长度变化较大时，难以确定存储空间的容量，数据元素的个数不能自由扩充(存储空间不灵活)

### 线性表的链式表示和实现

链式存储结构：

- 结点在存储器中的位置是任意的，即逻辑上相邻的数据元素在物理上不一定相邻

- 线性表的链式表示又称为非顺序映像或链式映像。
- 用一组物理位置任意的存储单元来存放线性表的数据元素。
- 这组存储单元既可以是连续的，也可以是不连续的，甚至是零散分布在内存中的任意位置上的。
- 链表中元素的逻辑次序和物理次序不一定相同。



1、结点：数据元素的存储映像。由数据域和指针域两部分组成

2、链表：n个结点由指针链组成一个链表。
它是线性表的链式存储映像，称为线性表的链式存储结构



各节点由两个域组成：

数据域：存储元素数值数据
指针域：存储直接后继结点的存储位置

头指针：
指链表指向第一个结点的指针，若链表有头结点，则是指向头结点的指针;
头指针具有标识作用，所以常用头指针冠以链表的名字;
无论链表是否为空，头指针均不为空。头指针是链表的必要元素

头结点：
头结点是为了操作的统一和方便而设立的，放在第一元素的结点之前，其数据域一般无意义（也可存放链表的长度）
有了头结点，对在第一元素结点前插入结点和删除第一结点，其操作与其它结点的操作就统一了
头结点不一定是链表必须要素

首元结点：是指链表中存储第一个数据元素a1的结点





- 单链表

  单链表由头指针唯一确定，因此单链表可用头指针名字来命名。

  结点只有一个指针域的链表称为单链表或线性链表

  ![image-20220621220712323](https://raw.githubusercontent.com/Dev597/mypic/master/image-20220621220712323.png)

- 双向链表

  结点有两个指针域的链表称为双链表

  ![image-20220621220729542](https://raw.githubusercontent.com/Dev597/mypic/master/image-20220621220729542.png)

  

- 循环链表

  首尾相接的链表叫循环链表

  ![image-20220621220746863](https://raw.githubusercontent.com/Dev597/mypic/master/image-20220621220746863.png)


带头节点和不带头节点两种形式

![image-20220625153243716](https://raw.githubusercontent.com/Dev597/mypic/master/image-20220625153243716.png)

如何表示空表

无头结点时：头指针为空

有头结点时：头结点的指针域为空

设置头节点的好处：

1.便于处理首元节点

2.便于空表和非空表的处理

头结点的数据域的内容

可以为空，也可以存放线性表的长度等信息，头结点不计入链表的长度值

链表（链式存储结构）的特点
(1)结点在存储器中的位置是任意的，即逻辑上相邻的数据元素
在物理上不一定相邻。
(2)访问时只能通过头指针进入链表，并通过每个结点的指针域依次向后顺序扫描其余结点，所以寻找第一个结点和最后一个结点所花费的时间不等这种存取元素的方法被称为顺序存取法

#### 单链表的定义和表示

**单链表的基本操作**

- 单链表的销毁

- 清空单链表

- 求单链表的表长

- 判断链表是否为空

- 取值：取单链表中第1个元素的内容

- 查找：

  - 按值查找：根据指定数据获取该数据所在的

    位置（该数据的地址）

  - 按值查找：根据指定数据获取该数据所在的
    位置序号（是第几个数据元素）

- 插入：在第1个结点前插入新结点

- 删除：删除第i个结点

- 单链表的建立
  头插法时间复杂度O(n)

![image-20220626132651571](https://raw.githubusercontent.com/Dev597/mypic/master/image-20220626132651571.png)

​		尾插法时间复杂度O(n)

![image-20220628201450471](https://raw.githubusercontent.com/Dev597/mypic/master/image-20220628201450471.png)

#### **循环链表**和循环链表合并

循环链表是头尾相接的链表(即表中最后一个结点的指针域指向头结点，整个链表形成一个**环**)(circular linked list)

**优点：**从表中任一结点出发均可访问全部结点

循环链表与单链表的主要**差异**当链表遍历时，判别当前指针p是否指向表尾结点的终止条件不同。

循环单链表的判别条件为p!=L或p->next!=L。

![image-20220629163126307](https://raw.githubusercontent.com/Dev597/mypic/master/img202206291631232.png)

![image-20220629163150008](https://raw.githubusercontent.com/Dev597/mypic/master/img202206291631340.png)

*循环链表的定义*

~~~cpp
typedef struct CLnode
{
    ElemType data;
    CLnode *next;
}*CircList;
~~~

*循环链表的初始化*

~~~cpp
void InitList(CircList &L)
{
    L = new CLnode;
    L->next = L;
}
~~~

循环链表的基本操作和单链表基本上相同，唯一不同的是，由于循环链表的最后一个结点的next不再是空指针，而是指向头结点，因此，循环中的结束条件要发生变化

~~~cpp
单链表--------------循环链表
while(p)--------->while(p!=L)
while(p->next)--->while(p->next!=L)
~~~



#### 双向链表

在双向链表中的结点有两个指针域，一个指向直接后继，另一个指向直接前驱。

![image-20220629163852406](https://raw.githubusercontent.com/Dev597/mypic/master/img202206291638080.png)

双向链表结构

![image-20220629180601424](https://raw.githubusercontent.com/Dev597/mypic/master/img202206291806362.png)

双向循环链表

![image-20220629164112164](https://raw.githubusercontent.com/Dev597/mypic/master/img202206291641823.png)

和单链的循环表类似，双向链表也可以有循环表
·让头结点的前驱指针指向链表的最后一个结点
·让最后一个结点的后继指针指向头结点。

为空是头节点的前驱和后继都指向自身

双向链表结构的对称性（设指针p指向某一结点）:
`p->prior->next  = p =  p->next->prior`

在双向链表中有些操作（如：ListLength、GetElem等）,因仅涉及一个方向的指针，故它们的算法与线性链表的相同。但在插入、删除时，则需同时修改两个方向上的指针，两者的操作的时间复杂度均为O（n)。

**双向链表的插入**

![image-20220629173912572](https://raw.githubusercontent.com/Dev597/mypic/master/img202206291739888.png)

**双向链表的删除**

![image-20220702164708965](https://raw.githubusercontent.com/Dev597/mypic/master/image-20220702164708965.png)



**单链表、循环链表和双向链表的时间效率比较**

![image-20220702184359102](C:/Users/Dev/Desktop/image-20220702184359102.png)

**顺序表和链表的比较**

- 链式存储结构的优点：
  结点空间可以动态申请和释放；
  数据元素的逻辑次序靠结点的指针来指示，插入和删除时不需要移动数据元素。

- 链式存储结构的缺点：
  存储密度小，每个结点的指针域需额外占用存储空间。当每个结点的数据域所占字节不多时，指针域所占存储空间的比重显得很大。

  链式存储结构是非随机存取结构。对任一结点的操作都要从头指针依指针链查找到该结点，这增加了算法的复杂度。

> 存储密度是指结点数据本身所占的存储量和整个结点结构中
> 所占的存储量之比，即：
> 存储密度=-结点数据本身占用的空间  /  结点占用的空间总量 

![image-20220702191024616](https://cdn.jsdelivr.net/gh/dev597/mypic/4616.png)

