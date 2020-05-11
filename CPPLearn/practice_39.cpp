#include <iostream>
using namespace std;
#include <vector>

/*
���������������ֱ��ʾ��λ�����������������
��������Ӧ�����飬���е�1��ʾǽ�ڣ�0��ʾ�����ߵ�·�����ݱ�֤��Ψһ��,�������ж�����������Թ�ֻ��һ��ͨ����
*/

struct Point
{
	int raw;
	int col;
};

void findPath(vector<vector<int>> &matrix, Point point, vector<Point> &ret, vector<vector<Point>> &path, int &raw, int &col);
int main()
{
	int col = 0, raw = 0;
	while (cin >> raw)
	{
		cin >> col;
		vector<vector<int>> matrix;
		vector<int> colData;
		for (int i = 0; i < raw; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				int temp = 0;
				cin >> temp;
				colData.push_back(temp);
			}
			matrix.push_back(colData);
			colData.clear();
		}
		Point p;
		p.col = 0; p.raw = 0;
		vector<Point> ret;
		vector<vector<Point>> path;
		findPath(matrix, p, ret, path, raw, col);
		int min = 200,rember=0;
		for (int i = 0; i < (int)path.size(); ++i)
		{
			if (min > (int)path[i].size())
			{
				rember = i;
				min = path[i].size();
			}
		}
		//���ո�ʽ���
		for (int i = 0; i < (int)path[rember].size(); ++i)
		{
			cout << '(' << path[rember][i].raw << ',' << path[rember][i].col << ')' << endl;
		}

	}
	return 0;
}

void findPath(vector<vector<int>> &matrix, Point point,vector<Point> &ret, vector<vector<Point>> &path,int &raw,int &col)
{
	if (point.raw == raw-1 && point.col == col-1)
	{
		ret.push_back(point);
		path.push_back(ret);
		ret.erase(ret.end() - 1);
		return;
	}
	ret.push_back(point);
	matrix[point.raw][point.col] = 1;
	if (point.raw-1 >=0 && point.raw - 1 < raw && point.col >=0 &&point.col < col && matrix[point.raw-1][point.col] == 0)
	{
		point.raw = point.raw - 1;
		findPath(matrix, point, ret, path, raw, col);
	}
	if (point.raw + 1 >= 0 && point.raw + 1 < raw && point.col >=0 && point.col < col && matrix[point.raw + 1][point.col] == 0)
	{
		point.raw = point.raw + 1;
		findPath(matrix, point, ret, path, raw, col);
	}
	if (point.raw >= 0 && point.raw < raw && point.col - 1 >= 0 && point.col - 1 < col && matrix[point.raw][point.col - 1] == 0)
	{
		point.col = point.col - 1;
		findPath(matrix, point, ret, path, raw, col);
	}
	if (point.raw >= 0 && point.raw < raw && point.col + 1 >= 0 && point.col + 1 < col && matrix[point.raw][point.col+1] == 0)
	{
		point.col = point.col + 1;
		findPath(matrix, point, ret, path, raw, col);
	}
	matrix[point.raw][point.col] = 0;
	ret.erase(ret.end() - 1);

}