//
//  average_temp_2.cpp
//  coursera
//
//  Created by Денис Домашевич on 1/13/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <iostream>
#include <numeric>
#include <vector>

int main() {
    
    int n;
    std::cin >> n;
    
    std::vector<long long> temp(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> temp[i];
    }
    
    long long midTemp = std::accumulate(temp.begin(), temp.end(), 0LL) / n;
    
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(temp[i] > midTemp) cnt++;
    }
    
    std::cout << cnt << std::endl;
    for(int i = 0; i < n; ++i) {
        if(temp[i] > midTemp) std::cout << i << " ";
    }
    
    return 0;
    
}










