(defun cube (x)
  (defun cube-iter (guess)
    (let ((new-guess  (improve guess)))
      (if (good-enough? guess new-guess)
	  guess
	  (cube-iter new-guess))))
  (defun good-enough? (guess new-guess)
    (< (/ (abs (- guess new-guess)) guess) 1e-10))
  (defun improve (y)
    (/ (+ (/ x (* y y)) (* 2 y)) 3))
  (cube-iter 1.0))

(cube 27)
