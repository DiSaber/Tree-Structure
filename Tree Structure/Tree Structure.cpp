#include <iostream>
#include "Node.h";

int main()
{
    Node<std::string> root(2, "Root");  // Create a root node
    root.AddChild( Node<std::string>(2, "Random Data 0"));  // Insert a child
    root.AddChild(Node<std::string>(2, "Random Data 1"));

    auto& child0 = root.Children[0];  // Get a reference of the first child of the root
    child0.AddChild(Node<std::string>(2, "Child 0"));
    child0.AddChild(Node<std::string>(2, "Child 1"));


    Node<std::string> rootCopy(root);  // Copy the root node
    rootCopy.Data = "Root Copy";
    rootCopy.Children[0].Data = "Random Copy 0";
    rootCopy.Children[1].Data = "Random Copy 1";

    auto& copy0 = rootCopy.Children[0];  // Get a reference of the first child of the root copy
    copy0.Children[0].Data = "Copy 0";
    copy0.Children[1].Data = "Copy 1";


    Node<std::string> newRoot(2, "New Root");
    newRoot.AddChild(root.Children[0]);  // Copy child 0 of the root to child 0 of the new root
}
