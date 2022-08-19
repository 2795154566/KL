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
	cout << "******  1:添加联系人   *****" << endl;
	cout << "******  2:显示联系人   *****" << endl;
	cout << "******  3:删除联系人   *****" << endl;
	cout << "******  4:查找联系人   *****" << endl;
	cout << "******  5:修改联系人   *****" << endl;
	cout << "******  6:清除联系人   *****" << endl;
	cout << "******  0:退出通讯录   *****" << endl;
	cout << "****************************" << endl;

}
//1.添加联系人
void Add_Txl(struct Txl* p)
{

	if (p->num == MAX)
	{
		cout << "抱歉 通讯录已满" << endl;
		return;
	}
	else
	{//添加姓名
		string name = "0";
		cout << "请输入联系人的姓名" << endl;
		cin >> name;
		p->a[p->num].name = name;
		//添加性别
		int sex = 0;
		cout << "请输入联系人的性别" << endl;
		cout << "  1  " << endl;
		cout << "  2  " << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1)
			{
				cout << "  男  " << endl;
				break;
			}
			else if (sex == 2)
			{
				cout << "  女  " << endl;
				break;
			}
			else
				cout << "输入有误 请从新输入" << endl;
		}
		p->a[p->num].sex = sex;
		//添加年龄
		int age = 0;
		cout << "请输入联系人的年龄" << endl;
		cin >> age;
		p->a[p->num].age = age;
		//添加电话号码
		string Phone;
		cout << "请输入联系人的电话号码" << endl;
		cin >> Phone;
		p->a[p->num].Phone = Phone;
		//添加联系人地址
		string address;
		cout << "请输入联系人的地址" << endl;
		cin >> address;
		p->a[p->num].address = address;
		//通讯录的数目要加上去保存下来
		(p->num)++;
		cout << "你已添加成功" << endl;
		system("pause");
		system("cls");
	}
}
//2.显示联系人  
void shownMenu(struct Txl* p)
	{
		if (p->num == 0)
		{
			cout << "当前通讯录为空" << endl;
		}
		else
		{
			for (int i = 0; i < p->num; i++)
			{
				cout << "联系人的姓名" << p->a[i].name<<"\t";
				cout << "联系人的性别" << p->a[i].sex << "\t";
				cout << "联系人的年龄" << p->a[i].age << "\t";
				cout << "联系人的电话号码" << p->a[i].Phone << "\t";
				cout << "联系人的家庭住址" << p->a[i].address << endl;
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
//3.删除指定联系人
void deletePerson(struct Txl* p)
{
	string name;
	cout << "请输入你要删除的联系人" << endl;
	cin >> name;
	int ret = is_Exit(p, name);
	if (ret != -1)
	{
		for (int i = ret; i < p->num; i++)
		{
			p->a[i] = p->a[i + 1];
		}
		(p->num)--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
}
//4.查找联系人
void findPerson(struct Txl* p)
{
	string name;
	cout << "请输入你要查找的联系人" << endl;
	cin >> name;
	int ret = is_Exit(p, name);
	if (ret != -1)
	{
		cout << "联系人的姓名" << p->a[ret].name << "\t";
		cout << "联系人的性别" << p->a[ret].sex << "\t";
		cout << "联系人的年龄" << p->a[ret].age << "\t";
		cout << "联系人的电话号码" << p->a[ret].Phone << "\t";
		cout << "联系人的家庭住址" << p->a[ret].address << endl;
		
	}
	else
	{
		cout << "通讯录中没有此人信息" << endl;
	}

}
//5.修改联系人
void alterPerson(struct Txl* p)
{
	string name;
	int sex;
	int age;
	string Phone;
	string address;
	cout << "请输入要修改的联系人" << endl;
	cin >> name;
	int ret = is_Exit(p, name);
	if (ret != -1)
	{
		cout << "请输入修改后联系人的姓名" << endl;
		cin >> name;
		p->a[ret].name = name;
		cout << "请输入修改后联系人的性别" << endl;
		cout << "  1  " << endl;
		cout << "  2  " << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1)
			{
				cout << "  男  " << endl;
				break;
			}
			else if (sex == 2)
			{
				cout << "  女  " << endl;
				break;
			}
			else
				cout << "输入有误 请从新输入" << endl;
		}
		p->a[ret].sex = sex;
		cout << "请输入修改后联系人的年龄" << endl;
		cin >> age;
		p->a[ret].age = age;
		cout << "请输入修改后联系人的电话" << endl;
		cin >> Phone;
		p->a[ret].Phone = Phone;
		cout << "请输入修改后联系人的地址" << endl;
		cin >> address;
		p->a[ret].address = address;
	}

}
//6.清除联系人
void cleanPerson(struct Txl* p)
{
	p->num = 0;
	cout << "通讯录清空" << endl;
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
		cout << "请选择你要进行的操作:>" << endl;
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
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		default:
			break;

		}
	}

	return 0;
}