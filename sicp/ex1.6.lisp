;;; define my-sqrt
(defun sqrt-iter (guess x)
  (if (good-enough? guess x)
      guess
      (sqrt-iter (improve guess x) x)))
(defun improve (guess x)
  (average guess (/ x guess)))
(defun average (x y)
  (/ (+ x y) 2))
(defun good-enough? (guess x)
  (< (abs (- (square guess) x)) 0.001))
(defun square (x) (* x x))
(defun my-sqrt (x)
  (sqrt-iter 1.0 x))
;;; end define my-sqrt

(defun new-if (predicate then-clause else-clause)
  (cond (predicate then-clause)
	(t else-clause)))
(new-if (= 2 3) 0 5)
(new-if (= 1 1) 0 5)
(my-sqrt 0.0000001)
(my-sqrt 70000)

(new-if (= 2 3) (print "a") (print "b"))
(+ 1 2)
