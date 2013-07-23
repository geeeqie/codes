(defun sqaure (x) (* x x))
(defun smallest-divisor (n)
  (find-divisor n 2))
(defun find-divisor (n test-divisor)
  (cond ((> (square test-divisor) n) n)
	((= (mod n test-divisor) 0) test-divisor)
	(t (find-divisor n (+ test-divisor 1)))))

(smallest-divisor 199)
(smallest-divisor 1999)
(smallest-divisor 19999)

(mapcar #'smallest-divisor (list 199 1999 19999))
