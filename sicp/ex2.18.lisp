(defun my-reverse (lst)
  (if (null lst)
      '()
      (append (my-reverse (cdr lst))
	      (list (car lst)))))

(my-reverse (list 1 4 9 16 25))
