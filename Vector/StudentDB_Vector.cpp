#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define SUB 3
class Student {
	int reg;
	string name;
	double average;
	double marks[SUB];
	char grade;
public:
	Student()
	{
		reg = 0;
		name = "";
		grade = ' ';
		average = 0;
		for (int i = 0; i < SUB; i++)
		{
			marks[i] = 0;
		}
	}
	void setter();
	void getter();
	int getReg();
};
void Student::setter()
{
	int sum = 0;
	bool flag;
	do
	{
		cout << "Enter Reg No for student For Insertion ( Reg no Must be in range of ( 1000-9999) : ";
		cin >> reg;
		if (reg >= 1000 && reg <= 9999)
			break;
		else
			cout << "!)Wrong Input ,please enter agian\n\n";

	} while (true);
	cin.ignore(10, '\n');
	cout << "Enter Name of Student : ";
	getline(cin, name);
	cout << "\tEnter Marks of Student\n";
	for (int j = 0; j < SUB; j++)
	{
		do
		{
			cout << "\tSubject " << j + 1 << " Marks : ";
			cin >> marks[j];
			if (marks[j] >= 0 && marks[j] <= 100)
			{
				break;
			}
			else
				cout << "Marks Range must be 0 to 100\n";
		} while (true);
		sum += marks[j];
	}
	average = sum / SUB * 1.0;
	if (average >= 80)
		grade = 'A';
	else if (average < 80 && average >= 70)
		grade = 'B';
	else if (average < 70 && average >= 60)
		grade = 'C';
	else
		grade = 'D';
}
int Student::getReg()
{
	return reg;
}
void Student::getter()
{
	cout << reg << "  " << name << " ";
	for (int i = 0; i < SUB; i++)
	{
		cout << "\t" << marks[i];
	}
	cout << "\t" << average << "%" << "\t" << grade << endl << endl;
}

int main()
{
	vector<Student> student;
	Student S;
	int ch, n = 0, reg, temp;
	int index;
	do
	{
		system("cls");
		cout << "###########*******     MAIN MENU   *********############\n\n";
		cout << "1 ) Create Data Base of Student \n\n";
		cout << "2 ) Display Student Data of DataBase\n\n";
		cout << "3 ) Append Student Data in DataBase\n\n";
		cout << "4 ) Delete Student Data from DataBase\n\n";
		cout << "5 ) Sort Student Data from DataBase\n\n";
		cout << "6 ) Update Student Data from DataBase\n\n";
		cout << "7 ) Reset the Array\n\n";
		cout << "8 ) Exit\n\n";
		cout << "Enter Your Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			if (student.size() == 0)
			{
				cout << "Enter No of Student : ";
				cin >> n;
				for (int i = 0; i < n; i++)
				{
					S.setter();
					student.push_back(S);
				}
			}
			else
				cout << "Please Reset the Array First\n";

			system("pause");
			break;
		case 2://display
			if (student.size() > 0)
			{
				cout << "RegNO\tName \t\tS1\tS2\tS3\t%\tGrade\n";
				for (int i = 0; i < student.size(); i++)
				{
					student[i].getter();
				}
			}
			else
				cout << "Please Fill the Array First\n";
			system("pause");
			break;
		case 3://insertion
			S.setter();
			student.push_back(S);
			system("pause");
			break;
		case 4://deletion
			if (student.size() > 0)
			{
				cout << "Enter regNo to Delete : ";
				cin >> reg;
				index = -1;
				for (int i = 0; i < student.size(); i++)
				{
					if (reg == student[i].getReg())
						index=i;
				}
				if (index >= 0)
				{
					student.erase(student.begin() + index);
					cout << "Student with RegNo: " << reg << " is deleted " << endl;
					index = -1;
				}
				else
					cout << "RegNo not exist\n";
			}
			else
				cout << "Please Fill the Array First\n";


			system("pause");
			break;
		case 5://sort
			if (student.size() > 0)
			{
				for (int i = 0; i < student.size(); i++)
				{
					cout << "inner for :" << i << " : " << "\n";
					for (int j = i + 1; j < student.size(); j++)
					{
						cout << "inner for :" << i << " : " << j << "\n";
						if (student[i].getReg() > student[j].getReg())
						{
							cout << "in if\n";
							swap(student[i], student[j]);
						}
					}

				}
			}
			else
				cout << "Please Fill the Array First\n";

			system("pause");

			break;
		case 6://update
			if (n > 0)
			{
				cout << "Enter regNo to update : ";
				cin >> reg;
				index = -1;
				for (int i = 0; i < student.size(); i++)
				{
					if (reg == student[i].getReg())
						index = i;
				}
				if (index >= 0)
				{

					student.erase(student.begin() + index);
					S.setter();
					student.insert(student.begin()+index,S);
					cout << "Student with RegNo: " << reg << " is updated " << endl;
					index = -1;
				}
			}
			else
				cout << "Please Fill the Array First\n";


			system("pause");
			break;
		case 7:

		//	student = new Student[MAX];
			student.clear();
			student.shrink_to_fit();
			break;
		case 8:
			exit(-1);
		default:
			cout << "!!!ERROR : You have Selected Wrong Choice , Kindly Select right one \n\n";
			cout << endl;
			system("pause");
		}
	} while (true);
}