#ifndef PIECE_HPP
#define PIECE_HPP
namespace boop {
enum PieceType { EMPTY, CAT, KITTEN };

enum Side { PLAYER1, PLAYER2 };

class Piece {
private:
  PieceType _type;
  Side _side;

public:
  Piece();
  Piece(PieceType type, Side side);
  PieceType get_type() const;
  Side get_side() const;
  void set_type(const PieceType &type);
  void set_side(const Side &side);
};
} // namespace boop
#endif
