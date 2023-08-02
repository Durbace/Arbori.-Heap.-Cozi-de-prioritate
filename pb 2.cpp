#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <cmath>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};
void inaltimeSubarbore(TreeNode* root, int h, int& h_max) {
	if (root == nullptr)
		return;
	if (h > h_max)
		h_max = h;
	inaltimeSubarbore(root->left, h + 1, h_max);
	inaltimeSubarbore(root->right, h + 1, h_max);
}
void SRD(TreeNode* root) {
	if (root == nullptr)
		return;
	SRD(root->left);
	std::cout << root->val << " ";
	SRD(root->right);
}
void RSD(TreeNode* root) {
	if (root == nullptr)
		return;
	std::cout << root->val << " ";
	RSD(root->left);
	RSD(root->right);
}
void SDR(TreeNode* root) {
	if (root == nullptr)
		return;
	SDR(root->left);
	SDR(root->right);
	std::cout << root->val << " ";
}
void creareLegaturi(TreeNode* root, std::vector<TreeNode*> nodes) {
	for (int i = 0; i < nodes.size(); i++) {
		if (root->left == nullptr && root->right == nullptr)
			return;
		if (root->left != nullptr && root->left->val == nodes[i]->val) {
			root->left = nodes[i];
			creareLegaturi(root->left, nodes);
		}
		else if (root->right != nullptr && root->right->val == nodes[i]->val) {
			root->right = nodes[i];
			creareLegaturi(root->right, nodes);
			return;
		}
	}
}
void creareArbore(TreeNode*& root) {
	std::vector<int> keys, leftChildren, rightChildren;
	std::ifstream fin("arbore1.txt");
	int key, leftChild, rightChild;
	while (fin >> key >> leftChild >> rightChild) {
		keys.push_back(key);
		leftChildren.push_back(leftChild);
		rightChildren.push_back(rightChild);
	}
	fin.close();
	std::vector<TreeNode*> nodes(keys.size());
	for (int i = 0; i < keys.size(); i++) {
		nodes[i] = new TreeNode;
		nodes[i]->val = keys[i];
		nodes[i]->left = nullptr;
		nodes[i]->right = nullptr;
	}
	for (int i = 0; i < leftChildren.size(); i++) {
		if (leftChildren[i] != -1) {
			TreeNode* newNode = new TreeNode;
			newNode->val = leftChildren[i];
			newNode->left = nullptr;
			newNode->right = nullptr;
			nodes[i]->left = newNode;
		}
		else {
			nodes[i]->left = nullptr;
		}
		if (rightChildren[i] != -1) {
			TreeNode* newNode = new TreeNode;
			newNode->val = rightChildren[i];
			newNode->left = nullptr;
			newNode->right = nullptr;
			nodes[i]->right = newNode;
		}
		else {
			nodes[i]->right = nullptr;
		}
	}
	root = nodes[0];
	creareLegaturi(root, nodes);
}
void afisarePeNiveluri(TreeNode* root) {
	if (root == nullptr)
		return;
	std::queue<TreeNode*> queue;
	queue.push(root);
	while (!queue.empty()) {
		int size = queue.size();
		for (int i = 0; i < size; i++) {
			TreeNode* current = queue.front();
			std::cout << current->val << " ";
			queue.pop();
			if (current->left)
				queue.push(current->left);
			if (current->right)
				queue.push(current->right);
		}
		std::cout << std::endl;
	}
}
void afisareFrunze() {
	std::vector<int> keys, leftChildren, rightChildren;
	std::ifstream fin("arbore1.txt");
	int key, leftChild, rightChild;
	while (fin >> key >> leftChild >> rightChild) {
		keys.push_back(key);
		leftChildren.push_back(leftChild);
		rightChildren.push_back(rightChild);
	}
	fin.close();
	for (int i = 0; i < keys.size(); i++) {
		if (leftChildren[i] == -1 && rightChildren[i] == -1)
			std::cout << keys[i] << " ";
	}
	std::cout << std::endl;
}
bool arboriIdentici() {
	std::vector<int> keys1, leftChildren1, rightChildren1;
	std::ifstream fin("arbore1.txt");
	int key1, leftChild1, rightChild1;
	while (fin >> key1 >> leftChild1 >> rightChild1) {
		keys1.push_back(key1);
		leftChildren1.push_back(leftChild1);
		rightChildren1.push_back(rightChild1);
	}
	fin.close();
	std::vector<int> keys2, leftChildren2, rightChildren2;
	std::ifstream fiin("arbore2.txt");
	int key2, leftChild2, rightChild2;
	while (fiin >> key2 >> leftChild2 >> rightChild2) {
		keys2.push_back(key2);
		leftChildren2.push_back(leftChild2);
		rightChildren2.push_back(rightChild2);
	}
	fiin.close();
	if (keys1.size() != keys2.size())
		return false;
	for (int i = 0; i < keys1.size(); i++) {
		if (keys1[i] != keys2[i] || leftChildren1[i] != leftChildren2[i] || rightChildren1[i] !=
			rightChildren2[i])
			return false;
	}
	return true;
}
bool arboreComplet(TreeNode* root, int k, int inaltime) {
	if (root == nullptr)
		return false;
	std::queue<TreeNode*> queue;
	queue.push(root);
	while (!queue.empty() && k < inaltime) {
		int size = queue.size();
		if (size != pow(2, k))
			return false;
		for (int i = 0; i < size; i++) {
			TreeNode* current = queue.front();
			queue.pop();
			if (current->left)
				queue.push(current->left);
			if (current->right)
				queue.push(current->right);
		}
		k++;
	}
	return true;
}
void adancimeNod(TreeNode* root, int k, int valoare) {
	if (root == nullptr)
		return;
	std::queue<TreeNode*> queue;
	bool gasit = false;
	queue.push(root);
	while (!queue.empty()) {
		int size = queue.size();
		for (int i = 0; i < size; i++) {
			TreeNode* current = queue.front();
			if (current->val == valoare) {
				std::cout << "Adancimea nodului " << valoare << " este: " << k;
				gasit = true;
				return;
			}
			queue.pop();
			if (current->left)
				queue.push(current->left);
			if (current->right)
				queue.push(current->right);
		}
		k++;
	}
	if (!gasit)
		std::cout << "Nodul " << valoare << " nu exista in arbore.";
}
int main() {
	int h_max = -1;
	TreeNode* root;
	creareArbore(root);
	inaltimeSubarbore(root, 0, h_max);
	std::cout << "Inaltime: " << h_max << std::endl;
	std::cout << "SRD: ";
	SRD(root);
	std::cout << std::endl;
	std::cout << "RSD: ";
	RSD(root);
	std::cout << std::endl;
	std::cout << "SDR: ";
	SDR(root);
	std::cout << std::endl;
	std::cout << "Afisare pe niveluri: " << std::endl;
	afisarePeNiveluri(root);
	std::cout << "Frunzele arborelui sunt: ";
	afisareFrunze();
	std::cout << "Arbori identici: " << arboriIdentici() << std::endl;
	std::cout << "Arbore complet: " << arboreComplet(root, 0, h_max) << std::endl;
	adancimeNod(root, 0, 5);
	return 0;
}
