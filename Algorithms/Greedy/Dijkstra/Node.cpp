#include "Node.h"

// default constructor
Node::Node()
	: m_index(0), m_pNext(nullptr), m_weight(0), m_type(-1)
{

}

// copy constructor
Node::Node(const Node& node) :
	m_index(node.m_index), m_pNext(nullptr), m_weight(node.m_weight), m_type(node.m_type)
{

}

// assignment constructor
Node& Node::operator=(const Node& node) {
	this->m_pNext = nullptr;
	this->m_index = node.m_index;
	this->m_weight = node.m_weight;
	this->m_type = node.m_type;

	return *this;
}

// overload con't
Node::Node(int val) :
	m_index(val), m_pNext(nullptr), m_weight(0), m_type(-1)
{

}

void Node::setIndex(const int& val) {
	this->m_index = val;
}

void Node::setType(const int& type) {
	this->m_type = type;
}

void Node::setWeight(const int& val) {
	this->m_weight = val;
}

void Node::setNextPtr(Node* Node) {
	this->m_pNext = Node;
}

int const Node::getType() const {
	return this->m_type;
}

int const Node::getWeight() const {
	return this->m_weight;
}

int const Node::getIndex() const {
	return this->m_index;
}

Node* Node::getNextPtr() const {
	return this->m_pNext;
}
