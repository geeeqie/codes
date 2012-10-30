(defun new1+ (a b)
  (if (= a 0)
      b
      (1+ (new1+ (1- a) b))))
(defun new2+ (a b)
  (if (= a 0)
      b
      (new2+ (1- a) (1+ b))))

(new1+ 10 20)
(new2+ 10 20)
