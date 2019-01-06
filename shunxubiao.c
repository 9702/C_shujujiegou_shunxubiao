#include <stdio.h>
#include <stdlib.h>
#define Size 5
typedef struct Table {
	int * head;		//声明了一个名为head的长度不确定的数组，也叫“动态数组”
	int length;	//记录当前顺序表的长度
	int size;	//记录顺序表分配的存储容量
}table;
//初始化数据包
table initTable() {
	table t;
	t.head = (int*)malloc(Size * sizeof(int));
	if (!t.head)
	{
		printf("初始化失败");
		exit(0);
	}
	t.length = 0;
	t.size = Size;
	return t;
}
//插入元素
table addTable(table t, int elem, int add)
{
	if (add>t.length + 1 || add<1) {
		printf("插入位置有问题");
		return t;
	}
	if (t.length >= t.size) {
		t.head = (int *)realloc(t.head, (t.size + 1) * sizeof(int));
		if (!t.head) {
			printf("存储分配失败");
		}
		t.size += 1;
	}
	for (int i = t.length - 1; i >= add - 1; i--) {
		t.head[i + 1] = t.head[i];
	}
	t.head[add - 1] = elem;
	t.length++;
	return t;
}
//删除元素
table delTable(table t, int add) {
	if (add>t.length || add<1) {
		printf("被删除元素的位置有误");
		exit(0);
	}
	for (int i = add; i<t.length; i++) {
		t.head[i - 1] = t.head[i];
	}
	t.length--;
	return t;
}
int selectTable(table t, int elem) {
	for (int i = 0; i<t.length; i++) {
		if (t.head[i] == elem) {
			return i + 1;
		}
	}
	return -1;
}
//更改元素
table amendTable(table t, int elem, int newElem) {
	int add = selectTable(t, elem);
	t.head[add - 1] = newElem;
	return t;
}
//输出顺序表中元素的函数
void displayTable(table t) {
	for (int i = 0; i<t.length; i++) {
		printf("%d ", t.head[i]);
	}
	printf("\n");
}
int main() {
	system("title");
	table t1 = initTable();
	int inter;
	int optin;
	//向顺序表中添加元素
	printf("请输入你需要存储的整数型数据：\n");
	for (int i = 1; i <= Size; i++) {
		printf("number %d:",i);
		scanf_s("%d", &t1.head[i - 1]);
		t1.length++;
	}
	printf("原顺序表：\n");
	displayTable(t1);

	printf("输入需要删除的元素:\n");
	scanf_s("%d",&inter);
	t1 = delTable(t1, inter);
	displayTable(t1);

	printf("在位置插入:\n");
	scanf_s("%d",&optin);
	printf("输入你需要插入的元素：\n");
	scanf_s("%d",&inter);
	t1 = addTable(t1, inter, optin);
	displayTable(t1);

	printf("查找元素的位置:\n");
	scanf_s("%d",&inter);
	int add = selectTable(t1, inter);
	printf("%d\n", add);

	printf("将元素:\n");
	scanf_s("%d",&optin);
	printf("改为：\n");
	scanf_s("%d",&inter);
	t1 = amendTable(t1, optin, inter);
	displayTable(t1);
	printf("顺序表中存储的元素分别是：\n");
	displayTable(t1);
	system("pause");
	return 0;
}
