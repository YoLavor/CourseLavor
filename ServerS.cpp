#include "stdafx.h"
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>

#include <fstream>
#include <iostream>
#include <string>
#include <locale>
#include <iomanip>


#include <sstream>
using namespace std;
#pragma warning(disable: 4996)
void admin();
void ch1();
void ch2();
void klient1();
void menuadmin();
void menu();
void uprklient();
void addk();
void qwe();
int y;
char l1[15];

template<typename T>
class newk
{
public:
	newk(T newlogin, T newpass)
	{
		this->newlogin = newlogin;
		this->newpass = newpass;
		//cout << "shablon"<<newlogin << newpass;
		ofstream fout;
		fout.open("D:\\2.txt", ios::app | ios::binary);
		fout << newlogin<<" "<<newpass<<" 0"<<endl ;
		fout.close();
	}


private:
	T newlogin;
	T newpass;

};
void addk()
{
	char newlog[15];
	char newpass[15];

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

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);
	
	recv(newConnection, newlog, sizeof(newlog), NULL);
	recv(newConnection, newpass, sizeof(newpass), NULL);
	cout << newlog << newpass;
	int pr = 0;
	ifstream fout("D:\\2.txt");
	string line;
	int numb = 1;
	
	if (!fout.is_open())
	{
		cout << "файл не открыт";
	}
	while (!fout.eof() )
	{

		getline(fout, line, '\n');
		string l, p;
		


		istringstream iss(line);
	
		iss >> l >> p;
		//cout << l << p;
		

		//int i = 0, pr = 0;
		//for (i = 0; newlog[i] != '\0' ; i++)
		
			
				cout << "l1=" << l << "  newlog=" << newlog <<"|"<< endl;
				if (l == newlog) {
					pr = 1;
			}


		
	}
	fout.close();
	char msg[1];
		cout << "aq" << pr;
		if (pr == 0) {
			cout << pr;
			msg[0] = '0';
			send(newConnection, msg, sizeof(msg), NULL);
			closesocket(sListen);
			closesocket(newConnection);
			string t2 = newlog;
			string t1 = newpass;
			newk<string> c(t2, t1);
			menu();
}
		if (pr == 1) {
			cout << pr;
			msg[0] = '1';
			send(newConnection, msg, sizeof(msg), NULL);
			closesocket(sListen);
			closesocket(newConnection);
			menu();
		}
	

}
class klient  {
public:


	  void showklient() {
		
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

		  SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
		  bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
		  listen(sListen, SOMAXCONN);

		  SOCKET newConnection;
		  newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);
		  ifstream fout("D:\\2.txt");
		  string line;
		
		 char msg[1],login[15],password[15],stat1[4];
		

		  if (!fout.is_open())
		  {
			  cerr << "файл не открыт";
		  }
		  int num = 1;
		  while (!fout.eof())
		  {

			  string n, s,stat;
			  

			  getline(fout, line, '\n');
			  istringstream iss(line);

			  iss >> s >> n >> stat;
			
			  strcpy(login, s.c_str());
			  strcpy(password, n.c_str());
			  if (s != "")
			  {
				  cout << "S=" << s << "N=" << n << endl;
				  sprintf(msg, "%d", num);
				  send(newConnection, msg, sizeof(msg), NULL);

				  send(newConnection, login, sizeof(login), NULL);
				  send(newConnection, password, sizeof(password), NULL);
				  send(newConnection, stat1, sizeof(stat1), NULL);
				 
				  num++;
			  }

			
		  }
		  fout.close();
		  closesocket(sListen);
		  closesocket(newConnection);
		  if (y == 1) {
			  uprklient();
		  }
		  if (y == 2) {
			changeklient();
		  }
	  
	  if (y == 3) {
		 removeklient();
	  }
		
	}
	  void removeklient() {
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

		  SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
		  bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
		  listen(sListen, SOMAXCONN);

		  SOCKET newConnection;
		  newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

		  if (newConnection == 0) {
			  std::cout << "Error #2\n";
		  }
		  char poz[1], iz[10], num[3];
		  recv(newConnection, num, sizeof(num), NULL);
		  recv(newConnection, poz, sizeof(poz), NULL);
		  recv(newConnection, iz, sizeof(iz), NULL); \
			  int n = atoi(num);
		  int pz = atoi(poz);
		

		  closesocket(newConnection);
		  closesocket(sListen);

		  ifstream file_in;

		  file_in.open("D:\\2.txt", std::ios::app);

		  if (!file_in)
		  {
			  cerr << "Ошибка, невозможно открыть файл : D:\\1.txt" << std::endl;

		  }
		  int i_number_line_delete = 1;
		  i_number_line_delete = n;
		  system("cls");
		  int i_number_line_now = 1;
		  string line;
		  string line_file_text;
		  string surname1, mark1;
		  while (getline(file_in, line))
		  {


			  if (!(i_number_line_now == i_number_line_delete))
			  {
				  line_file_text.insert(line_file_text.size(), line);

				  line_file_text.insert(line_file_text.size(), "\r\n");

			  }
			  else {

				  string surname, mark;



				  istringstream iss(line);

				  iss >> surname1 >> mark1;







			  }	i_number_line_now++;
		  }

		  file_in.close();

		  //теперь в line_file_text будет содержаться измененный текст файла, теперь можно перезаписать файл

		  std::ofstream file_out;

		  file_out.open("D:\\2.txt", std::ios::binary); //открыть и обрезать

		  //записать

		  file_out.write(line_file_text.c_str(), line_file_text.size()-1);
		
		  file_out.close();
		

		  //////////////////////

			  //////////////////


		  ofstream fout;
		
	
		  uprklient();

	}
	void  changeklient() {
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

		SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
		bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
		listen(sListen, SOMAXCONN);

		SOCKET newConnection;
		newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

		if (newConnection == 0) {
			std::cout << "Error #2\n";
		}
		char poz[1], iz[10], num[3];
		recv(newConnection, num, sizeof(num), NULL);
		recv(newConnection, poz, sizeof(poz), NULL);
		recv(newConnection, iz, sizeof(iz), NULL); \
			int n = atoi(num);
		int pz = atoi(poz);


		string surname, mark, p;
		closesocket(newConnection);
		closesocket(sListen);

		ifstream file_in;

		file_in.open("D:\\2.txt", std::ios::app);

		if (!file_in)
		{
			cerr << "Ошибка, невозможно открыть файл : D:\\1.txt" << std::endl;

		}
		int i_number_line_delete= 1;
		i_number_line_delete = n;
		system("cls");
		int i_number_line_now = 1;
		string line;
		string line_file_text;
		string surname1, mark1;
		while (getline(file_in, line))
		{
		

			if (!(i_number_line_now == i_number_line_delete))
			{
				line_file_text.insert(line_file_text.size(), line);

				line_file_text.insert(line_file_text.size(), "\r\n");

			}
			else {

			



				istringstream iss(line);

				iss >> surname1 >> mark1>>p ;







			}	i_number_line_now++;
		}

		file_in.close();

		//теперь в line_file_text будет содержаться измененный текст файла, теперь можно перезаписать файл

		std::ofstream file_out;

		file_out.open("D:\\2.txt", std::ios::binary); //открыть и обрезать

		//записать

		file_out.write(line_file_text.c_str(), line_file_text.size());
		file_out.clear();
		file_out.close();
	//////////////////////
	
		//////////////////


		ofstream fout;

		switch (pz)

		{
		case 1:




			fout.open("D:\\2.txt", std::ios::app);
			fout  << iz << " " << mark1 <<" "<<p<<endl;
			fout.close();

			break;
		case 2:
			fout.open("D:\\2.txt", std::ios::app);
			fout << surname1 << " " << iz<<" "<<p<<endl ;
			fout.close();

			break;


		}
		
		uprklient();
	}

};
class menuk {
public:void accountlogin()
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
	addr.sin_port = htons(1112);
	addr.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);
	recv(newConnection, login, sizeof(login), NULL);
    recv(newConnection, password, sizeof(password), NULL);

	int pr = 0;
	ifstream fout("D:\\2.txt");
	string line;
	int numb = 1;

	if (!fout.is_open())
	{
		cout << "файл не открыт";
	}
	while (!fout.eof())
	{

		getline(fout, line, '\n');
		string l, p,po;



		istringstream iss(line);

		iss >> l >> p>>po;
		//cout << l << p;


		//int i = 0, pr = 0;
		//for (i = 0; newlog[i] != '\0' ; i++)


		
		if (l == login&& p==password) {
			pr = 1; 
				strcpy(stat, po.c_str());
		}




	}
	fout.close();
	char str[1];
	sprintf(str, "%d", pr);
	//cout << str[0];
	send(newConnection, str, sizeof(str), NULL);
	closesocket(newConnection);
	closesocket(sListen);
	cout << "login1=" << login;
	if (pr == 0) { menu(); }
	if (pr == 1) {
		menk();
	}
}
	  void menk()
	  {
		  cout << "login2=" << login;
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

		  SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
		  bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
		  listen(sListen, SOMAXCONN);

		  SOCKET newConnection;
		  newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);
		  char msg[1];
		  recv(newConnection, msg, sizeof(msg), NULL);
		  closesocket(newConnection);
		  closesocket(sListen);
		  int i = atoi(msg);
		  if (i == 1) { mp(); }
		  if (i == 2) { izml(); }
		  if (i == 3) { izmp(); }
		  if (i == 4) { menu(); }
		  if (i == 5) { exit(1); }
	  }
	  void izml()
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
		  addr.sin_port = htons(1563);
		  addr.sin_family = AF_INET;

		  SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
		  bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
		  listen(sListen, SOMAXCONN);

		  SOCKET newConnection;
		  newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);
		  char msg[15];
		  recv(newConnection, msg, sizeof(msg), NULL);
		  
		  ifstream fout("D:\\2.txt");
		  string line;

	

		int r = 0;
		  if (!fout.is_open())
		  {
			  cerr << "файл не открыт";
		  }
		
		  while (!fout.eof())
		  {

			  string n, s;


			  getline(fout, line, '\n');
			  istringstream iss(line);

			  iss >> s >> n;

			if(s==msg)
			{
				r = 1;
			}


		  }
		  fout.close();
		  cout << r;
		  char str[1];
		  sprintf(str, "%d", r);
		  send(newConnection, str, sizeof(str), NULL);
		  closesocket(newConnection);
		  closesocket(sListen);
		  if (r == 1) { menk(); }

		  ifstream file_in;

		file_in.open("D:\\2.txt", std::ios::app);

		if (!file_in)
		{
			cerr << "Ошибка, невозможно открыть файл : D:\\1.txt" << std::endl;

		}
		
		system("cls");
		int i_number_line_now = 1;
	
		string line_file_text;
		string surname1, mark1;
		while (getline(file_in, line))
		{
			string surname, mark;



			istringstream iss(line);

			iss >> surname1 >> mark1;

			if (surname1!=login)
			{
				line_file_text.insert(line_file_text.size(), line);

				line_file_text.insert(line_file_text.size(), "\r\n");

			}
			else {

				string surname, mark,p;



				istringstream iss(line);

				iss >> surname1 >> mark1 >>p;
				
				line_file_text.insert(line_file_text.size(), msg);
				line_file_text.insert(line_file_text.size()," ");
				line_file_text.insert(line_file_text.size(), mark1);
				line_file_text.insert(line_file_text.size(), " ");
				line_file_text.insert(line_file_text.size(), p);
				line_file_text.insert(line_file_text.size(), " ");

				line_file_text.insert(line_file_text.size(), "\n");
				strcpy(login, msg);


			





			}	i_number_line_now++;
		}

		file_in.close();

		//теперь в line_file_text будет содержаться измененный текст файла, теперь можно перезаписать файл

		std::ofstream file_out;

		file_out.open("D:\\2.txt", std::ios::binary); //открыть и обрезать

		//записать

		file_out.write(line_file_text.c_str(), line_file_text.size());
		file_out.clear();
		file_out.close();

		menk();
	  }
	  void izmp()
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
		  addr.sin_port = htons(1565);
		  addr.sin_family = AF_INET;

		  SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
		  bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
		  listen(sListen, SOMAXCONN);

		  SOCKET newConnection;
		  newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);
		  char msg[15];
		  recv(newConnection, msg, sizeof(msg), NULL);

		  ifstream fout("D:\\2.txt");
		  string line;



		
		  
		  closesocket(newConnection);
		  closesocket(sListen);
	

		  ifstream file_in;

		  file_in.open("D:\\2.txt", std::ios::app);

		  if (!file_in)
		  {
			  cerr << "Ошибка, невозможно открыть файл : D:\\1.txt" << std::endl;

		  }

		  system("cls");
		  int i_number_line_now = 1;
		  char pq[4];
			  string line_file_text;
		  string surname1, mark1;
		  while (getline(file_in, line))
		  {
			  string surname, mark,p;



			  istringstream iss(line);

			  iss >> surname1 >> mark1>>pq;

			  if (surname1 != login)
			  {
				  line_file_text.insert(line_file_text.size(), line);

				  line_file_text.insert(line_file_text.size(), "\r\n");

			  }
			  else {

				  string surname, mark,p3;



				  istringstream iss(line);

				  iss >> surname1 >> mark1>>p3;

				  line_file_text.insert(line_file_text.size(), surname1);
				  line_file_text.insert(line_file_text.size(), " ");
				  line_file_text.insert(line_file_text.size(), msg);
				  line_file_text.insert(line_file_text.size(), " ");
				  line_file_text.insert(line_file_text.size(),p3);
				  line_file_text.insert(line_file_text.size(), " ");
				  line_file_text.insert(line_file_text.size(), "\r\n");







			  }	i_number_line_now++;
		  }

		  file_in.close();

		  //теперь в line_file_text будет содержаться измененный текст файла, теперь можно перезаписать файл

		  std::ofstream file_out;

		  file_out.open("D:\\2.txt", std::ios::binary); //открыть и обрезать

		  //записать

		  file_out.write(line_file_text.c_str(), line_file_text.size());
		  file_out.clear();
		  file_out.close();

		  menk();
	  }
	  void mp()
	  {
		  cout << "login3/5=" << login;
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

		  SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
		  bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
		  listen(sListen, SOMAXCONN);

		  SOCKET newConnection;
		  newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);
		 send(newConnection, stat, sizeof(stat), NULL);
		 int q = atoi(stat);
		 if (q == 1) {
			 closesocket(newConnection);
			 closesocket(sListen);
			 menk();
		 }
		 y = 4;
		 cout << "login31=" << login;
		
			 strcpy(l1, login);

		 qwe();

		
		 mp1();
	  }
	  void mp1() {
		  cout << "login4=" << login;
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

		  SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
		  bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
		  listen(sListen, SOMAXCONN);
	
		  SOCKET newConnection;
		  newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);
		  int mass2[9];
		  int i, i1, i2, p;
		  char num1[5], num2[5];
		  for (i2 = 1; i2 < 9; i2++)
		  {
			  //	recv(newConnection, num1, sizeof(num1), NULL);
			  recv(newConnection, num2, sizeof(num2), NULL);
			  i = atoi(num2);
			  mass2[i2] = i;


		  }
		  for (i2 = 1; i2 < 9; i2++)
		  {

			  cout << i2 << " " << mass2[i2] << endl;

		  }
		  closesocket(newConnection);
		  closesocket(sListen);

		  ifstream file_in;

		  file_in.open("D:\\1.txt", std::ios::app);

		  if (!file_in)
		  {
			  cerr << "Ошибка, невозможно открыть файл : D:\\1.txt" << std::endl;

		  }
		  int i_number_line_delete;
	

		  int i_number_line_now = 0;
		  string line;
		  string line_file_text;

		  while (getline(file_in, line))
		  {
			  i_number_line_now++;

			 

			  string surname, mark, name, age;
			  int p1, p2;



				  istringstream iss(line);

				  iss >> surname >> name >> mark >> age >> p1 >> p2;

				  p1 = p1 + mass2[i_number_line_now];
				  p2 = p2 + 20;


				  if (i_number_line_now < 9)
				  {
					  ofstream fout;



					  fout.open("D:\\5.txt", std::ios::app);
					  fout << surname << " " << name << " " << mark << " " << age << " " << p1 << " " << p2 << endl;
					  fout.close();
				  }


				  



			  
		  }

		  file_in.close();
		  remove("D:\\1.txt"); 
		  char oldname[] = "D:\\5.txt";                   // старое имя файла
		  char newname[] = "D:\\1.txt";                   // новое имя файла

		  int result;
	
		  result = rename(oldname, newname);
		  ofstream oFile("D:\\5.txt");

		//  cout << "login5=" << login;
		  
		  q1();
		  menu();
	  }
	  
	  void q1()
	  {
		  strcpy(login, l1);
		 // cout << "login6=" << login;
		  ifstream file_in;
		  file_in.open("D:\\2.txt", std::ios::app);

		  if (!file_in)
		  {
			  cerr << "Ошибка, невозможно открыть файл : D:\\2.txt" << std::endl;

		  }

		  int i_number_line_now = 1;
		  string line;
		  string line_file_text;
		  string surname1, mark1;
		  while (getline(file_in, line))
		  {
			  string surname, mark,p;



			  istringstream iss(line);

			  iss >> surname1 >> mark1>>p;

			  if (surname1 != login)
			  {
				  cout << "s1";
				  line_file_text.insert(line_file_text.size(), line);

				  line_file_text.insert(line_file_text.size(), "\r\n");

			  }
			  else {

				  cout << "s2";
				  string null = "1";


				  line_file_text.insert(line_file_text.size(), surname1);
				  line_file_text.insert(line_file_text.size(), " ");
				  line_file_text.insert(line_file_text.size(), mark1);
				  line_file_text.insert(line_file_text.size(), " ");
				  line_file_text.insert(line_file_text.size(), null);
				  line_file_text.insert(line_file_text.size(), " ");

				  line_file_text.insert(line_file_text.size(), "\n");
				








			  }	i_number_line_now++;
		  }
		
		  file_in.close();

		  //теперь в line_file_text будет содержаться измененный текст файла, теперь можно перезаписать файл

		  std::ofstream file_out;

		  file_out.open("D:\\2.txt", std::ios::binary); //открыть и обрезать

		  //записать

		  file_out.write(line_file_text.c_str(), line_file_text.size());
		  file_out.clear();
		  file_out.close();
		  menu();
		

	}	
	 
protected:
	char login[15];
	char password[15];
	char stat[4];
};
class admin {
public: char passadmin[15];
};
class admin_choice : public admin {
public: 
////////////////////////////////////	
	void show() {

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

		SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
		bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
		listen(sListen, SOMAXCONN);

		SOCKET newConnection;
		newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

		char msg[1];


		ifstream fout("D:\\4.txt");
		string line;
		int n = 0;

		if (!fout.is_open())
		{
			cerr << "файл не открыт";
		}
		while (!fout.eof())
		{



			getline(fout, line, '\n');
			istringstream iss(line);



		}
		strcpy(msg, line.c_str());

		fout.close();
		//cout << msg;

		send(newConnection, msg, sizeof(msg), NULL);


		ifstream fout1("D:\\1.txt");
		string line1;
		int numb = 1;

		if (!fout1.is_open())
		{
			cerr << "файл не открыт";
		}
		while (!fout1.eof())
		{

			string surname,name, marka ,age,mark,quantity;

			getline(fout1, line, '\n');
			istringstream iss(line);
			char   surname1[15], name1[15],marka1[9], age1[5], mark1[5], quantity1[5];
			iss >> surname>>name>> marka >> age>>mark>>quantity;
			strcpy(surname1, surname.c_str());
			strcpy(name1, name.c_str());
			strcpy(marka1, marka.c_str());
			strcpy(age1, age.c_str());
		    strcpy(mark1, mark.c_str());
			strcpy(quantity1, quantity.c_str());
		


			send(newConnection, surname1, sizeof(surname1), NULL);
			send(newConnection, name1, sizeof(name1), NULL);
			send(newConnection, marka1, sizeof(marka1), NULL);
			send(newConnection, age1, sizeof(age1), NULL);
     		send(newConnection, mark1, sizeof(mark1), NULL);
			send(newConnection, quantity1, sizeof(quantity1), NULL);
	}
		fout1.close();
		
		closesocket(sListen);
		closesocket(newConnection);
		ch1();

	}
	//////


			
	
	

void add() {
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

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);
	char   surname1[10],name1[10], age1[5], mark1[9];
   recv(newConnection, surname1, sizeof(surname1), NULL);
   recv(newConnection, name1, sizeof(name1), NULL);
	recv(newConnection, mark1, sizeof(mark1), NULL);
	recv(newConnection, age1, sizeof(age1), NULL);

	closesocket(newConnection);
	closesocket(sListen);
	cout << surname1 << mark1 << age1;
	ofstream fout;
	fout.open("D:\\1.txt", ios::app | ios::binary);
	fout <<surname1 << " " <<name1<<" "<< mark1 << " " << age1 << " 0 0" << endl;
	fout.close();
	ifstream fout1("D:\\4.txt");
	string line;


	if (!fout1.is_open())
	{
		cerr << "файл не открыт";
	}




		getline(fout1, line, '\n');
		istringstream iss(line);
		cout <<"proverka" <<line;
		fout1.close();
		ofstream rewrite("D:\\4.txt", ios::trunc);
		ofstream fout2;
		rewrite.close();
		fout2.open("D:\\4.txt", ios::app);
		int n = atoi(line.c_str());
		fout2 << n + 1;
		fout2.close();
		
	
	  }
//////////////////////////


void change() {
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

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

	if (newConnection == 0) {
		std::cout << "Error #2\n";
	}
	char poz[1], iz[15], num[3];
	recv(newConnection, num, sizeof(num), NULL);
	recv(newConnection, poz, sizeof(poz), NULL);
	recv(newConnection, iz, sizeof(iz), NULL);\
	int n = atoi(num);
	int pz = atoi(poz);


	closesocket(newConnection);
	closesocket(sListen);

	ifstream file_in;

	file_in.open("D:\\1.txt", std::ios::app);

	if (!file_in)
	{
		cerr << "Ошибка, невозможно открыть файл : D:\\1.txt" << std::endl;
		
	}
	int i_number_line_delete ;
	i_number_line_delete=n;
	system("cls");
	int i_number_line_now = 0;
	string line;
	string line_file_text;

	while (getline(file_in, line))
	{
		i_number_line_now++;

		if (!(i_number_line_now == i_number_line_delete))
		{
			line_file_text.insert(line_file_text.size(), line);

			line_file_text.insert(line_file_text.size(), "\r\n");

		}
		else {

			string surname, mark,name, age, p1, p2;



			istringstream iss(line);

			iss >> surname >>name>> mark >> age >> p1>>p2;


			


			ofstream fout;

			switch (pz)

			{
			case 1:

				fout.open("D:\\1.txt", std::ios::app);
				fout << iz << " " << name << " " << mark << " " << age << " " << p1 << " " << p2 << endl;
				fout.close();

				break;
			case 2:

				fout.open("D:\\1.txt", std::ios::app);
				fout << surname << " " << iz << " " << mark << " " << age << " " << p1 << " " << p2 << endl;
				fout.close();
				break;
			case 3:

				fout.open("D:\\1.txt", std::ios::app);
				fout << surname << " " << name << " " << iz << " " << age << " " << p1 << " " << p2 << endl;
				fout.close();
				break;
			case 4:

				fout.open("D:\\1.txt", std::ios::app);
				fout << surname << " " << name << " " << mark << " " << iz << " " << p1 << " " << p2 << endl;
				fout.close();
				break;

			
			}



		}
	}

	file_in.close();

	//теперь в line_file_text будет содержаться измененный текст файла, теперь можно перезаписать файл

	std::ofstream file_out;

	file_out.open("D:\\1.txt", std::ios::binary); //открыть и обрезать

	//записать

	file_out.write(line_file_text.c_str(), line_file_text.size());
	file_out.clear();
	file_out.close();
	menuadmin();

}
void ch1()
{
	cout << "tut";
	if (y == 1) {
		menuadmin();
	}
	if (y == 2) {
		change();
		
	}
	if(y==3)
	{
		remove();
		
	}
	if (y == 4)
	{
		menuk M;
		M.mp1();
	}
	

}

void remove() {
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

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr); 

	char num[3];
	int n;

	recv(newConnection, num, sizeof(num), NULL);
	closesocket(newConnection);
	closesocket(sListen);
	n = atoi(num);
	cout << n;
	ifstream file_in;


	file_in.open("D:\\1.txt");

	if (!file_in)
	{
		cerr << "Ошибка, невозможно открыть файл : D:\\1.txt" << std::endl;
		
	}
	
	cout << "Введите номер строки для удаления :" << std::endl;
	int i_number_line_delete = n;


	int i_number_line_now = 0;
	string line;
	string line_file_text;

	while (getline(file_in, line))
	{
		i_number_line_now++;

		if (!(i_number_line_now == i_number_line_delete))
		{
			line_file_text.insert(line_file_text.size(), line);

			line_file_text.insert(line_file_text.size(), "\r\n");

		}
	}

	file_in.close();



	std::ofstream file_out;

	file_out.open("D:\\1.txt", std::ios::trunc | std::ios::binary);


	file_out.write(line_file_text.c_str(), line_file_text.size());
	file_out.clear();

	ifstream fout1("D:\\4.txt");
	string line1;


	if (!fout1.is_open())
	{
		cerr << "файл не открыт";
	}




	getline(fout1, line1, '\n');
	istringstream iss(line1);
	cout << "proverka" << line1;
	fout1.close();
	ofstream rewrite("D:\\4.txt", ios::trunc);
	ofstream fout2;
	rewrite.close();
	fout2.open("D:\\4.txt", ios::app);
 n = atoi(line1.c_str());
	fout2 << n - 1;
	fout2.close();
	menuadmin();

	  }
void newpass()
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
	addr.sin_port = htons(1119);
	addr.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

	

	recv(newConnection, passadmin, sizeof(passadmin), NULL);
	closesocket(newConnection);
	closesocket(sListen);
	ofstream rewrite("D:\\3.txt", ios::trunc);
	ofstream fout2;
	rewrite.close();
	fout2.open("D:\\3.txt", ios::app);
	
	fout2 << passadmin;
	fout2.close();
	menuadmin();
}

};
void uprklient() {
	cout << "uprk" << endl;
	int f;
	char k1[1];
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

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

	if (newConnection == 0) {
		std::cout << "Error #2\n";
	}
	
	recv(newConnection, k1, sizeof(k1), NULL);
	//cout << k1;
	cout << "uprk1" << endl;
	f = atoi(k1);
	try
	{
		if (f < 1 || f > 4)
		{
			throw 123;
		}
	}
	catch (int i)
	{
		cout << "f=" << f;
		closesocket(sListen);
		closesocket(newConnection);
		uprklient();
	}
	klient Klient;
	
	closesocket(sListen);
	closesocket(newConnection);
	
	//cout << "f=" << f;

	switch (f)
	{
	case 1: 
		y = 1;
		Klient.showklient();

		break;
	case 2:
		y = 2;
	
		Klient.showklient();
	
		break;


	case 3:
		
		y = 3;
		
		Klient.showklient();
		break;
	case 4:
		cout << "4";
		
		menuadmin();
		break;
//	default:uprklient();

	}

}
int main(){
	setlocale(LC_ALL, "rus");
	menu();
	
}
void menu() {
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

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

	if (newConnection == 0) {
		std::cout << "Error #2\n";
	} 
	char msg[1];
	recv(newConnection, msg, sizeof(msg), NULL);
	closesocket(newConnection);
	closesocket(sListen);
	//cout <<msg[0];
	menuk MenuK;
	if (msg[0] == '1') { admin(); }
	if (msg[0] == '2') { MenuK.accountlogin(); }
	if (msg[0] == '3') { addk(); }
	if (msg[0] == '4') { exit(0); }
	

	
	
}
void admin()
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
	addr.sin_port = htons(1113);
	addr.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);
	char password[15], passadmin[15];
	recv(newConnection, password, sizeof(password), NULL);
	//cout << password;
	ifstream fout("D:\\3.txt");
	string line;
	int numb = 1;

	if (!fout.is_open())
	{
		cerr << "файл не открыт";
	}
	while (!fout.eof())
	{


		getline(fout, line, '\n');
		istringstream iss(line);
		strcpy(passadmin, line.c_str());

		
	}
	int i = 0, p = 0;
	for (i = 0; passadmin[i] != '\0' && p == 0; i++)
	{
		if (passadmin[i] != password[i]) {
			p = 1;
	}

	}
	char str[1];
	sprintf(str, "%d", p); 
	//cout << str[0];
	send(newConnection, str, sizeof(str), NULL);
	closesocket(newConnection);
	closesocket(sListen);
	if (p == 0) { menuadmin(); }
	else { menu(); }
}

 void menuadmin()
 {
	 admin_choice ACh;
	// cout << "ma";
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

	 SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	 bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	 listen(sListen, SOMAXCONN);

	 SOCKET newConnection;
	 newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

	 if (newConnection == 0) {
		 std::cout << "Error #2\n";
	 }
	 char msg1[1];
	 recv(newConnection, msg1, sizeof(msg1), NULL);

	 klient K;
	 closesocket(newConnection);
	 closesocket(sListen);
	
	 int i = atoi(msg1);
	 cout << i;
	 switch (i)
	 {
	 case 1:
		 y = 1;
		 ACh.show();
	
		 break;



	 case 2:
		 y = 2;
		 ACh.show();
		 menuadmin();

		 break;


		 break;
	 case 3:
		
		 ACh.newpass();
		 menuadmin();
		 break;
	 case 4:
		 uprklient();
		 menuadmin();
		 break;
	 case 5:
		
		 menu();
		 break;
	 case 6:
		 cout << "программа заврешена";
		 exit(0);
		 break;
	 default:
		 menuadmin();

	 }
	
	 //else { klient(); }
 }
 void qwe()
 {
	 admin_choice q999;
	 q999.show();
 }