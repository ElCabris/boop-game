#include <board.hpp>
#include <player.hpp>
#include <tuple>

namespace boop {
class GameManager {
private:
  Board &_board;
  Player &_player1;
  Player &_player2;
  std::tuple<Position, Position, Position> get_three_kittens();

public:
  GameManager(Board &board, Player &player1, Player &player2);
  bool exchange_kittens_for_cats();
};
} // namespace boop
