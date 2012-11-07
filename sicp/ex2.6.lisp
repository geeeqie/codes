(defvar zero (lambda (f) (lambda (x) x)))
(defun add-1 (n)
  (lambda (f) (lambda (x) (f ((n f) x)))))
(add-1 #'(add-1 #'zero))
