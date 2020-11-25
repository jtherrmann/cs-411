// huffcode.cpp  UNFINISHED
// Glenn G. Chappell
// 29 Nov 2015
//
// For CS 411/611 Fall 2015
// Assignment 6, Exercise A
// Source for class HuffCode
//
// Modified 11/22/17
// Chris Hartman
// For CS 411 Fall 2017

#include "huffcode.hpp"  // for class HuffCode declaration
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;

#include <memory>
using std::shared_ptr, std::make_shared;

#include <queue>
using std::priority_queue;

#include <vector>
using std::vector;


class NodeCompare {
public:
    bool operator() (const shared_ptr<Node>& node1, const shared_ptr<Node>& node2) {
        // Return true if the first node has lower priority than the second.
        return node1->weight > node2->weight;
    }
};


shared_ptr<Node> getHuffmanTree(const unordered_map<char, int> & weights) {
    if (weights.empty())
        return nullptr;

    auto trees = priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>, NodeCompare>();

    for (auto pair : weights)
        trees.push(make_shared<Node>(Node({pair.first, pair.second, nullptr, nullptr})));

    while (trees.size() > 1) {
        auto tree1 = trees.top();
        trees.pop();

        auto tree2 = trees.top();
        trees.pop();

        trees.push(make_shared<Node>(Node({0, tree1->weight + tree2->weight, tree1, tree2})));
    }
    return trees.top();
}


void HuffCode::traverseTree(const std::shared_ptr<Node> &tree, const string &codeword) {
    if (tree->isLeaf())
        this->symbolsToCodewords[tree->symbol] = codeword;
    else {
        traverseTree(tree->left, codeword + "0");
        traverseTree(tree->right, codeword + "1");
    }
}


void HuffCode::setWeights(const unordered_map<char, int> & weights) {
    this->huffmanTree = getHuffmanTree(weights);
    if (this->huffmanTree)
        this->traverseTree(this->huffmanTree, this->huffmanTree->isLeaf() ? "0" : "");
}


string HuffCode::encode(const string & text) const {
    string result;
    for (auto symbol : text)
        result += this->symbolsToCodewords.at(symbol);
    return result;
}


string HuffCode::decode(const string & codestr) const {
    if (!codestr.empty() && this->huffmanTree->isLeaf())
        return string(1, this->huffmanTree->symbol);

    string result;
    shared_ptr<Node> node = this->huffmanTree;

    for (auto bit : codestr) {
        node = (bit == '0' ? node->left : node->right);
        if (node->isLeaf()) {
            result += node->symbol;
            node = this->huffmanTree;
        }
    }
    return result;
}