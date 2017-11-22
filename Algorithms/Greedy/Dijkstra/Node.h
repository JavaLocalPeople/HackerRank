#pragma once

class Node {
public:
	// big four
	Node();
	~Node() = default;
	Node(const Node& node);
	Node& operator=(const Node& node);

	// overload con't
	Node(int val);

	// gets
	int const getWeight() const;
	int const getIndex() const;
	int const getType() const;

	Node* getNextPtr() const;

	// sets
	void setWeight(const int& weight);
	void setIndex(const int& index);
	void setNextPtr(Node* singleNode);
	void setType(const int& type);

private:
	Node *m_pNext;
	int m_index;
	int m_weight;
	int m_type;
};
