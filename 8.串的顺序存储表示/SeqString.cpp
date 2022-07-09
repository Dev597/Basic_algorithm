#include "SeqString.h"



String* initString()
{
	String* s = (String*)malloc(sizeof(String));
	s->data = NULL;
	s->len = 0;
	return s;
}


Status StrAssign(String *S, char *data)
{
	if (&S == NULL || data == NULL)
	{
		delete data;
		return ERROR;
	}
	int len = 0;
	char * temp = data;
	while (*temp)
	{
		len++;
		temp++;
	}
	if (len == 0)
	{
		S->data = NULL;
		S->len = 0;
	}
	else
	{
		temp = data;
		S->len = len;
		S->data = (char *)malloc(sizeof(char) * (len + 1));
		for (int i = 0; i < len; i++, temp++)
		{
			S->data[i] = *temp;
		}
	}
}


void printString(String* s) 
{
	for (int i = 0; i < s->len; i++) {
		printf(i == 0 ? "%c " : "-> %c ", s->data[i]);
	}
	printf("\n");
}


void forceMatch(String* master, String* sub)
{
	int i = 0;
	int j = 0;
	while (i < master->len && j < sub->len)
	{
		if (master->data[i] == sub->data[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == sub->len)
	{
		printf("force match success.\n");
		printf("子串在主串中的位置为%d\n", i - sub->len);
	}
	else
	{
		printf("force match fail.\n");
	}
}


int* getNext(String* s)
{
	int* next = (int*)malloc(sizeof(int) * s->len);
	int i = 0;
	int j = -1;
	next[i] = j;
	while (i < s->len - 1) {
		if (j == -1 || s->data[i] == s->data[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
	return next;
}


void printNext(int* next, int len) 
{
	for (int i = 0; i < len; i++) {
		printf(i == 0 ? "%d " : "-> %d ", next[i] + 1);
	}
	printf("\n");
}


void kmpMatch(String* master, String* sub, int* next) 
{
	int i = 0;
	int j = 0;
	while (i < master->len && j < sub->len) {
		if (j == -1 || master->data[i] == sub->data[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j == sub->len) {
		printf("kmp match success.\n");
		printf("子串在主串中的位置为%d\n", i - sub->len);
	}
	else {
		printf("kmp match fail.\n");
	}
}


void test01()
{
	String* s = initString();
	String* s1 = initString();
	StrAssign(s, "abaabbabc");
	StrAssign(s1, "abc");
	printString(s);
	printString(s1);
	forceMatch(s, s1);
}
void test02()
{
	String* s = initString();
	String* s1 = initString();
	StrAssign(s, "abaabbabc");
	StrAssign(s1, "abc");
	printString(s);
	printString(s1);
	int* next = getNext(s1);
	printNext(next, s1->len);
	kmpMatch(s, s1, next);

}
int main() {

	test02();

	system("pause");
	return 0;
}