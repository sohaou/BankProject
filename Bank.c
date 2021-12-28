
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> // getch() 사용
#include <time.h> // Sleep() 사용
#include <Windows.h> // system() 사용

# define MAX_NUM 100

typedef struct
{
	char name[20]; // 고객 이름
	char number[20]; // 주민등록번호
	char address[50]; // 고객 주소
	char tel[20]; // 고객 전화번호
	int balance; // 잔액
	int password; // 계좌비밀번호
	int add_num; //계좌번호
} BANK;

BANK bank[MAX_NUM];

int cnt = 0; // 계좌번호
int  cn = 0;

void gotoxy(int x, int y); // 이동함수
void menu_s(); // 메뉴 틀
int customer_menu(); // 고객메뉴
int manager_menu();  // 관리자(은행원) 메뉴
int menu(); // 시작 메뉴
int log_in(fp); // 관리자 로그인
void deposit_account(); // 입금
void withdraw_account(); // 출금
void account_transfer(); // 계좌이체
void balance_inquiry(); // 잔액 조회
void make_account();  // 계좌개설
void manager_menu1(); // 전체 고객 계좌조회 (계좌번호, 잔액 출력)
void manager_menu2(); // 고객 개인정보 출력(모든 고객 개인정보 출력)
void manager_menu3(); // 고객 개인정보 출력(특정 고객 검색)
void manager_menu4(); // 고객 정보수정

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
		case 1: // 고객
			system("cls");
			menu_s();
			ch2 = customer_menu(); // 고객메뉴

			if (ch2 == 1) { // 계좌개설
				system("cls");
				menu_s();
				make_account();
				break;
			}
			else if (ch2 == 2) { // 입금
				system("cls");
				menu_s();
				deposit_account();
				Sleep(2000); // 시간지연 1sec=1000
				break;
			}
			else if (ch2 == 3) { // 출금
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
			else if (ch2 == 5) {// 잔액조회
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
				printf("1) 모든 고객의 개인정보출력\n");

				gotoxy(41, 21);
				printf("2) 특정 고객의 개인정보출력\n");

				gotoxy(29, 29);
				printf(" 선            택  : ");
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
			fprintf(fp, "계좌번호     예금주              주민등록번호                  전화번호                        주소                                    비밀번호        잔액 \n");
			fprintf(fp, "==================================================================================================================\n");

			for (i = 0; i < cnt; i++)
			{
				fprintf(fp, "  000%d        %s        %s        %s \t%s   \t%2d  \t%5d원\n", bank[i].add_num, bank[i].name, bank[i].number, bank[i].tel, bank[i].address, bank[i].password, bank[i].balance);
				fprintf(fp, "---------------------------------------------------------------------------------------------------------------------------\n");
			}
			fclose(fp);
			exit(1);

		default:
			system("cls");
			menu_s();
			gotoxy(43, 20);
			printf("잘못 입력하셨습니다. 다시 선택해주세요.");
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
	printf("\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t\t┃\t\t                                          \t┃\n");
	printf("\t\t\t┃\t\t                                          \t┃\n");
	printf("\t\t\t┃\t\t                                          \t┃\n");
	printf("\t\t\t┃\t\t                                          \t┃\n");
	printf("\t\t\t┃\t\t                                          \t┃\n");
	printf("\t\t\t┃\t\t                                          \t┃\n");
	printf("\t\t\t┃\t\t                                          \t┃\n");
	printf("\t\t\t┃\t\t                                          \t┃\n");
	printf("\t\t\t┃\t\t                                          \t┃\n");
	printf("\t\t\t┃\t\t                                          \t┃\n");
	printf("\t\t\t┃\t\t                                          \t┃\n");
	printf("\t\t\t┃\t\t                                          \t┃\n");
	printf("\t\t\t┃\t\t                                          \t┃\n");
	printf("\t\t\t┃\t\t                                          \t┃\n");
	printf("\t\t\t┃\t\t                                          \t┃\n");
	printf("\t\t\t┃\t\t                                          \t┃\n");
	printf("\t\t\t┃\t\t                                          \t┃\n");
	printf("\t\t\t┃\t\t                                          \t┃\n");
	printf("\t\t\t┃\t\t                                          \t┃\n");
	printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}
int menu()
{
	int select;

	gotoxy(46, 13);
	printf(" 1)  고            객 ");

	gotoxy(46, 18);
	printf(" 2)  은     행     원 ");

	gotoxy(46, 23);
	printf(" 3)  종            료 ");

	gotoxy(32, 29);
	printf(" 선            택  : ");
	scanf("%d", &select);

	return select;
}

int customer_menu()
{
	int select1;

	gotoxy(46, 12);
	printf("1)  계   좌   개   설");

	gotoxy(46, 15);
	printf("2)  입             금");

	gotoxy(46, 18);
	printf("3)  출             금");

	gotoxy(46, 21);
	printf("4)  계   좌   이   체 ");

	gotoxy(46, 24);
	printf("5)  잔   액   조   회 ");

	gotoxy(32, 29);
	printf("선           택  : ");
	scanf("%d", &select1);

	return select1;
}

int manager_menu()
{
	int select2;

	gotoxy(44, 14);
	printf("1)  전체   고객   계좌   조회");

	gotoxy(44, 19);
	printf("2)  고객   개인   정보   관리");

	gotoxy(44, 24);
	printf("3)  고 객     정 보     수 정");

	gotoxy(44, 29);
	printf("선            택  :");
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
	printf("비밀번호를 입력해주세요 : ");
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
		printf("!!!비밀번호 일치!!!");
	}
	else
	{
		gotoxy(43, 20);
		printf("비밀번호  !!불!!일치");
		cn++;

		gotoxy(53, 26);
		printf("%d  /  3회 \n", cn);

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
			printf("!!입력횟수 초과입니다!!");

			gotoxy(47, 20);
			printf("프로그램이 종료됩니다.\n\n\n\n\n\n\n\n\n");

			fprintf(fp, "====================================================================================================================\n");
			fprintf(fp, "계좌번호     예금주        주민등록번호        전화번호                주소          비밀번호     잔액 \n");
			fprintf(fp, "====================================================================================================================\n");

			for (i = 0; i < cnt; i++)
			{
				fprintf(fp, "  000%d        %s        %s        %s \t%s   \t%2d  \t%6d원\n", bank[i].add_num, bank[i].name, bank[i].number, bank[i].tel, bank[i].address, bank[i].password, bank[i].balance);
				fprintf(fp, "---------------------------------------------------------------------------------------------------------------------------\n");
			}
			fclose(fp);
			exit(1);
		}
	}
}

void make_account()  // 계좌개설
{
	int i, j;
	int num, found = 0;

	gotoxy(47, 9);
	printf("<  계 좌 번 호 : %d  >", cnt + 1);
	bank[cnt].add_num = cnt + 1;

	gotoxy(37, 11);
	printf("* 이름을 입력해주세요 : ");
	scanf("%s", &bank[cnt].name);

	getchar(); // 입력버퍼를 비우기 위해

	gotoxy(37, 14.7);
	printf("* 주민등록번호를 입력해주세요 : ");
	scanf("%s", &bank[cnt].number);

	getchar();

	gotoxy(37, 17.7);
	printf("* 주소를 입력해주세요 : ");
	gets(bank[cnt].address);

	gotoxy(37, 20.7);
	printf("* 전화번호를 입력해주세요 : ");
	scanf("%s", &bank[cnt].tel);

	getchar();

	gotoxy(37, 23.7);
	printf("* 최초 입금액을 입력해주세요(원) : ");
	scanf("%d", &bank[cnt].balance);

	getchar();

	gotoxy(37, 26.7);
	printf("* 비밀번호 4자리를 설정해주세요 : ");
	scanf("%d", &bank[cnt].password);

	getchar();

	if (bank[cnt].balance == 0) {
		system("cls");
		menu_s();
		gotoxy(41, 18);

		printf("최초 입금액은 1원 이상부터 입금이 가능합니다.\n");

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
	printf(" [ 입         금 ]");

	gotoxy(37, 14);
	printf("계  좌  번  호 : ");
	scanf("%d", &id);

	if ((id < 1) || (id > 100)) {
		gotoxy(38, 18);
		printf("존재하지 않는 계좌번호입니다. \n");
		return;
	}

	gotoxy(37, 17);
	printf("입   금   액 (원) : ");
	scanf("%d", &money);

	getchar();

	gotoxy(37, 20);

	printf("----------확    인----------");

	gotoxy(37, 21);
	printf("입력한 계좌번호 : %d", id);
	gotoxy(37, 22);
	printf("입력한 입 금 액 : %d원", money);
	gotoxy(37, 23);
	printf("=> 맞으면 y / 틀리면 n을 입력해주세요 : ");
	scanf("%c", &q);
	getchar();

	if (q = 'y') {
		printf("\n\n");
		bank[id - 1].balance += money;
		gotoxy(37, 23);
		printf("   ! ! !   입금이 완료되었습니다.   ! ! !   ");
	}
	else if (q == 'n') {
		gotoxy(37, 23);
		printf("잘못 입력하였습니다. 다시 실행해주세요.\n");
	}
}

void withdraw_account() // 출금
{
	int id;
	int money;
	int num = 0;
	int q;

	gotoxy(47, 9);
	printf(" [ 출         금 ]");

	gotoxy(37, 14);
	printf("계  좌  번  호 : ");
	scanf("%d", &id);

	if ((id < 1) || (id > 100)) {
		gotoxy(37, 17);
		printf("존재하지 않는 계좌번호입니다. \n");
		return;
	}

	gotoxy(37, 17);
	printf("비밀번호 4자리를 입력해주세요 : ");
	scanf("%d", &q);

	if (q == bank[id - 1].password) {
		gotoxy(37, 20);
		printf("!!! 비밀번호 일치 !!! ");
		gotoxy(37, 22);
		printf("출    금    액 (원) : ");
		scanf("%d", &money);

		if (money > bank[id - 1].balance) {
			gotoxy(37, 24);
			printf("잔액이 부족합니다.\n");
		}
		else {
			bank[id - 1].balance -= money;
			gotoxy(37, 24);
			printf("출금이 완료되었습니다.\n");
		}
	}
}

void balance_inquiry() // 잔액 조회
{
	int id;

	gotoxy(47, 9);
	printf(" [ 잔   액   조   회 ]");

	gotoxy(37, 14);
	printf("계  좌  번  호 : ");
	scanf("%d", &id);

	if ((id < 1) || (id > 100)) {
		gotoxy(37, 17);
		printf("존재하지 않는 계좌번호입니다. \n");
		return;
	}

	gotoxy(37, 17);
	printf("예    금    주 : %s\n", bank[id - 1].name);
	gotoxy(37, 20);
	printf("잔          액 : %d원\n", bank[id - 1].balance);
}

void manager_menu1() // 전체 고객 계좌조회 (계좌번호, 잔액 출력)
{

	int i, j = 0;

	gotoxy(47, 9);
	printf("[ 전체 고객 계좌조회 ] \n");

	for (i = 0; i < cnt / 2; i++) {
		gotoxy(32, 12 + i * 8);
		printf("계  좌  번  호 : %d", bank[i].add_num);
		gotoxy(32, 14 + i * 8);
		printf("예    금    주 : %s", bank[i].name);
		gotoxy(32, 16 + i * 8);
		printf("잔          액 : %d원", bank[i].balance);
		gotoxy(32, 18 + i * 8);
		printf("----------------------\n");
	}
	for (i = cnt / 2; i < cnt; i++) {
		gotoxy(65, 12 + j * 8);
		printf("계  좌  번  호 : %d", bank[i].add_num);
		gotoxy(65, 14 + j * 8);
		printf("예    금    주 : %s", bank[i].name);
		gotoxy(65, 16 + j * 8);
		printf("잔          액 : %d원", bank[i].balance);
		gotoxy(65, 18 + j * 8);
		printf("----------------------\n");
		j++;
	}
	gotoxy(43, 36);
	printf("총 %d명 고객의 정보 출력이 끝났습니다.\n", cnt);
}

void manager_menu2() // 고객 개인정보 관리(전체 고객 개인정보 출력)
{
	int i, j = 0;

	if (cnt > 0) {
		gotoxy(47, 9);
		printf("[ 전체 고객 개인정보 ]\n");

		for (i = 0; i < cnt / 2; i++) {
			gotoxy(29, 12 + i * 10);
			printf("계  좌  번  호 : %d\n", bank[i].add_num);
			gotoxy(29, 14 + i * 10);
			printf("예    금    주 : %s\n", bank[i].name);
			gotoxy(29, 16 + i * 10);
			printf("주민 등록 번호 : %s\n", bank[i].number);
			gotoxy(29, 18 + i * 10);
			printf("주          소 : %s\n", bank[i].address);
			gotoxy(29, 20 + i * 10);
			printf("전  화  번  호 : %s\n", bank[i].tel);
			gotoxy(29, 21 + i * 10);
			printf("------------------------------\n");
		}

		for (i = cnt / 2; i < cnt; i++) {
			gotoxy(69, 12 + j * 10);
			printf("계  좌  번  호 : %d\n", bank[i].add_num);
			gotoxy(69, 14 + j * 10);
			printf("예    금    주 : %s\n", bank[i].name);
			gotoxy(69, 16 + j * 10);
			printf("주민 등록 번호 : %s\n", bank[i].number);
			gotoxy(69, 18 + j * 10);
			printf("주          소 : %s\n", bank[i].address);
			gotoxy(69, 20 + j * 10);
			printf("전  화  번  호 : %s\n", bank[i].tel);
			gotoxy(69, 21 + j * 10);
			printf("------------------------------\n");
			j++;
		}
		gotoxy(43, 45);
		printf("모든 데이터 출력이 완료되었습니다.\n");
	}
	else {
		gotoxy(47, 9);
		printf("데이터가 존재하지 않습니다.\n\n");
	}
}

void manager_menu3() // 고객 개인정보 (검색해서 그 고객의 모든 정보 출력)
{
	char name[20];
	int i;

	gotoxy(47, 9);
	printf("[ 특정 고객 전체정보 ]\n");

	// 저장된 데이터가 있다면
	if (cnt > 0) {
		gotoxy(35, 12);
		printf("찾고자하는 예금주를 입력해주세요 : ");
		scanf("%s", &name);

		for (i = 0; i < cnt; i++) {
			// strcmp는 문자열이 일치할 때 0을 반환
			// 0은 c언어에서 거짓을 의미
			// 그러므로 !을 붙여 참으로 변경하여 실행
			if (!strcmp(name, bank[i].name)) {
				gotoxy(35, 14);
				printf("예    금    주 : %s", bank[i].name);
				gotoxy(35, 16);
				printf("계  좌  번  호 : %d", bank[i].add_num);
				gotoxy(35, 18);
				printf("비  밀  번  호 : %d", bank[i].password);
				gotoxy(35, 20);
				printf("주민 등록 번호 : %s", bank[i].number);
				gotoxy(35, 22);
				printf("전  화  번  호 : %s", bank[i].tel);
				gotoxy(35, 24);
				printf("주          소 : %s", bank[i].address);
				gotoxy(35, 26);
				printf("잔          액 : %d원", bank[i].balance);
			}

		}
		gotoxy(35, 14);
	}
	else {
		gotoxy(35, 14);
		printf("데이터가 존재하지 않습니다.");
	}
}
void account_transfer() // 계좌이체
{
	int id_out;
	int money, i;
	int num = 0;
	char q;
	char name[20];

	gotoxy(47, 9);
	printf("[ 계  좌  이  체 ]\n");

	gotoxy(37, 14);
	printf("계  좌  번  호 : ");
	scanf("%d", &id_out);

	if ((id_out < 1) || (id_out > 100)) {
		gotoxy(37, 17);
		printf("존재하지 않는 계좌번호입니다. \n");
		return;
	}

	gotoxy(37, 17);
	printf("비  밀  번  호 : ");
	scanf("%d", &num);

	if (num == bank[id_out - 1].password) {
		gotoxy(37, 20);
		printf("!!! 비밀번호 일치 !!! ");
		gotoxy(37, 23);
		printf("보 내 는    금 액 : ");
		scanf("%d", &money);
		gotoxy(37, 26);
		printf("받    는    분 : ");
		scanf("%s", &name);

		for (i = 0; i < cnt; i++) {
			if (!strcmp(name, bank[i].name))
			{
				system("cls");
				menu_s();

				gotoxy(47, 9);
				printf("[ 계  좌  이  체 ]\n");

				gotoxy(40, 13);
				printf("-------------확    인-------------");

				gotoxy(37, 16);
				printf("받     는    분 : %s", name);
				gotoxy(37, 19);
				printf("입력한 송 금 액 : %d원", money);
				gotoxy(37, 22);
				printf("=> 맞으면 y / 틀리면 n을 입력해주세요 : ");
				scanf("%c", &q);
				getchar();

				if (q = 'y') {
					bank[id_out - 1].balance -= money;
					bank[i].balance += money;
					gotoxy(41, 22);
					printf("    !!!  송금이 완료되었습니다.  !!!    ");
				}
				else if (q == 'n') {
					gotoxy(47, 23);
					printf("잘못 입력하였습니다. 다시 실행해주세요.\n");
					return;
				}
			}
		}
	}
}

void manager_menu4() // 고객 정보 수정
{
	int id, num, pass;
	char name[20];
	char address[50];
	char tel[20];

	gotoxy(47, 9);
	printf("[ 고객 정보 수정 ]\n");

	gotoxy(37, 13);
	printf("수정하고자하는 고객의 계좌번호 : ");
	scanf("%d", &id);

	if ((id < 1) || (id > 100)) {
		gotoxy(37, 116);
		printf("존재하지 않는 계좌번호입니다. \n");
		return;
	}

	system("cls");
	menu_s();

	gotoxy(47, 9);
	printf("[ 고객 정보 수정 ]\n");

	gotoxy(37, 11);
	printf("수정할 항목을 선택해주세요!!");

	gotoxy(46, 14);
	printf(" 1) 이             름 ");
	gotoxy(46, 18);
	printf(" 2) 주             소 ");
	gotoxy(46, 22);
	printf(" 3) 전   화   번   호 ");
	gotoxy(46, 26);
	printf(" 4) 계좌  비 밀 번 호 ");


	gotoxy(29, 29);
	printf(" 수 정 할   항 목 : ");
	scanf("%d", &num);
	Sleep(500);

	system("cls");
	menu_s();

	gotoxy(47, 9);
	printf("[ 고객 정보 수정 ]\n");

	switch (num)
	{
	case 1:
		gotoxy(37, 12);
		printf(" !! 이 름 수 정 !! ");
		gotoxy(37, 16);
		printf("수 정 한   이 름 : ");
		scanf("%s", &name);
		strcpy(bank[id - 1].name, name);
		gotoxy(37, 20);
		printf(" 수 정 완 료 !!");
		break;

	case 2:
		gotoxy(37, 12);
		printf(" !! 주 소 수 정 !! ");
		gotoxy(37, 16);
		printf("수 정 한   주 소 : ");
		scanf("%s", &address);
		strcpy(bank[id - 1].address, address);
		gotoxy(37, 20);
		printf(" 수 정 완 료 !!");
		break;

	case 3:
		gotoxy(37, 12);
		printf(" !! 전 화 번 호 수 정 !! ");
		gotoxy(37, 16);
		printf("수 정 한   전 화 번 호 : ");
		scanf("%s", &tel);
		strcpy(bank[id - 1].tel, tel);
		gotoxy(37, 20);
		printf(" 수 정 완 료 !!");
		break;

	case 4:
		gotoxy(37, 12);
		printf(" !! 계 좌 비 밀 번 호 수 정 !! ");
		gotoxy(37, 16);
		printf("수 정 한   비 밀 번 호 : ");
		scanf("%d", &pass);
		bank[id - 1].password = pass;
		gotoxy(37, 20);
		printf(" 수 정 완 료 !!");
		break;
	}
}
