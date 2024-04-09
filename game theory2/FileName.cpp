#include<iostream>
#include<cmath>
#include<vector>
#include<ctime>

using namespace std; 

int random_tactic(vector<double> p) 
{
	vector<double> segments(p.size()); //������ �������� ������������
	double sum = 0; 
	for (int i = p.size()-1; i >= 0; --i) //��� ������� ������ 100 ������� �� �������, ������ �����������
	{
		segments[i] = 100 - sum; 
		sum += p[i]; 
	}
	int a = rand()%100; // ���� ��� ����� �������� � n - � �������, �� ���������� ��������� n
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
	cout << "������� ���������� ��������� ������ 1 � ������ 2" << endl; 
	cin >> p1_size >> p2_size; 
	vector<double> p1(p1_size);
	vector<double> p2(p2_size);
	cout << "������� ����������� ������������� ��������� 1 ������(� ���������)" << endl; 
	for (int i = 0; i < p1_size; ++i)
		cin >> p1[i];
	cout << "������ ������� ������. 100 ���:" << endl;
	for (int i = 0; i < 100; ++i) 
	{
		cout << random_tactic(p1) << " ";
	} 
	cout << endl << "������� ����������� ������������� ��������� 2 ������(� ���������)" << endl;
	for (int i = 0; i < p1_size; ++i)
		cin >> p2[i];
	cout << "������ ������� ������. 100 ���:" << endl;
	for (int i = 0; i < 100; ++i)
	{
		cout<< random_tactic(p2) << " ";
	}
}