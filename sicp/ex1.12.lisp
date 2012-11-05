(defun pascal (x y)
  (cond ((or (= x 1) (= y 1)) 1)
	(t (+ (pascal (- x 1) y) (pascal x (- y 1))))))
(pascal 4 4)
