//
//  main.cpp
//  1
//
//  Created by Alexey Karpov on 11.04.17.
//  Copyright © 2017 Alexey Karpov. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "Container.h"


using namespace std;

int main() {
    vector<int> b;
    Vector<int> a;
    for (int i = 0; i <= 20; i++)
        a.push_back(i * i);
    for (Vector<int>::Iterator<int> i = a.begin(); i != a.end(); i++)
    {
        cout << *i << endl;
    }
    a.insert(6, 0);
    for (Vector<int>::Iterator<int> i = a.begin(); i != a.end(); ++i)
    {
        cout << *i << endl;
    }
    a.clear();
    return 0;
}
