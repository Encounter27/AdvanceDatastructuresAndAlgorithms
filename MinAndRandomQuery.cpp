#include <iostream>
#include <list>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

typedef list<char> List;
typedef list<char>::iterator It;
typedef vector<It> vec;

void printList(const List& l)
{
    for(auto each : l)
    {
        cout << '[' << each << ']' << "->";
    }
    cout << "[NULL]";
}

char getRandom(vec& R, List& l, int& start, int& end)
{
    int pos = start + rand()%(end - start + 1);

    char ch = *R[pos];
    l.erase(R[pos]);
    R[pos] = R[end];
    end --;

    return ch;
}

char getMin(vec& R, List& l, int& start, int& end)
{
    char ch = l.front();

    l.erase(R[start]);
    start ++;

    return ch;
}

int main() {
    srand (time(NULL));
    List l;
    vec R;
    string s = "GEEKSFORGEEKS";
    std::sort(s.begin(), s.end());

    for(int i = 0; i < s.size(); ++i)
    {
        l.push_back(s[i]);
    }
    for(It each = l.begin(); each != l.end(); ++each)
        R.push_back(each);

    int start = 0, end = s.size() - 1;

    for(int i = 0; i < s.size(); ++ i)
    {
        printList(l);
        if(rand()%2)
        {
            
            cout << "\nMinimum = " << getMin(R, l, start, end) << endl;
        }
        else
        {
            cout << "\nRandom = " << getRandom(R, l, start, end) << endl;
        }
    }

    return 0;
}
