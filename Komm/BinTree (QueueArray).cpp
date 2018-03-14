#include "BinTree (QueueArray).h"
#include "assert.h"




Node &Node::operator =(Node &a){
	key=a.key;
	left=a.left;
	right=a.right;
	return *this;
}




BinTree::BinTree(int k):nodes(1),maxH(1){
  srand(time(nullptr));
  Node *t=new Node(k);
  root=t;
}


BinTree::~BinTree(){
	assert(root && "Tree is empty");
	DeleteSubtree(root);
}




void BinTree::DeleteSubtree(Node *a){
	assert(a && "Node = nullptr");
	if(a->left)
		DeleteSubtree(a->left);
	if(a->right)
		DeleteSubtree(a->right);
	delete a;
	--nodes;
}




void BinTree::AddNode(int val){
	AddNode(root, val);
}



void BinTree::AddNode(Node *a, int val){

	int t=rand()%2;
	std::cout << "t= " << t <<'\n';
	if(t==0){
			if(a->left)
				AddNode(a->left, val);
			else{
				a->left = new Node(val);
				++nodes;
			}
	}
	
	else{
			if(a->right)
				AddNode(a->right, val);
			else{
				a->right = new Node(val);
				++nodes;
			}
	}
}


unsigned int BinTree::getH(){
	assert(root && maxH==1 && "Tree is empty");
	CalculateHeight(root, 1);
	std::cout << "Vysota= " << maxH << '\n';
	return maxH;
}



void BinTree::CalculateHeight(Node *a, unsigned int k){
	assert(a && "Node = nullptr");
	if(maxH<k) maxH=k;
	if(a->left)
		CalculateHeight(a->left, k+1);
	if(a->right)
		CalculateHeight(a->right, k+1);
}


Node* BinTree::SearchKey(int k){
	return SearchKey(k, root);
}


Node* BinTree::SearchKey(int k, Node *a){
	assert(a && "Node = nullptr");
	Node* res;
	if(k==a->key){
		return a;
	}
	if(a->left){
		res=SearchKey(k, a->left);
		if(res!=nullptr) return res;
	}
	if(a->right){
		res=SearchKey(k, a->right);
		if(res!=nullptr) return res;
	}
	return nullptr;
}




void BinTree::Print(){
	Print(root);
}


void BinTree::Print(Node *a, unsigned int sh){
	assert(a && "Node = nullptr");
	if(a->right) Print(a->right, sh+10);
	std::cout << std::setw(sh) << a->key << '\n';
	if(a->left) Print(a->left, sh+10);
}


// обход в ширину


void BinTree::PrintBFS(){
	std::queue<Node *> queue;
	queue.push(root);
	HeightBFS(root, queue);
	std::cout << '\n';
//	std::cout << "height = " << height << '\n';
}

/*
if(i>=10) i=0;
if(j>=10) j=0;
*/
void BinTree::HeightBFS(Node* a, std::queue<Node *> &queue){
	unsigned int check=0;
	static unsigned int height=1;
	if(a->left){
		queue.push(a->left);
		check=1;
	}
	if(a->right){
		queue.push(a->right);
		check=1;
	}
	if(!queue.empty()){
		std::cout << a->key << " ";
		queue.pop();
	}
	if(check==1) ++height;
	if(!queue.empty()) HeightBFS(queue.front(), queue);
}
/*
void Node::Print(Node *a, int sh){
	if(a->left) Print(a->left, sh+10);
	if(a->right) Print(a->right, sh+10);
	for(int i=0; i<sh; ++i) std::cout << " ";
	std::cout << a->key << '\n';
}
*/






