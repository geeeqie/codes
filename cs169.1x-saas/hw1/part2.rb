class WrongNumberOfPlayersError < StandardError ; end
class NoSuchStrategyError < StandardError ; end

def rps_result(m1, m2)
    if m1 == m2
        return 0
    end
    if m1 == "R" && m2 == "S"
        return 0
    end
    if m1 == "S" && m2 == "P"
        return 0
    end
    if m1 == "P" && m2 == "R"
        return 0
    end
    return 1
end

def rps_game_winner(game)
    raise WrongNumberOfPlayersError unless game.length == 2
    game.each do |player|
        raise NoSuchStrategyError unless ["R", "P", "S"].include?(player[1].upcase)
    end
    win = rps_result(game[0][1].upcase, game[1][1].upcase)
    return game[win]
end

def rps_tournament_winner(tournament)
    if tournament[0][0].is_a? String
        return rps_game_winner(tournament)
    end
    winner0 = rps_tournament_winner(tournament[0])
    winner1 = rps_tournament_winner(tournament[1])
    return rps_game_winner([winner0, winner1])
end 

# qy
# NOTE: I find it is a recursive descent method!
# T ::= G | [T, T]
