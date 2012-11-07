(defun cube (x) (* x x x))
(defun p (x) (- (* 3 x) (* 4 (cube x))))
(defun sine (angle)
  (if (not (> (abs angle) 0.1))
      angle
      (p (sine (/ angle 3.0)))))
(sine 100)

;;; a) p is used 7 times
;;; b) time and space = O(log_3 (a))

;;; 0: (SINE 10000)
;;;   1: (SINE 3333.3333)
;;;     2: (SINE 1111.1111)
;;;       3: (SINE 370.37036)
;;;         4: (SINE 123.45679)
;;;           5: (SINE 41.152264)
;;;             6: (SINE 13.717422)
;;;               7: (SINE 4.572474)
;;;                 8: (SINE 1.524158)
;;;                   9: (SINE 0.50805265)
;;;                     10: (SINE 0.16935088)
;;;                       11: (SINE 0.056450292)
;;;                         12: (SINE 0.018816764)
;;;                           13: (SINE 0.0062722545)
;;;                           13: SINE returned 0.0062722545
;;;                         12: SINE returned 0.018815776
;;;                       11: SINE returned 0.05642068
;;;                     10: SINE returned 0.16854362
;;;                   9: SINE returned 0.4864796
;;;                 8: SINE returned 0.99891305
;;;               7: SINE returned -0.99023175
;;;             6: SINE returned 0.9132271
;;;           5: SINE returned -0.30678487
;;;         4: SINE returned -0.80486
;;;       3: SINE returned -0.3290279 
;;;     2: SINE returned -0.8446023
;;;   1: SINE returned -0.123808384
;;;0: SINE returned -0.36383396
