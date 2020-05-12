#lang scheme
(define (make-graph)
  (let ((nodeList '()))

; =========================HELPER FUNCTIONS=====================================================
    (define (append L1 L2)
      (cond ((null? L1) L2)
            (else (cons (car L1)
                        (append (cdr L1) L2)))))
  
    (define (checkList x L)
      (cond ((null?  L) #f)
            ((list? (car L)) (or (checkList x (car L)) (checkList x (cdr L))))
            ((eq? (car L) x) #t)
            (else (checkList x (cdr L)))))

    (define (add-to-list x y L)
      (cond ((null?  L) '())
            ((and (list? (car L)) (eq? (caar L) x)) (cons (add-to-list x y (car L)) (add-to-list x y (cdr L))))
            ((eq? (car L) x) (if (checkList y (cdr L)) (add-to-list x y (cdr L)) (cons x (append (cdr L) (list y))))); first element found
            ((and (list? (car L)) (not (eq? (caar L) x))) (cons (car L) (add-to-list x y (cdr L))))))
    
    (define (remove-from-list x y L)
      (cond ((null?  L) '())
            ((and (list? (car L)) (eq? (caar L) x)) (cons (remove-from-list x y (car L))  (cdr L)))
            ((eq? (car L) y) (remove-from-list x y (cdr L)))
            ((and (list? (car L)) (not (eq? (caar L) x))) (cons (car L) (remove-from-list x y (cdr L))))
            (else (cons (car L) (remove-from-list x y (cdr L))))))

    (define (exists x L)
       (cond ((null?  L) '())
            ((and (list? (car L)) (null? (cdr L))) (exists x (car L)))
            ((and (list? (car L)) (not(null? (cdr L)))) (cons (exists x (car L)) (exists x (cdr L))))
            ((eq? (car L) x) (exists x (cdr L)))
            (else (cons (car L) (exists x (cdr L))))))
            
;============================END OF HELPER FUNCTIONS==================================================
;QUESTION 4 PART A
    
    (define (add-node x)
      (if (checkList x  nodeList) #f (begin
                              (set! nodeList (append   nodeList (list (list x)))) #t)))
 ;;QUESTION 4 PART B
    (define (add-edge x y)
      (if (and (checkList x nodeList) (checkList y nodeList))
          (begin
            (set! nodeList (add-to-list x y nodeList) ) #t) #f))

;QUESTION 4 PART C
    (define (remove-edge x y)
      (if (and (checkList x nodeList) (checkList y nodeList))
          (begin
            (set! nodeList (remove-from-list x y nodeList) ) #t) #f))
    
;QUESTION 4 PART D
    (define (remove-node x)
      (if (checkList x nodeList)
          (begin (set! nodeList (exists x nodeList)) #t) #f))
      
;QUESTION 4 PART E
    
    (define (dsplay)

      (define (line)
        (lambda (L) (cond ((null? L) (newline))
                          ((list? (car L)) ((line) (car L)) (display ": ") ((line) (cdr L)))
                          (else (display (car L)) (display " ") ((line) (cdr L))))))
      
      ((line) nodeList))
                                     
                                     

;ULTIMATE FUNCTION TO CALL EACH FUNCTION
    
      (define (f method)
        (cond ((eq? method 'add-node) add-node)
              ((eq? method 'add-edge) add-edge)
              ((eq? method 'remove-node) remove-node)
              ((eq? method 'remove-edge) remove-edge)
              ((eq? method 'dsplay) dsplay)
              (else (lambda() (display "Unknown Request: ")
                      (display method) (newline))) ))
    f))

(define G (make-graph))


;X============X=================> TESTING OF QUESTION 4 <=====================X==================X

(display "QUESTION 4 A\n") ;======PART A=========

(display "(QUESTION 4 PART A, (Case 1) ((G 'add-node) 'a) )=> ")(newline)
(display "Expected: #t")(newline)
(display "Actual: ") ((G 'add-node) 'a) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 4 PART A, (Case 2) ((G 'add-node) 'b) )=> ")(newline)
(display "Expected: #t")(newline)
(display "Actual: ") ((G 'add-node) 'b) (newline) ; SCHEME EXPRESSION
    
(display "(QUESTION 4 PART A, (Case 3) ((G 'add-node) 'c) )=> ")(newline)
(display "Expected: #t")(newline)
(display "Actual: ") ((G 'add-node) 'c) (newline) ; SCHEME EXPRESSION
    
(display "(QUESTION 4 PART A, (Case 4) ((G 'add-node) 'a) )=> ")(newline)
(display "Expected: #f")(newline)
(display "Actual: ") ((G 'add-node) 'a) (newline) ; SCHEME EXPRESSION


(display "QUESTION 4 B\n") ;======PART B=========

(display "(QUESTION 4 PART B, (Case 1) ((G 'add-edge) 'a 'b)  )=> ")(newline)
(display "Expected: #t")(newline)
(display "Actual: ") ((G 'add-edge) 'a 'b)  (newline) ; SCHEME EXPRESSION


(display "(QUESTION 4 PART B, (Case 2) ((G 'add-edge) 'a 'c)  )=> ")(newline)
(display "Expected: #t")(newline)
(display "Actual: ") ((G 'add-edge) 'a 'c)  (newline) ; SCHEME EXPRESSION

(display "(QUESTION 4 PART B, (Case 3) ((G 'add-edge) 'b 'b)  )=> ")(newline)
(display "Expected: #t")(newline)
(display "Actual: ") ((G 'add-edge) 'b 'b)  (newline) ; SCHEME EXPRESSION

(display "(QUESTION 4 PART B, (Case 4) ((G 'add-edge) 'b 'c)  )=> ")(newline)
(display "Expected: #t")(newline)
(display "Actual: ") ((G 'add-edge) 'b 'c)  (newline) ; SCHEME EXPRESSION

(display "(QUESTION 4 PART B, (Case 5) ((G 'add-edge) 'c 'd)  )=> ")(newline)
(display "Expected: #f")(newline)
(display "Actual: ") ((G 'add-edge) 'c 'd)  (newline) ; SCHEME EXPRESSION

;Testing Part E at this point
(display "Testing Part E at this point\n")
(display "(QUESTION 4 PART E, (Display Function) ((G 'display))  )=> ")(newline)
(display "Expected: a: b c")(newline)
(display "b: b c")(newline)
(display "c: ")(newline)
(display "Actual: ") ((G 'dsplay)) (newline) ; SCHEME EXPRESSION
;((G 'dsplay)) 

(display "QUESTION 4 C\n") ;======PART C=========

(display "(QUESTION 4 PART C, (Case 1) ((G 'remove-edge) 'a 'c)  )=> ")(newline)
(display "Expected: #t")(newline)
(display "Actual: ") ((G 'remove-edge) 'a 'c)  (newline) ; SCHEME EXPRESSION



(display "QUESTION 4 D\n") ;======PART D=========

(display "(QUESTION 4 PART D, (Case 1) ((G 'remove-node) 'c)  )=> ")(newline)
(display "Expected: #t")(newline)
(display "Actual: ") ((G 'remove-node) 'c)  (newline) ; SCHEME EXPRESSION



(display "QUESTION 4 E\n") ;======PART E=========

(display "(QUESTION 4 PART E, (Display Function) ((G 'display))  )=> ")(newline)
(display "Expected: a: b")(newline)
(display "b: b")(newline)
(display "Actual: ") ((G 'dsplay)) (newline) ; SCHEME EXPRESSION








