#lang scheme
;Khushal Kumar Singh
;101094697

; ==================QUESTION 1 A========================
(define square (lambda(x) (* x x)))
(define double (lambda(x) (+ x x)))

(define (compose f g) (lambda (x) (f (g x))))
(newline)


; ==================QUESTION 1 B========================
(define (divisibleBy x)
  (lambda (temp) (if (= (remainder temp  x) 0) #t #f)
  ))

(define mod3 (divisibleBy 3))
(newline)


; ==================QUESTION 1 C========================


(define (newmap f)
    (lambda (y)
        (if (null? y) '() (cons (f (car y)) ( (newmap f) (cdr y) )))))

(define double-mapper (newmap (lambda(x) (* x 2))))
(newline)


; ==================QUESTION 1 D========================

(define (newfilter f)
  (lambda (y)
        (if (null? y) '() (if (f (car y)) (cons (car y) ((newfilter f) (cdr y))) ((newfilter f) (cdr y)) ))))

(define evens-filter (newfilter (divisibleBy 2)))
(define threes-filter (newfilter (divisibleBy 3)))
(newline)



; ==================QUESTION 1 E========================

(define (range a b)
  (if (> a b) '()
      (cons a (range (+ a 1) b))))

;(define myfunc (newmap (lambda(x) (* x 2))) )
;	(myfunc (range 1 20)) ; → (16 64 144 256 400)

;(define myfunc1 (newmap (lambda(x)(* x x) (newfilter (divisibleBy 2)) )))
;	(myfunc1 (range 1 20)) ; → (16 64 144 256 400)


(define myfunc1  (lambda (x) ((newmap (lambda(x)(* x x))) ((newfilter (divisibleBy 4)) x))))

;X============X=================> TESTING OF QUESTION 1 <=====================X==================X

(display "QUESTION 1 A\n") ;======PART A=========

(display "(QUESTION 1 PART A, (Case 1) ((compose square double) 3))=> ")(newline)
(display "Expected: 36")(newline)
(display "Actual: ")((compose square double) 3)(newline) ; SCHEME EXPRESSION

(display "(QUESTION 1 PART A, (Case 2) ((compose sqrt sqrt) 16))=> ")(newline)
(display "Expected: 2")(newline)
(display "Actual: ")((compose sqrt sqrt) 16)(newline) ; SCHEME EXPRESSION

(display "(QUESTION 1 PART A, (Case 3) ((compose square double) 1))=> ")(newline)
(display "Expected: 4")(newline)
(display "Actual: ")((compose square double) 1)(newline) ; SCHEME EXPRESSION

(display "QUESTION 1 B\n") ;======PART B=========

(display "(QUESTION 1 PART B, (Case 1) (mod3 7) )=> ")(newline)
(display "Expected: #f")(newline)
(display "Actual: ")(mod3 7) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 1 PART B , (case 2) (mod3 9))=> ")(newline)
(display "Expected: #t")(newline)
(display "Actual: ")(mod3 9)(newline) ; SCHEME EXPRESSION

(display "QUESTION 1 C\n") ;======PART C=========

(display "(QUESTION 1 PART C, (Case 1) (double-mapper '(1 2 3 4)) )=> ")(newline)
(display "Expected: (2 4 6 8)")(newline)
(display "Actual: ")(double-mapper '(1 2 3 4)) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 1 PART C , (Case 2) (double-mapper '(10 20 30)))=> ")(newline)
(display "Expected: (20 40 60)")(newline)
(display "Actual: ")(double-mapper '(10 20 30))(newline) ; SCHEME EXPRESSION

(display "QUESTION 1 D\n") ;======PART D=========

(display "(QUESTION 1 PART D, (Case 1) (evens-filter '(1 2 3 4 6 8 10 11 13 12 15 9 29 30 31 33)) )=> ")(newline)
(display "Expected: (2 4 6 8 10 12 30)")(newline)
(display "Actual: ")(evens-filter '(1 2 3 4 6 8 10 11 13 12 15 9 29 30 31 33)) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 1 PART D , (Case 2) (threes-filter '(1 2 3 4 6 8 10 11 13 12 15 9 29 30 31 33)))=> ")(newline)
(display "Expected: (3 6 12 15 9 30 33)")(newline)
(display "Actual: ")(threes-filter '(1 2 3 4 6 8 10 11 13 12 15 9 29 30 31 33))(newline) ; SCHEME EXPRESSION

(display "QUESTION 1 E\n") ;======PART E=========
(display "(QUESTION 1 PART E, (Case 1) (myfunc1 (range 1 20)) )=> ")(newline)
(display "Expected: (16 64 144 256 400)")(newline)
(display "Actual: ")(myfunc1 (range 1 20)) (newline) ; SCHEME EXPRESSION


(display "(QUESTION 1 PART E, (Case 2) (myfunc1 (range 20 40)) )=> ")(newline)
(display "Expected: (400 576 784 1024 1296 1600)")(newline)
(display "Actual: ")(myfunc1 (range 20 40)) (newline) ; SCHEME EXPRESSION


;X============X=================> END OF QUESTION 1 TESTING <=====================X==================X

; ==================QUESTION 2 A========================

(define (repeat x n)
  (if (> n 0) (cons x (repeat x (- n 1))) '() ))


; ==================QUESTION 2 B========================

;we are using professor's code here

(define (append L1 L2)
  (cond ((null? L1) L2)
        (else (cons (car L1)
               (append (cdr L1) L2)))))
;(append (list 1 2 3 7 8)(list 4 5 6))

(define (alternate list1 list2)
  (cond ;((and (null? L1) (null? L2)) (append L1 L2))
        ((null? list1) list2)
        ((null? list2) list1)
        (else (append (list (car list1) (car list2))
               (alternate (cdr list1) (cdr list2))))))


; ==================QUESTION 2 C========================

(define (count x L)
  (define (helper num x L)
    (if (null? L) num
        (if (eq? x (car L)) (helper (+ num 1) x (cdr L)) (helper num x (cdr L)))))
  (helper 0 x L)
  )


; ==================QUESTION 2 D========================


(define (mode L)
  (define (helper x L1 L2)
    (cond ((null? L1) x)
          ((> (count (car L1) L2) (count x L2)) (helper (car L1) (cdr L1) L2))
          (else (helper x (cdr L1) L2))))
  (helper (car L) L L))


;(define (decreasing L)

; ==================QUESTION 2 E========================

#|(define (consize L)
  (define (helper prev L)
    (cond ((and (null? (cdr L)) (not (< (car L) prev)))'())
          ((and (null? (cdr L)) (< (car L) prev)) (cons (car L) '()))
          ((< (car L) prev) (cons (car L) '()))
          ((> (car L) (cadr L)) (cons (car L) (helper (car L) (cdr L))))
          (else (helper (car L) (cdr L) ))
          ))
  (helper 0 L ))

#|(define (decreasing L)
  
  (define next (if (null? (cdr L)) '() (cadr L)))
  
  (define (helper L prev)
    (cond ((null? L) '())
          ((or(> (car L) next) (< (car L) prev)) (list (cons (car L) (helper (cdr L) (car L))))
          (else (helper (cdr L) (car L)))))
  (helper (consize L) 0))|#




      
(consize '(1 2 3 4 5 6 7))
(consize '(3 6 8 9 7 4 8 6 3))
(consize '(7 6 5 4 8 5 2 5 1 5 2 1))

;(decreasing '(1 2 3 4 5 6 7))
;(decreasing '(3 6 8 9 7 4 8 6 3))
;(decreasing '(7 6 5 4 8 5 2 5 1 5 2 1))|#


(define (helper prev L)
    (cond ((null? (cdr L)) (list (car L)))
          ((> (car L) (cadr L)) (append (list (car L)) (helper (car L) (cdr L))))
          ((< (car L) prev) (list (car L)))))

(define (decreasing L)
    (cond ((null? (cdr L)) '())
          ((< (car L) (cadr L)) (decreasing (cdr L)))
          ( else (cons (helper  0 L) (decreasing (cdr L)) ))))


;X============X=================> TESTING OF QUESTION 2 <=====================X==================X

(display "QUESTION 2 A\n") ;======PART A=========

(display "(QUESTION 2 PART A, (Case 1) (repeat 'b 5) )=> ")(newline)
(display "Expected: (b b b b b)")(newline)
(display "Actual: ")(repeat 'b 5) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 2 PART A, (Case 2) (repeat '6 9) )=> ")(newline)
(display "Expected: (6 6 6 6 6 6 6 6 6)")(newline)
(display "Actual: ")(repeat '6 9) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 2 PART A, (Case 3) (repeat 'x 7) )=> ")(newline)
(display "Expected: (x x x x x x x)")(newline)
(display "Actual: ")(repeat 'x 7)(newline) ; SCHEME EXPRESSION

(display "QUESTION 2 B\n") ;======PART B=========

(display "(QUESTION 2 PART B, (Case 1) (alternate (list 1 2 3)(list 4 5 6)) )=> ")(newline)
(display "Expected: (1 4 2 5 3 6)")(newline)
(display "Actual: ")(alternate (list 1 2 3)(list 4 5 6)) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 2 PART B , (case 2) (alternate '(0 0 0 0) '(1 1 1 1 1 1)) )=> ")(newline)
(display "Expected: (0 1 0 1 0 1 0 1 1 1)")(newline)
(display "Actual: ")(alternate '(0 0 0 0) '(1 1 1 1 1 1))(newline) ; SCHEME EXPRESSION

(display "QUESTION 2 C\n") ;======PART C=========

(display "(QUESTION 2 PART C, (Case 1) (count 3 '(1 4 3 6 2 3 3 1 4 3 5 7)) )=> ")(newline)
(display "Expected: 4")(newline)
(display "Actual: ") (count 3 '(1 4 3 6 2 3 3 1 4 3 5 7)) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 2 PART C , (Case 2) (count 'b '(4 b a 3 2 c b 1 b 2 d a)) )=> ")(newline)
(display "Expected: 3")(newline)
(display "Actual: ")(count 'b '(4 b a 3 2 c b 1 b 2 d a)) (newline) ; SCHEME EXPRESSION

(display "QUESTION 2 D\n") ;======PART D=========

(display "(QUESTION 2 PART D, (Case 1) (mode '(a b a c a d d a b c a b)) )=> ")(newline)
(display "Expected: a")(newline)
(display "Actual: ")(mode '(a b a c a d d a b c a b)) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 2 PART D , (Case 2) (mode '(c b a x 2 3 c 1 b 2 c a)) )=> ")(newline)
(display "Expected: c")(newline)
(display "Actual: ")(mode '(c b a x 2 3 c 1 b 2 c a)) (newline) ; SCHEME EXPRESSION

(display "QUESTION 2 E\n") ;======PART E=========
(display "(QUESTION 2 PART E, (Case 1) (decreasing '(3 6 8 9 7 4 8 6 3)) )=> ")(newline)
(display "Expected: ((9 7 4) (7 4) (8 6 3) (6 3))")(newline)
(display "Actual: ")(decreasing '(3 6 8 9 7 4 8 6 3)) (newline) ; SCHEME EXPRESSION


(display "(QUESTION 2 PART E, (Case 2) (decreasing '(7 6 5 4 8 5 2 5 1 5 2 1)) )=> ")(newline)
(display "Expected: ((7 6 5 4) (6 5 4) (5 4) (8 5 2) (5 2) (5 1) (5 2 1) (2 1))")(newline)
(display "Actual: ") (decreasing '(7 6 5 4 8 5 2 5 1 5 2 1)) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 2 PART E, (Case 3) (decreasing '(1 2 3 4 5)) )=> ")(newline)
(display "Expected: ()")(newline)
(display "Actual: ") (decreasing '(1 2 3 4 5)) (newline) ; SCHEME EXPRESSION


;X============X=================> END OF QUESTION 2 TESTING <=====================X==================X


; ==================QUESTION 3 A========================

(define (treeReduce op ini T)
  (cond ((null? T)  ini)
        ((list? (car T)) (op ini (treeReduce op ini (car T)) (treeReduce op ini (cdr T))))
        (else (op (car T) (treeReduce op ini (cdr T))))))



; ==================QUESTION 3 B========================

(define (height L)
  (define (helper h L)
    (cond ((not (list? L)) 0)
          ((null?  L) h)
          ((list? (car L)) (helper (+ h 1) (car L)))
          (else (helper h (cdr L))) ))
  (helper 1 L)
 )


; ==================QUESTION 3 C========================

(define (flattenTree T)
  (cond ((null? T) '())
        ((list? (car T)) (append (flattenTree (car T)) (flattenTree (cdr T))))
        (else (cons (car T) (flattenTree (cdr T))))))


; ==================QUESTION 3 D========================

(define (scale-tree t x)
  (cond ((null? t) '())
        ((list? (car t)) (cons (scale-tree (car t) x)
                               (scale-tree (cdr t) x)))
        (else (cons (* x (car t))
                    (scale-tree (cdr t) x)))))

(define (treeMerge T1 T2)
  (cond ((null? T1) T2) ;if first tree null then return other tree
        ((null? T2) T1) ;if second tree null then first other tree
        ((and (list? (car T1)) (not(list? (car T2)))) (cons (scale-tree (car T1) (car T2)) (treeMerge (cdr T1) (cdr T2)))) ; if car T1 is list and car T2 is sigle value then scale
        ((and (list? (car T2)) (not(list? (car T1)))) (cons (scale-tree (car T2) (car T1)) (treeMerge (cdr T1) (cdr T2)))) ; if car T2 is list and car T1 is sigle value then scale
        ((and (list? (car T2)) (list? (car T1))) (cons (treeMerge (car T1) (car T2)) (treeMerge (cdr T1) (cdr T2)))) ; both tree's car is list then cons of (send them as trees) + cdr part of both 
        (else (cons (* (car T1) (car T2)) (treeMerge (cdr T1) (cdr T2)))))) ; else part both trees car is single element so multiply them



;X============X=================> TESTING OF QUESTION 3 <=====================X==================X

(display "QUESTION 3 A\n") ;======PART A=========

(display "(QUESTION 3 PART A, (Case 1) (treeReduce + 0 '(1 (2 3)((4 5) 6 (7)((8 (9)) 10)))) )=> ")(newline)
(display "Expected: 55")(newline)
(display "Actual: ")(treeReduce + 0 '(1 (2 3)((4 5) 6 (7)((8 (9)) 10)))) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 3 PART A, (Case 2) (treeReduce + 0 '(1 (2 3)((4 5) 6 (7)((8 (9)) 10 (11 12 (13) ))))) )=> ")(newline)
(display "Expected: 91")(newline)
(display "Actual: ")(treeReduce + 0 '(1 (2 3)((4 5) 6 (7)((8 (9)) 10 (11 12 (13) ))))) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 3 PART A, (Case 3) (treeReduce * 1 '(1 (2 3)((4 5)))) )=> ")(newline)
(display "Expected: 120")(newline)
(display "Actual: ")(treeReduce * 1 '(1 (2 3)((4 5)))) (newline) ; SCHEME EXPRESSION

(display "QUESTION 3 B\n") ;======PART B==================

(display "(QUESTION 3 PART B, (Case 1) (height 'a) )=> ")(newline)
(display "Expected: 0")(newline)
(display "Actual: ")(height 'a) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 3 PART B, (Case 2) (height '(a)) )=> ")(newline)
(display "Expected: 1")(newline)
(display "Actual: ") (height '(a)) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 3 PART B, (Case 3) (height '(a (b) c)) )=> ")(newline)
(display "Expected: 2")(newline)
(display "Actual: ") (height '(a (b) c)) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 3 PART B, (Case 4) (height '(((((a(((b))))))))) )=> ")(newline)
(display "Expected: 8")(newline)
(display "Actual: ") (height '(((((a(((b))))))))) (newline) ; SCHEME EXPRESSION

(display "QUESTION 3 C\n") ;======PART C=========

(display "(QUESTION 3 PART C, (Case 1) (flattenTree '(1 (2 3) ((4 5 6 (7)))(((8 (9)))))) )=> ")(newline)
(display "Expected: (1 2 3 4 5 6 7 8 9)")(newline)
(display "Actual: ")(flattenTree '(1 (2 3) ((4 5 6 (7)))(((8 (9)))))) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 3 PART C, (Case 2) (flattenTree '(1 (2 3)((4 5) 6 (7)((8 (9)) 10)))) )=> ")(newline)
(display "Expected: (1 2 3 4 5 6 7 8 9 10) ")(newline)
(display "Actual: ")(flattenTree '(1 (2 3)((4 5) 6 (7)((8 (9)) 10)))) (newline) ; SCHEME EXPRESSION

(display "QUESTION 3 D\n") ;======PART D=========

(display "(QUESTION 3 PART D, (Case 1) (treeMerge '(2 (2 3)(4 5 ( 5 6 7))) '((5 (4 3)( 2 1))6 ( 7 8 ))) )=> ")(newline)
(display "Expected: ((10 (8 6) (4 2)) (12 18) (28 40 (5 6 7))) ")(newline)
(display "Actual: ") (treeMerge '(2 (2 3)(4 5 ( 5 6 7))) '((5 (4 3)( 2 1))6 ( 7 8 ))) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 3 PART D, (Case 2) (treeMerge '(1 (2 3)((4 5))) '(6 (7)((8 (9)) 10)) )=> ")(newline)
(display "Expected: (6 (14 3) ((32 (45)) 10)) ")(newline)
(display "Actual: ") (treeMerge '(1 (2 3)((4 5))) '(6 (7)((8 (9)) 10))) (newline) ; SCHEME EXPRESSION

;X============X=================> END OF QUESTION 2 TESTING <=====================X==================X

;================HELPER FUNCTIONS====================
(define-syntax stream-cons
    (syntax-rules ()
        ((stream-cons a b)(cons a (delay b)))))

(define (stream-car stream) 
    (car stream))
		
(define (stream-cdr stream)
    (force (cdr stream)))

;================END OF HELPER FUNCTIONS===============

; ==================QUESTION 4 A========================
(define (list->stream L)
  (if (null? L) '() (stream-cons (car L) (list->stream (cdr L)))))

; ==================QUESTION 4 B========================

(define (stream->list strm n)
  (define (helper strm x)
    (cond ((null? strm) '())
          ((>= x n) '())
          (else (cons (stream-car strm) (helper (stream-cdr strm) (+ x 1)) ))))
  (helper strm 0))


; ==================QUESTION 4 C========================

(define (factorial n)
  (define (helper counter total)
    (if (> counter n) total
        (helper (+ counter 1)  (* total counter))))
  (helper 1 1))
;Taken from professor's Lecture code


    
(define factorials (stream-cons (factorial 0) (stream-cons (factorial 1)
        (stream-cons (factorial 2) (stream-cons (factorial 3) (stream-cons (factorial 4)
        (stream-cons (factorial 5) (stream-cons (factorial 6) (stream-cons (factorial 7)
        (stream-cons (factorial 8) (stream-cons (factorial 9) '())))))))))))
                     


; ==================QUESTION 4 D========================

(define (prng seed)
  (let ((temp  (modulo (+ (* 22695477 seed) 1.0) (expt 2 32)) ))
     (stream-cons  (/ (truncate (* (/ temp (expt 2 32)) 10000)) 10000) (prng temp))))


; ==================QUESTION 4 E========================

(define (random-int r min max)
  (let ((x (truncate (* max (stream-car r))) ))
      (cond ((and (>= x min) (< x max))
             (stream-cons x (random-int (stream-cdr r) min max)))
            (else (random-int (stream-cdr r) min max)))))


;X============X=================> TESTING OF QUESTION 4 <=====================X==================X

(display "QUESTION 4 A\n\n") ;======PART A=========

(display "(QUESTION 4 PART A, (Case 1) (list->stream (range 1 10)) )=> ")(newline)
(display "Expected: (1 . #<promise:...697/A3_101094697.rkt:382:34>)")(newline)
(display "Actual: ")(list->stream (range 1 10)) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 4 PART A, (Case 2) (list->stream (range 30 40)) )=> ")(newline)
(display "Expected: (30 . #<promise:...697/A3_101094697.rkt:382:34>)")(newline)
(display "Actual: ")(list->stream (range 30 40)) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 4 PART A, (Case 3) (list->stream (range 15 20)) )=> ")(newline)
(display "Expected: (15 . #<promise:...697/A3_101094697.rkt:382:34>)")(newline)
(display "Actual: ")(list->stream (range 15 20)) (newline) ; SCHEME EXPRESSION

(display "QUESTION 4 B\n\n") ;======PART B=========

(display "(QUESTION 4 PART B, (Case 1) (stream->list (list->stream (range 1 10)) 5) )=> ")(newline)
(display "Expected:(1 2 3 4 5) ")(newline)
(display "Actual: ")(stream->list (list->stream (range 1 10)) 5) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 4 PART B, (Case 2) (stream->list (list->stream (range 30 40) 3)) )=> ")(newline)
(display "Expected: (30 31 32)")(newline)
(display "Actual: ") (stream->list (list->stream (range 30 40)) 3) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 4 PART B, (Case 3) (stream->list (list->stream (range 15 20)) 2) )=> ")(newline)
(display "Expected: (15 16) ")(newline)
(display "Actual: ")(stream->list (list->stream (range 15 20)) 2) (newline) ; SCHEME EXPRESSION

(display "QUESTION 4 C\n\n") ;======PART C=========

(display "(QUESTION 4 PART C, (Case 1) (stream->list factorials 10)  )=> ")(newline)
(display "Expected:(1 1 2 6 24 120 720 5040 40320 362880) ")(newline)
(display "Actual: ") (stream->list factorials 10)  (newline) ; SCHEME EXPRESSION

(display "QUESTION 4 D\n\n") ;======PART D=========

(display "(QUESTION 4 PART D, (Case 1) (stream->list (prng 3) 5)  )=> ")(newline)
(display "Expected:(0.01585 0.4954 0.9988 0.7253 0.0307) ")(newline)
(display "Actual: ") (stream->list (prng 3) 5)  (newline) ; SCHEME EXPRESSION

(display "QUESTION 4 E\n\n") ;======PART E=========

(display "(QUESTION 4 PART D, (Case 1) (random-int (prng 3) 1 100)  )=> ")(newline)
(display "Expected:(1.0 . #<promise:...697/A3_101094697.rkt:382:34>) ")(newline)
(display "Actual: ") (random-int (prng 3) 1 100)  (newline) ; SCHEME EXPRESSION

(display "For checking if our about result is correct,
we are converting it to list and checking first 5 numbers
in the range 1 and 100\n") 
(stream->list (random-int (prng 3) 1 100) 5)

(newline)

(display "(QUESTION 4 PART D, (Case 2) (random-int (prng 3) 1 10) )=> ")(newline)
(display "Expected:(1.0 . #<promise:...697/A3_101094697.rkt:382:34>) ")(newline)
(display "Actual: ") (random-int (prng 3) 1 10)  (newline) ; SCHEME EXPRESSION

(display "For checking if our about result is correct,
 we are converting it to list and checking first 10 numbers
in the range 1 and 10\n") 
(stream->list (random-int (prng 3) 1 10) 10)

(newline)



  




  
  






                                   
  








