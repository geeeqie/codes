(defvar *line*)
(setf *line* (read-line))
(defvar *letters* (remove-if-not #'alpha-char-p *line*)

