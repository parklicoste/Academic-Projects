#lang scheme
;Khushal Kumar Singh
;101094697


;we are using professor's code here

(define (append L1 L2)
  (cond ((null? L1) L2)
        (else (cons (car L1)
               (append (cdr L1) L2)))))

; ==================QUESTION 1 A========================

(define (join key L)
  (cond ((null? (cdr L)) (car L))
        ((list? (car L)) (append (append (car L) (list key)) (join key (cdr L))))
        (else (join key (cdr L)))))




; ==================QUESTION 1 B========================

(define (helper key L)
    (cond ((null?  L) '())
          ((eq? (car L) key) '())
          (else (cons (car L) (helper key (cdr L))))))

(define (helper1 key L)
  (cond ((null? L) '())
        ((eq? key (car L)) (split key (cdr L)))
        (else (helper1 key (cdr L)))))
  

(define (split key L)
    (cond ((null? (cdr L)) (list (list (car L)))) 
          ((eq? key (car L)) (split key (cdr L)))
          (else (cons (helper  key L) (helper1 key (cdr L)) ))))
         



; ==================QUESTION 1 C========================

(define (slice L start end)
  (cond ((null? L) '())
        ((and (>= (car L) start) (< (car L) end)) (cons (car L) (slice (cdr L) start end)))
        (else (slice (cdr L) start end))))



; ==================QUESTION 1 D========================

(define (splice L index count newL)
  (cond ((null? L) '())
        ((> index 0) (cons (car L) (splice (cdr L) (- index 1) count newL)))
        ((= index 0) (cond ((> count 0) (splice (cdr L) index (- count 1) newL))
                           ((null? newL) (cons (car L) (splice (cdr L) index count newL)))
                           (else (cons (car newL) (splice L index count (cdr newL))))))))




;X============X=================> TESTING OF QUESTION 1 <=====================X==================X

(display "QUESTION 1 A\n")(newline) ;======PART A=========

(display "(QUESTION 1 PART A, (Case 1) (join 'and '((1) (2) (3) (4))) )=> ")(newline)
(display "Expected: (1 and 2 and 3 and 4)")(newline)
(display "Actual: ")(join 'and '((1) (2) (3) (4)))(newline) ; SCHEME EXPRESSION

(display "(QUESTION 1 PART A, (Case 2) (join 'x '((a b) ((c d) e) (f (g) h))) )=> ")(newline)
(display "Expected: (a b x (c d) e x f (g) h)")(newline)
(display "Actual: ")(join 'x '((a b) ((c d) e) (f (g) h)))(newline) ; SCHEME EXPRESSION


(display "QUESTION 1 B\n") ;======PART B=========

(display "(QUESTION 1 PART B, (Case 1) (split 'c '(a b c d e)) )=> ")(newline)
(display "Expected: ((a b)(d e))")(newline)
(display "Actual: ")(split 'c '(a b c d e)) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 1 PART B , (case 2) (split '0 '(1 0 1 1 0 2 0 0 1))) )=> ")(newline)
(display "Expected: ((1)(1 1)(2)(1))")(newline)
(display "Actual: ")(split '0 '(1 0 1 1 0 2 0 0 1))(newline) ; SCHEME EXPRESSION

(display "QUESTION 1 C\n") ;======PART C=========

(display "(QUESTION 1 PART C, (Case 1) (slice '(0 1 2 3 4 5 6 7 8 9) 3 8) )=> ")(newline)
(display "Expected: (3 4 5 6 7)")(newline)
(display "Actual: ")(slice '(0 1 2 3 4 5 6 7 8 9) 3 8) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 1 PART C , (Case 2) (slice '(0 1 2 3 4 5 6 7 8 9) 5 25) )=> ")(newline)
(display "Expected: (5 6 7 8 9)")(newline)
(display "Actual: ")(slice '(0 1 2 3 4 5 6 7 8 9) 5 25)(newline) ; SCHEME EXPRESSION

(display "(QUESTION 1 PART C , (Case 2) (slice '(0 1 2 3 4 5) -10 3) )=> ")(newline)
(display "Expected: (0 1 2)")(newline)
(display "Actual: ")(slice '(0 1 2 3 4 5) -10 3)(newline) ; SCHEME EXPRESSION

(display "QUESTION 1 D\n") ;======PART D=========

(display "(QUESTION 1 PART D, (Case 1) (splice '(a b c d e) 2 1 '(x y)) )=> ")(newline)
(display "Expected: (a b x y d e)")(newline)
(display "Actual: ")(splice '(a b c d e) 2 1 '(x y)) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 1 PART D , (Case 2) (splice '(a b c d e) 2 0 '(x y)) )=> ")(newline)
(display "Expected: (a b x y c d e) ")(newline)
(display "Actual: ")(splice '(a b c d e) 2 0 '(x y))(newline) ; SCHEME EXPRESSION



(display "(QUESTION 1 PART D , (Case 3) (splice '(a b c d e) 2 1 '()) )=> ")(newline)
(display "Expected: (a b d e) ")(newline)
(display "Actual: ")(splice '(a b c d e) 2 1 '())(newline) ; SCHEME EXPRESSION

