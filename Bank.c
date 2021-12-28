
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> // getch() ���
#include <time.h> // Sleep() ���
#include <Windows.h> // system() ���

# define MAX_NUM 100

typedef struct
{
	char name[20]; // �� �̸�
	char number[20]; // �ֹε�Ϲ�ȣ
	char address[50]; // �� �ּ�
	char tel[20]; // �� ��ȭ��ȣ
	int balance; // �ܾ�
	int password; // ���º�й�ȣ
	int add_num; //���¹�ȣ
} BANK;

BANK bank[MAX_NUM];

int cnt = 0; // ���¹�ȣ
int  cn = 0;

void gotoxy(int x, int y); // �̵��Լ�
void menu_s(); // �޴� Ʋ
int customer_menu(); // ���޴�
int manager_menu();  // ������(�����) �޴�
int menu(); // ���� �޴�
int log_in(fp); // ������ �α���
void deposit_account(); // �Ա�
void withdraw_account(); // ���
void account_transfer(); // ������ü
void balance_inquiry(); // �ܾ� ��ȸ
void make_account();  // ���°���
void manager_menu1(); // ��ü �� ������ȸ (���¹�ȣ, �ܾ� ���)
void manager_menu2(); // �� �������� ���(��� �� �������� ���)
void manager_menu3(); // �� �������� ���(Ư�� �� �˻�)
void manager_menu4(); // �� ��������

int main()
{
	FILE* fp;
	int choice1, ch, ch2, ch4, i;
	fp = fopen("data.txt", "a");

	while (1)
	{
		system("cls");
		menu_s();
		choice1 = menu();

		switch (choice1)
		{
		case 1: // ��
			system("cls");
			menu_s();
			ch2 = customer_menu(); // ���޴�

			if (ch2 == 1) { // ���°���
				system("cls");
				menu_s();
				make_account();
				break;
			}
			else if (ch2 == 2) { // �Ա�
				system("cls");
				menu_s();
				deposit_account();
				Sleep(2000); // �ð����� 1sec=1000
				break;
			}
			else if (ch2 == 3) { // ���
				system("cls");
				menu_s();
				withdraw_account();
				Sleep(2000);
				break;
			}
			else if (ch2 == 4) {
				system("cls");
				menu_s();
				account_transfer();
				Sleep(2000);
				break;
			}
			else if (ch2 == 5) {// �ܾ���ȸ
				system("cls");
				menu_s();
				balance_inquiry();
				Sleep(2000);
				break;
			}

		case 2:
			system("cls");
			menu_s();
			log_in(fp);
			Sleep(1000);
			system("cls");
			menu_s();
			ch = manager_menu();

			if (ch == 1) {
				system("cls");
				manager_menu1();
				Sleep(6000);
			}

			else if (ch == 2) {
				system("cls");
				menu_s();

				gotoxy(41, 15);
				printf("1) ��� ���� �����������\n");

				gotoxy(41, 21);
				printf("2) Ư�� ���� �����������\n");

				gotoxy(29, 29);
				printf(" ��            ��  : ");
				scanf("%d", &ch4);
				system("cls");

				if (ch4 == 1) {
					system("cls");
					manager_menu2();
					Sleep(6000);
				}

				else if (ch4 == 2) {
					system("cls");
					menu_s();
					manager_menu3();
					Sleep(6000);
				}
			}
			else if (ch == 3)
			{
				system("cls");
				menu_s();
				manager_menu4();
				Sleep(1000);
			}
			break;

		case 3:
			fprintf(fp, "==================================================================================================================\n");
			fprintf(fp, "���¹�ȣ     ������              �ֹε�Ϲ�ȣ                  ��ȭ��ȣ                        �ּ�                                    ��й�ȣ        �ܾ� \n");
			fprintf(fp, "==================================================================================================================\n");

			for (i = 0; i < cnt; i++)
			{
				fprintf(fp, "  000%d        %s        %s        %s \t%s   \t%2d  \t%5d��\n", bank[i].add_num, bank[i].name, bank[i].number, bank[i].tel, bank[i].address, bank[i].password, bank[i].balance);
				fprintf(fp, "---------------------------------------------------------------------------------------------------------------------------\n");
			}
			fclose(fp);
			exit(1);

		default:
			system("cls");
			menu_s();
			gotoxy(43, 20);
			printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �������ּ���.");
			return main();
		}
	}
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void menu_s()
{
	printf("\n\n\n\n\n\n\n");
	printf("\t\t\t����������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t��\t\t                                          \t��\n");
	printf("\t\t\t��\t\t                                          \t��\n");
	printf("\t\t\t��\t\t                                          \t��\n");
	printf("\t\t\t��\t\t                                          \t��\n");
	printf("\t\t\t��\t\t                                          \t��\n");
	printf("\t\t\t��\t\t                                          \t��\n");
	printf("\t\t\t��\t\t                                          \t��\n");
	printf("\t\t\t��\t\t                                          \t��\n");
	printf("\t\t\t��\t\t                                          \t��\n");
	printf("\t\t\t��\t\t                                          \t��\n");
	printf("\t\t\t��\t\t                                          \t��\n");
	printf("\t\t\t��\t\t                                          \t��\n");
	printf("\t\t\t��\t\t                                          \t��\n");
	printf("\t\t\t��\t\t                                          \t��\n");
	printf("\t\t\t��\t\t                                          \t��\n");
	printf("\t\t\t��\t\t                                          \t��\n");
	printf("\t\t\t��\t\t                                          \t��\n");
	printf("\t\t\t��\t\t                                          \t��\n");
	printf("\t\t\t��\t\t                                          \t��\n");
	printf("\t\t\t����������������������������������������������������������������������������������������������������������������������������������\n");
}
int menu()
{
	int select;

	gotoxy(46, 13);
	printf(" 1)  ��            �� ");

	gotoxy(46, 18);
	printf(" 2)  ��     ��     �� ");

	gotoxy(46, 23);
	printf(" 3)  ��            �� ");

	gotoxy(32, 29);
	printf(" ��            ��  : ");
	scanf("%d", &select);

	return select;
}

int customer_menu()
{
	int select1;

	gotoxy(46, 12);
	printf("1)  ��   ��   ��   ��");

	gotoxy(46, 15);
	printf("2)  ��             ��");

	gotoxy(46, 18);
	printf("3)  ��             ��");

	gotoxy(46, 21);
	printf("4)  ��   ��   ��   ü ");

	gotoxy(46, 24);
	printf("5)  ��   ��   ��   ȸ ");

	gotoxy(32, 29);
	printf("��           ��  : ");
	scanf("%d", &select1);

	return select1;
}

int manager_menu()
{
	int select2;

	gotoxy(44, 14);
	printf("1)  ��ü   ��   ����   ��ȸ");

	gotoxy(44, 19);
	printf("2)  ��   ����   ����   ����");

	gotoxy(44, 24);
	printf("3)  �� ��     �� ��     �� ��");

	gotoxy(44, 29);
	printf("��            ��  :");
	scanf("%d", &select2);

	return select2;
}

int log_in(fp)
{
	char password[] = "admin123";
	char answer[20];
	int num = 0;
	int i = 0;

	gotoxy(41, 15);
	printf("��й�ȣ�� �Է����ּ��� : ");
	for (i = 0; num != 13; i++) {
		answer[i] = _getch();
		if (answer[i] == '\0') {
			i--;
			log_in();
		}
		_putch('*');
		num = (int)answer[i];
	}
	answer[i - 1] = '\0';
	if (strcmp(password, answer) == 0) {
		gotoxy(46, 20);
		printf("!!!��й�ȣ ��ġ!!!");
	}
	else
	{
		gotoxy(43, 20);
		printf("��й�ȣ  !!��!!��ġ");
		cn++;

		gotoxy(53, 26);
		printf("%d  /  3ȸ \n", cn);

		Sleep(1000);

		if (cn != 3) {
			system("cls");
			menu_s();
			log_in();
		}
		else if (cn == 3) {
			system("cls");
			menu_s();

			gotoxy(46, 16);
			printf("!!�Է�Ƚ�� �ʰ��Դϴ�!!");

			gotoxy(47, 20);
			printf("���α׷��� ����˴ϴ�.\n\n\n\n\n\n\n\n\n");

			fprintf(fp, "====================================================================================================================\n");
			fprintf(fp, "���¹�ȣ     ������        �ֹε�Ϲ�ȣ        ��ȭ��ȣ                �ּ�          ��й�ȣ     �ܾ� \n");
			fprintf(fp, "====================================================================================================================\n");

			for (i = 0; i < cnt; i++)
			{
				fprintf(fp, "  000%d        %s        %s        %s \t%s   \t%2d  \t%6d��\n", bank[i].add_num, bank[i].name, bank[i].number, bank[i].tel, bank[i].address, bank[i].password, bank[i].balance);
				fprintf(fp, "---------------------------------------------------------------------------------------------------------------------------\n");
			}
			fclose(fp);
			exit(1);
		}
	}
}

void make_account()  // ���°���
{
	int i, j;
	int num, found = 0;

	gotoxy(47, 9);
	printf("<  �� �� �� ȣ : %d  >", cnt + 1);
	bank[cnt].add_num = cnt + 1;

	gotoxy(37, 11);
	printf("* �̸��� �Է����ּ��� : ");
	scanf("%s", &bank[cnt].name);

	getchar(); // �Է¹��۸� ���� ����

	gotoxy(37, 14.7);
	printf("* �ֹε�Ϲ�ȣ�� �Է����ּ��� : ");
	scanf("%s", &bank[cnt].number);

	getchar();

	gotoxy(37, 17.7);
	printf("* �ּҸ� �Է����ּ��� : ");
	gets(bank[cnt].address);

	gotoxy(37, 20.7);
	printf("* ��ȭ��ȣ�� �Է����ּ��� : ");
	scanf("%s", &bank[cnt].tel);

	getchar();

	gotoxy(37, 23.7);
	printf("* ���� �Աݾ��� �Է����ּ���(��) : ");
	scanf("%d", &bank[cnt].balance);

	getchar();

	gotoxy(37, 26.7);
	printf("* ��й�ȣ 4�ڸ��� �������ּ��� : ");
	scanf("%d", &bank[cnt].password);

	getchar();

	if (bank[cnt].balance == 0) {
		system("cls");
		menu_s();
		gotoxy(41, 18);

		printf("���� �Աݾ��� 1�� �̻���� �Ա��� �����մϴ�.\n");

		system("cls");
		make_account();
	}
	cnt++;

}

void deposit_account()
{
	int id;
	int money;
	char q;

	gotoxy(47, 9);
	printf(" [ ��         �� ]");

	gotoxy(37, 14);
	printf("��  ��  ��  ȣ : ");
	scanf("%d", &id);

	if ((id < 1) || (id > 100)) {
		gotoxy(38, 18);
		printf("�������� �ʴ� ���¹�ȣ�Դϴ�. \n");
		return;
	}

	gotoxy(37, 17);
	printf("��   ��   �� (��) : ");
	scanf("%d", &money);

	getchar();

	gotoxy(37, 20);

	printf("----------Ȯ    ��----------");

	gotoxy(37, 21);
	printf("�Է��� ���¹�ȣ : %d", id);
	gotoxy(37, 22);
	printf("�Է��� �� �� �� : %d��", money);
	gotoxy(37, 23);
	printf("=> ������ y / Ʋ���� n�� �Է����ּ��� : ");
	scanf("%c", &q);
	getchar();

	if (q = 'y') {
		printf("\n\n");
		bank[id - 1].balance += money;
		gotoxy(37, 23);
		printf("   ! ! !   �Ա��� �Ϸ�Ǿ����ϴ�.   ! ! !   ");
	}
	else if (q == 'n') {
		gotoxy(37, 23);
		printf("�߸� �Է��Ͽ����ϴ�. �ٽ� �������ּ���.\n");
	}
}

void withdraw_account() // ���
{
	int id;
	int money;
	int num = 0;
	int q;

	gotoxy(47, 9);
	printf(" [ ��         �� ]");

	gotoxy(37, 14);
	printf("��  ��  ��  ȣ : ");
	scanf("%d", &id);

	if ((id < 1) || (id > 100)) {
		gotoxy(37, 17);
		printf("�������� �ʴ� ���¹�ȣ�Դϴ�. \n");
		return;
	}

	gotoxy(37, 17);
	printf("��й�ȣ 4�ڸ��� �Է����ּ��� : ");
	scanf("%d", &q);

	if (q == bank[id - 1].password) {
		gotoxy(37, 20);
		printf("!!! ��й�ȣ ��ġ !!! ");
		gotoxy(37, 22);
		printf("��    ��    �� (��) : ");
		scanf("%d", &money);

		if (money > bank[id - 1].balance) {
			gotoxy(37, 24);
			printf("�ܾ��� �����մϴ�.\n");
		}
		else {
			bank[id - 1].balance -= money;
			gotoxy(37, 24);
			printf("����� �Ϸ�Ǿ����ϴ�.\n");
		}
	}
}

void balance_inquiry() // �ܾ� ��ȸ
{
	int id;

	gotoxy(47, 9);
	printf(" [ ��   ��   ��   ȸ ]");

	gotoxy(37, 14);
	printf("��  ��  ��  ȣ : ");
	scanf("%d", &id);

	if ((id < 1) || (id > 100)) {
		gotoxy(37, 17);
		printf("�������� �ʴ� ���¹�ȣ�Դϴ�. \n");
		return;
	}

	gotoxy(37, 17);
	printf("��    ��    �� : %s\n", bank[id - 1].name);
	gotoxy(37, 20);
	printf("��          �� : %d��\n", bank[id - 1].balance);
}

void manager_menu1() // ��ü �� ������ȸ (���¹�ȣ, �ܾ� ���)
{

	int i, j = 0;

	gotoxy(47, 9);
	printf("[ ��ü �� ������ȸ ] \n");

	for (i = 0; i < cnt / 2; i++) {
		gotoxy(32, 12 + i * 8);
		printf("��  ��  ��  ȣ : %d", bank[i].add_num);
		gotoxy(32, 14 + i * 8);
		printf("��    ��    �� : %s", bank[i].name);
		gotoxy(32, 16 + i * 8);
		printf("��          �� : %d��", bank[i].balance);
		gotoxy(32, 18 + i * 8);
		printf("----------------------\n");
	}
	for (i = cnt / 2; i < cnt; i++) {
		gotoxy(65, 12 + j * 8);
		printf("��  ��  ��  ȣ : %d", bank[i].add_num);
		gotoxy(65, 14 + j * 8);
		printf("��    ��    �� : %s", bank[i].name);
		gotoxy(65, 16 + j * 8);
		printf("��          �� : %d��", bank[i].balance);
		gotoxy(65, 18 + j * 8);
		printf("----------------------\n");
		j++;
	}
	gotoxy(43, 36);
	printf("�� %d�� ���� ���� ����� �������ϴ�.\n", cnt);
}

void manager_menu2() // �� �������� ����(��ü �� �������� ���)
{
	int i, j = 0;

	if (cnt > 0) {
		gotoxy(47, 9);
		printf("[ ��ü �� �������� ]\n");

		for (i = 0; i < cnt / 2; i++) {
			gotoxy(29, 12 + i * 10);
			printf("��  ��  ��  ȣ : %d\n", bank[i].add_num);
			gotoxy(29, 14 + i * 10);
			printf("��    ��    �� : %s\n", bank[i].name);
			gotoxy(29, 16 + i * 10);
			printf("�ֹ� ��� ��ȣ : %s\n", bank[i].number);
			gotoxy(29, 18 + i * 10);
			printf("��          �� : %s\n", bank[i].address);
			gotoxy(29, 20 + i * 10);
			printf("��  ȭ  ��  ȣ : %s\n", bank[i].tel);
			gotoxy(29, 21 + i * 10);
			printf("------------------------------\n");
		}

		for (i = cnt / 2; i < cnt; i++) {
			gotoxy(69, 12 + j * 10);
			printf("��  ��  ��  ȣ : %d\n", bank[i].add_num);
			gotoxy(69, 14 + j * 10);
			printf("��    ��    �� : %s\n", bank[i].name);
			gotoxy(69, 16 + j * 10);
			printf("�ֹ� ��� ��ȣ : %s\n", bank[i].number);
			gotoxy(69, 18 + j * 10);
			printf("��          �� : %s\n", bank[i].address);
			gotoxy(69, 20 + j * 10);
			printf("��  ȭ  ��  ȣ : %s\n", bank[i].tel);
			gotoxy(69, 21 + j * 10);
			printf("------------------------------\n");
			j++;
		}
		gotoxy(43, 45);
		printf("��� ������ ����� �Ϸ�Ǿ����ϴ�.\n");
	}
	else {
		gotoxy(47, 9);
		printf("�����Ͱ� �������� �ʽ��ϴ�.\n\n");
	}
}

void manager_menu3() // �� �������� (�˻��ؼ� �� ���� ��� ���� ���)
{
	char name[20];
	int i;

	gotoxy(47, 9);
	printf("[ Ư�� �� ��ü���� ]\n");

	// ����� �����Ͱ� �ִٸ�
	if (cnt > 0) {
		gotoxy(35, 12);
		printf("ã�����ϴ� �����ָ� �Է����ּ��� : ");
		scanf("%s", &name);

		for (i = 0; i < cnt; i++) {
			// strcmp�� ���ڿ��� ��ġ�� �� 0�� ��ȯ
			// 0�� c���� ������ �ǹ�
			// �׷��Ƿ� !�� �ٿ� ������ �����Ͽ� ����
			if (!strcmp(name, bank[i].name)) {
				gotoxy(35, 14);
				printf("��    ��    �� : %s", bank[i].name);
				gotoxy(35, 16);
				printf("��  ��  ��  ȣ : %d", bank[i].add_num);
				gotoxy(35, 18);
				printf("��  ��  ��  ȣ : %d", bank[i].password);
				gotoxy(35, 20);
				printf("�ֹ� ��� ��ȣ : %s", bank[i].number);
				gotoxy(35, 22);
				printf("��  ȭ  ��  ȣ : %s", bank[i].tel);
				gotoxy(35, 24);
				printf("��          �� : %s", bank[i].address);
				gotoxy(35, 26);
				printf("��          �� : %d��", bank[i].balance);
			}

		}
		gotoxy(35, 14);
	}
	else {
		gotoxy(35, 14);
		printf("�����Ͱ� �������� �ʽ��ϴ�.");
	}
}
void account_transfer() // ������ü
{
	int id_out;
	int money, i;
	int num = 0;
	char q;
	char name[20];

	gotoxy(47, 9);
	printf("[ ��  ��  ��  ü ]\n");

	gotoxy(37, 14);
	printf("��  ��  ��  ȣ : ");
	scanf("%d", &id_out);

	if ((id_out < 1) || (id_out > 100)) {
		gotoxy(37, 17);
		printf("�������� �ʴ� ���¹�ȣ�Դϴ�. \n");
		return;
	}

	gotoxy(37, 17);
	printf("��  ��  ��  ȣ : ");
	scanf("%d", &num);

	if (num == bank[id_out - 1].password) {
		gotoxy(37, 20);
		printf("!!! ��й�ȣ ��ġ !!! ");
		gotoxy(37, 23);
		printf("�� �� ��    �� �� : ");
		scanf("%d", &money);
		gotoxy(37, 26);
		printf("��    ��    �� : ");
		scanf("%s", &name);

		for (i = 0; i < cnt; i++) {
			if (!strcmp(name, bank[i].name))
			{
				system("cls");
				menu_s();

				gotoxy(47, 9);
				printf("[ ��  ��  ��  ü ]\n");

				gotoxy(40, 13);
				printf("-------------Ȯ    ��-------------");

				gotoxy(37, 16);
				printf("��     ��    �� : %s", name);
				gotoxy(37, 19);
				printf("�Է��� �� �� �� : %d��", money);
				gotoxy(37, 22);
				printf("=> ������ y / Ʋ���� n�� �Է����ּ��� : ");
				scanf("%c", &q);
				getchar();

				if (q = 'y') {
					bank[id_out - 1].balance -= money;
					bank[i].balance += money;
					gotoxy(41, 22);
					printf("    !!!  �۱��� �Ϸ�Ǿ����ϴ�.  !!!    ");
				}
				else if (q == 'n') {
					gotoxy(47, 23);
					printf("�߸� �Է��Ͽ����ϴ�. �ٽ� �������ּ���.\n");
					return;
				}
			}
		}
	}
}

void manager_menu4() // �� ���� ����
{
	int id, num, pass;
	char name[20];
	char address[50];
	char tel[20];

	gotoxy(47, 9);
	printf("[ �� ���� ���� ]\n");

	gotoxy(37, 13);
	printf("�����ϰ����ϴ� ���� ���¹�ȣ : ");
	scanf("%d", &id);

	if ((id < 1) || (id > 100)) {
		gotoxy(37, 116);
		printf("�������� �ʴ� ���¹�ȣ�Դϴ�. \n");
		return;
	}

	system("cls");
	menu_s();

	gotoxy(47, 9);
	printf("[ �� ���� ���� ]\n");

	gotoxy(37, 11);
	printf("������ �׸��� �������ּ���!!");

	gotoxy(46, 14);
	printf(" 1) ��             �� ");
	gotoxy(46, 18);
	printf(" 2) ��             �� ");
	gotoxy(46, 22);
	printf(" 3) ��   ȭ   ��   ȣ ");
	gotoxy(46, 26);
	printf(" 4) ����  �� �� �� ȣ ");


	gotoxy(29, 29);
	printf(" �� �� ��   �� �� : ");
	scanf("%d", &num);
	Sleep(500);

	system("cls");
	menu_s();

	gotoxy(47, 9);
	printf("[ �� ���� ���� ]\n");

	switch (num)
	{
	case 1:
		gotoxy(37, 12);
		printf(" !! �� �� �� �� !! ");
		gotoxy(37, 16);
		printf("�� �� ��   �� �� : ");
		scanf("%s", &name);
		strcpy(bank[id - 1].name, name);
		gotoxy(37, 20);
		printf(" �� �� �� �� !!");
		break;

	case 2:
		gotoxy(37, 12);
		printf(" !! �� �� �� �� !! ");
		gotoxy(37, 16);
		printf("�� �� ��   �� �� : ");
		scanf("%s", &address);
		strcpy(bank[id - 1].address, address);
		gotoxy(37, 20);
		printf(" �� �� �� �� !!");
		break;

	case 3:
		gotoxy(37, 12);
		printf(" !! �� ȭ �� ȣ �� �� !! ");
		gotoxy(37, 16);
		printf("�� �� ��   �� ȭ �� ȣ : ");
		scanf("%s", &tel);
		strcpy(bank[id - 1].tel, tel);
		gotoxy(37, 20);
		printf(" �� �� �� �� !!");
		break;

	case 4:
		gotoxy(37, 12);
		printf(" !! �� �� �� �� �� ȣ �� �� !! ");
		gotoxy(37, 16);
		printf("�� �� ��   �� �� �� ȣ : ");
		scanf("%d", &pass);
		bank[id - 1].password = pass;
		gotoxy(37, 20);
		printf(" �� �� �� �� !!");
		break;
	}
}
