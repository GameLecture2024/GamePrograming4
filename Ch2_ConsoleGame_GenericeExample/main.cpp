#include "ConsoleUtility.h"
#include <iostream>
#include <conio.h>   // _getch
#include "Pokeball.h"
#include <array>     // std::array<tpyname T, int N>

void Example()
{
	// 0.1�ʸ��� 1~100������ ���� �������� �� �پ� ����ϴ� �ڵ带 �����غ�����

	while (true)
	{
		int rand = ConsoleUtil::GetRandomInt(10);
		std::cout << rand;
		Sleep(100);
		break;
	}

	int x = ConsoleUtil::GetRandomInt(10);
	int y = ConsoleUtil::GetRandomInt(10);
	ConsoleUtil::GotoXY(x, y);
	std::cout << "������ ��ǥ�� ���" << std::endl;
}

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13

template <int N>
void Display(int index)
{
	for (int i = 0; i < N; i++)
	{
		if (i == index)
		{
			std::cout << "�� ";
		}
		else 
		{
			std::cout << "�� ";
		}
		
	}	
}

template <int N>
void Display2D(int index)
{
	int height = index / N;   // ����
	int width = index % N;	  // ����

	// ctrl + k + s

	for (int y = 0; y < N; y++)
	{
		for (int i = 0; i < N; i++)
		{
			if (i == width && y == height)
			{
				std::cout << "�� ";
			}
			else
			{
				std::cout << "�� ";
			}
		}
		std::cout << std::endl;
	}
}


/*
*  std::array (���� �迭) Fixed size Array
*  - Ư¡ : ũ�Ⱑ �����Ǿ� �ְ�, ��Ģ�� ��Ȯ�� ǥ���� �� �ִ�.
*  - �ǹ� : ũ�Ⱑ ������ �� �ִ� �迭�� ����� ���� ������?   vector (���� �迭)
*/


int main()
{
	int selectedIndex = 0;
	char input;
	// Ű���� �����¿� �Է��� �޾Ƽ� �������� �����ϴ� �׸� ���
	
	// ���ϸ����� �����͸� ����

	// PokeMon  (�� Ÿ��)		    : ������ ����, ũ�Ⱑ ���� ���. �� ��ü�� ���¸� ǥ���� ��. 
	// PokeMon* (���� Ÿ��, �ּҰ�)  : ���縦 ���ϰ� �����͸� �����´�.

	// ���� ������ ���� ũ�Ⱑ ũ��. PokeMon*
	// ���� �� ������ ����, ���°� �����ϱ� ������ ������ ǥ��

	
	ConsoleUtil::SetCursorVisible(false);

	std::array<PokeMon*, 36> pokeballs;

	// std::vector<PokeMon> pokeballs;

	PokeMon defaultMonster(0, "");

	pokeballs.fill(&defaultMonster);

	pokeballs[0] = new PokeMon(1, "�̻��ؾ�");
	pokeballs[1] = new PokeMon(25, "��ī��");
	pokeballs[2] = new PokeMon(15, "���̸�");
	pokeballs[3] = new PokeMon(18, "���α�");


	while (true)
	{
		const int size = 6;
		int sizePow = size * size;

		ConsoleUtil::GotoXY(0, 0);
		Display2D<size>(selectedIndex);   // ���� ������ �������� �����ִ� Display�Լ� �����.

		if (_kbhit())
		{
			input = _getch();

			if (input == LEFT)
			{
				//std::cout << "���� ȭ��Ű�� �Է�"; �� �۵��� �ȴ�.
				selectedIndex = (selectedIndex - 1 + sizePow) % sizePow;  // 0 ~ 5  -1
			}
			else if (input == RIGHT)
			{
				selectedIndex = (selectedIndex + 1) % sizePow;  // 0 ~ 5  -1
			}
			else if (input == UP)
			{
				// selectedIndex�� ���� �� �Ʒ��� �̵��ϵ��� �ڵ带 �ۼ��غ�����.
				selectedIndex = (selectedIndex - size + sizePow) % sizePow;
			}
			else if (input == DOWN)
			{
				selectedIndex = (selectedIndex + size) % sizePow;
			}
			else if (input == ENTER)
			{
				break;
			}

			system("cls"); // ȭ�� �����
		}

		

		ConsoleUtil::GotoXY(30, 0);
		std::cout << "���� UI";
		ConsoleUtil::GotoXY(30, 1);
		std::cout << "No_" << pokeballs[selectedIndex]->get_number() << pokeballs[selectedIndex]->get_name();
	}

	// selectedIndex;

	std::cout << pokeballs[selectedIndex]->get_name() << std::endl;


}