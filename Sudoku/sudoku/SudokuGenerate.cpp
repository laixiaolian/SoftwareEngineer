#include<iostream>
#include<cstdio>
#include<string>
#include"SudokuGenerate.h"
#include<time.h>
using namespace std;

//ÿ�������µ�����֮ǰ����ʼ����ά����
void SudokuGenerate::init()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			num[i][j] = 0;
		}
	}
}

//ÿ�������µ�����֮ǰ��������һ���µ�һά���飬������1-9��˳�����
//֮��������9*9������ÿ��ʱ������Ӹ�һά�����г�ȡԪ��
void SudokuGenerate::initArray()
{
	int array[9] = { 0 };
	count[11] = { 0 };
	int h=0;
	for(h=0;h<9;)
	{
		int temp = rand() % 9;
		//�жϴ˴����ɵ�temp�Ƿ��Ѿ��ڸ�һά������
		if (array[temp] == 0)
		{
			//��Ϊtemp=rand()%9���ɵ���0-8�������������Ҫ��һ
			count[h] = temp+1;

			//������������Ѿ�������һά�����С�
			array[temp] = 1;
			h++;
		}
	}

	//���ɵ�һά����
	/*for (int p = 0; p < 9; p++)
	{
		cout << count[p] << " ";
	}*/
	//cout << endl << endl;
}

//���û��ݷ���������
bool SudokuGenerate::generate(int k)
{
	int i = k / 9;
	int j = k % 9;
	if (k == 81)
	{
		//����һ����������ӡ
		print();
		cout << endl;
		//printf("\n");
		return true;
	}

	//���9*9������λ��(i,j)�Ѿ�����������
	else if (num[i][j] != 0)
	{
		//������һλ�õ�����
		if (generate(k + 1))
		{
			return true;
		}
	}

	//�Կ�λ(i,j)��������
	else
	{
		//����ÿ�е����ִ�һά�����������ȡ
		for (int l = 1; l <= 9;l++)
		{
			int temp = rand() % 9;
			num[i][j] = count[temp];

			//�ж����������Ƿ�Ϸ�
			if (IsRightPlace(num[i][j], i, j))
			{
				if (generate(k + 1)) 
				{
					return true;
				}
			}
		}

		//���Ϸ�����λ��(i,j)����Ϊ0������
		num[i][j] = 0;
	}
	return false;
}

//�ж�����������Ƿ�Ϸ�
bool SudokuGenerate::IsRightPlace(int number, int row, int col)
{
	int temp = number;

	//ͬ�в�ͬ�����Ƿ������֮��ͬ������
	for (int i = 0; i < 9; i++)
	{
		if (i != row&&num[i][col] == temp)
		{
			return false;
		}
	}

	//ͬ�в�ͬ�������Ƿ������֮��ͬ������
	for (int i = 0; i < 9; i++)
	{
		if (i != col&&num[row][i] == temp)
		{
			return false;
		}
	}

	//�ж�3*3�Ź����Ƿ�Ϸ�
	int m = row / 3;
	m *= 3;
	int n = col / 3;
	n *= 3;
	for (int i = m; i < m+3; i++)
	{
		for (int j = n; j < n+3; j++)
		{
			if (i != row&&j != col&&num[i][j] == temp)
			{
				return false;
			}
		}
	}
	return true;
}

//��ӡ����
void SudokuGenerate::print()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << num[i][j] << " ";
			//printf("%d ", num[i][j]);
		}
		cout << endl;
		//printf("\n");
	}
}


void SudokuGenerate::set(int number)
{
	init();
	num[0][0] = number;
}