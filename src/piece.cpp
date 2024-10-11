#include <piece.hpp>

boop::Piece::Piece() : _type(EMPTY) {}
boop::PieceType boop::Piece::get_type() const { return _type; }
