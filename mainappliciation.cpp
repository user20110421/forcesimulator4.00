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
	cout << "程序地址：https://github.com/user20110421/forcesimulator4.00\n\n正在检测程序权限……\n";
	sleep(2);
	if (bIsAdmin) {
		MessageBox(NULL, "程序运行时权限没有问题。点击确定（或OK）继续。", "权限检测程序", MB_ICONASTERISK | MB_OK);
		start();
	} else {
e:
		system("cls");
		cout << "程序检测到当前正在以普通用户权限运行。请执行以下操作：\n"
		     << "  重新选择运行方式。\n"
		     << "    [1]继续使用普通用户权限运行。此方法能使用户继续使用此程序，"
		     << "但无法使用完整功能。窗口颜色也会因此受限。\n"
		     << "    [2]退出并使用管理员权限运行。此方法能使用户使用完整功能，且不会"
		     << "导致窗口颜色受限。建议选择此项。\n\n"
		     << "输入[1]或[2]选择。\n";
		string adn;
		cin >> adn;
		while (1) {
			if (adn == "[1]") {
				admin = false;
				start();
			}
			if (adn == "[2]")
				exit(0);
			if (adn == "【1】" || adn == "【2】") {
				MessageBox(NULL, "请使用英文输入法", "程序已暂停", MB_ICONASTERISK | MB_OK);
				goto e;
			}
		}
	}

}

void start() {
	system("cls");
	system("color 07");
	for (int wait = 10; wait >= 0; wait--) {
		cout << "模拟器正在启动。按S进入设置。（"
		     << wait << "s）\n";
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
	cout << "当前正在进行平面设置。请按照步骤操作。\n";
	sleep(3);
	system("cls");
	cout << "（1/4）平面长度：" << length;
	if (revise == false || length == 32) {
		cout << "（默认）\n";
	}
	if (revise == true)
		cout << "\n";
	cout << "  若要进行修改，请输入修改的数据；若不修改，请输入原数据。\n";
	cout << "特别提醒：千万不要输入字母及符号，以免出现死循环且无法操作"
	     << "或进入模拟器后突然退出的异常情况！\n";
	cin >> length;
	revise = true;
	if (length == 16) {
		revise = false;
	}
	system("cls");
	cout << "（2/4）请设置对象的质量（即，需要多少N的力才能推动它）：";
	cin >> quality;
	system("cls");

color:
	cout << "（3/4）设置背景色：\n"
	     << "<default>：使用默认颜色";
	cout << "（基本Windows窗口，即白色。输入E查看示例）\n";
	cout << "\n r：红色\n"
	     << " y：黄色\n"
	     << " g：绿色\n"
	     << " p：紫色\n"
	     << "输入对应字母进行选择。\n";
	cin >> bg;
	if (bg == "E" || bg == "e") {
		system("cls");
		system("start exemaple.exe");
		goto color;
	}
	system("cls");
	do {
		cout << "（4/4）设置字体颜色：\n"
		     << "<default>：使用默认颜色（黑色）\n"
		     << " r：红色\n"
		     << " y：黄色\n"
		     << " g：绿色\n"
		     << " p：紫色\n"
		     << "输入对应字母进行选择。\n";
		cin >> typecolor;
		if (typecolor == bg) {
			cout << "字体颜色不可与背景色相同！\n";
			sleep(2);
			system("cls");
			continue;
		}
		break;
	} while (1);
	system("cls");
	for (int s = 10; s >= 0; s--) {
		cout << "修改已完成。\n" << s << "s后保存设置并进入模拟器。\n"
		     << "若想重新修改，请按R。\n";
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
	cout << "当前正在进行平面设置。请按照步骤操作。\n";
	sleep(3);
	system("cls");
	cout << "（1/2）平面长度：" << length;
	if (revise == false || length == 32) {
		cout << "（默认）\n";
	}
	if (revise == true)
		cout << "\n";
	cout << "  若要进行修改，请输入修改的数据；若不修改，请输入原数据。\n";
	cout << "特别提醒：千万不要输入字母及符号，以免出现死循环且无法操作"
	     << "或进入模拟器后突然退出的异常情况！\n";
	cin >> length;
	revise = true;
	if (length == 32) {
		revise = false;
	}
	system("cls");
	cout << "（2/2）请设置对象的质量（即，需要多少N的力才能推动它）：";
	cin >> quality;
	system("cls");
	for (int s = 10; s >= 0; s--) {
		cout << "修改已完成。\n" << s << "s后保存设置并进入模拟器。\n"
		     << "若想重新修改，请按R。\n";
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
		cout << "当前正在以普通用户权限运行。\n";
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
	cout << "已预设代码为1的对象。\n";
p:
	cout << "█";

	for (int i = 1; i <= length * 4; i++) {
		cout << "  ";
	}
	cout << "\n";
	text[1] = number;
	number++;
	if (prepare_object == false)
		cout << "  ";
	for (int j = 1; j <= length * 4; j++) {
		cout << "═";
	}
	int code;
	do {
		while (1) {
			cout << "\n若要对指定且已存在的对象执行操作，请输入该对象的代码。\n"
			     << "若要重新开始，请输入-1。\n";
			cin >> code;
			if (code == -1) {
				system("cls");
				start();
			}
			for (int m = 1; m <= 16; m++) {
				if (code == text[m])
					break;//代码有效
				else
					cout << "找不到代码为" << code << "的对象。\n";
				continue;
			}
			cout << "要对代码为#" << code << "的对象进行什么操作？\n"
			     << "delete：删除\n"
			     << "push：推动（即向选定的目标施加一个力）\n";
			string operate;
			cin >> operate;
			if (operate == "delete") {
				po == false;
				simulation();
			}

			if (operate == "push") {
				cout << "请输入1~" << l - 1 << "之间的数据。\n";
				int N;
				cin >> N;
				cout << "正在执行命令： #" << code << " push " << N << "N\n";
				sleep(1);
				if (quality > N)
					goto p;
				for (int i2 = 1; i2 <= length * 4; i2++) {
					if (i2 == N) {
						cout << "█";
					}
					cout << "  ";
				}
				cout << "\n";
				for (int j2 = 1; j2 <= length * 4; j2++) {
					cout << "═";
				}
				cout << "\n";
			}
		}
	} while (1);



}

int main() {
	system("title 受力模拟器");
	check();
	start();

	return 0;
}

