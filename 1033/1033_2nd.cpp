#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

struct cell
{
    int x;
    int y;
};

int main() {


    int wallsCount = 0;
    const int wallSquare = 9;
	char in;
    
    std::queue<cell> myQ;
	std::vector<char> labirint;
	std::vector<bool> mask;
    
    int size;
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
    
    myQ.push(EntryOne);
    myQ.push(EntryTwo);
    
    while(!myQ.empty())
    {
        cell pivot = myQ.front();		
        
        if(pivot.x < 0 ||
           pivot.x >= size ||
           pivot.y < 0 ||
           pivot.y >= size ||
           labirint[size * pivot.y + pivot.x] == '#')
        {
            wallsCount++;
        }
        else if(!mask[size * pivot.y + pivot.x])
        {
			mask[size * pivot.y + pivot.x] = true;

            myQ.push({pivot.x - 1, pivot.y});
            myQ.push({pivot.x + 1, pivot.y});
            myQ.push({pivot.x, pivot.y - 1});
            myQ.push({pivot.x, pivot.y + 1});
        }

        myQ.pop();
    }
    
    wallsCount -= 4;
    
    std::cout << wallsCount * wallSquare;
    
    return 0;
}
