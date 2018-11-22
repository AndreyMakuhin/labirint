//
//  main.cpp
//  stones
//
//  Created by Андрей Макухин on 22.11.2018.
//  Copyright © 2018 Андрей Макухин. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> stones;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    
    int n;
    int val;
    std::cin >> n;
    
    while (std::cin >> val)
    {
        stones.push_back(val);
    }
    
    std::sort(stones.begin(), stones.end());
    
    
    
    
    return 0;
}
