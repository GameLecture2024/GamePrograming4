/* 
*  enum �����غ�����.
* 
*  class �ȿ� enum�� Ȱ���غ�����.
*/

/*
*  enum : ������.
*  enum���� ����� ������ �� �ִ�.
*/

#include <vector>
#include <iostream>

enum Trait
{
	Strength,
	Dexterity,
	Inteligence,
	None
};

enum Stat
{
	Damage,
	Health,
	Mana,
	Speed
};

/*
*  Trait - Stat ���踦 �����ؾ� �մϴ�.
*  STR 1 �÷��� �� ? : Damage(���� ��ġ) + ( ); // �տ���
*/

/*
*  VectorŸ���� �Ѱ���.
*  Trait , Stat
*  Dex�ø��� Speed �����ϴ� �ý����� ������.
* 
*  �迭 ���·� ����Ǿ� �ִ� �ڷᱸ���̱� ������, �ڷ��� ���� �� �߰��� �� �� �������� �߻��� �� �ִ�.
*  ������� �����Ǿ� ���� ���� �������� ������ �߻����� �� ������ ����ȴ�.
*  
*  Map <<
*/

// vector 0��°�ڸ���  ���ڸ� �����Ѵ�.
// map[Ÿ���� STR] 1�� ����

class TraitBonus
{
private:
	void IncreaseStat(Stat stat, int amount)
	{
		Stats[static_cast<int>(stat)] += amount;
	}

public:

	std::vector<int> Stats;

	TraitBonus() : Stats(4, 0) {}

	void GetTrait(Trait trait)
	{
		switch (trait)
		{
		case Trait::Strength:
			IncreaseStat(Damage, 5);
			IncreaseStat(Health, 1);
			break;
		case Trait::Dexterity:
			IncreaseStat(Speed, 1);
			break;
		case Trait::Inteligence:
			IncreaseStat(Mana, 5);
			break;
		}
	}

	void ShowStats()
	{
		std::cout << "Damage : " << Stats[Damage] << std::endl;
		std::cout << "Health : " << Stats[Health] << std::endl;
		std::cout << "Mana   : " << Stats[Mana] << std::endl;
		std::cout << "Speed   : " << Stats[Speed] << std::endl;
	}
};

class Player
{
private:
	TraitBonus traitbonus;

public:
	Player() : traitbonus() {}

	TraitBonus GetTraits() const { return traitbonus; }

	void GetTrait(Trait trait)
	{
		traitbonus.GetTrait(trait);
	}

	void ShowStatus()
	{
		traitbonus.ShowStats();
	}
};

/*
*  C������ Casting ������
*  - �������� ����ȯ�� ���ÿ� �� �� �ִ�.
*  CPP������ Casting
   - static_cast,  const_cast, reinterpret_cast // dynamic_cast

   �ǵ�ġ ���� ����ȯ�� �߻��� �� �ִ�.

   Tip) int, double, std::string Primitive Type Ÿ���� ��ȯ�ϰ� ������, static_cast����϶�
   const_cast : ����� �����ִ� ����ȯ
   reinterpret_cast : �޸𸮿� �����Ͽ� int* -> double* ���ؼ��Ͽ� ��ȯ�ϴ� ��ȯ.
   dynamic_cast : Ŭ������ ��Ӱ��踦 ����ȯ�Ͽ�, ���� �����Ͱ� �������� ������ null��ȯ�ϴ�.

   if(dynamic_cast<Monster> d){}

*/

void EnumTest1()
{
	// enum�� ������, ������ enum���� ��ȯ�ϴ� �����Դϴ�.

	int num = Stat::Damage;

	Stat someType = (Stat)num;                // C������ ����ȯ.
	Stat someType2 = static_cast<Stat>(num);  // CPP ����ȯ

	if (someType2 == Stat::Damage)  // someType ����� ����ȯ�� �Ǿ��ٸ� �ڵ尡 ����� ���̴�.
	{
		std::cout << "����::�������� ��µǾ����ϴ�." << std::endl;
	}	
}


// Enum vectorŸ������ ����ȯ�Ͽ� ����ϴ� ����
void EnumTest2()
{
	Player player;

	//player.IncreaseStat(Stat::Damage, 5); // �÷��̾��� ���ݷ� ������ 5��ŭ �������Ѷ�.
	//player.ShowPlayerStat();
}


void EnumTest3()
{
	TraitBonus traits;

	traits.GetTrait(Trait::Strength);

	traits.ShowStats();

	// �÷��̾��� Ư���� ������������ , Ư�� ������ �����ϰ� �Ϸ��� ��� �ڵ带 �ۼ��ؾ� �ұ�?

	// enum Trait, enum Stat, int amount �Լ��� �ʿ��մϴ�.
}

void EnumTest4()
{
	Player player;
	// player�ȿ� �ִ� Traitbonus Ŭ������ �����Ͽ� �Լ� ���
	//player.GetTraits().GetTrait(Trait::Strength);
	//player.GetTraits().ShowStats();

	// playerŬ������ Traitbonus �Լ��� Wrapping�ߴ�. 
	player.GetTrait(Trait::Strength);
	player.ShowStatus();
}

int main()
{
	//EnumTest1();
	//EnumTest2();
	//EnumTest3();
	//EnumTest4();

	// �Է��� ����Ͽ� ������ �������� ������

	// ȭ�� ��� :  1�� ������ Strenth ������Ų��.. 2�� ������,, 3�� ������ 4�� ������...

	Player player;

	std::cout << "  =========������=================== " << std::endl;

	int input;
	std::cout << "���� ����� �Է����� �� Ư���� A�� �ø��ϴ�." << std::endl;
	std::cin >> input;

	if (input >= Trait::None)
	{
		std::cout << "�߸��� ���ڸ� �Է��߽��ϴ�." << std::endl;
	}
	else
	{
		player.GetTrait(static_cast<Trait>(input));
	}

	player.ShowStatus();
}


// �÷��̾� ������ �ý��� + ���� ��� �ý���
// �������� ���� �� ������ ����� �� �ְ� ������.
// Player   TraitBouns, Levelup