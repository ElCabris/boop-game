#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <cstddef>
namespace boop {

template <typename T> struct Node {
  T value;
  Node *up, *down, *left, *right;
  Node(T value);
  Node();
};

template <typename T> class NodeMatrix {
private:
  Node<T> *_nodes;
  std::size_t _size;

public:
  NodeMatrix(const std::size_t &size);
  ~NodeMatrix();
  std::size_t get_size() const;
  Node<T> *get_head() const;
};
} // namespace boop

template <typename T> boop::Node<T>::Node(T value) : value(value) {}

template <typename T> boop::Node<T>::Node() : value(T()) {}

template <typename T>
boop::NodeMatrix<T>::NodeMatrix(const std::size_t &size)
    : _nodes(new Node<T>[size * size]), _size(size) {
  for (std::size_t i = 0; i < _size; i++) {
    for (size_t j = 0; j < _size; j++) {
      std::size_t node_id = i * _size + j;
      Node<T> *node = &_nodes[node_id];

      if (j > 0) {
        node->left = &_nodes[node_id - 1];
      }

      if (j < _size - 1) {
        node->right = &_nodes[node_id + 1];
      }

      if (i < _size - 1) {
        node->down = &_nodes[node_id + _size];
      }

      if (i > 0) {
        node->up = &_nodes[node_id - _size];
      }
    }
  }
}

template <typename T> boop::NodeMatrix<T>::~NodeMatrix() { delete[] _nodes; }

template <typename T> std::size_t boop::NodeMatrix<T>::get_size() const {
  return _size;
}

template <typename T> boop::Node<T> *boop::NodeMatrix<T>::get_head() const {
  return _nodes[0];
}
#endif
