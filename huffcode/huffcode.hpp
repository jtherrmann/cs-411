// Jake Herrmann
// CS 411
// 25 Nov 2020
//
// huffcode.hpp
// Header file for Huffman encoding.
// Based on the skeleton file by Glenn G. Chappell and Chris Hartman.


#ifndef FILE_HUFFCODE_H_INCLUDED
#define FILE_HUFFCODE_H_INCLUDED

#include <string>
#include <unordered_map>
#include <memory>


// ============================================================================
// Class HuffCode
// Encoding and decoding using a Huffman code
// ============================================================================
class HuffCode {

// ----------------------------------------------------------------------------
// HuffCode: public member functions
// ----------------------------------------------------------------------------
public:
    // Compiler-generated default ctor, copy ctor, copy =, dctor used

    void setWeights(const std::unordered_map<char, int> & weights);

    std::string encode(const std::string & text) const;

    std::string decode(const std::string & codestr) const;

// ----------------------------------------------------------------------------
// HuffCode: inner classes and structs
// ----------------------------------------------------------------------------
private:
    struct Node {
        char symbol;
        int weight;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;

    public:
        bool isLeaf() {
            return !this->left;
        }
    };

    class NodeCompare {
    public:
        bool operator() (const std::shared_ptr<Node> & node1, const std::shared_ptr<Node> & node2) {
            // Return true if the first node has lower priority than the second. Note that if the
            // weights are equal, then the second node has lower priority.
            return node1->weight > node2->weight;
        }
    };

// ----------------------------------------------------------------------------
// HuffCode: private member functions
// ----------------------------------------------------------------------------
private:
    static std::shared_ptr<Node> _createTree(const std::unordered_map<char, int> & weights);

    void _traverseTree(const std::shared_ptr<Node> & node, const std::string & codeword);

// ----------------------------------------------------------------------------
// HuffCode: data members
// ----------------------------------------------------------------------------
private:
    std::shared_ptr<Node> _tree;

    std::unordered_map<char, std::string> _codewords;

};  // End class HuffCode


#endif //#ifndef FILE_HUFFCODE_H_INCLUDED
