# define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <stdio.h>
#include <queue>

struct cell
{
    int x;
    int y;
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
   
    int wallsCount = 0;
    const int wallSquare = 9;
    
    std::queue<cell> myQ;
    
    int size;
    std::cin >> size;
    
    cell EntryOne = {0,0};
    cell EntryTwo ={size -1, size - 1};
    
    char *labirint = new char[size*size];
    bool *mask = new bool[size * size];    
    
    for(int i = 0; i < size*size; i++)
    {
		std::cin >> labirint[i];
    }	
    
	for (int i = 0; i < size*size; i++)
	{
		mask[i] = false;
	}

    myQ.push(EntryOne);
    mask[EntryOne.y * size + EntryOne.x] = true;
    myQ.push(EntryTwo);
    mask[EntryTwo.y * size + EntryTwo.x]=true;
    
    while(!myQ.empty())
    {
        cell pivot = myQ.front();
        
        //left
        if(pivot.x - 1 >= 0)
        {
            if(labirint[size * pivot.y + pivot.x - 1] != '#')
            {
                if(!mask[pivot.y * size + pivot.x - 1])
                {
                    myQ.push({pivot.x - 1, pivot.y});
                    mask[pivot.y * size + pivot.x - 1] = true;
                }
            }
            else
            {
                wallsCount++;
            }
        }
        else
        {
            wallsCount++;
        }
        //~left
        
        //rigth
        if(pivot.x + 1 < size)
        {
            if(labirint[size * pivot.y + pivot.x + 1] != '#')
            {
                if(!mask[pivot.y * size + pivot.x + 1])
                {
                    myQ.push({pivot.x + 1, pivot.y});
                    mask[pivot.y * size + pivot.x + 1] = true;
                }
            }
            else
            {
                wallsCount++;
            }
        }
        else
        {
            wallsCount++;
        }
        //~right
        
        //up
        if(pivot.y - 1 >= 0)
        {
            if(labirint[size * (pivot.y - 1) + pivot.x] != '#')
            {
                if(!mask[(pivot.y - 1) * size + pivot.x])
                {
                    myQ.push({pivot.x, pivot.y - 1});
                    mask[(pivot.y - 1) * size + pivot.x] = true;
                }
            }
            else
            {
                wallsCount++;
            }
        }
        else
        {
            wallsCount++;
        }
        //~up
        
        //down
        if(pivot.y + 1 < size )
        {
            if(labirint[size * (pivot.y + 1) + pivot.x] != '#')
            {
                if(!mask[(pivot.y + 1) * size + pivot.x])
                {
                    myQ.push({pivot.x , pivot.y + 1});
                    mask[(pivot.y + 1) * size + pivot.x] = true;
                }
            }
            else
            {
                wallsCount++;
            }
        }
        else
        {
            wallsCount++;
        }
        //~down
        
        myQ.pop();    
	  
    }
    
    wallsCount -= 4;

	int output = wallsCount * wallSquare;
    
    std::cout <<output;	
    
    return 0;
}
