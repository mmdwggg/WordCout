#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void parameter_c(string &file) {
	cout << "�ַ���:" << file.size();
}
void parameter_w(string &file) {
	int flag = 1;
	int num = 0;
	for (int i = 0; i < file.size(); i++) {
		if (file[i] != ' ' && file[i] != '\t' && file[i] != ',') {
			if (flag == 1) {
				flag = 0;
				num++;
			}
		}
		else {
			flag = 1;
		}
	}
	cout << "������:" << num;
}
int main(int argc, char* argv[]) {
	if (argc != 3 ) {
		cout << "�����������ʽ����";
		return 0;
	}
	string filename=string(argv[2]);
	string parameter=string(argv[1]);
	string file;
	string str;
	ifstream ifs;
	ifs.open(filename, ios::in);
	while (getline(ifs, str)) {
		file += str;
		file += " ";
	}
	cout << file << endl;
	ifs.close();
	if (parameter == "-c") {
		parameter_c(file);
	}
	else if(parameter == "-w"){
		parameter_w(file);
	}
	else {
		cout << "���Ʋ�������";
	}
	return 0;
}