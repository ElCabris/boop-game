#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <cstddef>
#include <piece.hpp>
#include <vector>

namespace boop {
class Player {
private:
  std::vector<Piece> _pieces;
  Side _side;
  std::size_t _max_number_pieces;

public:
  Player(std::size_t initial_number_chips, Side _side);
  Side get_side() const;
  std::vector<Piece> get_pieces() const;
  std::size_t get_max_number_pieces() const;
  bool use_cat();
  bool use_kitten();
  bool add_cat();
  bool add_kitten();
};

} // namespace boop
#endif
