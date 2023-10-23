#include <iostream>
#include <stdio.h>
#include <vector>

int main()
{
    using std::vector;
    vector<int> array = { 0, 1, 2, 3 };
    int ilength = array.size();
    array.push_back(4);

    return 0;
}
