#lang scheme
(define (operator? x)
  (cond ((eq? x '+) #t)
        ((eq? x '*) #t)
        ((eq? x '-) #t)
        ((eq? x '/) #t)
        (else #f)))

(define (operator x)
  (cond ((eq? x '+) +)
        ((eq? x '*) *)
        ((eq? x '-) -)
        ((eq? x '/) /)
        (else #f)))

; ==================QUESTION 3 A========================

(define (eval-prefix expression)
  (cond ((number? expression) expression)
        ((list? expression) (cond ((null? expression) 0)
                                  ((operator? (car expression)) ((operator (car expression)) (eval-prefix (cadr expression)) (eval-prefix (caddr expression))))
                                  ;((list? (car expression))(eval-prefix (car expression)))
                                  (else expression )))))

(display "QUESTION 3 A\n")(newline) ;======PART A=========

(display "(QUESTION 3 PART A, (Case 1) (eval-prefix '(+ (+ 1 2) 3)) )=> ")(newline)
(display "Expected: 6")(newline)
(display "Actual: ")(eval-prefix '(+ (+ 1 2) 3)) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 3 PART A, (Case 2) (eval-prefix '(* (+ 1 2) (* 1 (+ 1 (- 4 2))))) )=> ")(newline)
(display "Expected: 9")(newline)
(display "Actual: ")(eval-prefix '(* (+ 1 2) (* 1 (+ 1 (- 4 2)))))(newline) ; SCHEME EXPRESSION


; ==================QUESTION 3 B========================

(define (parse-infix expression)
  (cond ((number? expression) expression)
        ((list? expression) (cond ((null? (cdr expression)) (parse-infix(car expression)) )
                           ((operator? (cadr expression)) (list (cadr expression) (parse-infix (car expression)) (parse-infix (cddr expression))))
                           (else expression)))))

(display "QUESTION 3 B\n")(newline) ;======PART B=================================

(display "(QUESTION 3 PART B, (Case 1) (parse-infix '(10 - 5)) )=> ")(newline)
(display "Expected: (- 10 5)")(newline)
(display "Actual: ") (parse-infix '(10 - 5)) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 3 PART B, (Case 2) (parse-infix '(1 + 2 - 3)) )=> ")(newline)
(display "Expected: (+ 1 (- 2 3))")(newline)
(display "Actual: ") (parse-infix '(1 + 2 - 3)) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 3 PART B, (Case 3) (parse-infix '(1 + 2 * 3 - 4)) )=> ")(newline)
(display "Expected: (+ 1 (* 2 (- 3 4)))")(newline)
(display "Actual: ")(parse-infix '(1 + 2 * 3 - 4)) (newline) ; SCHEME EXPRESSION

(display "(QUESTION 3 PART B, (Case 4) (parse-infix '(1 + (2 + 2) * 3)) )=> ")(newline)
(display "Expected: (+ 1 (* (+ 2 2) 3))")(newline)
(display "Actual: ")(parse-infix '(1 + (2 + 2) * 3)) (newline) ; SCHEME EXPRESSION


#|(define (parse-infix exp)
  (define (iter exp L)
    (cond ((number? exp) exp)
          ((list? exp) (cond ((null? (cdr exp))  (car exp) )
                             ((operator? (cadr exp)) (list (cadr exp) L (caddr exp) (iter (cdddr exp) (list (cadr exp) L (caddr exp)))))
                             (else exp)))))
  (iter exp (car exp)))

|#

                                       