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
    (else "No se puede evaluar")
    ))

(define (subst e s v)
  (cond
     ((eq? s e) v)
     ((number? e) e)
     ((sum? e) (make-sum (subst (sum-izq e) s v)
                         (subst (sum-der e) s v)))
     ((mul? e) (make-mul (subst (mul-izq e) s v)
                         (subst (mul-der e) s v)))))             
    
  
          
(define e (make-sum (make-mul 2 3) 4))
(define es (make-sum (make-mul 'x 3) 'x))
  