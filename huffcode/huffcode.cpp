// Jake Herrmann
// CS 411
// 25 Nov 2020
//
// huffcode.cpp
// Source file for Huffman encoding.
// Based on the skeleton file by Glenn G. Chappell and Chris Hartman.


#include "huffcode.hpp"

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


// ----------------------------------------------------------------------------
// HuffCode: public member functions
// ----------------------------------------------------------------------------

void HuffCode::setWeights(const unordered_map<char, int> & weights) {
    _tree = _createTree(weights);
    if (_tree)
        _traverseTree(_tree, _tree->isLeaf() ? "0" : "");
}


string HuffCode::encode(const string & text) const {
    string result;
    for (auto symbol : text)
        result += _codewords.at(symbol);
    return result;
}


string HuffCode::decode(const string & codestr) const {
    if (!codestr.empty() && _tree->isLeaf())
        return string(1, _tree->symbol);

    string result;
    shared_ptr<Node> node = _tree;

    for (auto bit : codestr) {
        node = (bit == '0' ? node->left : node->right);
        if (node->isLeaf()) {
            result += node->symbol;
            node = _tree;
        }
    }
    return result;
}


// ----------------------------------------------------------------------------
// HuffCode: private member functions
// ----------------------------------------------------------------------------

shared_ptr<HuffCode::Node> HuffCode::_createTree(const unordered_map<char, int> & weights) {
    if (weights.empty())
        return nullptr;

    auto trees = priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>, NodeCompare>();

    for (auto pair : weights)
        trees.push(make_shared<Node>(Node({pair.first, pair.second})));

    while (trees.size() > 1) {
        auto tree1 = trees.top();
        trees.pop();

        auto tree2 = trees.top();
        trees.pop();

        trees.push(make_shared<Node>(Node({0, tree1->weight + tree2->weight, tree1, tree2})));
    }
    return trees.top();
}


void HuffCode::_traverseTree(const std::shared_ptr<Node> & node, const string & codeword) {
    if (node->isLeaf())
        _codewords[node->symbol] = codeword;
    else {
        _traverseTree(node->left, codeword + "0");
        _traverseTree(node->right, codeword + "1");
    }
}
