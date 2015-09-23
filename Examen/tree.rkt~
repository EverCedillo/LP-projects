#lang racket
(require test-engine/racket-tests)
;Árbol vacío
(define empty-tree '());
;Construye un nodo de arbol con su contenido y sus dos hijos
(check-expect (make-node 0 '() '()) '(0 '() '()))
(define (make-node data left right)(list data left right))
;Devuelve el hijo izquierdo de un nodo
(check-expect (left-node t) '())
;
(define (left-node node) (cadr node))
;Devuelve el hijo derecho de un nodo
(check-expect (right-node t) '())
;
(define (right-node node) (caddr node))
;Dvuelve el dato almacenado en un nodo
(check-expect (data-node t) 4)
;
(define (data-node node) (car node))
;Construye un arbol (nodo-raíz con hijos vaciós)
(check-expect (make-tree 4) '(4 () ()))
;
(define (make-tree data) (make-node data '() '() ))
;Devuelve #t si el arbol está vacío #f de lo contrario
(check-expect (empty-tree? '()) #t)
;
(define (empty-tree? t) (or (empty? t) (null? t)))
;Devuelve #t si el nodo es una hoja, #f de lo contrario
(check-expect (leaf-node? t) #t)
;
(define (leaf-node? t) (and (empty-tree? (right-node t))(empty-tree? (left-node t))))
;Devuelve una lista con los datos resultado del recorrido inorder del árbol
(check-expect (inorder-tree t6) '(1 3 4 6 7 8 10 13 14))
;
(define (inorder-tree t)
  (if (empty-tree? t)
      '()(append (inorder-tree (left-node t))
                 (list(data-node t))
                 (inorder-tree (right-node t)))))
;Devuelve una lista con los datos resultado del recorrido preorder del árbol
(check-expect (preorder-tree t6) '(8 3 1 6 4 7 10 14 13))
;
(define (preorder-tree t)
  (if (empty-tree? t)
      '()(append (list(data-node t))
                 (preorder-tree (left-node t))
                 (preorder-tree (right-node t)))))
;Devuelve una lista con los datos resultado del recorrido postorder del árbol
(check-expect (preorder-tree t6) '(1 4 7 6 3 13 14 10 8))
;
(define (postorder-tree t)
  (if (empty-tree? t)
      '()(append (postorder-tree (left-node t))
                 (postorder-tree (right-node t))
                 (list(data-node t)))))
;Devuelve un árbol, t con la añadiruda de un dato d
(check-expect (insert-tree empty-tree 1) '(1 '() '()))
;
(define (insert-tree t d)
  (cond
    ((empty-tree? t) (make-node d '() '()))
    ((< d (data-node t))(make-node (data-node t)(insert-tree (left-node t) d)(right-node t)))
    ((> d (data-node t))(make-node (data-node t)(left-node t)(insert-tree (right-node t) d)))
    ((= d (data-node t)) t)))
;Devuelve #t si un dato d se encuentra en un árbol t; #f de lo contrario
(check-expect (member-tree? t6 10) #t)
;
(define (member-tree? t d)
  (cond
    ((empty-tree? t) #f)
    ((= d (data-node t)) #t)
    ((< d (data-node t))(member-tree? (left-node t) d))
    ((> d (data-node t))(member-tree? (right-node t) d))))
;Subtree
(check-expect (sub-tree t1 3) empty-tree)
;
(define (sub-tree t d)
    (cond
    ((empty-tree? t) '())
    ((= d (data-node t)) t)
    ((< d (data-node t))(sub-tree (left-node t) d))
    ((> d (data-node t))(sub-tree (right-node t) d))))
;Devuelve un árbol, t con la añadidura de lo datos en la lista l
(check-expect (insert-list-to-tree '(1) empty-tree) (make-tree 1))
;
(define (insert-list-to-tree l t)
  (if (null? l)
      t(insert-list-to-tree (cdr l) (insert-tree t (car l)))))
;Devuelve un árbol, t sin el dato d
(check-expect (delete-tree t1 4) empty-tree)
;
(define (delete-tree t d)
  (if (member-tree? t d)
      (insert-list-to-tree (remove d (preorder-tree t)) '())t))
;---Lazy mirror---
;Inserta elementos con el criterio de orden inverso
(check-expect (insertR-tree empty-tree 1) '(1 '() '()))
;
(define (insertR-tree t d)
  (cond
    ((empty-tree? t) (make-node d '() '()))
    ((> d (data-node t))(make-node (data-node t)(insertR-tree (left-node t) d)(right-node t)))
    ((< d (data-node t))(make-node (data-node t)(left-node t)(insertR-tree (right-node t) d)))
    ((= d (data-node t)) t)))
;Devuelve un árbol, t con la añadidura de lo datos en la lista l (inverso)
(check-expect (insert-list-to-tree '(1) empty-tree) (make-tree 1))
;
(define (insertR-list-to-tree l t)
  (if (null? l)
      t(insertR-list-to-tree (cdr l) (insertR-tree t (car l)))))  
;Devuelve un árbol, espejo del árbol t
(check-expect (mirror-tree t2) '(4 (5 () ()) (3 () ())))
(define (mirror-tree t)
  (insertR-list-to-tree (preorder-tree t) '()))

;Árbol gráfico
(define (display-tree t)
  (define (disp t n)
    (if (empty-tree? t)
      ""(string-append (b-string n)(number->string(data-node t))"\n"
                     (disp (left-node t) (+ n 1))
                     (disp (right-node t)(+ n 1)))))(display (disp t 1))
  )
;Auxiliar de construcción de cadena para el árbol gráfico
(define (b-string n)
  (if (= 1 n) "├─"
  (string-append "│ "(b-string (- n 1)))))

      

;Árbol de ejemplo  

(define t(make-tree 4))
(define t1(insert-tree t 3))
(define t2(insert-tree t1 5))
(define t3(insert-tree t2 7))
(define t4(insert-list-to-tree (list 1 2 3 4 5 1 0 212 34 12 55 33 234 11 723) '()))
(define t5(mirror-tree t4))
(define t6(insert-list-to-tree (list 8 3 10 1 6 4 7 14 13) '()))

