#include "TreeForBaBM.h"













Tree::Tree(){
	root=nullptr;
}

void Tree::Print(){
	Print(root);
}

void Tree::Print(SalesmanNode *a, unsigned int sh){
	//assert(a && "SalesmanNode = nullptr"); просто копипаст
	SalesmanNode *temp=nullptr;
	if(a->right){
		temp=dynamic_cast <SalesmanNode*> (a->right);
		Print(temp, sh+10);
	}
	cout << std::setw(sh) << a->cost << '\n';
	if(a->left){
		temp=dynamic_cast <SalesmanNode*> (a->left);
		Print(temp, sh+10);
	}
}

SalesmanNode *Tree::search_min(SalesmanNode *b){
	return DFS(root, b);
}


SalesmanNode *Tree::DFS(SalesmanNode *u, SalesmanNode *b){
	SalesmanNode *temp=b;
	SalesmanNode *temp2=nullptr;
	if(u->right){
		temp2=dynamic_cast <SalesmanNode*> (u->right);
		temp=DFS(temp2, b);
	}
	else
		if(u!=temp) return min(u, temp);
	if(u->left){
		temp2=dynamic_cast <SalesmanNode*> (u->left);
		temp=DFS(temp2, temp);
	}
	else
		if(u!=b) return min(u, temp);
	return temp;
}





void Tree::setRoot(SalesmanNode *a){
// 	if(this->empty()){
// 		this->root=a;
// 		return;
// 	}
// 	char check = 'n';
// 	cout << "Root does not empty. Do you really want to rewrite it?\n";
// 	cout << "[y/n]: ";
// 	cin >> check;
// 	while(check!='y'&&check!='n'){
// 		cout << "Invalid value, Type again 'y' or 'n': ";
// 		cin >> check;
// 	}
// 	if(check=='y'){
		this->root=a;
		cout << "Done.\n";
		return;
	//}
	//cout << "Root does not changed\n";
}


bool Tree::empty(){	//Сделано
	if(root) return false;
	return true;
}



Tree::~Tree(){		//сделано
	if(this->empty()) return;
	SalesmanNode *temp=nullptr;
	if(root->left){
		temp=dynamic_cast <SalesmanNode*> (root->left);
		DeleteSTree(temp);
	}
	if(root->right){
		temp=dynamic_cast <SalesmanNode*> (root->right);
		DeleteSTree(temp);
	}
	delete root;
	root=nullptr;
}



void Tree::DeleteSTree(SalesmanNode *a){ //Сделано
	SalesmanNode *temp=nullptr;
	if(a->left){
		temp=dynamic_cast <SalesmanNode*> (a->left);
		DeleteSTree(temp);
	}
	if(a->right){
		temp=dynamic_cast <SalesmanNode*> (a->right);
		DeleteSTree(temp);
	}
	delete a;
}

/*
SalesmanNode *Tree::RetRoot(){ //root может быть nullptr
	return root;
}
*/
