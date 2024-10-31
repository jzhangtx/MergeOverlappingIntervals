// MergeOverlappingIntervals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

bool InRange(const std::vector<int>& v, int n)
{
    if (n >= v[0] && n <= v[1])
        return true;

    return false;
}

std::vector<std::vector<int>> MergeIntervals(std::vector<std::vector<int>>& intervals)
{
    for (auto i = intervals.begin(); i != intervals.end(); ++i)
    {
        for (auto j = i + 1; j != intervals.cend();)
        {
            if (InRange(*j, (*i)[0]))
            {
                std::vector<int> v(2);
                v[0] = (*j)[0];
                if (InRange(*j, (*i)[1]))
                    v[1] = (*j)[1];
                else
                    v[1] = (*i)[1];
                (*i)[0] = v[0];
                (*i)[1] = v[1];
                j = intervals.erase(j);
            }
            else if (InRange(*i, (*j)[0]))
            {
                std::vector<int> v(2);
                v[0] = (*i)[0];
                if (InRange(*i, (*j)[1]))
                    v[1] = (*i)[1];
                else
                    v[1] = (*j)[1];
                (*i)[0] = v[0];
                (*i)[1] = v[1];
                j = intervals.erase(j);
            }
            else
                ++j;
        }
    }

    return intervals;
}

int main()
{
    while (true)
    {
        int count = 0;
        std::cout << "Number of intervals: ";
        std::cin >> count;
        if (count == 0)
            break;

        std::vector<std::vector<int>> vecVec;
        vecVec.reserve(count);

        for (int i = 0; i < count; ++i)
        {
            std::vector<int> vec(2);
            std::cin >> vec[0] >> vec[1];
            vecVec.push_back(std::move(vec));
        }

        MergeIntervals(vecVec);

        std::cout << "The merged intervals: " << std::endl;
        for (size_t i = 0; i < vecVec.size(); ++i)
        {
            if (i != 0)
                std::cout << ", ";
            std::cout << "{ " << vecVec[i][0] << ", " << vecVec[i][1] << " }";
        }
        std::cout << std::endl << std::endl;
    }
}
