#lang scheme
;KHUSHAL KUMAR SINGH
;101094697
;ANDREW RUNKA


(define (cbrt x)

  (define (cube x) (* x x x))

  (define (good-enough? guess)
    (let ((precision 0.001)        ; so this will return true or false 
          (diff (abs (- (cube guess) x))))
      (< diff precision)))
  
  (define (average x y )
    (/ (+ x y) 2))

  (define (improve guess)
    (average guess (/ (+ (/ x (* guess guess)) (* 2 guess)) 3)))
    ;(/ (+ (/ x (* guess guess)) (* 2 guess)) 3))

  (define (cbrt-iteration guess)
    (if (good-enough? guess)
        guess
        (cbrt-iteration (improve guess))))
  
  (cbrt-iteration 1.0))

(cbrt 64)

(display "Question 1 Part B: \n")

(define (cbrt1 x)

  (define (cube x) (* x x x))

  (define (good-enough? guess)
    (let ((precision 0.001)        ; so this will return true or false 
          (diff (abs (- (cube guess) x))))
      (< diff precision)))
  
  (define (average x y )
    (/ (+ x y) 2))

  (define (improve guess)
    (average guess (/ (+ (/ x (* guess guess)) (* 2 guess)) 3)))
    ;(/ (+ (/ x (* guess guess)) (* 2 guess)) 3))

  (define (cbrt-iteration guess)
    (new-if (good-enough? guess) guess (cbrt-iteration (improve guess)) ))
  

  (define (new-if predicate consequent alternate)
            (cond (predicate consequent)
                (else alternate)))
  
  
  (cbrt-iteration 1.0))

(display "====================OUESTION 1 TESTING====================\n")

(display "QUESTION 1 PART A CUBEROOT  (cbrt 3) => ")(newline)
   (display "Expected: 1.4")(newline)
   (display "Actual: ")(cbrt 3)(newline) ; SCHEME EXPRESSION

(display "QUESTION 1 PART A CUBEROOT  (cbrt 27) => ")(newline)
   (display "Expected: 3")(newline)
   (display "Actual: ")(cbrt 27)(newline) ; SCHEME EXPRESSION

(display "QUESTION 1 PART A CUBEROOT  (cbrt -27) => ")(newline)
   (display "Expected: -3")(newline)
   (display "Actual: ")(cbrt (- 27))(newline) ; SCHEME EXPRESSION

(display "QUESTION 1 PART A CUBEROOT  (cbrt -27) => ")(newline)
   (display "Expected: 4")(newline)
   (display "Actual: ")(cbrt 64)(newline) ; SCHEME EXPRESSION


(display "QUESTION 1 PART B => ")(newline)
(display "This version runs infinitely and eventually out of memory, because it keeps calling itself asking for")
(display "third argument.since scheme uses applicative order, so eventually it will run out of memory.\n")

;this version runs infinitely and eventually out of memory, because it keeps calling itself asking for
;third argument. so eventually it will run out of memory.

(display "====================END OF OUESTION 1 TESTING====================\n")

;QUESTION 2 A

(define (product a b term next)
      (if (> a b)
          1
          (* (term a)                   ; multiplying with last number
             (product (next a) b term next))))

(product 5 10 (lambda(x)x) (lambda(x)(+ x 1)) )

;QUESTION 2 B
(define (product-it a b)
  (define (helper counter total)        ; with the help of helper function
    (if (> counter b) total
        (helper (+ counter 1)  (* total counter))))
  (helper a 1))

(product-it 5 10)

;QUESTION 2 C 1
(define (pi-product1)
  (define (pi-term x) (+ x (* x x x)))
  (define (pi-next x) (+ x 1))
  (product 1 25 pi-term pi-next))
(newline)

(display "TESTING QUESTION 2 C 1\n")
(pi-product1)

;QUESTION 2 C 2
(define (pi-product2)
  (define (pi-term k) (* (+ 1 (* 2 k)) (+ 1 (* 2 k))))
  (define (pi-next x) (+ x 1))
  (product 1 10 pi-term pi-next))

(display "TESTING QUESTION 2 C 2\n")
(pi-product2)

#|(define (pi-product3)
  (define (pi-term i) (* 3 i))
  (define (pi-next x) (+ x 1))
  ;(define (pi-nested a) (product a 2 pi-term pi-next))
  ;)
  (product 1 2 (lambda(x) (product x 2 pi-term pi-next)) pi-next))

(pi-product3)
|#


;QUESTION 3 A
(define (palindrome? s)
  (define (helper s i j)
    (if (< i j)
         (if (not(equal? (string-ref s i) (string-ref s j)))  #f (helper s (+ 1 i) (- j 1))) ; if first and last character is not equal then its false
            #t))
   (helper s 0 (- (string-length s) 1))
  )

(display "TESTING QUESTION 3 PART A\n")
(palindrome? "madam")
(palindrome? "abba")
(palindrome? "tahohat")
(palindrome? "tahcohcat")


;QUESTION 4 A
(define (f x)
  (if (< x 3) x
      (+ (f (- x 1)) (* 2 (f (- x 2))) (* 3 (f (- x 3))) )))

(display "TESTING QUESTION 4 PART A\n")
(f 5)
(display "SUBSTUTION MODEL FOR (F 5) A\n")
(+ (f 4) (* 2 (f 3)) (* 3 (f 2)))
(+ (+ (f 3) (* 2 (f 2)) (* 3 (f 1))) (* 2 (f 3)) (* 3 (f 2)))
(+ (+ (+ (f 2) (* 2 (f 1)) (* 3 (f 0))) (* 2 (f 2)) (* 3 (f 1))) (* 2 (f 3)) (* 3 (f 2)))
(+ (+ (+ (f 2) (* 2 (f 1)) (* 3 (f 0))) (* 2 (f 2)) (* 3 (f 1))) (* 2 (+ (f 2) (* 2 (f 1)) (* 3 (f 0)))) (* 3 (f 2)))
(+ (+ (+ 2 (* 2 1) (* 3 0)) (* 2 2) (* 3 1)) (* 2 (+ 2 (* 2 1) (* 3 0))) (* 3 2))
(+ (+ (+ 2 2 0) 4 3) (* 2 (+ 2 (* 2 1) (* 3 0))) (* 3 2))
(+ (+ 4 4 3) (* 2 (+ 2 (* 2 1) (* 3 0))) (* 3 2))
(+ (+ 4 4 3) (* 2 (+ 2 2 0)) (* 3 2))
(+ 11 (* 2 (+ 2 2 0)) (* 3 2))
(+ 11 (* 2 4) (* 3 2))
(+ 11 8 (* 3 2))
(+ 11 8 6)
25


;QUESTION 5 A
(define (pascals a b) 
  (cond ((or  (= a b) (= 0 b)  ) 1)
        ((or (< a 0) (< b 0) (< a b )) 0)
        (else (+ (pascals (- a 1) (- b 1)) (pascals (- a 1) b) ))))

(display "TESTING QUESTION 5 A\n")

(pascals 0 0)
(pascals 2 0)
(pascals 2 1)
(pascals 4 1)
(pascals 4 2)
(pascals 4 3)

;QUESTION 5 B
(define (printTriangle n)
  
  (define (helper counter)
    (cond ((= counter n) (display "\n"))
          ((< counter n) (and (helper-p counter 0) (helper (+ counter 1))))
         ))
   
  (helper 0)    
 )


(define (helper-p val1 val2)
    (cond ((> val2 val1) (display "\n" ))
          ((<= val2 val1) (and (display (pascals val1 val2)) (helper-p val1 (+ val2 1))))))

(display "TESTING QUESTION 5 B \n")
(printTriangle 5)

 ;QUESTION 6
(define (hyper x)
  (cond ((eq? x +) *)
        ((eq? x *) expt)
        (else expt ))
 )

        
(display "TESTING QUESTION 6\n")

(define my-mult (hyper +))
(my-mult 3 4)
		
(define my-exp (hyper my-mult))
(my-exp 2 4)

(define my-tetra (hyper my-exp))
(my-tetra 2 4)



