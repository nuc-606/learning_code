#include<iostream>
using namespace std;
class Person
{
private:
    int age;
    char name[10];
    int sex;
public:
    Person()
    {
        cout << "���������������Ա�";
        cin >> age >> name >> sex;
        cout << "p1��";
    };//�޲ι��캯������
    Person(int, char[], int);//�вι��캯������
    Person(Person&);//�������캯������
    ~Person() {};//������������
    int GetX() { return age; }
    char* GetY() { return name; }
    int GetZ() { return sex; }
    void print()
    {
        cout << "����Ϊ:" << age << " ����Ϊ:" << name << " �Ա�Ϊ:";
        if (sex == 1)
        {
            cout << "��" << endl;
        }
        else
        {
            cout << "Ů" << endl;
        }
    }
};
Person::Person(int x, char y[], int z)//���ⶨ���вι��캯��
{
    age = x;
    strcpy(name, y);
    sex = z;
}
Person::Person(Person& p)//���ⶨ�忽�����캯��
{
    age = p.age;
    strcpy(name, p.name);
    sex = p.sex;
}

int main()
{
    char p2name[10] = "������";
    Person p1;//ʹ��print�����������޲ι��캯������p1
    p1.print();
    Person p2(12, "����", 1);//�����вι��캯����ʼ��
    cout << "p2��";
    p2.print();
    Person p3(p2);//�ö���p2��ʼ��
    cout << "p3��";
    p3.print();
}