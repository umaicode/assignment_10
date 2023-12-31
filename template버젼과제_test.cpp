/*
* 객체들의 Set을 포함하는 테이블의 배열을 갖는 클래스 구현하기- template 버젼 완성하기
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
	Person(string pid, string pname) : pid(pid), pname(pname) { }
	string GetName() { return pname; }
	string GetId() { return pid; }
	void SetName(char* str) { pname = str; }
	virtual ~Person() {}

};

class Employee : public Person {
private:
	string eno;
	string role;
public:
	Employee(string pid, string pname, string eno, string role) : Person(pid, pname), eno(eno), role(role) { }


	virtual bool Equals(Employee* p);
	void Print() {
		cout << " eno: " << eno << " role: " << role << " pid: " << GetId() << " pname: " << GetName() << endl;
	}
};
bool Employee::Equals(Employee* p) {
	return (eno == p->eno && role == p->role && this->GetName() == p->GetName() && this->GetId() == p->GetId());
}



class Student {
private:
	string sid;
	string major;
public:
	virtual void Print();
	Student(string sid, string major) : sid(sid), major(major) {}
	string getSid() { return sid; }
	string getMajor() { return major; }
};

void Student::Print() {
	cout << " sid: " << sid << " major: " << major;

}
class WorkStudent : public Student {
private:
	string job;
public:
	WorkStudent(string sid, string major, string job) :Student(sid, major), job(job) {}
	void Print();
	string GetName() { return job; }
	void SetName(char* str) { job = str; }
	virtual bool Equals(WorkStudent* p);
};

bool WorkStudent::Equals(WorkStudent* p) {
	return (getSid() == p->getSid() && getMajor() == p->getMajor() && job == p->job);
}

void WorkStudent::Print() {
	Student::Print();
	cout << " job: " << job << endl;
}


template <class T>
class Bag {//Bag는 템플릿 버전
public:
	virtual int Add(T*); // 정수 하나를 bag에 삽입
	virtual int Delete(char*); //bag에서 정수 하나를 삭제
	virtual T* Search(char*);
	bool IsFull() {
		if (topBag == bagMaxSize) {
			Full();
			return true;
		}
		return false;
	}
	// bag이 포화상태이면 true, 그렇지 않으면 false를 반환
	bool IsEmpty() {
		if (topBag == 0) {
			Empty();
			return true;
		}
		return false;
	}
	// bag이 공백 상태이면 true, 그렇지 않으면 false를 반환
	int Top();
	virtual void Print();

protected:
	Bag(int bagSize);
	void Full() {
		cout << "꽉찼습니다." << endl;
		// bag이 포화상태일 때의 조치
	}
	void Empty() {
		cout << "비어있습니다" << endl; // bag이 공백 상태일 때의 조치
	}
	T** arr; //> 생성자에서 arr = new T*[Size]; > arr[i] = new T();
	int bagMaxSize; // 배열의 크기
	int topBag; // 배열에서 원소가 들어 있는 가장 높은 위치
	//*
	~Bag() {
		for (int i = 0; i < bagMaxSize; i++) {
			delete arr[i];
		}
		delete[] arr;
	}
	// */
};

template <class T>
Bag<T>::Bag(int bagSize) : bagMaxSize(bagSize) {
	topBag = 0;
	arr = new T * [bagSize];
	//for (int i = 0; i < bagSize; i++) {
	//	arr[i] = new T();
	//}
}

template <class T>
void Bag<T>::Print() {
	T* p;
	for (int i = 0; i < topBag; i++) {
		p = arr[i];
		cout << "Bag::Print 실행gka" << endl;
		p->Print();
	}
}

template <class T>
int Bag<T>::Add(T* p) {
	if (topBag < bagMaxSize) {
		arr[topBag] = p;
		topBag++;
		//cout << "Bag에 추가되었습니다. topBag은 "<< topBag<<"입니다." << endl;
	}
	return 1;
}

template <class T>
int Bag<T>::Delete(char* str) {
	for (int i = 0; i < topBag; i++) {
		if (arr[i]->GetName() == str) {
			arr[i]->SetName(const_cast<char*>("*****"));
			return 1;
		}
	}
	return -1;
}

template <class T>
int Bag<T>::Top() {
	return topBag;
}

template <class T>
T* Bag<T>::Search(char* str) {
	for (int i = 0; i < topBag; i++) {
		if (arr[i]->GetName() == str) {
			return arr[i];
		}
	}
	return nullptr;
}

template <class T>
class Set : public Bag <T> {
public:
	Set(int setSize) :Bag <T>(setSize) {}
	int Add(T*);
	int Delete(char*);
	void Print();
	T* Search(char*);
};

template <class T>
T* Set<T>::Search(char* str) {
	return Bag<T>::Search(str);
}

template <class T>
void Set<T>::Print() {
	Bag<T>::Print();
}

template <class T>
int Set<T>::Add(T* p) {
	if (!Set<T>::IsFull()) {

		for (int i = 0; i < topBag; i++) {


			if ((*(arr[i])).Equals(p)) {//중복체크
				cout << "중복이 있습니다" << endl;
				return 1;
			}
		}
		Bag<T>::Add(p);
	}
	return 1;
}

template <class T>
int Set<T>::Delete(char* str) {
	return Bag<T>::Delete(str);
}

template <class T>
class RecordSet : public Set <T> {
	int setMaxSize;//5개의 레코드 수
	int topRecordSet;//해당 레코드세트에서 입력할 위치
public:
	RecordSet(int maxSize) :Set(maxSize), setMaxSize(maxSize) {
		topRecordSet = 0;
	}
	T* Search(char*);
	void Print();
	int Add(T* p);
};

template <class T>
T* RecordSet<T>::Search(char* str) {
	return Set<T>::Search(str);
}

template <class T>
int RecordSet<T>::Add(T* p) {
	return Set<T>::Add(p);
}

template <class T>
void RecordSet<T>::Print() {
	Set<T>::Print();
}

template <class T>
class RecordTable {
	int tableMaxSize;
	int topRecordTable;
	RecordSet<T>** data;
	int capacity;
	int record;
public:
	RecordTable(int numberSet, int numberRecords) :tableMaxSize(numberSet), capacity(numberRecords) {
		record = 0;
		topRecordTable = 0;
		data = new RecordSet<T>*[numberSet];//10개의 set
		for (int i = 0; i < numberSet; i++) {
			data[i] = new RecordSet<T>(numberRecords);//각 set는 5개 records
		}


	}
	int Add(T*); // 정수 하나를 bag에 삽입
	int Delete(char*);
	T* Search(char*);
	void Print();
};

template <class T>
int RecordTable<T>::Delete(char* str) {
	for (int i = 0; i < topRecordTable; i++) {
		//Employee* p = data[i]->Search(d);
		//if (p != nullptr) {
		//    cout << "없는 이름입니다."<<endl;
		//    return -1;
		//}
		if (data[i]->Delete(str) == 1) {
			record++;
		}


	}
	return record;

}//bag에서 정수 하나를 삭제

template <class T>
int RecordTable<T>::Add(T* p) {
	if (!data[topRecordTable]->IsFull()) {
		data[topRecordTable]->Add(p);

		return 1;
	}
	else {
		topRecordTable++;
		//cout << "topRecordTable은" << topRecordTable << "입니다." << endl;
		data[topRecordTable]->Add(p);
		return 1;
	}

}

template <class T>
void RecordTable<T>::Print() {
	for (int i = 0; i < topRecordTable + 1; i++)
	{
		data[i]->Print();
	}
	cout << endl;
}

template <class T>
T* RecordTable<T>::Search(char* str) {
	for (int i = 0; i < topRecordTable; i++) {
		T* p = data[i]->Search(str);
		if (p != nullptr) {
			return p;
		}

	}
	return nullptr;
}

int main() {
	Person* members[30];//Employee 선언으로 변경하는 문제 해결 필요 
	WorkStudent* workers[20];
	RecordTable<Employee> etable(10, 5);//10개의 record sets, 각 set은 5개의 records
	RecordTable<WorkStudent> wtable(10, 5);
	int select;
	Employee* e; WorkStudent* ws;
	int result;
	while (1)
	{
		cout << "\n선택 1: member  객체 30개 입력, 2.table 출력, 3: table 객체 찾기,4. table에서 객체 삭제, 5. 종료" << endl;
		cin >> select;
		switch (select) {
		case 1://table에 객체 30개 입력
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
			workers[1] = new WorkStudent("s012", "coding", "ong");
			workers[2] = new WorkStudent("s013", "coding", "dong");
			workers[3] = new WorkStudent("s014", "coding", "fong");
			workers[4] = new WorkStudent("s015", "coding", "tong");
			workers[5] = new WorkStudent("s016", "coding", "nong");
			workers[6] = new WorkStudent("s017", "coding", "mong");
			workers[7] = new WorkStudent("s018", "coding", "kong");
			workers[8] = new WorkStudent("s019", "coding", "long");
			workers[9] = new WorkStudent("s020", "coding", "pong");
			workers[10] = new WorkStudent("s021", "coding", "lim");
			workers[11] = new WorkStudent("s022", "coding", "mim");
			workers[12] = new WorkStudent("s023", "coding", "bim");
			workers[13] = new WorkStudent("s024", "coding", "dim");
			workers[14] = new WorkStudent("s025", "coding", "rim");
			workers[15] = new WorkStudent("s026", "coding", "qim");
			workers[16] = new WorkStudent("s021", "coding", "fim");
			workers[17] = new WorkStudent("s021", "coding", "him");
			workers[18] = new WorkStudent("s027", "coding", "jim");
			workers[19] = new WorkStudent("s027", "coding", "jjj");


			for (int i = 0; i < 10; i++)
			{
				etable.Add(dynamic_cast<Employee*>(members[i]));

			}
			for (int i = 0; i < 20; i++)
			{
				wtable.Add(workers[i]);

			}
			break;
		case 2:
			// table의 모든 객체 출력하기
			//table 모양으로 출력해야 한다: | *** | ???? | === |으로 출력한다.

			etable.Print();
			wtable.Print();
			break;
		case 3:
			// table에서 객체 찾기

			e = etable.Search(const_cast<char*>("kim"));
			if (e == nullptr) cout << "kim이 존재하지 않는다" << endl;
			else
				e->Print();

			ws = wtable.Search(const_cast<char*>("kim"));
			if (ws == nullptr) cout << "kim이 존재하지 않는다" << endl;
			else
				ws->Print();
			break;
		case 4:
			//table에서 객체 삭제하기
			result = etable.Delete(const_cast<char*>("hong"));
			if (result > 0)
				cout << "삭제된 records 숫자" << result << endl;
			result = wtable.Delete(const_cast<char*>("hong"));
			if (result > 0)
				cout << "삭제된 records 숫자" << result << endl;
			break;

		default:
			exit(0);

		}
	}
	system("pause");
	return 1;
}