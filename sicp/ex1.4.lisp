(defun a-plus-abs-b (a b)
    (funcall (if (> b 0) #'+ #'-) a b))
(a-plus-abs-b 1 -2)
