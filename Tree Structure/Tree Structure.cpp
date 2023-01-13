#include <iostream>
#include "Node.h";

int main()
{
    Node<std::string> root(2, "Root");
    root.SetChild(0, Node<std::string>(2, "Random Data 0"));
    root.SetChild(1, Node<std::string>(2, "Random Data 1"));

    auto& child0 = root.Children[0];
    child0.SetChild(0, Node<std::string>(2, "Child 0"));
    child0.SetChild(1, Node<std::string>(2, "Child 1"));


    Node<std::string> rootCopy(root);
    rootCopy.Data = "Root Copy";
    rootCopy.Children[0].Data = "Random Copy 0";
    rootCopy.Children[1].Data = "Random Copy 1";

    auto& copy0 = rootCopy.Children[0];
    copy0.Children[0].Data = "Copy 0";
    copy0.Children[1].Data = "Copy 1";
}
