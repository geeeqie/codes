(defun for-each (proc lst)
  (if (null lst)
      nil
      (progn
	(funcall proc (car lst))
	(for-each proc (cdr lst)))))
(for-each (lambda (x) (format t "~a~%" x))
	  (list 57 321 88))
