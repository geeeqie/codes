;;; define my-sqrt
(defun sqrt-iter (guess x)
  (if (good-enough? guess (improve guess x))
      guess
      (sqrt-iter (improve guess x) x)))
(defun improve (guess x)
  (average guess (/ x guess)))
(defun average (x y)
  (/ (+ x y) 2))
(defun good-enough? (guess new-guess)
  (< (/ (abs (- guess new-guess)) guess) 0.001))
(defun square (x) (* x x))
(defun my-sqrt (x)
  (sqrt-iter 1.0 x))
;;; end define my-sqrt
(my-sqrt 2)
