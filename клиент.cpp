#include "stdafx.h"
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>

#pragma warning(disable: 4996)
void klient();
void admin();
void adminmenu();
void menu();
void choice1();
void choice2();
void choice3();
void choice4();
void choice5();
void choice6();
void choice7();
void choice8();
void choice9();
void choice10();
void choice11();
void choice12();
void choice13();
void menuuprklient();
void menuklient();
int k;
void choice1()
{

	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1280);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server12.\n";

	}
	int i;
	char msg[1];
	msg[0] = '1';

	recv(Connection, msg, sizeof(msg), NULL);

	//cout << msg[0];

	cout << endl << "____________________________________________________________________" << endl;
	cout << "| N |    название   |    материал   |  марка   | год |рейтинг| цена$ |" << endl;
	cout << "|___|_______________|_______________|__________|_____|_______|_______|" << endl;
	i = atoi(msg);


	//cout << i<<endl<<endl;
	//"|%3d|%10s|%10s|%4s|%8s|%3s|"
	int n;

	for (n = 0; n < 6; n++)
	{
		char   surname1[15], name1[15], marka1[9], age1[5], mark1[5], quantity1[5];
		//cout << "1";

		recv(Connection, surname1, sizeof(surname1), NULL);
		recv(Connection, name1, sizeof(name1), NULL);
		recv(Connection, marka1, sizeof(marka1), NULL);
		recv(Connection, age1, sizeof(age1), NULL);
		recv(Connection, mark1, sizeof(mark1), NULL);
		recv(Connection, quantity1, sizeof(quantity1), NULL);
		float par1 = atoi(mark1);
		float par2 = atoi(quantity1);
		float q = par1 / par2;
		//cout << age1;
		printf("|%3d|%15s|%15s|%10s|%5s| %.3f |%7s|\n", n + 1, surname1, name1, marka1, age1, q, quantity1);
		cout << "|___|_______________|_______________|__________|_____|_______|_______|" << endl;

	} k = n;
	closesocket(Connection);

}
//////////////////
void choice2()
{
	char   surname1[10], name1[10], age1[5], mark1[9];
	int age;
	cout << "Введите название" << endl;
	cin >> surname1;
	cout << "Введите материал" << endl;
	cin >> name1;
	cout << "Введите марку машины" << endl;
	cin >> mark1;
	while (true) {

		cout << "Введите год выпуска мебели" << endl;
		cin >> age;

		if (age > 2020 || age < 2000) {
			cout << "Неыверно введенные данные\n";

			system("pause");
			system("cls");
			cin.clear(ios::failbit);
		}
		if (cin.good()) {
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cin.ignore(10, '\n');

	}
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1282);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server.\n";

	}
	sprintf(age1, "%d", age);
	send(Connection, surname1, sizeof(surname1), NULL);
	send(Connection, name1, sizeof(name1), NULL);
	send(Connection, mark1, sizeof(mark1), NULL);
	send(Connection, age1, sizeof(age1), NULL);
	closesocket(Connection);


}
//////////////////
void choice3()
{
	int i;
	int i1;
	while (true) {
		cout << "Введите номер записи мебели которую хотите изменить" << endl;


		cin >> i1;

		if (i1 > k || i1 < 1) {
			cout << "Неыверно введенные данные\n";



			cin.clear(ios::failbit);
		}
		if (cin.good()) {
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cin.ignore(10, '\n');


	}
	while (true) {
		cout << "Выберите что хотите изменить" << endl;
		cout << "1)Название мебели" << endl;
		cout << "2)материал мебели" << endl;
		cout << "3)Марка мебели" << endl;
		cout << "4)Год выпуска" << endl;


		cin >> i;

		if (i > 4 || i < 1) {
			cout << "Неыверно введенные данные\n";



			cin.clear(ios::failbit);
		}
		if (cin.good()) {
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cin.ignore(10, '\n');

	}
	char iz[15];
	int age;
	if (i == 1) { cout << "Введите новое название мебели" << endl; cin >> iz; }
	if (i == 2) { cout << "Введите новый материал мебели" << endl; cin >> iz; }
	if (i == 3) { cout << "Введите новую марку" << endl; cin >> iz; }
	if (i == 4) {
		while (true) {
			cout << "Выберите новый год" << endl;



			cin >> age;

			if (age > 2020 || age < 2000) {
				cout << "Неыверно введенные данные\n";



				cin.clear(ios::failbit);
			}
			if (cin.good()) {
				cin.ignore(10, '\n');
				break;
			}
			cin.clear();
			cin.ignore(10, '\n');

		}
		sprintf(iz, "%d", age);
	}


	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1117);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server1.\n";

	}
	char poz[1];
	char num[3];
	sprintf(num, "%d", i1);
	sprintf(poz, "%d", i);

	send(Connection, num, sizeof(num), NULL);
	send(Connection, poz, sizeof(poz), NULL);
	send(Connection, iz, sizeof(iz), NULL);
	closesocket(Connection);
	cout << "Запись успешно изменена" << endl;
	system("pause");

	adminmenu();
}
//////////////////
void choice4() {

	int i;
	while (true) {

		cout << "Введите порядковый номер записи которую хотите удалить" << endl;
		cin >> i;

		if (i > k || i < 1) {
			cout << "Неыверно введенные данные\n";

			system("pause");
			system("cls");
			cin.clear(ios::failbit);
		}
		if (cin.good()) {
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cin.ignore(10, '\n');

	}

	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1118);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server1.\n";

	}
	char num[3];
	sprintf(num, "%d", i);


	send(Connection, num, sizeof(num), NULL);

	closesocket(Connection);

}
void choice5()
{
	char newpass[15];
	cout << "Введите новый пароль" << endl;
	cin >> newpass;
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1119);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server1.\n";

	}



	send(Connection, newpass, sizeof(newpass), NULL);

	closesocket(Connection);

	adminmenu();

}
void choice6()

{
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1137);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server12.\n";

	}

	int num = 1, t = 0;
	char msg[1];
	k = 0;
	char login[15];
	char password[15];
	char id[4];
	k = 0;
	cout << " ___________________________________" << endl;
	cout << "| N |     логин     |    пароль     |" << endl;
	cout << "|___|_______________|_______________|" << endl;
	for (int i = 1; t == 0; i++)

	{
		recv(Connection, msg, sizeof(msg), NULL);

		recv(Connection, login, sizeof(login), NULL);
		recv(Connection, password, sizeof(password), NULL);
		recv(Connection, id, sizeof(id), NULL);
		num = atoi(msg);

		if (i == num)
		{
			printf("|%3d|%15s|%15s|\n", num, login, password);
			cout << "|___|_______________|_______________|" << endl;
			k++;
		}
		else
		{
			t = 1;
		}





	}
	closesocket(Connection);


}
void choice7()
{
	int i;
	int i1;
	while (true) {
		cout << "Введите номер записи которую хотите изменить" << endl;


		cin >> i1;

		if (i1 > k || i1 < 1) {
			cout << "Неыверно введенные данные\n";



			cin.clear(ios::failbit);
		}
		if (cin.good()) {
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cin.ignore(10, '\n');


	}
	while (true) {
		cout << "Выберите что хотите изменить" << endl;
		cout << "1)логин" << endl;
		cout << "2)Пароль" << endl;




		cin >> i;

		if (i > 2 || i < 1) {
			cout << "Неыверно введенные данные\n";



			cin.clear(ios::failbit);
		}
		if (cin.good()) {
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cin.ignore(10, '\n');

	}
	char iz[10];
	int age;
	if (i == 1) { cout << "Введите новый логин" << endl; cin >> iz; }
	if (i == 2) { cout << "Введите новый пароль " << endl; cin >> iz; }




	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1156);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server1.\n";

	}
	char poz[1];
	char num[3];
	sprintf(num, "%d", i1);
	sprintf(poz, "%d", i);

	send(Connection, num, sizeof(num), NULL);
	send(Connection, poz, sizeof(poz), NULL);
	send(Connection, iz, sizeof(iz), NULL);
	closesocket(Connection);
	cout << "Запись успешно изменена" << endl;

	system("pause");
	system("cls");
	menuuprklient();

}
void choice8()
{
	int n;
	char num[3];
	cout << "Введите номер для удаления" << endl;
	cin >> n;
	if (n<1 || n>k)
	{
		cout << "Данного номера не существует" << endl;
		choice8();
	}
	sprintf(num, "%d", n);

	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1210);
	addr.sin_family = AF_INET;
	char k1[1];
	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server11.\n";

	}
	send(Connection, num, sizeof(num), NULL);
	closesocket(Connection);
	cout << "Удаление прошло успешно" << endl;
	system("pause");
	system("cls");
	menuuprklient();
}
void choice9()
{

	system("cls");
	char newlog[15];
	char newpass[15];
	cout << "Введите логин" << endl;
	cin >> newlog;
	cout << "Введите пароль" << endl;
	cin >> newpass;
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1177);
	addr.sin_family = AF_INET;
	int i;
	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server.\n";

	}
	char msg[1];
	send(Connection, newlog, sizeof(newlog), NULL);
	send(Connection, newpass, sizeof(newpass), NULL);
	recv(Connection, msg, sizeof(msg), NULL);
	closesocket(Connection);

	if (msg[0] == '0') {
		cout << "Пользователь успешно создан" << endl;
		system("pause");
		system("cls"); menu();
	}
	if (msg[0] == '1') {
		cout << "Пользователь с данным логином уже существует" << endl; system("pause");
		system("cls"); menu();
	}

}
void choice10()
{
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1999);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server.\n";

	}
	char stat[4];

	recv(Connection, stat, sizeof(stat), NULL);
	int q = atoi(stat);
	if (q == 1) {
		cout << "Это эксперт уже оценил" << endl; system("pause");
		system("cls");
		closesocket(Connection);

		menuklient();
	}
	closesocket(Connection);
	choice1();
	choice13();

}
void choice11()
{
	char nl[15];
	cout << "Введите новый логин" << endl;
	cin >> nl;
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1563);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server.\n";

	}

	send(Connection, nl, sizeof(nl), NULL); \
		char str[1];
	recv(Connection, str, sizeof(str), NULL);
	int v = atoi(str);

	closesocket(Connection);
	if (v == 1) { cout << "Пользователь с таким логином сужествует!!!" << endl; system("pause");
	system("cls"); menuklient(); }
	if (v == 0) { cout << "Пользователь успешно изменен!!!" << endl; system("pause");
	system("cls"); menuklient(); }


}
void choice12()
{
	char nl[15];
	cout << "Введите новый пароль" << endl;
	cin >> nl;
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1565);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server.\n";

	}

	send(Connection, nl, sizeof(nl), NULL); \


		closesocket(Connection);
	cout << "Пользователь успешно изменен!!!" << endl; system("pause");
	system("cls");
	menuklient();
}
void choice13() {

	int mass[9];
	int mass2[9];
	int i, i1, i2, p;

	for (i = 1; i < 9; i++)
	{


		while (true) {
			printf("присвойте оцнку %d цели номер (1-8): ", i);
			cin >> mass[i];

			if (mass[i] > 8 || mass[i] < 1) {
				cout << "Неыверно введенные данные\n";

				cin.clear(ios::failbit);
			}
			if (cin.good()) {
				cin.ignore(10, '\n');
				break;
			}
			cin.clear();
			cin.ignore(10, '\n');

		}


		for (i1 = 0; i1 < i; i1++)
		{
			if (mass[i] == mass[i1]) { cout << "Данная цель уже оценена " << endl; i--; }
		}


	}
	for (i = 1; i < 9; i++)
	{
		//	cout << i << " " << mass[i] << endl;

	}
	//cout << endl;

	for (i2 = 1; i2 < 9; i2++)
	{
		for (i = 1; i < 9; i++)
		{
			if (i2 == mass[i])
			{
				mass2[i2] = i;
			}
		}
	}
	for (i2 = 1; i2 < 9; i2++)
	{
		mass2[i2] = 8 - mass2[i2];
		//	cout << i2 << " " << mass2[i2] << endl;

	}
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1994);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server.\n";

	}
	char num1[5], num2[5];

	for (i2 = 1; i2 < 9; i2++)
	{
		sprintf(num1, "%d", i2);
		sprintf(num2, "%d", mass2[i2]);
		mass2[i2] = 8 - mass2[i2];
		//	send(Connection, num1, sizeof(num1), NULL);
		send(Connection, num2, sizeof(num2), NULL);
	} 
	closesocket(Connection);
	cout << "Оценки выставленны успешно" << endl;
	menu();

}

void menuuprklient()
{
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1200);
	addr.sin_family = AF_INET;
	char k1[1];
	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server11.\n";

	}
	cout << "Cделайте выбор" << endl;
	cout << "1)Просмотр всех пользователей" << endl;
	cout << "2)Изменить данные пользователя" << endl;
	cout << "3)Удалить пользователя" << endl;
	cout << "4)Выход в меню администратра" << endl;
	cin >> k1;
	int po = atoi(k1);
	send(Connection, k1, sizeof(k1), NULL);
	closesocket(Connection);
	if (po == 1) {
		choice6();	 system("pause");
		system("cls");  menuuprklient();
	}
	if (po == 2) {
		choice6(); choice7();
	}
	if (po == 3) {
		choice6(); choice8();
	}
	if (po == 4) {
		cout << "4";

		system("cls");
		adminmenu();
	}
	else { cout << "Неверный вариант ответа" << endl; menuuprklient(); }
}
void menuklient()
{

	system("cls");
	int i;

	cout << "Сделайте выбор!!!" << endl;
	cout << "1)Оставить отзыв" << endl;
	cout << "2)Изменить логин" << endl;
	cout << "3)Изменить пароль" << endl;
	cout << "4)Выход  в меню  первого уровня" << endl;
	cout << "5)Выход из программы" << endl;

	cin >> i;
	try
	{
		if (i > 5 || i < 1)
		{
			throw 123;
		}
	}
	catch (int i1)
	{
		cout << "Неверно введенные данные!!!\n";
		system("pause");
		system("cls");
		menuklient();
	}


	//WSAStartup
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1562);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server.\n";

	}

	char msg[1];
	if (i == 1) {
		msg[0] = '1';
		send(Connection, msg, sizeof(msg), NULL);
		closesocket(Connection);

		system("cls");
		choice10();
	}
	if (i == 2) {
		msg[0] = '2';
		send(Connection, msg, sizeof(msg), NULL);
		closesocket(Connection);

		system("cls");
		choice11();
	}
	if (i == 3) {
		msg[0] = '3';
		send(Connection, msg, sizeof(msg), NULL);
		closesocket(Connection);

		system("cls");
		choice12();
	}
	if (i == 4) {
		msg[0] = '4';
		send(Connection, msg, sizeof(msg), NULL);
		closesocket(Connection);

		system("cls");
		menu();
	}
	if (i == 5) {
		msg[0] = '5';
		send(Connection, msg, sizeof(msg), NULL);
		closesocket(Connection);
		cout << "Программа завершена!" << endl;
		exit(1);
	}
}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru");
	menu();
}
void menu()
{
	setlocale(LC_ALL, "Russian");
	//WSAStartup
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;
	int i;
	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server.\n";

	}

	char msg[1];
	while (true) {
		cout << "Connected!\n";
		cout << "1)Вход от имени админа" << endl;
		cout << "2)Вход от имени клиента" << endl;
		cout << "3)Регистрация пользователя" << endl;
		cout << "4)Выход " << endl;

		cin >> i;

		if (i > 4 || i < 1) {
			cout << "Неыверно введенные данные\n";

			system("pause");
			system("cls");
			cin.clear(ios::failbit);
		}
		if (cin.good()) {
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cin.ignore(10, '\n');

	}

	system("cls");

	switch (i)
	{
	case 1:


		msg[0] = '1';
		send(Connection, msg, sizeof(msg), NULL);
		closesocket(Connection);
		admin();


		break;
	case 2:


		msg[0] = '2';
		send(Connection, msg, sizeof(msg), NULL);
		closesocket(Connection);
		klient();


		break;
	case 3:
		msg[0] = '3';
		send(Connection, msg, sizeof(msg), NULL);
		closesocket(Connection);
		choice9();
		break;

	case 4:
		msg[0] = '4';
		send(Connection, msg, sizeof(msg), NULL);
		closesocket(Connection);
		cout << "Программа завершена";
		exit(1);
		break;

	}


	system("pause");

}
void admin()
{

	system("cls");
	char  password[15];
	string password1;
	cout << "Вход от имени администпратора" << endl;
	cout << "Введите пароль" << endl;

	int ch = 0;
	while (true) // Создание бесконечного цикла.
	{
		ch = _getch();
		if (ch == 0) {
			ch = _getch();
		}
		if (ch == 13) // Установка Enter на прерывание цикла.
		{
			break; // Прерывание цикла.
		}
		if (ch == 27) // Установка Esc на закрытие консоли.
		{
			exit(0); // Выход из консоли.
		}
		if (ch == 8) // Установка Backspace на удаление символов.
		{
			cout << (char)8 << ' ' << char(8);

			if (!password1.empty())
				password1.erase(password1.length() - 1);
		}
		else
		{
			cout << '*'; // Замена символов на *
			password1 += (char)ch; // Преврашение кода из целого числа в символ.
		}
	}
	strcpy(password, password1.c_str());
	//WSAStartup
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1113);
	addr.sin_family = AF_INET;
	int i;
	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server.\n";

	}


	send(Connection, password, sizeof(password), NULL);
	char str[1];
	recv(Connection, str, sizeof(str), NULL);
	//cout << str;
	closesocket(Connection);


	if (str[0] == '0') {
		cout << endl << "Вход выпoлнен" << endl; system("pause");
		system("cls"); adminmenu();
	}
	else {
		cout << endl << "неверный пароль" << endl; system("pause");
		system("cls"); menu();
	}

}

void klient()
{

	system("cls");
	cout << "Вход от имени клиента" << endl;
	char login[15], password[15];
	cout << "Введите логин" << endl;
	cin >> login;
	cout << "Введите пароль" << endl;
	string password1;


	int ch = 0;
	while (true) // Создание бесконечного цикла.
	{
		ch = _getch();
		if (ch == 0) {
			ch = _getch();
		}
		if (ch == 13) // Установка Enter на прерывание цикла.
		{
			break; // Прерывание цикла.
		}
		if (ch == 27) // Установка Esc на закрытие консоли.
		{
			exit(0); // Выход из консоли.
		}
		if (ch == 8) // Установка Backspace на удаление символов.
		{
			cout << (char)8 << ' ' << char(8);

			if (!password1.empty())
				password1.erase(password1.length() - 1);
		}
		else
		{
			cout << '*'; // Замена символов на *
			password1 += (char)ch; // Преврашение кода из целого числа в символ.
		}
	}
	strcpy(password, password1.c_str());

	//WSAStartup
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1112);
	addr.sin_family = AF_INET;
	int i;
	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server.\n";

	}
	char str[1];
	send(Connection, login, sizeof(login), NULL);

	send(Connection, password, sizeof(password), NULL);
	recv(Connection, str, sizeof(str), NULL);
	closesocket(Connection);
	if (str[0] == '0') { cout << "Неверный логин и/или пароль" << endl; menu(); }
	if (str[0] == '1') {
		cout <<endl<< "Успешный вход" << endl;
		system("pause"); menuklient();
	}
}

void adminmenu()
{

	system("cls");
	setlocale(LC_ALL, "Russian");
	//WSAStartup
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1114);
	addr.sin_family = AF_INET;
	int i;
	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server1.\n";

	}

	char msg[1];
	while (true) {
		cout << "Меню Администраора" << endl;
		cout << "1)Просмотр имеющейся мебели" << endl;

		cout << "2)Изменить информацию о мебели" << endl;

		cout << "3)Изменить пароль" << endl;
		cout << "4)Управление клиентами " << endl;
		cout << "5)Выход в меню 1-го уровня" << endl;
		cout << "6)Выход из программы" << endl;

		cin >> i;

		if (i > 6 || i < 1) {
			cout << "Неыверно введенные данные\n";

			system("pause");
			system("cls");
			cin.clear(ios::failbit);
		}
		if (cin.good()) {
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cin.ignore(10, '\n');

	}

	switch (i)
	{
	case 1:
		sprintf(msg, "%d", i);
		send(Connection, msg, sizeof(msg), NULL);
		closesocket(Connection);
		system("cls");
		choice1();
		system("pause");
		system("cls");
		adminmenu();
		break;
	case 2:

		sprintf(msg, "%d", i);
		send(Connection, msg, sizeof(msg), NULL);
		closesocket(Connection);

		system("cls");
		choice1();
		choice3();
		system("pause");
		system("cls");
		adminmenu();


		break;
	case 3:
		sprintf(msg, "%d", i);
		send(Connection, msg, sizeof(msg), NULL);
		closesocket(Connection);

		system("cls");
		choice5();
		system("pause");
		system("cls");
		adminmenu();
		break;
	case 4:
		sprintf(msg, "%d", i);
		send(Connection, msg, sizeof(msg), NULL);
		closesocket(Connection);

		system("cls");
		menuuprklient();

		system("cls");
		adminmenu();
		break;
	case 5:
		sprintf(msg, "%d", i);
		send(Connection, msg, sizeof(msg), NULL);
		closesocket(Connection);
		system("pause");
		system("cls");
		menu();

		break;
	case 6:
		sprintf(msg, "%d", i);
		send(Connection, msg, sizeof(msg), NULL);
		closesocket(Connection);

		system("cls");
		cout << "программа заврешена" << endl;
		exit(0);
		break;
	default:
		cout << "Неверный вариант ответа" << endl;

		adminmenu();
	}


	system("pause");

}