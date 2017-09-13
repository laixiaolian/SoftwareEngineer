#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\sudoku\SudokuGenerate.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SudokuTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
			SudokuGenerate sudoku;
			//��������һ�е�һ����Ϊ3
			sudoku.set(3);

			
			//��һ�е�������������3����ʱӦ��return false;
			bool test1 = sudoku.IsRightPlace(3, 0, 2);

			//�����е�һ����������3����ʱӦ��return false;
			bool test2 = sudoku.IsRightPlace(3, 2, 0);

			//�ڶ��еڶ�����������3����ʱ3*3�Ź��������ظ����֣�return false;
			bool test3 = sudoku.IsRightPlace(3, 1, 1);

			//�ڵڶ��е�������������3���������ж�����������ͻ��return true;
			bool test4 = sudoku.IsRightPlace(3, 1, 6);
			
			Assert::IsTrue(test1 == false);
			Assert::IsTrue(test2 == false);
			Assert::IsTrue(test3 == false);
			Assert::IsTrue(test4 == true);
		}

	};
}