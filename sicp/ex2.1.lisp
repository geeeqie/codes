(defun make-rat (n d)
  (let ((g (gcd n d)))
	(cons (/ (funcall (if (> (/ n d) 0) #'+ #'-) (abs n))
		 g)
	      (/ (abs d) g))))

(make-rat 4 -8)
(make-rat -4 -8)
(make-rat -4 8)


