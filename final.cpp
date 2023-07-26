//Baseball Simulator �`It's SHOWTIME!�`

#include <iostream>
#include <vector>
#include <random>
using namespace std;

//�@�N���X, �֐�, �C�e���[�^���g���܂��傤. 


//�o�b�^�[�̃N���X
class batter {
	string name;
	int avg;
	int obp;
	int slg;

public:
	string get_name();
	void set_name(string new_name);

	int get_avg();
	void set_avg(int new_avg);

	int get_obp();
	void set_obp(int new_obp);

	int get_slg();
	void set_slg(int new_slg);
};


//�o�b�^�[�N���X�̃����o�֐��̒�`
string batter::get_name() {
	return name;
}

void batter::set_name(string new_name) {
	name = new_name;
}

int batter::get_avg() {
	return avg;
}

void batter::set_avg(int new_avg) {
	avg = new_avg;
}

int batter::get_obp() {
	return obp;
}

void batter::set_obp(int new_obp) {
	obp = new_obp;
}

int batter::get_slg() {
	return slg;
}

void batter::set_slg(int new_slg) {
	slg = new_slg;
}


//�s�b�`���[�̃N���X
class picher {
	string name;
	int baa;
	double so;

public:
	string get_name();
	void set_name(string new_name);

	int get_baa();
	void set_baa(int new_baa);

	double get_so();
	void set_so(double new_so);
};


//�s�b�`���[�N���X�̃����o�֐��̒�`
string picher::get_name() {
	return name;
}

void picher::set_name(string new_name) {
	name = new_name;
}

int picher::get_baa() {
	return baa;
}

void picher::set_baa(int new_baa) {
	baa = new_baa;
}

double picher::get_so() {
	return so;
}

void picher::set_so(double new_so) {
	so = new_so;
}


//�ΐ�񐔕��̗��������֐�
vector<int> generateRandomNumbers(int count) {
	random_device engine;
	mt19937 gen(engine());
	uniform_int_distribution<int> dis(1, 1000);

	vector<int> numbers;

	for (int i = 0; i < count; ++i) {
		int random_number = dis(gen);
		numbers.push_back(random_number);
	}

	return numbers;
}


//�ΐ팋�ʐ����֐�
void vs(batter batter1, picher picher1, int matchcount) {
	vector<int>numbers = generateRandomNumbers(matchcount);//��������
	int threshold1 = 250 + (batter1.get_avg() - 250) + (picher1.get_baa() - 250);
	int threshold2 = batter1.get_obp() - batter1.get_avg() + threshold1;
	int threshold3 = 1000 - (picher1.get_so() / 27) * 1000;

	double count1 = 0;
	double count2 = 0;
	double count3 = 0;
	double count4 = 0;

	int vsCount = 1;

	// �C�e���[�^���g���ăx�N�^�[�̗v�f�ɃA�N�Z�X
	vector<int>::iterator it;
	for (it = numbers.begin(); it != numbers.end(); ++it) {

		if (*it <= threshold1) {
			cout << "��" << vsCount << "�ŐȁF" << "�q�b�g" << endl;
			count1 += 1;
		}
		else if (*it > threshold1 && *it < threshold2) {
			cout << "��" << vsCount << "�ŐȁF" << "�l����" << endl;
			count2 += 1;
		}
		else if (*it >= threshold3) {
			cout << "��" << vsCount << "�ŐȁF" << "�O�U" << endl;
			count3 += 1;
		}
		else {
			cout << "��" << vsCount << "�ŐȁF" << "�A�E�g" << endl;
			count4 += 1;
		}

		vsCount++;

	}
	cout << endl;

	double result1 = count1 / (count1 + count3 + count4)*1000;
	int resultAVG = static_cast<int>(result1);

	cout << count1 + count2 + count3 + count4 << "�Ő�," << count1 + count3 + count4 << "�Ő�," << count1 << "����," << count3 << "�O�U," << count2 << "�l����." << endl;
	cout << "�ŗ��F." << resultAVG << endl;
	cout << endl;
}


//���͂��ꂽ�ŗ��Əo�ۗ��Ɣ�ŗ��̌��؂�����֐�
int checkInput1() {
	int value;
	do {
		cin >> value;
		if(value<0||value>1000){
			cout << "�s���Ȓl�ł�. 0�`1000�̐�������͂��Ă�������." << endl;
		}
	} while (value < 0 || value>1000);
	return value;
}


//���͂��ꂽ�D�O�U���̌��؂�����֐�
double checkInput2() {
	double value;
	do {
		cin >> value;
		if (value < 0 || value>27) {
			cout << "�s���Ȓl�ł�. 0�`27�̐�������͂��Ă�������." << endl;
		}
	} while (value < 0 || value>27);
	return value;
}


//���C���֐�
int main() {
	int i = 0;

	do {
		batter batter;//�o�b�^�[�Ɋւ���f�[�^�����ϐ�
		string a;
		int b, c, d;
		cout << "�o�b�^�[�̖��O����͂��Ă�������." << endl;
		cin >> a;
		cout << "�ŗ�����͂��Ă�������.(�����œ��́j" << endl;
		b = checkInput1();
		cout << "�o�ۗ�����͂��Ă�������.(�����œ��́j" << endl;
		c = checkInput1();
		cout << "���ŗ�����͂��Ă�������.(�����œ��́j" << endl;
		cin >> d;
		cout << endl;

		batter.set_name(a);
		batter.set_avg(b);
		batter.set_obp(c);
		batter.set_slg(d);

		picher picher;//�s�b�`���[�Ɋւ���f�[�^�����ϐ�
		string e;
		int f;
		double g;
		cout << "�s�b�`���[�̖��O����͂��Ă�������." << endl;
		cin >> e;
		cout << "��ŗ�����͂��Ă�������.(�����œ��́j" << endl;
		f = checkInput1();
		cout << "�D�O�U������͂��Ă�������." << endl;
		g = checkInput2();
		cout << endl;

		picher.set_name(e);
		picher.set_baa(f);
		picher.set_so(g);

		cout << "------------------------------------------" << endl;
		cout << "�o�b�^�[�̖��O�F" << batter.get_name() << endl;
		cout << "�ŗ��F." << batter.get_avg() << endl;
		cout << "�o�ۗ��F." << batter.get_obp() << endl;
		cout << "���ŗ��F." << batter.get_slg() << endl;
		cout << endl;

		cout << "�s�b�`���[�̖��O�F" << picher.get_name() << endl;
		cout << "��ŗ��F." << picher.get_baa() << endl;
		cout << "�D�O�U���F" << picher.get_so() << endl;
		cout << "------------------------------------------" << endl;
		cout << endl;;

		int matchcount;

		cout << "���Őȏ������܂����H�i�����œ��́j" << endl;
		cin >> matchcount;
		cout << endl;
		cout << "------------------------------------------" << endl;
		cout << matchcount << "�Őȏ����̌��ʂ̗\�z" << endl;
		vs(batter, picher, matchcount);
		cout << "------------------------------------------" << endl;
		cout << "�I�����܂����H�i�͂��F1, �������F0�j" << endl;
		cin >> i;
		cout << endl;
		cout << "------------------------------------------" << endl;
	} while (i == 0);

}