/*
* ��ü���� Set�� �����ϴ� ���̺��� �迭�� ���� Ŭ���� �����ϱ�- template ���� �ϼ��ϱ�
*/
#include <iostream>
#include <string>
#define DefaultSize 50
using namespace std;
class Employee;
class Person { 
    string pid;
    string pname;
public:
    string GetName() { return pname; }
    void SetName(char* str) { pname = str; }
};

class Employee : public Person {
private:
    string eno;
    string role;
public:
    Employee() :Person() {}
    
    virtual void Print();
    virtual bool Equals(Employee* p);
};
bool Employee::Equals(Employee* p) {

}
void Employee::Print() {
    
}


class Student {
private:
    string sid;
    string major;
public:
   void Print();
};
void Student::Print() {
  
    
}
class WorkStudent : public Student {
private:
    string job;
public:
     void Print();
};


class Bag {
public:
    virtual int Add(T*); // ���� �ϳ��� bag�� ����
    virtual int Delete(char*); //bag���� ���� �ϳ��� ����
    virtual T* Search(char*);
    bool IsFull();
    // bag�� ��ȭ�����̸� true, �׷��� ������ false�� ��ȯ
    bool IsEmpty();
    // bag�� ���� �����̸� true, �׷��� ������ false�� ��ȯ
    int Top();
    virtual void Print();

protected:
    Bag(int bagSize);
    void Full(); // bag�� ��ȭ������ ���� ��ġ
    void Empty(); // bag�� ���� ������ ���� ��ġ

    T** arr; //> �����ڿ��� arr = new T*[Size]; > arr[i] = new T();
    int bagMaxSize; // �迭�� ũ��
    int topBag; // �迭���� ���Ұ� ��� �ִ� ���� ���� ��ġ
    //*
    ~Bag() {
        for (int i = 0; i < bagMaxSize; i++) {
            delete arr[i];
        }
        delete[] arr;
    }
    // */
};
Bag::Bag(int bagSize) : bagMaxSize(bagSize) {
    topBag = 0;
    arr = new T * [bagSize];
  
}
void Bag::Print() {

}





int Bag::Add(T* x) {

}

int Bag::Delete(char* str) {
  
}

int Bag::Top() {
   
}

T* Bag::Search(char* str) {
 
}

class Set : public Bag {
public:
    Set(int setSize) :Bag(setSize) {}
    int Add(T*);
    int Delete(char*);
    void Print();
    T* Search(char*);
};
T* Set::Search(char* str) {
 
}
void Set::Print() {
  
}

int Set::Add(T* p) {

}

int Set::Delete(char* str) {
   

}

class RecordSet : public Set {
    int setMaxSize;//5���� ���ڵ� ��
    int topRecordSet;//�ش� ���ڵ弼Ʈ���� �Է��� ��ġ
public:
    RecordSet(int maxSize) :Set(maxSize), setMaxSize(maxSize) {
        topRecordSet = 0;
    }
    T* Search(char*);
    void Print();
    int Add(T* p);
};
T* RecordSet::Search(char* str) {

}
int RecordSet::Add(T* p) {

}
void RecordSet::Print() {
  
}

class RecordTable {
    int tableMaxSize;
    int topRecordTable;
    RecordSet** data;
    int capacity;
public:
    RecordTable(int numberSet, int numberRecords) :tableMaxSize(numberSet), capacity(numberRecords) {
        topRecordTable = 0;
        data = new RecordSet * [numberSet];//10���� set
        for (int i = 0; i < numberSet; i++) {
            data[i] = new RecordSet(numberRecords);//�� set�� 5�� records
        }


    }
    int Add(T*); // ���� �ϳ��� bag�� ����
    int Delete(char*);
    T* Search(char*);
    void Print();
};
int RecordTable::Delete(char* str) {
    

}//bag���� ���� �ϳ��� ����
int RecordTable::Add(T* p) {
  
}
void RecordTable::Print() {
  
}
T* RecordTable::Search(char* str) {
   
}

int main() {
    Employee* members[30];//Employee �������� �����ϴ� ���� �ذ� �ʿ� 
    WorkStudent* workers[20];
    RecordTable<Employee> etable(10, 5);//10���� record sets, �� set�� 5���� records
    RecordTable<WorkStudent> wtable(10, 5);
    int select;
    Employee* e; WorkStudent* ws;
    int result;
    while (1)
    {
        cout << "\n���� 1: member  ��ü 30�� �Է�, 2.table ���, 3: table ��ü ã��,4. table���� ��ü ����, 5. ����" << endl;
        cin >> select;
        switch (select) {
        case 1://table�� ��ü 30�� �Է�
            members[0] = new Employee("p1", "hong", "E1", "Coding");
            members[1] = new Employee("p2", "hee", "E2", "Coding");
            members[2] = new Employee("p3", "kim", "E3", "Test");
            members[3] = new Employee("p4", "lee", "E4", "Test");
            members[4] = new Employee("p5", "ko", "E5", "Design");
            members[5] = new Employee("p6", "choi", "E6", "Design");
            members[6] = new Employee("p7", "han", "E7", "Sales");
            members[7] = new Employee("p8", "na", "E8", "Sales");
            members[8] = new Employee("p9", "you", "E9", "Account");
            members[9] = new Employee("p10", "song", "E10", "Production");
            workers[0] = new WorkStudent("s011", "coding", "hong");
            workers[1] = new WorkStudent("s012", "coding",  "ong");
            workers[2] = new WorkStudent("s013", "coding",  "dong");
            workers[3] = new WorkStudent("s014", "coding",  "fong");
            workers[4] = new WorkStudent("s015", "coding",  "tong");
            workers[5] = new WorkStudent("s016", "coding",  "nong");
            workers[6] = new WorkStudent("s017", "coding",  "mong");
            workers[7] = new WorkStudent("s018", "coding",  "kong");
            workers[8] = new WorkStudent("s019", "coding",  "long");
            workers[9] = new WorkStudent("s020", "coding",  "pong");
            workers[10] = new WorkStudent("s021", "coding",  "lim");
            workers[11] = new WorkStudent("s022", "coding",  "mim");
            workers[12] = new WorkStudent("s023", "coding",  "bim");
            workers[13] = new WorkStudent("s024", "coding",  "dim");
            workers[14] = new WorkStudent("s025", "coding", "rim");
            workers[15] = new WorkStudent("s026", "coding", "qim");
            workers[16] = new WorkStudent("s021", "coding",  "fim");
            workers[17] = new WorkStudent("s021", "coding",  "him");
            workers[18] = new WorkStudent("s027", "coding",  "jim");
            workers[19] = new WorkStudent("s027", "coding",  "jjj");


            for (int i = 0; i < 10; i++)
            {
                etable.Add(members[i]);

            }
            for (int i = 0; i < 20; i++)
            {
                wtable.Add(workers[i]);

            }
            break;
        case 2:
            // table�� ��� ��ü ����ϱ�
            //table ������� ����ؾ� �Ѵ�: | *** | ???? | === |���� ����Ѵ�.

            etable.Print();
            wtable.Print();
            break;
        case 3:
            // table���� ��ü ã��

            e = etable.Search("kim");
            if (e == nullptr) cout << "kim�� �������� �ʴ´�" << endl;
            else
                e->Print();

            ws = wtable.Search("kim");
            if (ws == nullptr) cout << "kim�� �������� �ʴ´�" << endl;
            else
                ws->Print();
            break;
        case 4:
            //table���� ��ü �����ϱ�
            result = etable.Delete("hong");
            if (result > 0)
                cout << "������ records ����" << result << endl;
            result = wtable.Delete("hong");
            if (result > 0)
                cout << "������ records ����" << result << endl;
            break;

        default:
            exit(0);

        }
    }
    system("pause");
    return 1;
}