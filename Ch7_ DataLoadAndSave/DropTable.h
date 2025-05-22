#pragma once

/*
*  1. DropItem �����ڸ� ����� ������.
*  2. Monster�� �����͸� �޾ƿ� �� �ְ� Private�ʵ带 �����Ѵ�.
*  3. public ���̺� ������, vector�� DropItem�� �߰��غ�����.
*  4. �ڷᱸ���� ����ϴ� �Լ��� ��������. 
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
		// 3. �ڷ� ������ �����Ͽ� ��������.
		drop.emplace_back(1, 10, 100);
		drop.emplace_back(2, 20, 200);
		drop.emplace_back(3, 30, 300);
		drop.emplace_back(4, 40, 400);
		drop.emplace_back(5, 50, 500);

		// ���� � ����ġ ���̺��� �����ߴ°�?
		SetDropItem();
	}

	void SetDropItem()
	{
		int index = ConsoleUtil::GetRandomInt(drop.size() - 1);                   //index 0���� �����Ѵ�.	   size() - 1

		currentDropItem = drop[index];
	}

	void Drop()
	{
		std::cout << "ȹ���� ����ġ : " << currentDropItem.exp << std::endl;
		std::cout << "ȹ���� �� : " << currentDropItem.money << std::endl;

		// player.GetDropItem(); player�� exp�� ������Ų��. money ������Ų��.
	}
};