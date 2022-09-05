#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

struct ChildNodes
{
    int leftNode;
    int rightNode;
};

ChildNodes findChildNodes(int target, int tree[])
{

    auto itr = std::find(tree, tree + sizeof(tree), target);
    int index = itr - tree;

    int leftNode = tree[2 * index + 1];
    int rightNode = tree[2 * index + 2];

    ChildNodes childNodes;
    childNodes.leftNode = leftNode;
    childNodes.rightNode = rightNode;

    return childNodes;
}

int main()
{
    int x, p;
    std::cin >> x >> p;
    int length = std::pow(2, x) - 1;
    int tree[length];

    for (int i = 0; i < std::pow(2, x) - 1; i++)
    {
        std::cin >> tree[i];
    }

    ChildNodes childNodes = findChildNodes(p, tree);

    std::string leftNodeStr = childNodes.leftNode != -1 ? std::to_string(childNodes.leftNode) : "NULL";
    std::string rightNodeStr = childNodes.rightNode != -1 ? std::to_string(childNodes.rightNode) : "NULL";

    std::cout << leftNodeStr << " " << rightNodeStr << std::endl;
}