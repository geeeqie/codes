def combine_anagrams(words)
    anagrams = Hash.new { |k,v| k[v]=[] }
    words.each do |w|
        sorted_word = w.downcase.chars.sort.join
        anagrams[sorted_word] << w
    end
    anagram_array = []
    anagrams.each do |k, v|
        anagram_array << v
    end
    return anagram_array
end
