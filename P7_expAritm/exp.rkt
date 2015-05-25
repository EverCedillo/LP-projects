#lang racket
(require test-engine/racket-tests)
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
;--------------
(check-expect (evaluar 5) 5)
(check-expect (evaluar 'x) "No se puede evaluar")
(check-expect (evaluar (make-sum 3 5)) 8)
(check-expect (evaluar (make-mul 3 5)) 15)
(check-expect (evaluar (make-sum 3 'z)) "No se puede evaluar")
(check-expect (evaluar (make-mul 'x 'y)) "No se puede evaluar")
;--------------
(define (evaluar en)
  (if (exp-num? en)
   (cond
    ((number? en) en )
    ((sum? en) (+(evaluar (sum-izq en))
                  (evaluar (sum-der en))))
    ((mul? en) (*(evaluar (mul-izq en))
                  (evaluar (mul-der en))))
    ;(else "No se puede evaluar")
    )"No se puede evaluar"))

;--------------
(check-expect (subst 5 'x 2) 5)
(check-expect (subst 'x 'x 2) 2)
(check-expect (subst (make-sum 3 5) 'x 2) (make-sum 3 5))
(check-expect (subst (make-sum (make-mul 3 'x) (make-mul 4 'x)) 'x 2)
              (make-sum (make-mul 3 2) (make-mul 4 2)))
(check-expect (subst (make-sum (make-mul 'x 'y) (make-mul 'x 'z)) 'x 2)
              (make-sum (make-mul 2 'y) (make-mul 2 'z)))
;--------------
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
(test)