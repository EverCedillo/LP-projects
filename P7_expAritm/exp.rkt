#lang racket
(define-struct sum (izq der))
(define-struct mul (izq der))

(define (exp-num? n)
  (cond
    ((number? n) #t )
    ((sum? n) (and(exp-num? (sum-izq n))
                  (exp-num? (sum-der n))))
    ((mul? n) (and(exp-num? (mul-izq n))
                  (exp-num? (mul-der n))))
    (else #f)
    ))

(define (eval en)
   (cond
    ((number? en) en )
    ((sum? en) (+(eval (sum-izq en))
                  (eval (sum-der en))))
    ((mul? en) (*(eval (mul-izq en))
                  (eval (mul-der en))))
    (else "Error")
    ))
          
(define e (make-sum (make-mul 2 3) 4))