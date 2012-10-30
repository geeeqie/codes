(defun f-rec (n)
  (cond ((< n 3) n)
	((>= n 3) (+ (f (- n 1))
		     (* 2 (f (- n 2)))
		     (* 3 (f (- n 3)))))))

(defun f-iter (n fn-1 fn-2 fn-3)
  (cond ((< n 3) n)
	(t (f-iter (- n 1)
		   (+ fn-1 (* 2 fn-2) (* 3 fn-3))
		   fn-1
		   fn-2))))
(f-rec 5)
(f-iter 5)
