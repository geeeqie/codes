(defun my-equal (lst1 lst2)
  (let ((item1 (car lst1))
	(item2 (car lst2)))
    (cond ((and (eq lst1 nil)
		(eq lst2 nil))
		t)
	  ((or (eq lst1 nil)
	       (eq lst2 nil))
	   nil)
	  ((and (not (consp item1))
		(not (consp item2))
		(eq item1 item2))
	   (my-equal (cdr lst1) (cdr lst2)))
	  ((and (consp item1)
		(consp item2))
	   (and (my-equal item1 item2)
		(my-equal (cdr lst1) (cdr lst2))))
	  (t nil))))

(my-equal '((a b) (c e d)) '((a b) (c e d)))



