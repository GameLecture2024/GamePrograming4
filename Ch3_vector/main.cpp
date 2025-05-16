
#include <iostream>
#include <vector>

using namespace std;

/*
*  ��ǥ : �迭�� ũ�⸦ �������� �����ϴ� �ڵ带 �����.
* 
*         "�ڵ�" vector
*/

/*
*  int 10�� �迭�� �����Ѵ�.
*  �迭�� Ư¡ : ũ�Ⱑ ����. ���� �� ũ�⸦ ������� �Ѵ�. 40����Ʈ�� ������ Ȯ���ؾ��Ѵ�.
*  41����Ʈ ������ �������� �޸𸮸� ���� - ������ �߻�
*/

// �迭�� ũ�⸦ N ���� �� �ְ� �ڵ带 �߰��غ���.
// String, char, double �ڵ带 �߰��غ�����

/*
*  vector Ŭ������ ���
*  
*    push_back    : ������ ���� �����͸� �߰��Ѵ�.(�̹� �����ϴ� �����͸�)
     size()       : ������ ���̸� ��ȯ�Ѵ�.
	 emplace_back : ������ ���� ���� ������ �����͸� �ٷ� �߰��Ѵ�., 
     pop_back	  : ���� �ڿ� �ִ� ������ �Ѱ��� �����Ѵ�.
	 empty		  : ������ ũ�Ⱑ 0�̸� true, �̻��̸� false ��ȯ�Ѵ�.
	 insert()	  : �־��� ��ġ�� �����͸� �Է��Ѵ�.   vec.insert(vec.begin() + 2, 10); 
	 erase()	  : �־��� ��ġ�� �����͸� �����Ѵ�.   vec.erase(vec.begin());
*/

/*
*  	vec.0 = 1_������  
    <- erase
*/



template<typename T,int N>
void MakeArray(T*& ptr, T value)
{
	// ����� �޸𸮸� ����
	// �迭�� ũ�⸦ �������� ����� �����ִ� ���� �ڵ�
	delete[] ptr;
	ptr = new T[N];

	for (int i = 0; i < N; i++)
	{
		*(ptr + i) = value;
		cout << *(ptr + i) << " ";
	}

	cout << endl;
}

// Ŭ���� �̸� Monster ��ȣ, �̸�



class Monster
{
private:
	int num;
	string name;

public:
	Monster() = default;
	~Monster() = default;
	Monster(int num, string name) : num(num), name(name) {}

	int get_num() const { return num; }
	string get_name() const { return name; }

	// "cout<< Monster������� ���� ����"
	// friend �ܺ� Ŭ������ private�� ������ �� �ְ� ���ִ� Ű����
	friend ostream& operator<<(ostream& os, const Monster& obj)
	{
		os << obj.num << "_" << obj.name << " ";
		return os;
	}
};

template<typename T>
void Show(vector<T>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}

	std::cout << endl;
}

int main()
{
	// �������� �迭�� ũ�⸦ �����ϰ� �����ϴ� �Լ� ���ø�.
	// Ŭ���� ���ø�
	// �κ��丮 10��. -> 11��  (Array 10��.) -> 

	int* aPtr = new int[10];
	double* bPtr = new double[10];
	string* cPtr = new string[10];
	Monster* dPtr = new Monster[10];

	Monster sample(0, "���");

	MakeArray<int,15>(aPtr, 0);
	MakeArray<double, 10>(bPtr, 0.1);
	MakeArray<string, 10>(cPtr, "AAA");
	MakeArray<Monster, 10>(dPtr, sample);


	// vector�� ���� �迭�� �����ϰ� ����ϱ�


	std::cout << "\n ���� ��� ���� " << std::endl;

	std::vector<int> nums; // vector int�� �����ϴ� �����迭 Ŭ����.
	

	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.clear();

	Show<int>(nums);

	//for (int i = 0; i < nums.size(); i++)
	//{
	//	cout << nums[i] << " ";
	//}
	std::vector<double> doublecontainer;
	std::vector<string> stringcontainer;
	std::vector<Monster> monsterDatabase;
	monsterDatabase.emplace_back(1, "���");
	monsterDatabase.emplace_back(2, "������");
	monsterDatabase.emplace_back(3, "��");
	monsterDatabase.clear();
	
	for (int i = 0; i < 10; i++)
	{
		nums.push_back(0);
		doublecontainer.push_back(0.1);
		stringcontainer.push_back("AAA");
		monsterDatabase.push_back(sample);
	}

	Show<int>(nums);
	Show<double>(doublecontainer);
	Show<string>(stringcontainer);
	Show<Monster>(monsterDatabase);
	//monsterDatabase.pop_back();
	//monsterDatabase.pop_back();
	//monsterDatabase.pop_back();

	if (!monsterDatabase.empty())
	{
		cout << "�����Ͱ� �ֽ��ϴ�." << endl;
	}

    
	// intŸ���� �����ϴ� �迭�� vector �����̳ʿ� �����ϴ� �ڵ带 �ۼ��ϼ���.
	vector<int> nnn;
	nnn.push_back(1);
	nnn.pop_back();
	nnn.size();

	// ��Ʈ����.  4���� ��
	// vector<Block> blocks;

	// 4���� ����. ����, ������, ����, �ü�
	// vector<GameClass> gameClasses;

	// ��ü. Monster
	// �����ϴ� Ŭ���� MonsterManager
	// vector<Monster>


}
