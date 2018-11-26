#include <iostream>
#include <stdio.h>
#include <vector>

struct cell
{
    int x;
    int y;
};

std::vector<char> labirint;
std::vector<bool> mask;

int CountingWalls(cell next);

int wallsCount = 0;
int size;


int main() {
    
    const int wallSquare = 9;
	char in;     
    
    std::cin >> size;
    
    cell EntryOne = {0,0};
    cell EntryTwo ={size - 1, size - 1};  

    for(int i = 0; i < size*size; i++)
    {  		
		mask.push_back(false);
    }    
    
	while (std::cin >> in)
	{
		labirint.push_back(in);
	}  
    
	wallsCount += CountingWalls(EntryOne);
	wallsCount += CountingWalls(EntryTwo);    
    
    wallsCount -= 4;
    
    std::cout << wallsCount * wallSquare;
    
    return 0;
}

int CountingWalls(cell next)
{	
	if (next.x < 0 ||
		     next.x >= size ||
		     next.y < 0 ||
		     next.y >= size ||
		     labirint[size * next.y + next.x] == '#')
	{
		return 1;
	}
	else if (!mask[size * next.y + next.x])
	{
		mask[size * next.y + next.x] = true;

		return
		CountingWalls({ next.x - 1, next.y }) + 
		CountingWalls({ next.x + 1, next.y }) +
		CountingWalls({ next.x,     next.y - 1 }) + 
		CountingWalls({ next.x,     next.y + 1 });
	}
	else
	{
		return 0;
	}
}
