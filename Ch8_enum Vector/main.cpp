/* 
*  enum 선언해보세요.
* 
*  class 안에 enum을 활용해보세요.
*/

/*
*  enum : 열거형.
*  enum으로 상수를 저장할 수 있다.
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
*  Trait - Stat 관계를 정의해야 합니다.
*  STR 1 올렸을 때 ? : Damage(기존 수치) + ( ); // 합연산
*/

/*
*  Vector타입의 한계점.
*  Trait , Stat
*  Dex올리면 Speed 증가하는 시스템을 만들어라.
* 
*  배열 형태로 저장되어 있는 자료구조이기 때문에, 자료의 삭제 및 추가를 할 때 문제점이 발생할 수 있다.
*  순서대로 정리되어 있지 않은 데이터의 변경이 발생했을 때 문제가 예상된다.
*  
*  Map <<
*/

// vector 0번째자리에  숫자를 저장한다.
// map[타입이 STR] 1을 저장

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
*  C형태의 Casting 문제점
*  - 여러가지 형변환을 동시에 할 수 있다.
*  CPP형태의 Casting
   - static_cast,  const_cast, reinterpret_cast // dynamic_cast

   의도치 않은 형변환이 발생할 수 있다.

   Tip) int, double, std::string Primitive Type 타입을 변환하고 싶으면, static_cast사용하라
   const_cast : 상수를 없애주는 형변환
   reinterpret_cast : 메모리에 접근하여 int* -> double* 재해석하여 변환하는 변환.
   dynamic_cast : 클래스의 상속관계를 형변환하여, 실제 데이터가 존재하지 않으면 null반환하다.

   if(dynamic_cast<Monster> d){}

*/

void EnumTest1()
{
	// enum을 정수로, 정수를 enum으로 변환하는 예제입니다.

	int num = Stat::Damage;

	Stat someType = (Stat)num;                // C형태의 형변환.
	Stat someType2 = static_cast<Stat>(num);  // CPP 형변환

	if (someType2 == Stat::Damage)  // someType 제대로 형변환이 되었다면 코드가 실행될 것이다.
	{
		std::cout << "스탯::데미지가 출력되었습니다." << std::endl;
	}	
}


// Enum vector타입으로 형변환하여 사용하는 예제
void EnumTest2()
{
	Player player;

	//player.IncreaseStat(Stat::Damage, 5); // 플레이어의 공격력 스탯을 5만큼 증가시켜라.
	//player.ShowPlayerStat();
}


void EnumTest3()
{
	TraitBonus traits;

	traits.GetTrait(Trait::Strength);

	traits.ShowStats();

	// 플레이어의 특성을 증가시켯을때 , 특정 스탯을 증가하게 하려면 어떠한 코드를 작성해야 할까?

	// enum Trait, enum Stat, int amount 함수가 필요합니다.
}

void EnumTest4()
{
	Player player;
	// player안에 있는 Traitbonus 클래스에 접근하여 함수 사용
	//player.GetTraits().GetTrait(Trait::Strength);
	//player.GetTraits().ShowStats();

	// player클래스에 Traitbonus 함수를 Wrapping했다. 
	player.GetTrait(Trait::Strength);
	player.ShowStatus();
}

int main()
{
	//EnumTest1();
	//EnumTest2();
	//EnumTest3();
	//EnumTest4();

	// 입력을 사용하여 스탯을 증가시켜 보세요

	// 화면 출력 :  1을 누르면 Strenth 증가시킨다.. 2를 누르면,, 3를 누르면 4를 누르면...

	Player player;

	std::cout << "  =========레벨업=================== " << std::endl;

	int input;
	std::cout << "숫자 몇번을 입력했을 때 특성을 A를 올립니다." << std::endl;
	std::cin >> input;

	if (input >= Trait::None)
	{
		std::cout << "잘못된 숫자를 입력했습니다." << std::endl;
	}
	else
	{
		player.GetTrait(static_cast<Trait>(input));
	}

	player.ShowStatus();
}


// 플레이어 레벨업 시스템 + 스탯 상승 시스템
// 레벨업을 했을 때 스탯을 상승할 수 있게 만들어라.
// Player   TraitBouns, Levelup