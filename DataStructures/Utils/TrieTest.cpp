#include "Trie.h"
#include <string>

int main()
{
    std::string keys[] = {"the",
                          "a",
                          "there",
                          "answer",
                          "any",
                          "by",
                          "bye",
                          "their"};
    int n = sizeof(keys) / sizeof(keys[0]);

    Trie root;

    for (int i = 0; i < n; i++)
        root.Insert(keys[i]);

    root.Search("the") ? std::cout << "Yes\n" : std::cout << "No\n";
    root.Search("these") ? std::cout << "Yes\n" : std::cout << "No\n";

    return 0;
}