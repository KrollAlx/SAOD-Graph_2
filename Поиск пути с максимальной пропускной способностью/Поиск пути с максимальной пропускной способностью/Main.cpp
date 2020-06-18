#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

const int inf = INT32_MIN;

int searchMaxWeight(vector<vector<int>> graph, int begin, int end, int N) 
{
	vector<vector<int>> s(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (graph[i][j] > graph[j][i])
			{
				s[i][j] = graph[i][j] - graph[j][i];
			}
			else
			{
				s[i][j] = inf;
			}
		}
	}
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			if (i != k)
			{
				for (int j = 0; j < N; j++)
				{
					if (j != i)
					{
						if (s[i][j] < min(s[i][k], s[k][j]))
						{
							s[i][j] = min(s[i][k], s[k][j]);
						}
					}
				}
			}
		}
	}
	return s[begin - 1][end - 1];
}

int main()
{
	setlocale(LC_ALL, "ru");

	vector<vector<int>> graph = { {0,2,6,0,0,0},
								  {0,0,0,3,5,0},
								  {0,0,0,2,0,0},
								  {0,0,0,0,0,3},
								  {0,0,0,4,0,7},
								  {0,0,0,0,0,0} };
	int begin;
	cout << "¬ведите начальный пункт: ";
	cin >> begin;
	int end;
	cout << "¬ведите конечный пункт: ";
	cin >> end;

	int maxWeight = searchMaxWeight(graph, begin, end, graph[0].size());
	cout << "ћаксимальный вес, который может быть транспортирован в сети из пункта "
		<< begin << " в пункт " << end << " равен " << maxWeight << endl;

	system("pause");
	return 0;
}