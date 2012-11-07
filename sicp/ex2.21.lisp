(defun square-list-with-map (lst)
  (mapcar (lambda (x) (* x x)) lst))

(defun square-list (lst)
  (if (null lst)
      nil
      (cons ((lambda (x) (* x x)) (car lst))
	    (square-list (cdr lst)))))
      
(square-list-with-map (list 1 2 3 4))
(square-list (list 1 2 3 4))

