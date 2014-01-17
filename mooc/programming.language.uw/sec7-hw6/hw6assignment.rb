# University of Washington, Programming Languages, Homework 6, hw6runner.rb

# This is the only file you turn in, so do not modify the other files as
# part of your solution.

class MyPiece < Piece
  # The constant All_My_Pieces should be declared here
  All_My_Pieces = All_Pieces +
                  [ rotations([[0,0],[0,-1],[-1,0],[1,0],[-1,-1]]),
                    [[[-1,0],[0,0],[1,0],[-2,0],[2,0]],
                     [[0,0],[0,-1],[0,1],[0,-2],[0,2]]],
                    rotations([[0,0],[0,-1],[1,0]])]

  # your enhancements here
  @@cheating = false

  def self.cheating= c
    @@cheating = c
  end

  def self.cheating
    @@cheating
  end

  def self.next_piece (board)
    if @@cheating
      @@cheating = false
      MyPiece.new([[[0,0]]], board)
    else
      MyPiece.new(All_My_Pieces.sample, board)
    end
  end
end

class MyBoard < Board
  # your enhancements here
  def initialize (game)
    super(game)
    @grid = Array.new(num_rows) {Array.new(num_columns)}
    @current_block = MyPiece.next_piece(self)
  end

  def next_piece
    @current_block = MyPiece.next_piece(self)
    @current_pos = nil
  end

  def store_current
    locations = @current_block.current_rotation
    displacement = @current_block.position
    locations.length.times {|index| 
      current = locations[index];
      @grid[current[1]+displacement[1]][current[0]+displacement[0]] = 
      @current_pos[index]
    }
    remove_filled
    @delay = [@delay - 2, 80].max
  end

  attr_accessor :score
end

class MyTetris < Tetris
  # your enhancements here
  def set_board
    @canvas = TetrisCanvas.new
    @board = Board.new(self)
    @board = MyBoard.new(self)
    @canvas.place(@board.block_size * @board.num_rows + 3,
                  @board.block_size * @board.num_columns + 6, 24, 80)
    @board.draw
  end

  alias :old_key_bindings :key_bindings
  def key_bindings
    old_key_bindings
    @root.bind('u', proc { 2.times {@board.rotate_clockwise}}) 
    @root.bind('c', proc { self.cheat })
  end

  def cheat
    if not MyPiece.cheating and @board.score >= 100
      @board.score -= 100 
      MyPiece.cheating = true
    end
  end

end


