#include <game_manager.hpp>

boop::GameManager::GameManager(Board &board, Player &player)
    : _board(board), _player(player) {}
