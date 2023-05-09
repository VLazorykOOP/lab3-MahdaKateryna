// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №3. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//



// Ваші файли загловки 
//
#include "Lab3Example.h"
#include <iostream>
int main()
{
    std::cout << " Lab #3  !\n";
//  Код виконання завдань
//  Головне меню завдань
//  Функції та класи можуть знаходитись в інших файлах проекту

	char choose = '5';
	do {
		system("cls");
		std::cout << " Lab #3 \n";
		std::cout << "Main menu: \n1)Task 1 \n2)Task 2 \n3) Exit\n\n";
		std::cout << "Choose the task: ";
		choose = std::cin.get();

		std::cin.get();

		switch (choose) {
		case '1': mainExample1();
			break;
		case '2': mainExample3();   break;

		case '3': return 0;
		}
		std::cout << "\nPress any key and enter\n";
		choose = std::cin.get();
	} while (choose != '3');
	return 0;
}

