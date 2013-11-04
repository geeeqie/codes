class CartesianProduct
  include Enumerable
  def initialize(seq1, seq2)
      @seq1 = seq1
      @seq2 = seq2
  end
  def each
      @seq1.each do |x|
          @seq2.each do |y|
              yield [x, y]
          end
      end
  end
end

