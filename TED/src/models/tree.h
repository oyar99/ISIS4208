#ifndef TREE_H
#define TREE_H

#include <vector>
#include <unordered_set>
#include <string>

/**
 * Represents a node-labeled rooted tree data structure referred to as T.
 * 
 * Nodes have a unique id from 1 to n where n is the number of nodes in T.
 * Labels are not necessarily unique and are drawn from the alphabet of all integers.
 * 
 * This structure provides elementary operations on the tree T used as sub-routines by 
 * a variety of algorithms.
 * 
 * Other specific algorithms may be implemented in separate packages.
*/
struct Tree {
    // Adjacency list for T.
    // adj[u] corresponds to the children of u
    std::vector<std::vector<int>> adj;
    // Id of the root node.
    int root;
    // Maps a node to its label.
    std::vector<int> labels;
    // Maps a node to its parent.
    std::vector<int> parent;


    /**
     * Constructs T from the pre-order traversal string representation.
     * 
     * The pre-order traversal has additional parenthesis that enclose the sub-tree rooted at u
     * for all u.
     * 
     * The running time complexity is of the order O(3n) where n corresponds to the number of nodes in T.
    */
    Tree(const std::string& pre_order);

    /**
     * Gets a preorder string unique representation of T in linear time.
     * For instance, the tree
     *          
     *                        2
     *                       / \
     *                      /   \
     *                     1     3
     *                    / \   / \
     *                   0   7 9   1
     *                      /
     *                     2 
     * 
     * has the following pre-order sequence:
     * 
     * 2(1(0()7(2()))3(9()1()))
     * 
    */
    std::string pre_order();

    /**
     * Uses Heavy-light decomposition to return a set of vertex disjoint paths
     * from the tree T. It is guaranteed that any path from a leaf to the root
     * will go through at most O(lgn) paths from this set.
    */
    std::vector<std::unordered_set<int>> decompose();
};

#endif