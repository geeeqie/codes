(list 'a 'b 'c)
(list (list 'george))
(cdr '((x1 x2) (y1 y2)))
(cadr '((x1 x2) (y1 y2)))
(consp (car '(a short list)))

(defun memq (item x)
  (cond ((null x) nil)
	((eq item (car x)) x)
	(t (memq item (cdr x)))))

(memq 'red '((red shoes) (blue socks)))
(memq 'red '(red shoes blue socks))

(eq (list 'a 'b) (list 'a 'b))

