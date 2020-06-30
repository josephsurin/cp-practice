"""
divisor game

alice and bob play a game, with alice going first. at the start of the game a number N is on the chalkboard. each player takes a turn. on each player's turn, that player makes a move by:
    choosing any x such that 0 < x < N and x divides N
    then replacing N with N-x on the chalkboard
if a player cannot make a move, they lose the game

return True if and only if alice wins the game
"""

class Solution:
    def divisorGame(self, N: int) -> bool:
        return not N & 1
