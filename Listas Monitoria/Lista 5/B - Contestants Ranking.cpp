#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <set>
using namespace std;

string x[101];
string y[101];
string z[101];

int main()
{
    int T, N;
    scanf("%d", &T);
    while(T--)
    {
        map<string, int> members;
        set<string> unrankedMembers, rankedMembers[101];
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            cin >> x[i] >> y[i] >> z[i];
        }
        members["Ahmad"] = 1;
        rankedMembers[0].insert("Ahmad");
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (rankedMembers[i].count(x[j]) == 1)
                {
                    if (members[y[j]] == 0)
                    {
                        members[y[j]] = 1;
                        rankedMembers[i + 1].insert(y[j]);
                    }
                    if (members[z[j]] == 0)
                    {
                        members[z[j]] = 1;
                        rankedMembers[i + 1].insert(z[j]);
                    }
                }
                if (rankedMembers[i].count(y[j]) == 1)
                {
                    if (members[x[j]] == 0)
                    {
                        members[x[j]] = 1;
                        rankedMembers[i + 1].insert(x[j]);
                    }
                    if (members[z[j]] == 0)
                    {
                        members[z[j]] = 1;
                        rankedMembers[i + 1].insert(z[j]);
                    }
                }
                if (rankedMembers[i].count(z[j]) == 1)
                {
                    if (members[x[j]] == 0)
                    {
                        members[x[j]] = 1;
                        rankedMembers[i + 1].insert(x[j]);
                    }
                    if (members[y[j]] == 0)
                    {
                        members[y[j]] = 1;
                        rankedMembers[i + 1].insert(y[j]);
                    }
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (members[x[i]] == 0)
            {
                unrankedMembers.insert(x[i]);
            }
            if (members[y[i]] == 0)
            {
                unrankedMembers.insert(y[i]);
            }
            if (members[z[i]] == 0)
            {
                unrankedMembers.insert(z[i]);
            }
            members[x[i]] = 1;
            members[y[i]] = 1;
            members[z[i]] = 1;
        }

        cout << members.size() << endl;
        set<string>::iterator n;
        for (int i = 0; i <= N; i++)
        {
            if (rankedMembers[i].size() == 0)
            {
                break;
            }
            else
            {
                for (n = rankedMembers[i].begin(); n != rankedMembers[i].end(); ++n)
                {
                    cout << *n << " " << i << endl;
                }
            }
        }
        for (n = unrankedMembers.begin(); n != unrankedMembers.end(); ++n)
        {
            cout << *n << " undefined\n";
        }
    }

    return 0;
}