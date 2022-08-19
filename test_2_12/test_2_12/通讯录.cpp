#include<iostream>
using namespace std;
#define MAX 1000
#include <string>
struct person
{
	string name;
	int sex;
	int age;
	string Phone;
	string address;
};
struct Txl
{
	struct person a[MAX];
	int num;
};
void Menu()
{
	cout << "****************************" << endl;
	cout << "******  1:�����ϵ��   *****" << endl;
	cout << "******  2:��ʾ��ϵ��   *****" << endl;
	cout << "******  3:ɾ����ϵ��   *****" << endl;
	cout << "******  4:������ϵ��   *****" << endl;
	cout << "******  5:�޸���ϵ��   *****" << endl;
	cout << "******  6:�����ϵ��   *****" << endl;
	cout << "******  0:�˳�ͨѶ¼   *****" << endl;
	cout << "****************************" << endl;

}
//1.�����ϵ��
void Add_Txl(struct Txl* p)
{

	if (p->num == MAX)
	{
		cout << "��Ǹ ͨѶ¼����" << endl;
		return;
	}
	else
	{//�������
		string name = "0";
		cout << "��������ϵ�˵�����" << endl;
		cin >> name;
		p->a[p->num].name = name;
		//����Ա�
		int sex = 0;
		cout << "��������ϵ�˵��Ա�" << endl;
		cout << "  1  " << endl;
		cout << "  2  " << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1)
			{
				cout << "  ��  " << endl;
				break;
			}
			else if (sex == 2)
			{
				cout << "  Ů  " << endl;
				break;
			}
			else
				cout << "�������� ���������" << endl;
		}
		p->a[p->num].sex = sex;
		//�������
		int age = 0;
		cout << "��������ϵ�˵�����" << endl;
		cin >> age;
		p->a[p->num].age = age;
		//��ӵ绰����
		string Phone;
		cout << "��������ϵ�˵ĵ绰����" << endl;
		cin >> Phone;
		p->a[p->num].Phone = Phone;
		//�����ϵ�˵�ַ
		string address;
		cout << "��������ϵ�˵ĵ�ַ" << endl;
		cin >> address;
		p->a[p->num].address = address;
		//ͨѶ¼����ĿҪ����ȥ��������
		(p->num)++;
		cout << "������ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}
//2.��ʾ��ϵ��  
void shownMenu(struct Txl* p)
	{
		if (p->num == 0)
		{
			cout << "��ǰͨѶ¼Ϊ��" << endl;
		}
		else
		{
			for (int i = 0; i < p->num; i++)
			{
				cout << "��ϵ�˵�����" << p->a[i].name<<"\t";
				cout << "��ϵ�˵��Ա�" << p->a[i].sex << "\t";
				cout << "��ϵ�˵�����" << p->a[i].age << "\t";
				cout << "��ϵ�˵ĵ绰����" << p->a[i].Phone << "\t";
				cout << "��ϵ�˵ļ�ͥסַ" << p->a[i].address << endl;
			}
			system("pause");
			system("cls");
		}


	}
//3.1 
int is_Exit(struct Txl* p, string name)
{
	for (int i = 0; i < p->num; i++)
	{
		if (name == p->a[i].name)

			return i;
	}
	return -1;
}
//3.ɾ��ָ����ϵ��
void deletePerson(struct Txl* p)
{
	string name;
	cout << "��������Ҫɾ������ϵ��" << endl;
	cin >> name;
	int ret = is_Exit(p, name);
	if (ret != -1)
	{
		for (int i = ret; i < p->num; i++)
		{
			p->a[i] = p->a[i + 1];
		}
		(p->num)--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
}
//4.������ϵ��
void findPerson(struct Txl* p)
{
	string name;
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	cin >> name;
	int ret = is_Exit(p, name);
	if (ret != -1)
	{
		cout << "��ϵ�˵�����" << p->a[ret].name << "\t";
		cout << "��ϵ�˵��Ա�" << p->a[ret].sex << "\t";
		cout << "��ϵ�˵�����" << p->a[ret].age << "\t";
		cout << "��ϵ�˵ĵ绰����" << p->a[ret].Phone << "\t";
		cout << "��ϵ�˵ļ�ͥסַ" << p->a[ret].address << endl;
		
	}
	else
	{
		cout << "ͨѶ¼��û�д�����Ϣ" << endl;
	}

}
//5.�޸���ϵ��
void alterPerson(struct Txl* p)
{
	string name;
	int sex;
	int age;
	string Phone;
	string address;
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	cin >> name;
	int ret = is_Exit(p, name);
	if (ret != -1)
	{
		cout << "�������޸ĺ���ϵ�˵�����" << endl;
		cin >> name;
		p->a[ret].name = name;
		cout << "�������޸ĺ���ϵ�˵��Ա�" << endl;
		cout << "  1  " << endl;
		cout << "  2  " << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1)
			{
				cout << "  ��  " << endl;
				break;
			}
			else if (sex == 2)
			{
				cout << "  Ů  " << endl;
				break;
			}
			else
				cout << "�������� ���������" << endl;
		}
		p->a[ret].sex = sex;
		cout << "�������޸ĺ���ϵ�˵�����" << endl;
		cin >> age;
		p->a[ret].age = age;
		cout << "�������޸ĺ���ϵ�˵ĵ绰" << endl;
		cin >> Phone;
		p->a[ret].Phone = Phone;
		cout << "�������޸ĺ���ϵ�˵ĵ�ַ" << endl;
		cin >> address;
		p->a[ret].address = address;
	}

}
//6.�����ϵ��
void cleanPerson(struct Txl* p)
{
	p->num = 0;
	cout << "ͨѶ¼���" << endl;
	system("pause");
	system("cls");
}
int main()
{
	string name;
	int select = 0;
	struct Txl abs;
	//struct Txl* p;
	abs.num = 0;
	while (true)
	{
		Menu();
		cout << "��ѡ����Ҫ���еĲ���:>" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			Add_Txl(&abs);
			break;
		case 2:
			shownMenu(&abs);
			break;
		case 3:
			deletePerson(&abs);
		    break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			alterPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
			break;
		default:
			break;

		}
	}

	return 0;
}