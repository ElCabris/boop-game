#include "piece.hpp"
#include <graphics.hpp>
#include <iostream>

boop::GBoard::GBoard(Board &board) : _board(board) {}

void boop::GBoard::draw() const {
  const auto size = static_cast<int>(_board.get_size());
  std::cout << " ";
  for (auto i = 0; i < size; i++) {
    std::cout << (char)('A' + i) << ' ';
  }
  std::cout << std::endl;
  for (auto i = 0; i < size; i++) {
    std::cout << (i + 1) << ' ';
    for (auto j = 0; j < size; j++) {
      switch (_board.get_piece({i, j})->value.get_type()) {
      case EMPTY:
        std::cout << ' ';
        break;
      case CAT:
        std::cout << 'C';
        break;
      case KITTEN:
        std::cout << 'c';
        break;
      }
      std::cout << ' '; 
    }
    std::cout << std::endl; 
  }
}
