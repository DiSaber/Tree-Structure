#pragma once
#include <vector>

template<typename T>
class Node
{
public:
	std::vector<Node<T>> Children;
	T Data;
	Node<T>* Parent;

	Node(long nodeSize, const T& data)
		: Children(), Data(data), Parent(nullptr)
	{
		Children.reserve(nodeSize);
	}

	Node(long nodeSize, const T& data, Node<T>* parent)
		: Children(), Data(data), Parent(parent)
	{
		Children.reserve(nodeSize);
	}

	Node(const Node<T>& node)
		: Children(), Data(node.Data), Parent(node.Parent)
	{
		Children.reserve(node.Children.capacity());
		Children = node.Children;

		for (auto& childNode : Children) {
			childNode.Parent = this;
		}
	}

	void SetChild(long index, const Node<T>& child)
	{
		if (index < Children.size()) {
			Children[index] = child;
			Children[index].Parent = this;
		}
		else {
			Children.push_back(child);
			Children[Children.size() - 1].Parent = this;
		}
	}
};
