(defun square (x)
  (* x x))

;;; gen reversed result
(defun square-list1 (items)
  (defun iter (things answer)
    (if (null things)
	answer
	(iter (cdr things)
	      (cons (square (car things))
		    answer))))
  (iter items nil))

;;; gen a weird result
(defun square-list2 (items)
  (defun iter (things answer)
    (if (null things)
	answer
	(iter (cdr things)
	      (cons answer
		    (square (car things))))))
  (iter items nil))

;;; the correct thing
(defun square-list3 (items)
  (defun iter (things answer)
    (if (null things)
	answer
	(iter (cdr things)
	      (append answer
		    (list (square (car things)))))))
  (iter items nil))

(square-list1 (list 1 2 3 4))
(square-list2 (list 1 2 3 4))
(square-list3 (list 1 2 3 4))
