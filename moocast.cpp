// Moocast (C++)
// Cindy Wang 
// Contest: USACO 2016 December Contest, Silver

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct cow
{
    int x;
    int y;
    int p;
    int casted;
};

int N;
cow cows[200];
int castcount, maxcastcount = 0;

bool isReachable (cow a, cow b) // can cow a reach cow b
{
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    if (dx * dx + dy * dy < a.p * a.p)
        return true;
    else
        return false;
}

void floodfill(int a)
{
    for (int i = 0; i < N; i++)
    {
        // determine next cow
        if (a != i)
        {
            if (cows[i].casted != 1)
            {
                if (isReachable(cows[a], cows[i]))
                {
                    cows[i].casted = 1;
                    floodfill(i);
                }
            }
        }
    }
}

int main()
{
    ofstream fout ("moocast.out");
    ifstream fin ("moocast.in");

    // read in data
    fin >> N;
    for (int i = 0; i < N; i++)
    {
        fin >> cows[i].x >> cows[i].y >> cows[i].p;
    }

    // floodfill
    for (int i = 0; i < N; i++)
    {
        castcount = 0;
        cows[i].casted = 1;
        floodfill(i);
        for (int j = 0; j < N; j++)
        {
            if (cows[j].casted == 1)
            {
                castcount++;
                cows[j].casted = 0;
            }
        }
        maxcastcount = max(castcount, maxcastcount);
    }

    fout << maxcastcount << endl;

    return 0;
}
