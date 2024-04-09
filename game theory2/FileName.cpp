#include<iostream>
#include<cmath>
#include<vector>
#include<ctime>

using namespace std; 

int random_tactic(vector<double> p) 
{
	vector<double> segments(p.size()); //вектор отрезков вероятностей
	double sum = 0; 
	for (int i = p.size()-1; i >= 0; --i) //тут отрезок равный 100 делется на отрезки, равные вероятности
	{
		segments[i] = 100 - sum; 
		sum += p[i]; 
	}
	int a = rand()%100; // если это число попадает в n - й отрезок, то выбирается стратегия n
	for (int i = 0; i < p.size(); ++i)
	{
		if (a >= 1 && a < segments[0]) 
			return 1;
		else
			for (int j = 1; j < p.size(); ++j)
				if (a <= segments[j] && a > segments[j - 1])
					return j + 1;
	}

}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int p1_size, p2_size; 
	cout << "Введите количество стратегий игрока 1 и игрока 2" << endl; 
	cin >> p1_size >> p2_size; 
	vector<double> p1(p1_size);
	vector<double> p2(p2_size);
	cout << "Введите вероятности использования стратегий 1 игрока(в процентах)" << endl; 
	for (int i = 0; i < p1_size; ++i)
		cin >> p1[i];
	cout << "Выборы первого игрока. 100 игр:" << endl;
	for (int i = 0; i < 100; ++i) 
	{
		cout << random_tactic(p1) << " ";
	} 
	cout << endl << "Введите вероятности использования стратегий 2 игрока(в процентах)" << endl;
	for (int i = 0; i < p1_size; ++i)
		cin >> p2[i];
	cout << "Выборы второго игрока. 100 игр:" << endl;
	for (int i = 0; i < 100; ++i)
	{
		cout<< random_tactic(p2) << " ";
	}
}