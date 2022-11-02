#include "sinhvien.h"
#include "sach.h"
#include "muonTra.h"
#include "draw_line.h"
#include "public_func.h"


typedef struct Node1
{
	SV data1;
	Node1* next1;
}node1;


typedef struct Node2
{
	Sach data2;
	Node2* next2;
}node2;


typedef struct SList1
{
	node1* head1;
	node1* tail1;
}list1;


typedef struct SList2
{
	node2* head2;
	node2* tail2;
}list2;


void khoiTao1(list1& l1)
{
	l1.head1 = NULL;
	l1.tail1 = NULL;
}


void khoiTao2(list2& l2)
{
	l2.head2 = NULL;
	l2.tail2 = NULL;
}


node1 *taoNode1(SV sv)
{
	node1* p1 = new node1;
	if (p1 != NULL)
	{
		p1->data1 = sv;
		p1->next1 = NULL;
	}
	return p1;
}


node2 *taoNode2(Sach s)
{
	node2* p2 = new node2;
	if (p2 != NULL)
	{
		p2->data2 = s;
		p2->next2 = NULL;
	}
	return p2;
}


void themCuoi1(list1& l1, SV sv)
{
	node1* p1 = new node1;
	if (l1.head1 == NULL)
	{
		l1.head1 = p1;
	}
	else
	{
		node1* tmp = l1.head1;
		while (tmp->next1 != NULL)
		{
			tmp = tmp->next1;
		}
		tmp->next1 = p1;
	}
}


void themCuoi2(list2& l2, Sach s)
{
	node2* p2 = new node2;
	if (l2.head2 == NULL)
	{
		l2.head2 = p2;
	}
	else
	{
		node2* tmp = l2.head2;
		while (tmp->next2 != NULL)
		{
			tmp = tmp->next2;
		}
		tmp->next2 = p2;
	}
}


void xuatList1(list1& l1)
{
	node1* tmp = l1.head1;
	if (tmp == NULL)
	{
		cout << "\nDanh sach rong...";
	}
	else
	{
		for (node1* i = l1.head1; i != NULL; i = i->next1)
		{
			SV sv = tmp->data1;
			sv.xuatSV();
		}
	}
}


int main()
{
	int x;
	list1 l1;
	//list2 l2;
	khoiTao1(l1);
	//khoiTao2(l2);
	SV sv;
	do {
		cout << "Them sinh vien?";
		cin >> x;
		if (x != 1)
		{
			continue;
		}
		else
		{
			sv.themSV();
			themCuoi1(l1, sv);
		}
	} while (x == 1);
	cout << "\n";
	xuatList1(l1);
	return 0;
}