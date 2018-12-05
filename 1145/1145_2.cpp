#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>

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

struct stepCell
{
    cell point;
    int step;
};

int n, m;
int cellsCount = 0;
vector<char> labirint;
vector<int> maskI;
vector<bool> maskB;
vector<cell> tupiks;
queue<stepCell> myQ;

vector<vector<int>> grafTupik;

int FindTupiks(cell next);

int CalculateDistance(cell start, cell end);

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif

	cin >> n >> m;	

	char input;
	while (cin >> input)//получаем ввод
	{
        if(input == '.')
            cellsCount++;
		labirint.push_back(input);
		maskI.push_back(-1);
		maskB.push_back(false);
	}

	cell startFind{1,1};
    bool finded = false;
	for (int y = 1; y < m - 1; y++)//ищем стартовую точку
	{
		for (int x = 1; x < n - 1; x++)
		{
			startFind = { x,y };
			if (labirint[y * n + x] == '.')
			{
                finded = true;
				break;
			}
		}
        if(finded) break;
	}
    
	int tup_count = FindTupiks(startFind);
    
    for(int x = 0; x < tupiks.size(); x++)
    {
        grafTupik.push_back(vector<int>());
        for(int y = 0; y < tupiks.size(); y++)
        {
            grafTupik[x].push_back(0);
        }
    }
    
    int maxLenght = 0;
    for (int start = 0; start < tupiks.size(); start++)
    {
        for (int end = 0; end < tupiks.size(); end++)
        {
            if(start != end)
            {
                int lenght = CalculateDistance(tupiks[start], tupiks[end]);
                grafTupik[start][end] = lenght;
                grafTupik[end][start] = lenght;
                if(lenght > maxLenght)
                {
                    maxLenght = lenght;
                }
            }
        }
    }
    
    cout << maxLenght;

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
	
	int continues = left + right + up + down;

	if (continues == 0 || continues == cellsCount - 1)
	{
		tupiks.push_back(next);
	}

	return continues + 1;
}

int CalculateDistance(cell start, cell end)
{
    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
        {
            maskI[y * n + x] = -1;
        }
    }

    myQ.push({start, 0});
    int step = 0;
    
    while(!myQ.empty())
    {
        cell recent = myQ.front().point;
        int step = myQ.front().step;
        
        if(labirint[recent.y * n + recent.x] == '#' || maskI[recent.y * n + recent.x] > 0)
        {
            myQ.pop();
            continue;
        }
        
        maskI[recent.y * n + recent.x] = step;
        
        if(recent == end)
        {
            break;
        }
        
        myQ.push({{recent.x + 1, recent.y}, step + 1});
        myQ.push({{recent.x - 1, recent.y}, step + 1});
        myQ.push({{recent.x, recent.y + 1}, step + 1});
        myQ.push({{recent.x, recent.y - 1}, step + 1});
       
        myQ.pop();
    }
    
    while(!myQ.empty())
    {
        myQ.pop();
    }
    
    return maskI[end.y * n + end.x];
}

/*for (int y = 0; y < m; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cout << labirint[y * n + x];
		}
		cout << endl;
	}*/
