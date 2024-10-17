#include <piece.hpp>

boop::Piece::Piece() : _type(EMPTY) {}
boop::Piece::Piece(boop::PieceType type, Side side) {
  _type = type;
  _side = side;
}
boop::PieceType boop::Piece::get_type() const { return _type; }
void boop::Piece::set_type(const PieceType &type) { _type = type; }
boop::Side boop::Piece::get_side() const { return _side; }
void boop::Piece::set_side(const Side &side) { _side = side; }
