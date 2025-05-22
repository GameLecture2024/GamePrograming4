#pragma once

/*
*  1. DropItem 생성자를 만들어 보세요.
*  2. Monster이 데이터를 받아올 수 있게 Private필드를 선언한다.
*  3. public 레이블에 생성자, vector의 DropItem을 추가해보세요.
*  4. 자료구조를 사용하는 함수를 만들어보세요. 
*/

#include <iostream>
#include <vector>
#include <ConsoleUtility.h>

struct DropItem
{
	int index;
	int exp;
	int money;
	
	DropItem() = default;
	DropItem(int index, int exp, int money) : index(index), exp(exp), money(money) {}
};


class Monster
{
private:
	int exp;
	int money;
	// 2
	std::vector<DropItem> drop;
	DropItem currentDropItem;
public:

	Monster(int exp, int money) : exp(exp), money(money)
	{
		// 3. 자료 구조를 생성하여 만들어보세요.
		drop.emplace_back(1, 10, 100);
		drop.emplace_back(2, 20, 200);
		drop.emplace_back(3, 30, 300);
		drop.emplace_back(4, 40, 400);
		drop.emplace_back(5, 50, 500);

		// 내가 어떤 경험치 테이블을 선택했는가?
		SetDropItem();
	}

	void SetDropItem()
	{
		int index = ConsoleUtil::GetRandomInt(drop.size() - 1);                   //index 0부터 시작한다.	   size() - 1

		currentDropItem = drop[index];
	}

	void Drop()
	{
		std::cout << "획득한 경험치 : " << currentDropItem.exp << std::endl;
		std::cout << "획득한 돈 : " << currentDropItem.money << std::endl;

		// player.GetDropItem(); player의 exp를 증가시킨다. money 증가시킨다.
	}
};