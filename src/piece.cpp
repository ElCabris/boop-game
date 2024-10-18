#include <piece.hpp>
#include <stdexcept>
#include <string>

boop::Piece::Piece() : _type(EMPTY) {}

boop::Piece::Piece(boop::PieceType type, Side side) {
  _type = type;
  _side = side;
}

boop::PieceType boop::Piece::get_type() const { return _type; }

void boop::Piece::set_type(const PieceType &type) { _type = type; }

boop::Side boop::Piece::get_side() const { return _side; }

void boop::Piece::set_side(const Side &side) { _side = side; }

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

boop::PieceType boop::char_to_type_piece(const char &type) {
  switch (type) {
  case 'C':
    return boop::CAT;
  case 'k':
    return boop::KITTEN;
  case ' ':
    return boop::EMPTY;
  default:
    throw std::invalid_argument(std::to_string(type) + "is not a type cat");
  }
}
