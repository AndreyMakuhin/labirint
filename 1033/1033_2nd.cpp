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
    freopen("inputs.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
   
    int wallsCount = 0;
    const int wallSquare = 9;
    
    std::queue<cell> myQ;
    
    int size;
    std::cin >> size;
    
    cell EntryOne = {0,0};
    cell EntryTwo ={size -1, size - 1};
    
    char *labirint = new char[size*size];
    bool **mask = new bool*[size];
    for(int i = 0; i < size; i++)
    {
        mask[i] = new bool[size];
        for(int j = 0; j < size; j++)
        {
            mask[i][j] = false;
        }
    }
    
    for(int i = 0; i < size*size; i++)
    {
        std::cin >> labirint[i];
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
        else if(!mask[pivot.x][pivot.y])
        {
            myQ.push({pivot.x - 1, pivot.y});
            myQ.push({pivot.x + 1, pivot.y});
            myQ.push({pivot.x, pivot.y - 1});
            myQ.push({pivot.x, pivot.y + 1});
        }
        
        mask[pivot.x][pivot.y] = true;
        
        myQ.pop();
    }
    
    wallsCount -= 4;
    
    std::cout << wallsCount * wallSquare;
    
    return 0;
}
