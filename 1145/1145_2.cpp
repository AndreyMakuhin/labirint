#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

struct cell
{
	int x;
	int y;
	bool operator==(cell other)
	{
		return this->x == other.x && this->y == other.y;
	}
};

int n, m;
vector<char> labirint;
vector<int> maskI;
vector<bool> maskB;
vector<cell> tupiks;

int FindTupiks(cell next);


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif

	cin >> n >> m;	

	char input;
	while (cin >> input)
	{
		labirint.push_back(input);
		maskI.push_back(-1);
		maskB.push_back(false);
	}

	cell startFind{1,1};
	for (int y = 1; y < m - 1; y++)
	{
		for (int x = 1; x < n - 1; x++)
		{
			startFind = { x,y };
			if (labirint[y * n + x] == '.')
			{
				break;
			}
		}
	}

	int tup_count = FindTupiks(startFind);	

	cout << "tupiks " << tup_count << endl;
			
	for (cell c : tupiks)
	{
		cout << c.x << " " << c.y << endl;
	}


	system("Pause");



	return 0;
}

int FindTupiks(cell next)
{
	if (labirint[next.y * n + next.x] == '#' || maskB[next.y * n + next.x])
	{
		return 0;
	}

	maskB[next.y * n + next.x] = true;
	
	int left = FindTupiks({next.x - 1, next.y});
	int right = FindTupiks({ next.x + 1, next.y });
	int up = FindTupiks({ next.x, next.y - 1 });
	int down = FindTupiks({ next.x, next.y + 1 });

	int cellVal = 1;
	int continues = left + right + up + down;

	if (continues == 0)
	{
		tupiks.push_back(next);
	}

	return cellVal + continues;
}

/*for (int y = 0; y < m; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cout << labirint[y * n + x];
		}
		cout << endl;
	}*/