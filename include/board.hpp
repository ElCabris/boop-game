#ifndef BOARD_HPP
#define BOARD_HPP
#include <linkedlist.hpp>
#include <piece.hpp>
namespace boop {

struct Position {
  int row, col;
};
class Board {
private:
  NodeMatrix<Piece> _matrix;

public:
  Board(const std::size_t &size);
  Node<Piece> *get_piece(Position position) const;
};
} // namespace boop
#endif
