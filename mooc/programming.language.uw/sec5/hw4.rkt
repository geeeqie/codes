
#lang racket

(provide (all-defined-out)) ;; so we can put tests in a second file

;; put your code below

(define (sequence low high stride)
  (if (> low high)
      '()
      (cons low (sequence (+ low stride) high stride))))


(define (string-append-map xs suffix)
  (map (lambda (x) (string-append x suffix)) xs))

(define (list-nth-mod xs n)
  (cond [(< n 0) (error "list-nth-mod: negative number")]
        [(null? xs) (error "list-nth-mod: empty list")]
        [#t (let ([r (remainder n (length xs))])
              (if (= r 0) (car xs)
                  (list-nth-mod (cdr xs) (- r 1))))]))

(define (stream-for-n-steps s n)
  (if (= n 0)
      '()
      (cons (car (s)) (stream-for-n-steps (cdr (s)) (- n 1)))))

(define funny-number-stream
  (letrec ([f (lambda (x) (cons (if (= (remainder x 5) 0) (- x) x)
                                (lambda () (f (+ x 1)))))])
  (lambda () (f 1))))

(define dan-then-dog
  (letrec ([f (lambda (x) (cons (if (= (remainder x 2) 1) "dan.jpg" "dog.jpg")
                                (lambda () (f (+ x 1)))))])
    (lambda () (f 1))))

(define (stream-add-zero s)
  (lambda () (cons (cons 0 (car (s)))
                   (stream-add-zero (cdr (s))))))

(define (cycle-lists xs ys)
  (letrec ([f (lambda (n) (cons (cons (list-nth-mod xs n)
                                      (list-nth-mod ys n))
                                (lambda () (f (+ n 1)))))])
    (lambda () (f 0))))

(define (vector-assoc v vec)
   (define (aux n)
     (cond [(= n (vector-length vec)) #f]
           [(let ([x (vector-ref vec n)])
              (and (pair? x)
                   (equal? (car x) v)))
            (vector-ref vec n)]
           [#t (aux (+ n 1))]))
   (aux 0))

(define (cached-assoc xs n)
  (let ([cache (make-vector n #f)]
        [i 0])
    (lambda (v) (or (vector-assoc v cache)
                    (let ([x (assoc v xs)])
                      (vector-set! cache i x)
                      (set! i (remainder (+ i 1) n))
                      x)))))

(define-syntax my-if 
  (syntax-rules (then else)
    [(my-if e1 then e2 else e3)
     (if e1 e2 e3)]))

(define-syntax while-less
  (syntax-rules (do)
    [(while-less e1 do e2)
     (letrec ([x e1]
           [f (lambda () (begin (and (< e2 x) (f))))])
       (f) #t)]))
