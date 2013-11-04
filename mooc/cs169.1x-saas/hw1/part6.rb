class Numeric
    @@currencies = {'dollar'=>1.0, 'yen' => 0.013, 'euro' => 1.292, 'rupee' => 0.019}
    def method_missing(method_id)
        singular_currency = method_id.to_s.gsub( /s$/, '')
        if @@currencies.has_key?(singular_currency)
            return self * @@currencies[singular_currency]
        else
            return super
        end
    end
    def in(c)
        singular_currency = c.to_s.gsub( /s$/, '')
        if @@currencies.has_key?(singular_currency)
            return self / @@currencies[singular_currency]
        else
            return super
        end
    end
end

class String
    def palindrome?
        newstr = self.downcase.gsub(/\W/, "")
        newstr.reverse == newstr
    end
end

module Enumerable
    def palindrome?
        arr = self.collect {|e| e}
        arr.reverse == arr
    end
end
