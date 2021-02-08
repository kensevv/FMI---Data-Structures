#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cassert>

template<typename T>
struct Node {
    T data;
    std::vector<Node*> children;

    Node(const T& data) {
        this->data = data;
    }

    Node(const T& data, const std::vector<Node*> & children) : Node(data) {
        this->children = children;
    }
    
    bool isLeaf() {
	    return children.empty();
	}
};

template<typename T>
class Tree {
    Node<T> * root;
    void printHelp(Node<T>* root) {
        if(root == nullptr) {
            return;
        }
        
        std::cout << root->data << " ";


        for(size_t i = 0; i < root->children.size(); i++) {
            printHelp(root->children[i]);
        }

        // for(size_t i = root->children.size(); i > 0; i--) {
        //     printHelp(root->children[i - 1]);
        // }
    }

    void printWithStack() {
        if(root == nullptr) {
            return;
        }

        std::stack<Node<T>*> s;
        s.push(root);
        
        while(!s.empty()){
            Node<T>* current = s.top();
            s.pop();
            std::cout << current->data << " ";
            
            for(size_t i = current->children.size(); i > 0; i--) {
                s.push(current->children[i - 1]);
            }
        }
    }

    void printWithBFS(){
        if(root == nullptr) {
            return;
        }

        std::queue<Node<T>*> q;
        q.push(root);

        while(!q.empty()){
            Node<T>* current = q.front();
            q.pop();
            std::cout<<current->data<<" ";

            for(size_t i = 0; i < current->children.size(); i++) {
                q.push(current->children[i]);
            }
        }
    }
public:
    Tree(Node<T> * root) {
        this->root = root;
    }

    void printTree() {
        // printHelp(root);
        // printWithStack();
        printWithBFS();
    }

    void printSumByLevel() {
        if(root == nullptr) {
            return;
        }

        std::queue<Node<T>*> q;

        q.push(root);
        q.push(nullptr);
        int sum = 0;

		while(!q.empty()){
            Node<T>* current = q.front();
			q.pop();

            if(current == nullptr) {
				std::cout << sum << std::endl;
				sum = 0;
                q.push(nullptr);
                current = q.front();
                q.pop();
                
                if(q.empty()) {
                    break;
                }
            }
			sum += current->data;

            for(size_t i = 0; i < current->children.size(); i++) {
                q.push(current->children[i]);
            }
		}
	}
};

int main() {

    Node<int>* ten = new Node<int>(10);
    Node<int>* twenty = new Node<int>(20);
    Node<int>* fifty = new Node<int>(50);
	std::vector<Node<int> *> one_children;
	one_children.push_back(ten);
	Node<int>* one = new Node<int>(1, one_children);
    
	std::vector<Node<int> *> five_children;
	five_children.push_back(twenty);
	Node<int>* five = new Node<int>(5, five_children);

	std::vector<Node<int> *> four_children;
	four_children.push_back(fifty);
	Node<int>* four = new Node<int>(4, four_children);

	Node<int>* six = new Node<int>(6);

	std::vector<Node<int> *> two_children;
	two_children.push_back(one);
	two_children.push_back(five);
	two_children.push_back(four);
	two_children.push_back(six);

	Node<int>* two = new Node<int>(2, two_children);


    Tree<int> tree(two);
    tree.printSumByLevel();
    std::cout << "\n";
    return 0;
}