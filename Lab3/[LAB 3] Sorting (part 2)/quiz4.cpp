#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxNumberOfPeople(vector<int> &rooms, vector<int> &people, int k)
{
    sort(rooms.begin(), rooms.end());
    sort(people.begin(), people.end());

    int i = 0, j = 0;
    int count = 0;
    int roomsSize = rooms.size();
    int peopleSize = people.size();

    while (i < roomsSize && j < peopleSize)
    {
        int lowerBound = people[j] - k;
        int upperBound = people[j] + k;

        if (rooms[i] >= lowerBound && rooms[i] <= upperBound)
        {
            count++;
            i++;
            j++;
        }
        else if (rooms[i] < lowerBound)
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return count;
}