#include "piece.hpp"
#include <graphics.hpp>
#include <iostream>

boop::GBoard::GBoard(Board &board) : _board(board) {}

void boop::GBoard::draw() const {
  const auto size = static_cast<int>(_board.get_size());
  std::cout << ' ';
  for (auto i = 0; i < size; i++) {
    std::cout << (char)('A' + i) << ' ';
  }
  std::cout << std::endl;
  for (auto i = 0; i < size; i++) {
    std::cout << (i + 1) << ' ';
    for (auto j = 0; j < size; j++) {
      std::cout << type_piece_to_char(
          _board.get_piece({i, j})->value.get_type());
      std::cout << ' ';
    }
    std::cout << std::endl;
  }
}

char boop::type_piece_to_char(const PieceType &type) {
  switch (type) {
  case CAT:
    return 'C';
  case KITTEN:
    return 'k';
  default:
    return ' ';
  }
}
