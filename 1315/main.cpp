#pragma comment(linker, "/STACK:67108864")

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cell
{
    int x;
    int y;
    int air;
};

int width;
int height;
int dist;
bool hasEscape = false;

vector<char> map;
queue<cell> myQ;

void Flood(cell in);
void Escape(cell start);
void CleanMap();
void CleanQueue();

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    
    int x;
    int y;
    
    cin >> width >> height >> x >> y >> dist;
    
    char inp;
    for(int i = 0; i < width * height; i++)
    {
        cin >> inp;
        map.push_back(inp);
    }
    
    for (int i = 0; i < width; i++)
    {
        if(map[i] == '.')
        {
            Flood({i + 1, height, -1});
        }
    }
    
    ///////дебажный вывод
    /*
    printf("%d %d %d %d %d\n", width, height, x, y, dist);

    for(int i = 0; i < width*height; i++)
    {
        cout << map[i];
        if((i + 1) % width == 0)
        {
            cout << "\n";
        }
    }
    cout << "\n";
    */
    ////////////
    
    Escape({x,y, dist});
    
    if(hasEscape)
        cout << "Can be rescued by himself\n";
    else
        cout << "Rescue operation required\n";
    
    return 0;
}

void Flood( cell in)
{
    myQ.push(in);
    
    while(!myQ.empty())
    {
        cell recent = myQ.front();
        if(map[(height - recent.y) * width + recent.x - 1] == '.')
        {
            map[(height - recent.y) * width + recent.x - 1] = 'o';
            
            myQ.push({recent.x, recent.y - 1, -1});
            myQ.push({recent.x - 1, recent.y, -1});
            myQ.push({recent.x + 1, recent.y, -1});
        }
        
        myQ.pop();
    }
}

void Escape(cell start)
{
    if(!hasEscape)
    {
        myQ.push(start);
        
        vector<cell> pockets;
        
        while(!myQ.empty() && !hasEscape)
        {
            cell recent = myQ.front();
            char& inCell = map[(height - recent.y) * width + recent.x - 1];
            if(recent.air == dist)
                CleanMap();
            
            if(recent.y > height)
            {
                hasEscape = true;
                break;
            }
            if(inCell == '.' && !hasEscape)
            {
                inCell = 'z';
                pockets.push_back({recent.x, recent.y, dist});
            }
            if(inCell == 'o' && recent.air > 0 && !hasEscape)
            {
                inCell = 'z';
                
                if(recent.y > 1)
                    myQ.push({recent.x, recent.y - 1, recent.air - 1});
                myQ.push({recent.x, recent.y + 1, recent.air - 1});
                if(recent.x < width)
                    myQ.push({recent.x + 1, recent.y, recent.air - 1});
                if(recent.x > 1)
                    myQ.push({recent.x - 1, recent.y, recent.air - 1});
            }
            myQ.pop();
            
            if(myQ.empty() && !pockets.empty())
            {
                for(cell c : pockets)
                {
                    myQ.push(c);
                }
                pockets.clear();
            }
        }
    }
    
    CleanMap();
    
}

void CleanMap()
{
    for(int i = 0; i < width*height; i++)
    {
        if(map[i] == 'z')
           {
               map[i] = 'o';
           }
    }
}

void CleanQueue()
{
    while(myQ.size() > 0)
    {
        myQ.pop();
    }
}
