#include "bits/stdc++.h"

using namespace std;


class Node {
public:
	char character;
	int freq;
	Node* left;
	Node* right;
	Node(char _character, int _freq, Node* _left, Node* _right){
		character = _character;
		freq = _freq;
		left = _left;
		right = _right;
	}
};


struct Compare {
	bool operator()(Node* a, Node* b){
		return a->freq > b->freq;
	}
};


void printer(Node* root, unordered_map<char,string>& m, string temp){

	if(root==nullptr) return;

	if(!root->left && !root->right){
		m[root->character] = temp;
		return;
	}

	printer(root->left,m,temp+'0');
	printer(root->right,m,temp+'1');
}


void huffmanCode(string text){
	
	unordered_map<char, int> freq;
	for (char ch: text) {
		freq[ch]++;
	}

	priority_queue<Node*,vector<Node*>,Compare> pq;

	for (auto pair: freq) {
		pq.push(new Node(pair.first,pair.second,nullptr,nullptr));
	}

	if(pq.size() == 0) {
		std::cout << "Text empty!" << std::endl;
		return;
	}

	while(pq.size() > 1){
		Node* firstNode = pq.top();
		pq.pop();
		Node* secondNode = pq.top();
		pq.pop();

		int sum = firstNode->freq + secondNode->freq;
		
		pq.push(new Node('\0',sum,firstNode,secondNode));

	}

	Node* root = pq.top();
	unordered_map<char,string> huffman;
	printer(root,huffman,"");

	for(auto& pair : huffman){
		std::cout << "Character:" << pair.first << " - Huffman Code:" << pair.second << std::endl;
	}
	
	string str = "";
	for (char ch: text) {
		str += huffman[ch];
	}

	cout << "Encoded string is :" << str << '\n';

}

int main(){

	string text = "akskmladlskdkasklldkasmkdmasdmmak dmsallmdmalsmldmka sd adasdsada";

	huffmanCode(text);

	return 0;

}



