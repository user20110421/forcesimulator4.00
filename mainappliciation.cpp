#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <unistd.h>
#include <ShlObj.h>
using namespace std;
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
int length = 16;
bool revise = false;
bool prepare_object = true;
int text[16];
string bg = "<default>";
string typecolor = "<default>";
int quality;
bool admin = true;

void start();
void settings();
void simulation();
void check();
void settings2();

void check() {
	BOOL bIsAdmin = IsUserAnAdmin();
	cout << "�����ַ��https://github.com/user20110421/forcesimulator4.00\n\n���ڼ�����Ȩ�ޡ���\n";
	sleep(2);
	if (bIsAdmin) {
		MessageBox(NULL, "��������ʱȨ��û�����⡣���ȷ������OK��������", "Ȩ�޼�����", MB_ICONASTERISK | MB_OK);
		start();
	} else {
e:
		system("cls");
		cout << "�����⵽��ǰ��������ͨ�û�Ȩ�����С���ִ�����²�����\n"
		     << "  ����ѡ�����з�ʽ��\n"
		     << "    [1]����ʹ����ͨ�û�Ȩ�����С��˷�����ʹ�û�����ʹ�ô˳���"
		     << "���޷�ʹ���������ܡ�������ɫҲ��������ޡ�\n"
		     << "    [2]�˳���ʹ�ù���ԱȨ�����С��˷�����ʹ�û�ʹ���������ܣ��Ҳ���"
		     << "���´�����ɫ���ޡ�����ѡ����\n\n"
		     << "����[1]��[2]ѡ��\n";
		string adn;
		cin >> adn;
		while (1) {
			if (adn == "[1]") {
				admin = false;
				start();
			}
			if (adn == "[2]")
				exit(0);
			if (adn == "��1��" || adn == "��2��") {
				MessageBox(NULL, "��ʹ��Ӣ�����뷨", "��������ͣ", MB_ICONASTERISK | MB_OK);
				goto e;
			}
		}
	}

}

void start() {
	system("cls");
	system("color 07");
	for (int wait = 10; wait >= 0; wait--) {
		cout << "ģ����������������S�������á���"
		     << wait << "s��\n";
		if (KEY_DOWN('S')) {
			if (admin == false) {
				settings2();
			}
			settings();
		}
		sleep(1);
		system("cls");

	}
	simulation();
}

void settings() {
	system("cls");
	system("color fc");
	cout << "��ǰ���ڽ���ƽ�����á��밴�ղ��������\n";
	sleep(3);
	system("cls");
	cout << "��1/4��ƽ�泤�ȣ�" << length;
	if (revise == false || length == 32) {
		cout << "��Ĭ�ϣ�\n";
	}
	if (revise == true)
		cout << "\n";
	cout << "  ��Ҫ�����޸ģ��������޸ĵ����ݣ������޸ģ�������ԭ���ݡ�\n";
	cout << "�ر����ѣ�ǧ��Ҫ������ĸ�����ţ����������ѭ�����޷�����"
	     << "�����ģ������ͻȻ�˳����쳣�����\n";
	cin >> length;
	revise = true;
	if (length == 16) {
		revise = false;
	}
	system("cls");
	cout << "��2/4�������ö����������������Ҫ����N���������ƶ�������";
	cin >> quality;
	system("cls");

color:
	cout << "��3/4�����ñ���ɫ��\n"
	     << "<default>��ʹ��Ĭ����ɫ";
	cout << "������Windows���ڣ�����ɫ������E�鿴ʾ����\n";
	cout << "\n r����ɫ\n"
	     << " y����ɫ\n"
	     << " g����ɫ\n"
	     << " p����ɫ\n"
	     << "�����Ӧ��ĸ����ѡ��\n";
	cin >> bg;
	if (bg == "E" || bg == "e") {
		system("cls");
		system("start exemaple.exe");
		goto color;
	}
	system("cls");
	do {
		cout << "��4/4������������ɫ��\n"
		     << "<default>��ʹ��Ĭ����ɫ����ɫ��\n"
		     << " r����ɫ\n"
		     << " y����ɫ\n"
		     << " g����ɫ\n"
		     << " p����ɫ\n"
		     << "�����Ӧ��ĸ����ѡ��\n";
		cin >> typecolor;
		if (typecolor == bg) {
			cout << "������ɫ�����뱳��ɫ��ͬ��\n";
			sleep(2);
			system("cls");
			continue;
		}
		break;
	} while (1);
	system("cls");
	for (int s = 10; s >= 0; s--) {
		cout << "�޸�����ɡ�\n" << s << "s�󱣴����ò�����ģ������\n"
		     << "���������޸ģ��밴R��\n";
		sleep(1);
		system("cls");
		if (KEY_DOWN('R')) {
			settings();
		}
	}
	simulation();
}

void settings2() {
	system("cls");
	system("color fc");
	cout << "��ǰ���ڽ���ƽ�����á��밴�ղ��������\n";
	sleep(3);
	system("cls");
	cout << "��1/2��ƽ�泤�ȣ�" << length;
	if (revise == false || length == 32) {
		cout << "��Ĭ�ϣ�\n";
	}
	if (revise == true)
		cout << "\n";
	cout << "  ��Ҫ�����޸ģ��������޸ĵ����ݣ������޸ģ�������ԭ���ݡ�\n";
	cout << "�ر����ѣ�ǧ��Ҫ������ĸ�����ţ����������ѭ�����޷�����"
	     << "�����ģ������ͻȻ�˳����쳣�����\n";
	cin >> length;
	revise = true;
	if (length == 32) {
		revise = false;
	}
	system("cls");
	cout << "��2/2�������ö����������������Ҫ����N���������ƶ�������";
	cin >> quality;
	system("cls");
	for (int s = 10; s >= 0; s--) {
		cout << "�޸�����ɡ�\n" << s << "s�󱣴����ò�����ģ������\n"
		     << "���������޸ģ��밴R��\n";
		sleep(1);
		system("cls");
		if (KEY_DOWN('R')) {
			if (admin == false)
				settings2();
			settings();
		}
	}
	simulation();
}

void simulation() {
	if (admin == false) {
		cout << "��ǰ��������ͨ�û�Ȩ�����С�\n";
		system("color 98");
		goto k;
	}
	if (bg == "<default>") {
		if (typecolor == "<default>")
			system("color f0");
		if (typecolor == "r")
			system("color f4");
		if (typecolor == "y")
			system("color f6");
		if (typecolor == "g")
			system("color f2");
		if (typecolor == "p")
			system("color f5");
	}
	if (bg == "r") {
		if (typecolor == "<default>")
			system("color 40");
		if (typecolor == "y")
			system("color 46");
		if (typecolor == "g")
			system("color 42");
		if (typecolor == "p")
			system("color 45");
	}

	if (bg == "y") {
		if (typecolor == "<default>")
			system("color 60");
		if (typecolor == "r")
			system("color 64");
		if (typecolor == "g")
			system("color 62");
		if (typecolor == "p")
			system("color 65");

	}

	if (bg == "g") {
		if (typecolor == "<default>")
			system("color 20");
		if (typecolor == "r")
			system("color 24");
		if (typecolor == "y")
			system("color 26");
		if (typecolor == "p")
			system("color 25");
	}

	if (bg == "p") {
		if (typecolor == "<default>")
			system("color 50");
		if (typecolor == "r")
			system("color 54");
		if (typecolor == "y")
			system("color 56");
		if (typecolor == "g")
			system("color 52");
	}
k:
	int number = 1;
	bool po = prepare_object;
	memset(text, 0, sizeof(text));
	cout << endl;
	int l = length * 2;
	cout << "��Ԥ�����Ϊ1�Ķ���\n";
p:
	cout << "��";

	for (int i = 1; i <= length * 4; i++) {
		cout << "  ";
	}
	cout << "\n";
	text[1] = number;
	number++;
	if (prepare_object == false)
		cout << "  ";
	for (int j = 1; j <= length * 4; j++) {
		cout << "�T";
	}
	int code;
	do {
		while (1) {
			cout << "\n��Ҫ��ָ�����Ѵ��ڵĶ���ִ�в�����������ö���Ĵ��롣\n"
			     << "��Ҫ���¿�ʼ��������-1��\n";
			cin >> code;
			if (code == -1) {
				system("cls");
				start();
			}
			for (int m = 1; m <= 16; m++) {
				if (code == text[m])
					break;//������Ч
				else
					cout << "�Ҳ�������Ϊ" << code << "�Ķ���\n";
				continue;
			}
			cout << "Ҫ�Դ���Ϊ#" << code << "�Ķ������ʲô������\n"
			     << "delete��ɾ��\n"
			     << "push���ƶ�������ѡ����Ŀ��ʩ��һ������\n";
			string operate;
			cin >> operate;
			if (operate == "delete") {
				po == false;
				simulation();
			}

			if (operate == "push") {
				cout << "������1~" << l - 1 << "֮������ݡ�\n";
				int N;
				cin >> N;
				cout << "����ִ����� #" << code << " push " << N << "N\n";
				sleep(1);
				if (quality > N)
					goto p;
				for (int i2 = 1; i2 <= length * 4; i2++) {
					if (i2 == N) {
						cout << "��";
					}
					cout << "  ";
				}
				cout << "\n";
				for (int j2 = 1; j2 <= length * 4; j2++) {
					cout << "�T";
				}
				cout << "\n";
			}
		}
	} while (1);



}

int main() {
	system("title ����ģ����");
	check();
	start();

	return 0;
}

