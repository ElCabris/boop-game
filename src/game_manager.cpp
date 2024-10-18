#include <game_manager.hpp>

boop::GameManager::GameManager(Board &board, Player &player1, Player &player2)
    : _board(board), _player1(player1), _player2(player2) {}
