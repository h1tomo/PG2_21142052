//Baseball Simulator ～It's SHOWTIME!～

#include <iostream>
#include <vector>
#include <random>
using namespace std;

//　クラス, 関数, イテレータを使いましょう. 


//バッターのクラス
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


//バッタークラスのメンバ関数の定義
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


//ピッチャーのクラス
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


//ピッチャークラスのメンバ関数の定義
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


//対戦回数分の乱数生成関数
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


//対戦結果生成関数
void vs(batter batter1, picher picher1, int matchcount) {
	vector<int>numbers = generateRandomNumbers(matchcount);//乱数生成
	int threshold1 = 250 + (batter1.get_avg() - 250) + (picher1.get_baa() - 250);
	int threshold2 = batter1.get_obp() - batter1.get_avg() + threshold1;
	int threshold3 = 1000 - (picher1.get_so() / 27) * 1000;

	double count1 = 0;
	double count2 = 0;
	double count3 = 0;
	double count4 = 0;

	int vsCount = 1;

	// イテレータを使ってベクターの要素にアクセス
	vector<int>::iterator it;
	for (it = numbers.begin(); it != numbers.end(); ++it) {

		if (*it <= threshold1) {
			cout << "第" << vsCount << "打席：" << "ヒット" << endl;
			count1 += 1;
		}
		else if (*it > threshold1 && *it < threshold2) {
			cout << "第" << vsCount << "打席：" << "四死球" << endl;
			count2 += 1;
		}
		else if (*it >= threshold3) {
			cout << "第" << vsCount << "打席：" << "三振" << endl;
			count3 += 1;
		}
		else {
			cout << "第" << vsCount << "打席：" << "アウト" << endl;
			count4 += 1;
		}

		vsCount++;

	}
	cout << endl;

	double result1 = count1 / (count1 + count3 + count4)*1000;
	int resultAVG = static_cast<int>(result1);

	cout << count1 + count2 + count3 + count4 << "打席," << count1 + count3 + count4 << "打数," << count1 << "安打," << count3 << "三振," << count2 << "四死球." << endl;
	cout << "打率：." << resultAVG << endl;
	cout << endl;
}


//入力された打率と出塁率と被打率の検証をする関数
int checkInput1() {
	int value;
	do {
		cin >> value;
		if(value<0||value>1000){
			cout << "不正な値です. 0～1000の整数を入力してください." << endl;
		}
	} while (value < 0 || value>1000);
	return value;
}


//入力された奪三振率の検証をする関数
double checkInput2() {
	double value;
	do {
		cin >> value;
		if (value < 0 || value>27) {
			cout << "不正な値です. 0～27の整数を入力してください." << endl;
		}
	} while (value < 0 || value>27);
	return value;
}


//メイン関数
int main() {
	int i = 0;

	do {
		batter batter;//バッターに関するデータを持つ変数
		string a;
		int b, c, d;
		cout << "バッターの名前を入力してください." << endl;
		cin >> a;
		cout << "打率を入力してください.(整数で入力）" << endl;
		b = checkInput1();
		cout << "出塁率を入力してください.(整数で入力）" << endl;
		c = checkInput1();
		cout << "長打率を入力してください.(整数で入力）" << endl;
		cin >> d;
		cout << endl;

		batter.set_name(a);
		batter.set_avg(b);
		batter.set_obp(c);
		batter.set_slg(d);

		picher picher;//ピッチャーに関するデータを持つ変数
		string e;
		int f;
		double g;
		cout << "ピッチャーの名前を入力してください." << endl;
		cin >> e;
		cout << "被打率を入力してください.(整数で入力）" << endl;
		f = checkInput1();
		cout << "奪三振率を入力してください." << endl;
		g = checkInput2();
		cout << endl;

		picher.set_name(e);
		picher.set_baa(f);
		picher.set_so(g);

		cout << "------------------------------------------" << endl;
		cout << "バッターの名前：" << batter.get_name() << endl;
		cout << "打率：." << batter.get_avg() << endl;
		cout << "出塁率：." << batter.get_obp() << endl;
		cout << "長打率：." << batter.get_slg() << endl;
		cout << endl;

		cout << "ピッチャーの名前：" << picher.get_name() << endl;
		cout << "被打率：." << picher.get_baa() << endl;
		cout << "奪三振率：" << picher.get_so() << endl;
		cout << "------------------------------------------" << endl;
		cout << endl;;

		int matchcount;

		cout << "何打席勝負しますか？（整数で入力）" << endl;
		cin >> matchcount;
		cout << endl;
		cout << "------------------------------------------" << endl;
		cout << matchcount << "打席勝負の結果の予想" << endl;
		vs(batter, picher, matchcount);
		cout << "------------------------------------------" << endl;
		cout << "終了しますか？（はい：1, いいえ：0）" << endl;
		cin >> i;
		cout << endl;
		cout << "------------------------------------------" << endl;
	} while (i == 0);

}