
class Node
{
private:
	int data;
	Node* next;
	Node* prev;
public:
	Node() = default;
	int getData();
	void setData(int a);
	Node* getNext();
	void setNext(Node* n);
	Node* getPrev();
	void setPrev(Node* p);
};

int Node::getData() {
	return this->data;
}
void Node::setData(int a) {
	this->data = a;
}
Node* Node::getNext() {
	return next;
}
void Node::setNext(Node* n) {
	next = n;
}
Node* Node::getPrev() {
	return prev;
}
void Node::setPrev(Node* p) {
	prev = p;
}

