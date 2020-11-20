#include <iostream>
#include <math.h>
#include <string>
#include <conio.h>

using namespace std;

class Administrirovanie
{
protected:
	string company;
	string position;
public:
	Administrirovanie(string company1, string position1)
	{
		company = company1;
		position = position1;
	}
	Administrirovanie() {};
	void show()
	{
		cout << "Company: " << company << endl;
		cout << "Position: " << position << endl;
	}
	void changeCompany(string ptr)
	{
		company = ptr;
	}
	void changePosition(string ptr)
	{
		position = ptr;
	}
	string getCompany()
	{
		return company;
	}
	string getPosition()
	{
		return position;
	}
};

class WorkersCharacters : virtual public Administrirovanie
{
protected:
	int expirience;
	string surname;
	string name;
public:
	WorkersCharacters(string company1, string position1, int expirience1, string surname1, string name1) :Administrirovanie(company1, position1)
	{
		expirience = expirience1;
		surname = surname1;
		name = name1;
	}
	WorkersCharacters() 
	{
		expirience = 0;
	};
	void show()
	{
		cout << "Surname: " << surname << endl;
		cout << "Name: " << name << endl;
		cout << "Expirience (how many years): " << expirience << endl;
	}
	void changeExpirience(int ptr)
	{
		expirience = ptr;
	}
	void changeSurname(string ptr)
	{
		surname = ptr;
	}
	void changeName(string ptr)
	{
		name = ptr;
	}
	int getExpirience()
	{
		return expirience;
	}
	string getSurname()
	{
		return surname;
	}
	string getName()
	{
		return name;
	}
};

class PersonalCharacters : virtual public Administrirovanie
{
protected:
	int age;
	string gender;
public:
	PersonalCharacters(string company1, string position1, int age1, string gender1) :Administrirovanie(company1, position1)
	{
		age = age1;
		gender = gender1;
	}
	PersonalCharacters() 
	{
		age = 0;
	};
	void show()
	{
		cout << age << " years old" << endl;
		cout << "Gender: " << gender << endl;
	}
	void changeAge(int ptr)
	{
		age = ptr;
	}
	void changeGender(string ptr)
	{
		gender = ptr;
	}
	int getAge()
	{
		return age;
	}
	string getGender()
	{
		return gender;
	}
};

class Human : public WorkersCharacters, public PersonalCharacters
{
	string education;
	string status;
public:
	Human(string company1, string position1, int expirience1, string surname1, string name1, int age1, string gender1, string education1, string status1)
		:WorkersCharacters(company1, position1, expirience1, surname1, name1), PersonalCharacters(company1, position1, age1, gender1)
	{
		education = education1;
		status = status1;
	}
	Human() {};
	void showHumanInfo()
	{
		WorkersCharacters::show();
		Administrirovanie::show();
		PersonalCharacters::show();
		cout << "Education: " << education << endl;
		cout << "Status: " << status << endl;
	}
	void changeEducation(string ptr)
	{
		education = ptr;
	}
	void changeStatus(string ptr)
	{
		status = ptr;
	}
	string getEducation()
	{
		return education;
	}
	string getStatus()
	{
		return status;
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
		choiceButton = (choiceButton + 4) % 4;

		if (choiceButton == 0) cout << "-> Write information" << endl;
		else cout << " Write information" << endl;

		if (choiceButton == 1) cout << "-> Correct information" << endl;
		else cout << " Correct information" << endl;

		if (choiceButton == 2) cout << "-> Display information" << endl;
		else cout << " Display all information" << endl;		

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

int menuWhoRed(Human*& mas, int n) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		choose_menu = (choose_menu + (n + 1)) % (n + 1);

		for (int i = 0; i < n; i++)
			if (i == choose_menu) { cout << " -> " << i + 1 << " - " << mas[i].getSurname() << endl; }
			else { cout << " " << i + 1 << " - " << mas[i].getSurname() << endl; }

		if (choose_menu == n) { cout << " -> Exit from this menu" << endl; }
		else cout << " Exit from this menu" << endl;

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}

int menuWhatRed(Human*& mas, int choose) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		choose_menu = (choose_menu + 10) % 10;

		if (choose_menu == 0) { cout << " -> Surname: " << mas[choose].getSurname() << endl; }
		else cout << " Surname: " << mas[choose].getSurname() << endl;

		if (choose_menu == 1) { cout << " -> Name: " << mas[choose].getName() << endl; }
		else cout << " Name: " << mas[choose].getName() << endl;

		if (choose_menu == 2) { cout << " -> Company: " << mas[choose].getCompany() << endl; }
		else cout << " Company: " << mas[choose].getCompany() << endl;

		if (choose_menu == 3) { cout << " -> Position: " << mas[choose].getPosition() << endl; }
		else cout << " Position: " << mas[choose].getPosition() << endl;

		if (choose_menu == 4) { cout << " -> Age: " << mas[choose].getAge() << endl; }
		else cout << " Age: " << mas[choose].getAge() << endl;

		if (choose_menu == 5) { cout << " -> Expirience: " << mas[choose].getExpirience() << endl; }
		else cout << " Expirience: " << mas[choose].getExpirience() << endl;

		if (choose_menu == 6) { cout << " -> Gender: " << mas[choose].getGender() << endl; }
		else cout << " Gender: " << mas[choose].getGender() << endl;

		if (choose_menu == 7) { cout << " -> Education: " << mas[choose].getEducation() << endl; }
		else cout << " Education: " << mas[choose].getEducation() << endl;

		if (choose_menu == 8) { cout << " -> Status: " << mas[choose].getStatus() << endl; }
		else cout << " Status: " << mas[choose].getStatus() << endl;

		if (choose_menu == 9) { cout << " -> Exit from this menu " << endl; }
		else cout << " Exit from this menu " << endl;


		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}

int main()
{
	int n = 0;
	Human* mas = new Human [n];
	while (true)
	{
		int choice = menuBegin();
		if (choice == 0)
		{
			Human sum;
			cout << "Surname: ";
			string ptr1 = writeWords();
			sum.changeSurname(ptr1);
			system("cls");
			cout << "Name: ";
			ptr1 = writeWords();
			sum.changeName(ptr1);
			system("cls");
			cout << "Age: ";
			int ptr = writeNumbers();
			sum.changeAge(ptr);
			system("cls");
			cout << "Company: ";
			ptr1 = writeWords();
			sum.changeCompany(ptr1);
			system("cls");
			cout << "Position: ";
			ptr1 = writeWords();
			sum.changePosition(ptr1);
			system("cls");
			cout << "Expirience: ";
			ptr = writeNumbers();
			sum.changeExpirience(ptr);
			system("cls");
			cout << "Gender: ";
			ptr1 = writeWords();
			sum.changeGender(ptr1);
			system("cls");
			cout << "Education: ";
			ptr1 = writeWords();
			sum.changeEducation(ptr1);
			system("cls");
			cout << "Status: ";
			ptr1 = writeWords();
			sum.changeStatus(ptr1);
			system("cls");
			n++;
			Human* ptrr = new Human[n];
			for (int i = 0; i < n - 1; i++)
				ptrr[i] = mas[i];
			mas = ptrr;
			ptrr = NULL;
			delete[]ptrr;
			mas[n - 1] = sum;
		}
		else
			if (choice == 1) {
				if (n != 0) {
					while (true) {
						int choose1 = menuWhoRed(mas, n);
						if (choose1 == n) break;
						while (true) {
							int choose2 = menuWhatRed(mas, choose1);
							if (choose2 == 9) break;
							if (choose2 == 0) {
								cout << "Enter surname ";
								string ptr = writeWords();
								mas[choose1].changeSurname(ptr);
								system("cls");
							}
							else
								if (choose2 == 1) {
									cout << "Enter name: ";
									string ptr = writeWords();
									mas[choose1].changeName(ptr);
									system("cls");
								}
								else
									if (choose2 == 2) {
										cout << "Enter company: ";
										string ptr = writeWords();
										mas[choose1].changeCompany(ptr);
										system("cls");
									}
									else
										if (choose2 == 3) {
											cout << "Enter position: ";
											string ptr = writeWords();
											mas[choose1].changePosition(ptr);
											system("cls");
										}
										else
											if (choose2 == 4) {
												cout << "Enter age: ";
												int ptr = writeNumbers();
												mas[choose1].changeAge(ptr);
												system("cls");
											}
											else
												if (choose2 == 5) {
													cout << "Enter expirience: ";
													int ptr = writeNumbers();
													mas[choose1].changeExpirience(ptr);
													system("cls");
												}
												else
													if (choose2 == 6) {
														cout << "Enter gender: ";
														string ptr = writeWords();
														mas[choose1].changeGender(ptr);
														system("cls");
													}
													else
														if (choose2 == 7) {
															cout << "Enter education: ";
															string ptr = writeWords();
															mas[choose1].changeEducation(ptr);
															system("cls");
														}
														else
															if (choose2 == 6) {
																cout << "Enter status: ";
																string ptr = writeWords();
																mas[choose1].changeStatus(ptr);
																system("cls");
															}
						}
					}
				}
				else {
					cout << "You don't add humans yet" << endl;
					system("pause");
					system("cls");
				}
			}
			else 
				if (choice == 2)
				{
					if (n != 0)
					{
						for (int i = 0; i < n; i++) {
							mas[i].showHumanInfo();
							cout << endl;
							cout << endl;
						}
						system("pause");
						system("cls");
					}
					else
					{
						cout << "You don't add humans yet" << endl;
						system("pause");
						system("cls");
					}
				}
				else
				{
					cout << "(0^0) Goodbye!!! (0^0)" << endl;
					break;
				}
	}
	return 0;
}
