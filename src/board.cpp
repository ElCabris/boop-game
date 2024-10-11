#include <board.hpp>
#include <piece.hpp>
#include <stdexcept>
#include <string>

boop::Board::Board(const std::size_t &size) : _matrix(size) {}

boop::Node<boop::Piece> *
boop::Board::get_piece(Position position) const {
  auto aux = _matrix.get_head();

  for (auto i = 0; i < position.row; i++) {
    if (aux->right == nullptr) {
      throw std::invalid_argument(std::to_string(position.row) + ", " +
                                  std::to_string(position.col) + "is no valid");
    }
    aux = aux->right;
  }

  for (auto i = 0; i < position.col; i++) {
    if (aux->down == nullptr) {
      throw std::invalid_argument(std::to_string(position.row) + ", " +
                                  std::to_string(position.col) + "is no valid");
    }
  }
  return aux;
}

void boop::Board::add_piece(Position& position, PieceType type) {
	auto aux = get_piece(position);

	if (aux->value.get_type() != EMPTY) {
		throw std::invalid_argument("box " + std::to_string(position.row) + ',' + std::to_string(position.col) + "is not available");
	}

	aux->value.set_type(type);
}
