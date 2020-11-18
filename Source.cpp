#include <iostream>
#include <math.h>
#include <string>
#include <conio.h>

using namespace std;

class Administrirovanie
{
protected:
	int age, zp;
	string name;
	string surname;
	string firma;
public:
	Administrirovanie(int n, int zp1, string name1, string surname1, string firma1)
	{
		age = n;
		zp = zp1;
		name = name1;
		surname = surname1;
		firma = firma1;
	}
	virtual void show() = 0;
	virtual void Pension(int n, string gender) = 0;
};

class Director : virtual public Administrirovanie
{
protected:
	string gender;
	string obrazovanie;
public:
	Director(int n, int zp1, string name1, string surname1, string firma1, string gender1, string obrazovanie1) :Administrirovanie(n, zp1, name1, surname1, firma1)
	{
		obrazovanie = obrazovanie1;
		gender = gender1;
	}
	void show()
	{
		cout << "-----------Director-----------" << endl;
		cout << surname << " " << name << " " << age << " years old";
		cout << "\nCompany: " << firma;
		cout << "\nSalary: " << zp << "$";
		cout << "\nGender: " << gender;
		cout << "\nEducation: " << obrazovanie << endl << endl;
	};
	void Pension(int n, string gender)
	{
		if (gender == "male" || gender == "Male")
			if (n < 62)
				cout << 62 - n << " years left until retirement" << endl << endl;
			else cout << "May already retire" << endl << endl;
		else if (gender == "female" || gender == "Female")
			if (n < 57)
				cout << 57 - n << " years left until retirement" << endl << endl;
			else cout << "May already retire" << endl << endl;
		else cout << "Incorrect gender entered for determining the date of retirement" << endl << endl;
	}
};

class productManager : virtual public Administrirovanie
{
protected:
	int stazh;
	string type;
public:
	productManager(int n, int zp1, string name1, string surname1, string firma1, int l, string type1) :Administrirovanie(n, zp1, name1, surname1, firma1)
	{
		stazh = l;
		type = type1;
	}
	void show()
	{
		cout << "-----------Manager-----------" << endl;
		cout << surname << " " << name << " " << age << " years old";
		cout << "\nCompany: " << firma;
		cout << "\nSalary: " << zp << "$";
		cout << "\nExpirience: " << stazh << " year(s)";
		cout << "\nType: " << type << endl << endl;
	};
	void Pension(int n, string gender)
	{
		if (n < 62)
			cout << 62 - n << " years left until retirement" << endl << endl;
		else cout << "May already retire" << endl << endl;
	}
};

class Programmer : public Director, public productManager
{
	string role;
	string kind;
public:
	Programmer(int n, int zp1, string name1, string surname1, string firma1, string kind1, string role1, string gender1, string obrazovanie1, int l, string type1)
	:Administrirovanie(n, zp1, name1, surname1, firma1), Director(n, zp1, name1, surname1, firma1, gender1, obrazovanie1), productManager(n, zp1, name1, surname1, firma1, l, type1)
	{
		kind = kind1;
		role = role1;
	}
	void show()
	{
		cout << "-----------Programmer-----------" << endl;
		cout << surname << " " << name << " " << age << " years old";
		cout << "\nCompany: " << firma;
		cout << "\nSalary: " << zp << "$";
		cout << "\nRole: " << role;
		cout << "\nProgrammer's kind: " << kind;
		cout << "\nGender: " << gender;
		cout << "\nEducation: " << obrazovanie;
		cout << "\nExpirience: " << stazh << " year(s)";
		cout << "\nType: " << type << endl << endl;
	};
	void Pension(int n, string gender)
	{
		if (gender == "male" || gender == "Male")
			if (n < 62)
				cout << 62 - n << " years left until retirement" << endl << endl;
			else cout << "May already retire" << endl << endl;
		else if (gender == "female" || gender == "Female")
			if (n < 57)
				cout << 57 - n << " years left until retirement" << endl << endl;
			else cout << "May already retire" << endl << endl;
		else cout << "Incorrect gender entered for determining the date of retirement" << endl << endl;
	}
};

int writeNumbers() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13 && numbers.length() != 0) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stoi(numbers);
}

string writeWords() {
	string slovo;
	while (true) {
		int Knopka;
		char sumbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13 && slovo.length() != 0) {
					break;
				}
				else {
					sumbol = (char)Knopka;
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z')) {
						slovo = slovo + sumbol;
						cout << sumbol;
					}
				}
	}
	return slovo;
}

int menuBegin()
{
	int choiceButton = 0, button = 0;
	system("cls");
	while (true)
	{
		choiceButton = (choiceButton + 3) % 3;

		if (choiceButton == 0) cout << "-> Write information" << endl;
		else cout << " Write information" << endl;

		if (choiceButton == 1) cout << "-> Display all information" << endl;
		else cout << " Display all information" << endl;

		if (choiceButton == 2) cout << "-> Exit" << endl;
		else cout << " Exit" << endl;

		button = _getch();
		if (button == 224)
		{
			button = _getch();
			if (button == 72) choiceButton--;
			if (button == 80) choiceButton++;
		}
		if (button == 13) { system("cls"); return choiceButton; }
		system("cls");
	}
}

int menuWrite()
{
	int choiceButton = 0, button = 0;
	system("cls");
	while (true)
	{
		choiceButton = (choiceButton + 4) % 4;

		if (choiceButton == 0) cout << "-> Write information about Director" << endl;
		else cout << " Write information about Director" << endl;

		if (choiceButton == 1) cout << "-> Write information about Manager" << endl;
		else cout << " Write information about Manager" << endl;

		if (choiceButton == 2) cout << "-> Write information about Programmer" << endl;
		else cout << " Write information about Programmer" << endl;

		if (choiceButton == 3) cout << "-> Exit" << endl;
		else cout << " Exit" << endl;

		button = _getch();
		if (button == 224)
		{
			button = _getch();
			if (button == 72) choiceButton--;
			if (button == 80) choiceButton++;
		}
		if (button == 13) { system("cls"); return choiceButton; }
		system("cls");
	}
}

void directorF(int& ageD, int& zpD, string& nameD, string& surnameD, string& firmaD, string& gender, string& educ)
{
	cout << "Enter Director's surname: ";
	surnameD = writeWords();
	cout << "\nEnter Director's name: ";
	nameD = writeWords();
	cout << "\nEnter Director's age: ";
	ageD = writeNumbers();
	cout << "\nEnter Director's company: ";
	firmaD = writeWords();
	cout << "\nEnter Director's salary: ";
	zpD = writeNumbers();
	cout << "\nEnter Director's gender: ";
	gender = writeWords();
	cout << "\nEnter Director's education: ";
	educ = writeWords();
	system("cls");
};

void managerF(int& ageM, int& zpM, string& nameM, string& surnameM, string& firmaM, int& expirience, string& type)
{
	cout << "Enter Manager's surname: ";
	surnameM = writeWords();
	cout << "\nEnter Manager's name: ";
	nameM = writeWords();
	cout << "\nEnter Manager's age: ";
	ageM = writeNumbers();
	cout << "\nEnter Manager's company: ";
	firmaM = writeWords();
	cout << "\nEnter Manager's salary: ";
	zpM = writeNumbers();
	cout << "\nEnter Manager's expirience (how many years): ";
	expirience = writeNumbers();
	cout << "\nEnter Manager's type (junior, middle, higher): ";
	type = writeWords();
	system("cls");
};

void programmerF(int& ageP, int& zpP, string& nameP, string& surnameP, string& firmaP, string& kind, string& roleP, string& gender, string& educ, int& expirience, string& type)
{
	cout << "Enter Programmer's surname: ";
	surnameP = writeWords();
	cout << "\nEnter Programmer's name: ";
	nameP = writeWords();
	cout << "\nEnter Programmer's age: ";
	ageP = writeNumbers();
	cout << "\nEnter Programmer's company: ";
	firmaP = writeWords();
	cout << "\nEnter Programmer's salary: ";
	zpP = writeNumbers();
	cout << "\nEnter Programmer's kind (tester or developer): ";
	kind = writeWords();
	cout << "\nEnter Programmer's role (application, web, systemic): ";
	roleP = writeWords();
	cout << "\nEnter Programmer's gender: ";
	gender = writeWords();
	cout << "\nEnter Programmer's education: ";
	educ = writeWords();
	cout << "\nEnter Programmer's expirience (how many years): ";
	expirience = writeNumbers();
	cout << "\nEnter Programmer's type (junior, middle, higher): ";
	type = writeWords();
	system("cls");
};

int main()
{
	string surnameP, nameP, nameD, nameM, surnameD, surnameM, firmaD, firmaM ,firmaP, roleP, kind, type, gender, educ;
	int ageP, zpP, ageD, zpD, ageM, zpM, stazh;
	int n = 1;
	Administrirovanie** mas = new Administrirovanie * [n];
	n--;
	while (true)
	{
		int choice = menuBegin();
		if (choice == 0)
		{
			while (true)
			{
				int choiceWrite = menuWrite();
				if (choiceWrite == 0)
				{
					directorF(ageD, zpD, nameD, surnameD, firmaD, gender, educ);
					mas[n] = new Director(ageD, zpD, nameD, surnameD, firmaD, gender, educ);
					mas[n]->show();
					mas[n]->Pension(ageD, gender);
					n++;
					n++;
					Administrirovanie** masD = new Administrirovanie * [n];
					n--;
					copy(mas, mas + n, masD);
					mas = masD;
					masD = NULL;
					delete[]masD;
					system("pause");
					system("cls");
				}
				else
					if (choiceWrite == 1)
					{
						managerF(ageM, zpM, nameM, surnameM, firmaM, stazh, type);
						mas[n] = new productManager(ageM, zpM, nameM, surnameM, firmaM, stazh, type);
						mas[n]->show();
						mas[n]->Pension(ageM, gender);
						n++;
						n++;
						Administrirovanie** masM = new Administrirovanie * [n];
						n--;
						copy(mas, mas + n, masM);
						mas = masM;
						masM = NULL;
						delete[]masM;
						system("pause");
						system("cls");
					}
					else
						if (choiceWrite == 2)
						{
							programmerF(ageP, zpP, nameP, surnameP, firmaP, kind, roleP, gender, educ, stazh, type);
							mas[n] = new Programmer(ageP, zpP, nameP, surnameP, firmaP, kind, roleP, gender, educ, stazh, type);
							mas[n]->show();
							mas[n]->Pension(ageP, gender);
							n++;
							n++;
							Administrirovanie** masP = new Administrirovanie * [n];
							n--;
							copy(mas, mas + n, masP);
							mas = masP;
							masP = NULL;
							delete[]masP;
							system("pause");
							system("cls");
						}
						else break;
			}
		}
		else
			if (choice == 1)
			{
				if (n != 0)
				{
					for (int i = 0; i < n; i++)
						mas[i]->show();
					system("pause");
				}
				else
				{
					cout << "No information\n" << endl;
					system("pause");
					continue;
				}
			}
			else
			{
				cout << "(0^0) Goodbye!!! (0^0)" << endl;
				break;
			}
	}
	delete[]mas;
	return 0;
}