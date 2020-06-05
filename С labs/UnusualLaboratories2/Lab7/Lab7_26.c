#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<malloc.h>
#include <locale.h>

typedef struct DateOfBirth
{
	int day;
	int month;
	int year;
}Date;

typedef struct PassportInfo
{
	char series[10];
	int number;
	char place[20];
}Passport;

typedef struct ParametersOfEmployee
{
	char fullname[30];
	Date birth;
	Passport data;
	char insurance[20];
	char education[20];
	char post[20];
	int money;
	Date work;
	char additions[80];
	int vacation;
}Employee;

typedef struct ListOfEmployee//двунапрвленный список
{
	Employee customer;
	struct ListOfEmployee*next;
	struct ListOfEmployee*prev;
}List;

/////////////////////////// 1 - разновидности меню
void MainHelp()
{
	printf("Main menu:\n");
	printf("1-Employee View\n");
	printf("2-Add/Delete employee\n");
	printf("3-Find someone\n");
	printf("4-Other menu\n");
	printf("5-Exit\n");
}

void Find()
{
	printf("Find menu:\n");
	printf("1-Find by full name\n");
	printf("2-Find by BirthDate\n");
	printf("3-Find by passport\n");
	printf("4-Find by insurance\n");
	printf("5-Find by education\n");
	printf("6-Find by post\n");
	printf("7-Find by salary\n");
	printf("8-Find by StartWork\n");
	printf("9-Find by vacation\n");
	printf("10-Main Menu\n");
	printf("11-Exit\n");
}

void AddDel()
{
	printf("Edit menu:\n");
	printf("1-Add new customer\n");
	printf("2-Delete customer from list\n");
	printf("3-Main Menu\n");
	printf("4-Exit\n");
}

void OtherHelp()
{
	printf("Invate menu:\n");
	printf("1-BirthDay\n");
	printf("2-CutEmployee\n");
	printf("2-BestVacation\n");
	printf("4-Main Menu\n");
	printf("5-Exit\n");
}
/////////////////////////// 2 - функции поиска и печати
void Print(List* list)   //Распечатать элемент списка
{
	if (list != 0)
	{
		printf("Full name:%s\n", list->customer.fullname);
		printf("Date of birth:%d.", list->customer.birth.day);
		printf("%d.", list->customer.birth.month);
		printf("%d\n", list->customer.birth.year);
		printf("Passport Data:%s", list->customer.data.series);
		printf("%d\n", list->customer.data.number);
		printf("Passport place:%s\n", list->customer.data.place);
		printf("Insurance card:%s\n", list->customer.insurance);
		printf("Education:%s\n", list->customer.education);
		printf("Post:%s\n", list->customer.post);
		printf("Salary:%d\n", list->customer.money);
		printf("First day of work:%d.", list->customer.work.day);
		printf("%d.", list->customer.work.month);
		printf("%d\n", list->customer.work.year);
		printf("Additions:%s\n", list->customer.additions);
		printf("Current Vacation:%d\n", list->customer.vacation);
		printf("////////////////////////////////////////////////\n");
	}
}

void ListPrint(List* list)     //Распечатать весь список
{
	Print(list);
	if (list->next != NULL)
	{
		ListPrint(list->next);
	}
}

void FullFind(List* list, char* name)     //имя
{
	if (list == 0)
	{
		printf("Can't find.\n");
		return ;
	}
	if (strcmp(list->customer.fullname, name) == 0)
	{
		Print(list);
	}
	FullFind(list->next, name);
}

void DayFind(List* list, int h1, int h2, int h3)          
{
	if (list == 0)
	{
		printf("Can't find.\n");
		return ;
	}
	if (list->customer.birth.day == h1 && list->customer.birth.month == h2 && list->customer.birth.year == h3)
	{
		Print(list);
	}
	
	DayFind(list->next, h1, h2, h3);
	
}

void PasFind(List* list, char* h1, int h2, char* h3)
{
	if (list == 0)
	{
		printf("Can't find.\n");
		return ;
	}
	if (strcmp(list->customer.data.series, h1) == 0 && list->customer.data.number == h2 && strcmp(list->customer.data.place, h3) == 0)
	{
		Print(list);
	}
	PasFind(list->next, h1, h2, h3);
	
}

void InsFind(List* list, char* name)     //имя
{
	if (list == 0)
	{
		printf("Can't find.\n");
		return ;
	}
	if (strcmp(list->customer.insurance, name) == 0)
	{
		Print(list);
	}
	InsFind(list->next, name);
}

void EdFind(List* list, char* name)     //имя
{
	if (list == 0)
	{
		printf("Can't find.\n");
		return ;
	}
	if (strcmp(list->customer.education, name) == 0)
	{
		Print(list);
	}
	EdFind(list->next, name);
}

void PostFind(List* list, char* name)     //имя
{
	if (list == 0)
	{
		printf("Can't find.\n");
		return ;
	}
	if (strcmp(list->customer.education, name) == 0)
	{
		Print(list);
	}
	PostFind(list->next, name);
}

void SalFind(List* list, int height)          //рост
{
	if (list == 0)
	{
		printf("Can't find.\n");
		return;
	}
	if (list->customer.money == height)
	{
		Print(list);
	}
	
	SalFind(list->next, height);
}

void WorkFind(List* list, int h1, int h2, int h3)          //рост
{
	if (list == 0)
	{
		printf("Can't find.\n");
		return ;
	}
	if (list->customer.work.day == h1 && list->customer.work.month == h2 && list->customer.work.year == h3)
	{
		Print(list);
	}
	WorkFind(list->next, h1, h2, h3);
	
}

void VacFind(List* list, int height)          //рост
{
	if (list == 0)
	{
		printf("Can't find.\n");
		return ;
	}
	if (list->customer.vacation == height)
	{
		Print(list);
	}
	
	VacFind(list->next, height);
	
}
/////////////////////////// 3 - функции редактирования
void Add(List** list, Employee customer)
{
	List* temp = (List*)malloc(sizeof(List));
	if (!temp)
	{
		printf("Error\n");
		exit(1);
	}
	List* current;
	temp->customer = customer;
	temp->next = NULL;
	if ((*list) == NULL)
	{
		temp->prev = NULL;
		(*list) = temp;
	}
	else
	{
		current = (List*)malloc(sizeof(List));
		current = (*list);
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = temp;
		temp->prev = current;
	}
}

void AddNew(List** list)//Ввод нового пользователя
{
	List* current;
	Employee employee;
	current = *list;
	while (current->next != 0)
	{
		current = current->next;
	}
	printf("Enter full name:");
	scanf_s("%s", employee.fullname, 30);
	employee.birth.day = -1;
	for (; employee.birth.day < 0 || employee.birth.day > 30;)
	{
		printf("Enter day of birth:");
		scanf_s("%d", &employee.birth.day);
		if (employee.birth.day < 0 || employee.birth.day > 30)
		{
			scanf_s("%*[^\n]");
			printf("Input eror.\n");
		}
	}
	employee.birth.month = -1;
	for (; employee.birth.month < 0 || employee.birth.month > 12;)
	{
		printf("Enter month of birth:");
		scanf_s("%d", &employee.birth.month);
		if (employee.birth.day < 0 || employee.birth.month > 12)
		{
			scanf_s("%*[^\n]");
			printf("Input eror.\n");
		}
	}
	employee.birth.year = -1;
	for (; employee.birth.year < 0;)
	{
		printf("Enter year of birth:");
		scanf_s("%d", &employee.birth.year);
		if (employee.birth.year < 0)
		{
			scanf_s("%*[^\n]");
			printf("Input eror.\n");
		}
	}
	printf("Enter Passport series:");
	scanf_s("%s", employee.data.series, 10);
	employee.data.number = -1;
	for (; employee.data.number < 0;)
	{
		printf("Enter Passport number:");
		scanf_s("%d", &employee.data.number);
		if (employee.data.number < 0)
		{
			scanf_s("%*[^\n]");
			printf("Input eror.\n");
		}
	}
	printf("Enter Passport place:");
	scanf_s("%s", employee.data.place, 20);
	printf("Enter Insurance:");
	scanf_s("%s", employee.insurance, 20);
	printf("Enter Education:");
	scanf_s("%s", employee.education, 20);
	printf("Enter Post:");
	scanf_s("%s", employee.post, 20);
	employee.money = -1;
	for (; employee.money < 0;)
	{
		printf("Enter money:");
		scanf_s("%d", &employee.money);
		if (employee.money < 0)
		{
			scanf_s("%*[^\n]");
			printf("Input eror.\n");
		}
	}
	employee.work.day = -1;
	for (; employee.work.day < 0 || employee.work.day > 30;)
	{
		printf("Enter first day of work:");
		scanf_s("%d", &employee.work.day);
		if (employee.work.day < 0 || employee.work.day > 30)
		{
			scanf_s("%*[^\n]");
			printf("Input eror.\n");
		}
	}
	employee.work.month = -1;
	for (; employee.work.month < 0 || employee.work.month > 12;)
	{
		printf("Enter first month of work:");
		scanf_s("%d", &employee.work.month);
		if (employee.work.day < 0 || employee.work.month > 12)
		{
			scanf_s("%*[^\n]");
			printf("Input eror.\n");
		}
	}
	employee.work.year = -1;
	for (; employee.work.year < 0;)
	{
		printf("Enter first year of work:");
		scanf_s("%d", &employee.work.year);
		if (employee.work.year < 0)
		{
			scanf_s("%*[^\n]");
			printf("Input eror.\n");
		}
	}
	printf("Enter additions:");
	scanf_s("%s", employee.additions, 80);
	employee.vacation = -1;
	for (; employee.vacation < 0 || employee.vacation > 1;)
	{
		printf("Enter vacation(0 if -, 1 if +):");
		scanf_s("%d", &employee.vacation);
		if (employee.vacation < 0)
		{
			scanf_s("%*[^\n]");
			printf("Input eror.\n");
		}
	}
	Add(list, employee);
}

void Delete(List** list, int id)                 //удалить элемент списка
{
	List* temp;
	if ((*list)->customer.data.number == id)
	{
		if ((*list)->prev == NULL)
		{
			(*list) = (*list)->next;
			free((*list)->prev);
			(*list)->prev = NULL;
		}
		else if ((*list)->next == NULL)
		{
			(*list)->prev->next = NULL;
			free((*list));
		}
		else
		{
			temp = (*list);
			(*list)->prev->next = (*list)->next;
			(*list)->prev = temp->prev;
			free(temp);
		}
		printf("Success.");
	}
	else
	{
		Delete(&((*list)->next), id);
	}
}

void DeleteList(List** list)                    //удалить весь список
{
	List* temp;
	for (; (*list) != NULL;)
	{
		temp = (*list);
		(*list) = (*list)->next;
		if (temp != 0)free(temp);
	}
}
/////////////////////////// 4 - прочие функции
void BirthdayFind(List* list, int h1, int h2, int h3)
{
	if (list == 0)
	{
		printf("Can't find.\n");
		return;
	}
	int h12;
	h12 = h1 + 1; 
	if (h12 > 12) { 
		h12 -= 12; 
	}
	if(list->customer.birth.month==h2 && list->customer.birth.day>=h1) Print(list);
	else if (list->customer.birth.month == h12 && list->customer.birth.day < h1) Print(list);
	
	DayFind(list->next, h1, h2, h3);
	
}

void CutFind(List* list, int h1, int k) {
	if (list == 0)
	{
		printf("Can't find.\n");
		return;
	}
	if (h1-list->customer.birth.year >= 50)
	{
		Print(list);
		FILE* fp2;
		fopen_s(&fp2, "cut.txt", "w");
		if (!fp2)
		{
			printf("Can't open file\n");
			exit(1);
		}
		fprintf(fp2, "Сотрудник %d увольняется из-за слабой эффективности в связи с сокращением штата\n", k);
		fprintf(fp2, "Следующие данные будут удалены после подтверждения увольнения:\n");
		fprintf(fp2, "%s\n", list->customer.fullname);
		fprintf(fp2, "%d\n", list->customer.birth.day);
		fprintf(fp2, "%d\n", list->customer.birth.month);
		fprintf(fp2, "%d\n", list->customer.birth.year);
		fprintf(fp2, "%s\n", list->customer.data.series);
		fprintf(fp2, "%d\n", list->customer.data.number);
		fprintf(fp2, "%s\n", list->customer.data.place);
		fprintf(fp2, "%s\n", list->customer.insurance);
		fprintf(fp2, "%s\n", list->customer.education);
		fprintf(fp2, "%s\n", list->customer.post);
		fprintf(fp2, "%d\n", list->customer.money);
		fprintf(fp2, "%d\n", list->customer.work.day);
		fprintf(fp2, "%d\n", list->customer.work.month);
		fprintf(fp2, "%d\n", list->customer.work.year);
		fprintf(fp2, "%s\n", list->customer.additions);
		fprintf(fp2, "%d\n", list->customer.vacation);

		fclose(fp2);
		k++;
	}

	CutFind(list->next, h1, k);
}

void VWorkFind(List* list, int h1, int h2, int h3, int h4)
{
	if (list == 0)
	{
		printf("Can't find.\n");
		return;
	}
	if (list->customer.data.number == h4) {
		Print(list);
		int h11 = h1 - list->customer.work.day;
		int h12 = h2 - list->customer.work.month;
		int h13 = h3 - list->customer.work.year;
		if (h11 < 1) {
			h11 += 30;
			h12 -= 1;
		}
		if (h12 < 1) {
			h12 += 12;
			h13 -= 1;
		}
		printf("Employee work time:%d.%d.%d", h11, h12, h13);
		if (h12 >= 6) h12 -= 6;
		h12 = 12 - h12;
		h11 = 30 - h11;
		printf("Next Vacation stast after: %d days %d mounth", h11, h12);
	}
	

	VWorkFind(list->next, h1, h2, h3, h4);

}
/////////////////////////// 5 - файловые операции
void LoadFromFile(List** list)                   //загразка из файла
{
	FILE* fp;
	char str[16][101];
	int i;
	Employee customer;
	Passport pas;
	Date dt1, dt2;
	fopen_s(&fp, "TZ.txt", "r");
	if (!fp)
	{
		printf("Can't open file:TZ.txt.\n");
		exit(1);
	}
	for (i = 0; !feof(fp); i++)
	{
		fgets(str[i], 100, fp);
		str[i][strlen(str[i]) - 1] = 0;
		if (i == 15)
		{
            strcpy_s(customer.fullname, 30  , str[0]);
			dt1.day = atoi(str[1]);
			dt1.month = atoi(str[2]);
			dt1.year = atoi(str[3]);
			customer.birth = dt1;
			strcpy_s(pas.series, 10 , str[4]);
			pas.number = atoi(str[5]);
			strcpy_s(pas.place, 20 , str[6]);
			customer.data = pas;
			strcpy_s(customer.insurance, 20 , str[7]);
			strcpy_s(customer.education, 20 , str[8]);
			strcpy_s(customer.post,  20 , str[9]);
			customer.money = atoi(str[10]);
			dt2.day = atoi(str[11]);
			dt2.month = atoi(str[12]);
			dt2.year = atoi(str[13]);
			customer.work = dt2;
            strcpy_s(customer.additions, 80 , str[14]);
			customer.vacation = atoi(str[15]);
			Add(list, customer);
			i = -1;
		}
	}
	fclose(fp);
}

void LoadToFile(List* list)                          //загрузка в файл
{
	FILE* fp;
	fopen_s(&fp,"TZ.txt", "w");
	if (!fp)
	{
		printf("Can't open file:TZ.txt.\n");
		exit(1);
	}
	for (; list != 0;)
	{
		fprintf(fp, "%s\n", list->customer.fullname);
		fprintf(fp, "%d\n", list->customer.birth.day);
		fprintf(fp, "%d\n", list->customer.birth.month);
		fprintf(fp, "%d\n", list->customer.birth.year);
		fprintf(fp, "%s\n", list->customer.data.series);
		fprintf(fp, "%d\n", list->customer.data.number);
		fprintf(fp, "%s\n", list->customer.data.place);
		fprintf(fp, "%s\n", list->customer.insurance);
		fprintf(fp, "%s\n", list->customer.education);
		fprintf(fp, "%s\n", list->customer.post);
		fprintf(fp, "%d\n", list->customer.money);
		fprintf(fp, "%d\n", list->customer.work.day);
		fprintf(fp, "%d\n", list->customer.work.month);
		fprintf(fp, "%d\n", list->customer.work.year);
		fprintf(fp, "%s\n", list->customer.additions);
		fprintf(fp, "%d\n", list->customer.vacation);
		list = list->next;
	}
	fclose(fp);
}

void End(List* list)     //загрузка+чистка+выход
{
	LoadToFile(list);
	DeleteList(&list);     //ListAction.h
	exit(1);
}

/////////////////////////// 6 - сами менюшки
void MainMenu(List* list);

void FindMenu(List* list)         //найти пользователя или пользователей
{
	int d = -1, m = -1, y = -1;
	int command = 0, code = -1;
	int smth = -1;
	char str[80];
	char smth1[10], smth2[20];
	

	while (command != 7612495) {
		Find();
		scanf_s("%d", &command);
		system("cls");
		switch (command)
		{
		case 1:
			printf("Print full name:");
			scanf_s("%s", str, 80);
			FullFind(list, str);
			strcpy_s(str, 80, "");
			break;
		case 2:
			for (; d < 0 || d>30;)
			{
				printf("Print Day:");
				scanf_s("%d", &d);
				if (d < 0 || d > 30)
				{
					scanf_s("%*[^\n]");
					printf("Input eror.\n");
				}
			}
			for (; m < 0 || m>12;)
			{
				printf("Print Month:");
				scanf_s("%d", &m);
				if (m < 0 || m > 12)
				{
					scanf_s("%*[^\n]");
					printf("Input eror.\n");
				}
			}
			for (; y < 0;)
			{
				printf("Print Year:");
				scanf_s("%d", &y);
				if (y < 0)
				{
					scanf_s("%*[^\n]");
					printf("Input eror.\n");
				}
			}
			DayFind(list, d, m, y);
			d = -1; m = -1; y = -1;
			break;
		case 3:
			printf("Print series:");
			scanf_s("%s", smth1, 10);
			for (; smth < 0;)
			{
				printf("Print Number:");
				scanf_s("%d", &smth);
				if (smth < 0)
				{
					scanf_s("%*[^\n]");
					printf("Input eror.\n");
				}
			}
			printf("Print place:");
			scanf_s("%s", smth2, 20);
			PasFind(list, smth1, smth, smth2);
			strcpy_s(smth1, 80, "");
			strcpy_s(smth2, 80, "");
			smth = -1;
			break;
		case 4:
			printf("Print insurance:");
			scanf_s("%s", str, 80);
			InsFind(list, str);
			strcpy_s(str, 80, "");
			break;
		case 5:
			printf("Print education:");
			scanf_s("%s", str, 80);
			EdFind(list, str);
			strcpy_s(str, 80, "");
			break;
		case 6:
			printf("Print post:");
			scanf_s("%s", str, 80);
			PostFind(list, str);
			strcpy_s(str, 80, "");
			break;
		case 7:
			printf("Print salary:");
			scanf_s("%d", &smth);
			SalFind(list, smth);
			smth = 0;
			break;
		case 8:
			for (; d < 0 || d>30;)
			{
				printf("Print Day:");
				scanf_s("%d", &d);
				if (d < 0 || d > 30)
				{
					scanf_s("%*[^\n]");
					printf("Input eror.\n");
				}
			}
			for (; m < 0 || m>12;)
			{
				printf("Print Month:");
				scanf_s("%d", &m);
				if (m < 0 || m > 12)
				{
					scanf_s("%*[^\n]");
					printf("Input eror.\n");
				}
			}
			for (; y < 0;)
			{
				printf("Print Year:");
				scanf_s("%d", &y);
				if (y < 0)
				{
					scanf_s("%*[^\n]");
					printf("Input eror.\n");
				}
			}
			WorkFind(list, d, m, y);
			d = -1, m = -1, y = -1;
			break;
		case 9:
			printf("Print vacation:(1 if + / 0 if -)");
			scanf_s("%d", &smth);
			VacFind(list, smth);
			smth = 0;
			break;
		case 10:
			MainMenu(list);
			break;

		case 11:
			End(list);
			break;

		default:
			printf("Wrong command.Press F1 to get help.\n");
			printf("%d", command);
			break;
		}
	}
}

void EditMenu(List* list)                //меню редактирования списка сотрудников
{
	int command = 0, code = -1;
	while (command != 7612495) {
		AddDel();
		scanf_s("%d", &command);
		system("cls");
		switch (command)
		{
		case 1:
			AddNew(&list);
			break;
		case 2:
			for (; code < 0;)
			{
				printf("Print passport num of deleting employee:");
				scanf_s("%d", &code);
				if (code < 0)
				{
					scanf_s("%*[^\n]");
					printf("Input eror.\n");
				}
			}
			Delete(&list, code);
			code = -1;
			break;
		case 3:
			MainMenu(list);
			break;
		case 4:
			End(list);
			break;
		default:
			printf("Wrong command.Press F1 to get help.\n");
			printf("%d", command);
			break;
		}
	}
}

void OtherMenu(List* list)    //меню для работы с приглашениями
{
	int d = -1, m = -1, y = -1, smth = -1;
	int command = 0;
	
	while (command != 7612495) {
		OtherHelp();
		scanf_s("%d", &command);
		system("cls");
		switch (command)
		{
		case 1:
			for (; d < 0 || d>30;)
			{
				printf("Print Day:");
				scanf_s("%d", &d);
				if (d < 0 || d > 30)
				{
					scanf_s("%*[^\n]");
					printf("Input eror.\n");
				}
			}
			for (; m < 0 || m>12;)
			{
				printf("Print Month:");
				scanf_s("%d", &m);
				if (m < 0 || m > 12)
				{
					scanf_s("%*[^\n]");
					printf("Input eror.\n");
				}
			}
			for (; y < 0;)
			{
				printf("Print Year:");
				scanf_s("%d", &y);
				if (y < 0)
				{
					scanf_s("%*[^\n]");
					printf("Input eror.\n");
				}
			}
			BirthdayFind(list, d, m, y);
			d = -1, m = -1, y = -1;
			break;
		case 2:
			for (; y < 0;)
			{
				printf("Print Year:");
				scanf_s("%d", &y);
				if (y < 0)
				{
					scanf_s("%*[^\n]");
					printf("Input eror.\n");
				}
			}
			CutFind(list, y, 0);
			y = -1;
			break;
		case 3:
			for (; d < 0 || d>30;)
			{
				printf("Print Day:");
				scanf_s("%d", &d);
				if (d < 0 || d > 30)
				{
					scanf_s("%*[^\n]");
					printf("Input eror.\n");
				}
			}
			for (; m < 0 || m>12;)
			{
				printf("Print Month:");
				scanf_s("%d", &m);
				if (m < 0 || m > 12)
				{
					scanf_s("%*[^\n]");
					printf("Input eror.\n");
				}
			}
			for (; y < 0;)
			{
				printf("Print Year:");
				scanf_s("%d", &y);
				if (y < 0)
				{
					scanf_s("%*[^\n]");
					printf("Input eror.\n");
				}
			}
			for (; smth < 0;)
			{
				printf("Print employee passport num:");
				scanf_s("%d", &smth);
				if (smth < 0)
				{
					scanf_s("%*[^\n]");
					printf("Input eror.\n");
				}
			}
			VWorkFind(list, d, m, y, smth);
			d = -1, m = -1, y = -1; smth = -1;
			break;


		case 4:
			MainMenu(list);
			break;
		case 5:
			End(list);
			break;
		default:
			printf("Wrong command.Press F1 to get help.\n");
			printf("%d", command);
			break;
		}
	}
}

void MainMenu(List* list)             //главная 
{
	int command = 0, code = -1;
	MainHelp();

	while (command != 7612495) {
		scanf_s("%d", &command);
		system("cls");
		switch (command)
		{
		case 1:
			ListPrint(list);
			MainMenu(list);
			break;
		case 2:
			EditMenu(list);
			break;
		case 3:
			FindMenu(list);
			break;
		case 4:
			OtherMenu(list);
			break;
		case 5:
			End(list);
			break;
		default:
			printf("Wrong command.Press F1 to get help.\n");
			printf("%d", command);
			break;
		}
	}
}

//////////////////////// 7-программа



int main()
{
	setlocale(LC_ALL, "Russian");
	int command = 0;
	List* list;
	list = (List*)malloc(sizeof(List));
	list = NULL;
	LoadFromFile(&list); //SupAction.h
	MainMenu(list);
	return 0;
}