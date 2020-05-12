#lang scheme
#| ASSIGNMENT 1
   3007 Programming paradigms
   Khushal Kumar Singh
   101094697 |#
(display "ASSIGNMENT 1\n")
(display "3007 Programming paradigms\n")
(display "Khushal Kumar Singh\n")
(display "101094697\n\n")

(display "Q1 A) 1 + -2 - 3 + 4 + -5 + 6 \n"); QUESTION 1 PART A
(display "Scheme Expression that we have written (+ 1 (- 2) (- 3) 4 (- 5) 6) \nTesting Below\n\n") 


(display "Q1 B) 20-1+((26/2 + 2)*(20/5 - 2)) \n"); QUESTION 1 PART B
(display "Scheme Expression that we have written (+ 20 (- 1) (* (+ (/ 26 2) 2) (- (/ 20 5) 2)))\nTesting Below\n\n")


(display "Q1 C) (63/9*(12/4-14/(13+2))+12)/4 \n"); QUESTION 1 PART C
(display "Scheme Expression that we have written (/ (+ (* (/ 63 9) (- (/ 12 4) (/ 14 (+ 13 2)))) 12) 4)\nTesting Below\n\n")

(display "Q1 D) ((50*20)*2)+((17/4)+3.85)+((30*2)-48)\n"); QUESTION 1 PART D
(display "Scheme Expression that we have written (+ (* 50 20 2) (+ (/ 17 4) 3.85) (- (* 30 2) 48))\nTesting Below\n\n")
   ; SCHEME EXPRESSION
(display "\n")

;X============X=================> TESTING OF QUESTION 1 <=====================X==================X

(display "(QUESTION 1 PART A)=> ")(newline)
   (display "Expected: 1")(newline)
   (display "Actual: ")(+ 1 (- 2) (- 3) 4 (- 5) 6)(newline) ; SCHEME EXPRESSION

(display "(QUESTION 1 PART B)=> ")(newline)
   (display "Expected: 49")(newline)
   (display "Actual: ")(+ (- 20 1) (* (+ (/ 26 2) 2) (- (/ 20 5) 2)))(newline) ; SCHEME EXPRESSION

(display "(QUESTION 1 PART C)=> ")(newline)
   (display "Expected: 6 37/60")(newline)
   (display "Actual: ")(/ (+ (* (/ 63 9) (- (/ 12 4) (/ 14 (+ 13 2)))) 12) 4)(newline) ; SCHEME EXPRESSION

(display "(QUESTION 1 PART D)=> ")(newline)
   (display "Expected: 2020.1")(newline)
   (display "Actual: ")(+ (* 50 20 2) (+ (/ 17 4) 3.85) (- (* 30 2) 48))(newline) ; SCHEME EXPRESSION

;X============X=================> END OF QUESTION 1 <=====================X==================X



(display "Q2 A) Procedure cube x^3 = x * x  * x \n"); QUESTION 2 PART A
(display "Scheme Expression that we have written (define (cube x) (* x x x))\nTesting Below\n\n")
(define (cube x) (* x x x))   ; SCHEME EXPRESSION

#|   PLEASE DISCARD THIS

(cube 3)
(* 3 3 3)
eval (* 3 3 3)
     eval * => #<procedure:*>
     eval 3 => 3
     eval 3 => 3
     eval 3 => 3
apply #<procedure:*> to (3 3 3)  => 27|#



(display "Q2 B) f(x) = 3 * x * x + 4 \n"); QUESTION 2 PART A
(display "Scheme Expression that we have written (define (f x) (+ (* 3 x x) 4))\nTesting Below\n\n")
(define (f x) (+ (* 3 x x) 4))   ; SCHEME EXPRESSION


#|   PLEASE DISCARD THIS

(f 3)
(+ (* 3 3 3) 4)
eval (+ (* 3 3 3) 4)
     eval + => #<procedure:+>
     eval (* 3 3 3)
          eval * => #<procedure:*>
          eval 3 => 3
          eval 3 => 3
          eval 3 => 3
          apply #<procedure:*> to (3 3 3)  => 27
     eval 4 => 4
     apply #<procedure:+> to (27 4)  => 31 |#



(display "Q2 C) g(x) = f(2x) - 2x^3 \n"); QUESTION 2 PART B
(display "Scheme Expression that we have written (define (g x)) (- (f (* 2 x)) (* 2 (cube x)))\nTesting Below\n\n")
(define (g x) (- (f (* 2 x)) (* 2 (cube x))))   ; SCHEME EXPRESSION


#|   PLEASE DISCARD THIS

(g 3)
(- (f (* 2 3)) (* 2 3 3 3))
(- (f 6) (* 2 3 3 3))
(- (f 6) 54)
(- (+ (* 3 6 6) 4) 54)
 eval (- (+ (* 3 6 6) 4) 54)
      eval - => #<procedure:->
      eval (+ (* 3 6 6) 4)
           eval + => #<procedure:+>
           eval (* 3 6 6)
                eval * => #<procedure:*>
                eval 3 =>3
                eval 3 =>6
                eval 3 =>6
                apply #<procedure:*> to (3 6 6) => 108
          eval 4 => 4
          apply #<procedure:+> to (108  4) => 112
     eval 54 => 54
     apply #<procedure:-> to (112 54) => 58
|#

(display "Q2 D) h(x) = 2f(x/2) + g(x) \n"); QUESTION 2 PART B
(display "Scheme Expression that we have written (define (h x)) (* 2 (f (/ x 2)) (g x)\nTesting Below\n\n")
(define (h x) (+ (* 2 (f (/ x 2))) (g x) ))  ; SCHEME EXPRESSION


#| PLEASE DISCARD THIS 

(h 4)
(+ (* 2 (f (/ 4 2))) (g 4) )
(+ (* 2 (f 2)) (g 4) )
(+ (* 2 (+ (* 3 2 2) 4)) (g 4) )
(+ (* 2 (+ (* 3 2 2) 4)) (- (f (* 2 4)) (* 2 4 4 4)) )
(+ (* 2 (+ (* 3 2 2) 4)) (- (f 8) (* 2 4 4 4)) )
(+ (* 2 (+ (* 3 2 2) 4)) (- (+ (* 3 8 8) 4) (* 2 4 4 4)) )
eval (+ (* 2 (+ (* 3 2 2) 4)) (- (+ (* 3 8 8) 4) (* 2 4 4 4)) )
     eval + => #<procedure:+>
     eval (* 2 (+ (* 3 2 2) 4))
          eval * => #<procedure:*>
          eval 2 => 2
          eval (+ (* 3 2 2) 4)
               eval + => #<procedure:+>
               eval (* 3 2 2)
                    eval * => #<procedure:*>
                    eval 3 => 3
                    eval 2 => 2
                    eval 2 => 2
                    apply #<procedure:*> to (3 2 2) => 12
               eval 4 => 4
               apply #<procedure:+> to (12 4) => 16
          apply #<procedure:*> to (2 16) => 32
     eval (- (+ (* 3 8 8) 4) (* 2 4 4 4))
          eval - = #<procedure:->
          eval (+ (* 3 8 8) 4)
               eval + => #<procedure:+>
               eval (* 3 8 8)
                    eval * => #<procedure:*>
                    eval 3 => 3
                    eval 8 => 8
                    eval 8 => 8
                    apply #<procedure:*> to (3 8 8) => 192
               eval 4 => 4
               apply <#procedure:+> to (192 4) => 196
          eval (* 2 4 4 4)
               eval * => #<procedure:*>
               eval 2 => 2
               eval 4 => 4
               eval 4 => 4
               eval 4 => 4
              apply #<procedure:*> to (2 4 4 4 ) => 128
         apply #<procedure:-> to (196 128) => 68
     apply #<procedure:+> to (32 68) => 100 |#


(display "Substitution model using applicative order for (h (* 2 3))\n\n")
(display "Q2 E)\n")

(h (* 2 3))
(h 6)                                     ; => 2*3 = 6
(+ (* 2 (f (/ 6 2))) (g 6) )
(+ (* 2 (f 3)) (g 6) )                    ; 6/2 = 3
(+ (* 2 (+ (* 3 3 3) 4)) (g 6))
(+ (* 2 (+ 27 4)) (g 6))                  ; 3 * 3 * 3 = 27
(+ (* 2 31) (g 6))                        ; 27 + 4 = 31
(+ 62 (g 6))                              ; 2 * 31 = 62
(+ 62 (- (f (* 2 6)) (* 2 (cube 6))))
(+ 62 (- (f 12) (* 2 (cube 6))))             ;  2 * 6 = 12
(+ 62 (- (+ (* 3 12 12) 4) (* 2 (cube 6))))
(+ 62 (- (+ 432 4) (* 2 (cube 6))))          ; 3 * 12 * 12 = 434
(+ 62 (- 436 (* 2 (cube 6))))                ; 434 + 4 = 438
(+ 62 (- 436 (* 2 (cube 6))))                        ; 2 * 6 * 6 * 6 = 434
(+ 62 (- 436 (* 2 (* 6 6 6))))
(+ 62 (- 436 (* 2 216)))
(+ 62 (- 436 432))
(+ 62 4)                                  ; 438 - 434 = 4
66 (newline)                              ; 62 + 4 = 66





(display "Substitution model using normal order for (h (* 2 3))\n\n")
(display "Q2 F)\n")
(h (* 2 3))
(+ (* 2 (f (/ (* 2 3) 2))) (g (* 2 3)) )
(+ (* 2 (+ (* 3 (/ (* 2 3) 2) (/ (* 2 3) 2)) 4)) (g (* 2 3)) )
(+ (* 2 (+ (* 3 (/ 6 2) (/ (* 2 3) 2)) 4)) (g (* 2 3)) )            ; 2 * 3 => 6
(+ (* 2 (+ (* 3 3 (/ (* 2 3) 2)) 4)) (g (* 2 3)) )                  ; 6 / 2 => 3
(+ (* 2 (+ (* 3 3 (/ 6 2)) 4)) (g (* 2 3)) )                        ; 2 * 3 => 6
(+ (* 2 (+ (* 3 3 3) 4)) (g (* 2 3)) )                              ;
(+ (* 2 (+ 27 4)) (g (* 2 3)) )                                     ; 3 * 3 * 3 => 27
(+ (* 2 31) (g (* 2 3)))                                            ; 27 + 4 => 31
(+ 62 (g (* 2 3)))                                                  ; 31 * 2 => 31     
(+ 62 (- (f (* 2 (* 2 3))) (* 2 (cube (* 2 3)))))
(+ 62 (- (+ (* 3 (* 2 (* 2 3)) (* 2 (* 2 3))) 4) (* 2 (cube (* 2 3)))))
(+ 62 (- (+ (* 3 (* 2 6) (* 2 (* 2 3))) 4) (* 2 (cube (* 2 3)))))
(+ 62 (- (+ (* 3 12 (* 2 (* 2 3))) 4) (* 2 (cube (* 2 3)))))
(+ 62 (- (+ (* 3 12 (* 2 6)) 4) (* 2 (cube (* 2 3)))))
(+ 62 (- (+ (* 3 12 12) 4) (* 2 (cube (* 2 3)))))
(+ 62 (- (+ 432 4) (* 2 (cube (* 2 3)))))
(+ 62 (- 436 (* 2 (cube (* 2 3)))))
(+ 62 (- 436 (* 2 (* (* 2 3) (* 2 3) (* 2 3)))))
(+ 62 (- 436 (* 2 (* 6 (* 2 3) (* 2 3)))))
(+ 62 (- 436 (* 2 (* 6 6 (* 2 3)))))
(+ 62 (- 436 (* 2 (* 6 6 6))))
(+ 62 (- 436 (* 2 216)))
(+ 62 (- 436 432))
(+ 62 4)
66(newline)


;X============X=================> TESTING OF QUESTION 2 <=====================X==================X

;<===============PART A=====================>

;simple cases +positive numbers
(display "QUESTION 2 PART A CUBE  (cube 3) => ")(newline)
   (display "Expected: 27")(newline)
   (display "Actual: ")(cube 3)(newline) ; SCHEME EXPRESSION

(display "QUESTION 2 PART A CUBE  (cube 5) => ")(newline)
   (display "Expected: 125")(newline)
   (display "Actual: ")(cube 5)(newline) ; SCHEME EXPRESSION

;negative cases

(display "QUESTION 2 PART A CUBE  (cube -3) => ")(newline)
   (display "Expected: -27")(newline)
   (display "Actual: ")(cube (- 3))(newline) ; SCHEME EXPRESSION

(display "QUESTION 2 PART A CUBE  (cube -7) => ")(newline)
   (display "Expected: -343")(newline)
   (display "Actual: ")(cube (- 7))(newline) ; SCHEME EXPRESSION

; Zero case 
(display "QUESTION 2 PART A CUBE  (cube 0) => ")(newline)
   (display "Expected: 0")(newline)
   (display "Actual: ")(cube 0)(newline) ; SCHEME EXPRESSION

;<================ PART B ====================>

;simple case Positive

(display "(QUESTION 2 PART B  (F 3) => ")(newline)
   (display "Expected: 31")(newline)
   (display "Actual: ")(f 3)(newline) ; SCHEME EXPRESSION

(display "(QUESTION 2 PART B  (F 10) => ")(newline)
   (display "Expected: 304")(newline)
   (display "Actual: ")(f 10)(newline) ; SCHEME EXPRESSION

;negative case

(display "(QUESTION 2 PART B  (F -5) => ")(newline)
   (display "Expected: 79")(newline)
   (display "Actual: ")(f (- 5))(newline) ; SCHEME EXPRESSION

(display "(QUESTION 2 PART B  (F -9) => ")(newline)
   (display "Expected: 247")(newline)
   (display "Actual: ")(f (- 9))(newline) ; SCHEME EXPRESSION

;Zero case
(display "(QUESTION 2 PART B  (F 0) => ")(newline)
   (display "Expected: 4")(newline)
   (display "Actual: ")(f 0)(newline) ; SCHEME EXPRESSION

;<================ PART C ====================>

;simple case Positive

(display "(QUESTION 2 PART C  (G 4) => ")(newline)
   (display "Expected: 68")(newline)
   (display "Actual: ")(g 4)(newline) ; SCHEME EXPRESSION

(display "(QUESTION 2 PART C  (G 8) => ")(newline)
   (display "Expected: -252")(newline)
   (display "Actual: ")(g 8)(newline) ; SCHEME EXPRESSION

;negative case

(display "(QUESTION 2 PART C  (G -3) => ")(newline)
   (display "Expected: 166")(newline)
   (display "Actual: ")(g (- 3))(newline) ; SCHEME EXPRESSION

(display "(QUESTION 2 PART C  (G -7) => ")(newline)
   (display "Expected: 1278")(newline)
   (display "Actual: ")(g (- 7))(newline) ; SCHEME EXPRESSION

;Zero case
(display "(QUESTION 2 PART C  (G 0) => ")(newline)
   (display "Expected: 4")(newline)
   (display "Actual: ")(g 0)(newline) ; SCHEME EXPRESSION

;<================ PART D ====================>

;simple case Positive

(display "(QUESTION 2 PART D  (H 6) => ")(newline)
   (display "Expected: 66")(newline)
   (display "Actual: ")(h 6)(newline) ; SCHEME EXPRESSION

(display "(QUESTION 2 PART D  (H 2) => ")(newline)
   (display "Expected: 50")(newline)
   (display "Actual: ")(h 2)(newline) ; SCHEME EXPRESSION

;negative case

(display "(QUESTION 2 PART D  (H -4) => ")(newline)
   (display "Expected: 356")(newline)
   (display "Actual: ")(h (- 4))(newline) ; SCHEME EXPRESSION

(display "(QUESTION 2 PART D  (H -1) => ")(newline)
   (display "Expected: 27.50")(newline)
   (display "Actual: ")(h (- 1))(newline) ; SCHEME EXPRESSION

;Zero case
(display "(QUESTION 2 PART D  (H 0) => ")(newline)
   (display "Expected: 12")(newline)
   (display "Actual: ")(h 0)(newline) ; SCHEME EXPRESSION

;X============X=================> END OF QUESTION 2 <=====================X==================X


;QUESTION 3 PART 1


(define (quadratic a b c)
  (define (disc)(- (* b b) (* 4 a c)))
  (if (or (= a 0) (< (disc) 0)) #f (/ (+ (- b) (sqrt (disc))) (* 2 a)) ))


;QUESTION 3 PART 2

(define (convert a b c)
  (cond ((< a 0) (display "You have given negative value"))
        ((and (equal? b "B") (equal? c "KB")) (/ a 1000))
        ((and (equal? b "B") (equal? c "B")) a )
        ((and (equal? b "B") (equal? c "KiB")) (/ a 1024))
        ((and (equal? b "KB") (equal? c "KB")) a)
        ((and (equal? b "KB") (equal? c "B")) (* a 1000))
        ((and (equal? b "KB") (equal? c "KiB")) (/ a 1.024))
        ((and (equal? b "KiB") (equal? c "KB")) (* a 1.024))
        ((and (equal? b "KiB") (equal? c "B")) (* a 1024))
        ((and (equal? b "KiB") (equal? c "KiB")) a)
        (else (display "Could not convert from ") (display b) (display " to ") (display c)(newline))))



;X============X=================> TESTING OF QUESTION 3 <=====================X==================X

; PART A
; when a is 0

(display "QUESTION 3 PART A  (quadratic 0 (- 3) 1) => ")(newline)
   (display "Expected: #f")(newline)
   (display "Actual: ")(quadratic 0 5 1)(newline) ; SCHEME EXPRESSION

; when discriminant is less than 0 (imaginary roots or no real roots
(display "(QUESTION 3 PART A  (quadratic 7 (- 3) 1) => ")(newline)
   (display "Expected: #f")(newline)
   (display "Actual: ")(quadratic 7 (- 3) 1)(newline) ; SCHEME EXPRESSION

; if discriminant = 0 then equal roots
(display "(QUESTION 3 PART A  (quadratic 3 6 3) => ")(newline)
   (display "Expected: 1")(newline)
   (display "Actual: ")(quadratic 3 (- 6) 3)(newline) ; SCHEME EXPRESSION

; real roots
(display "(QUESTION 3 PART A  (quadratic 3 6 3) => ")(newline)
   (display "Expected: (-5 + 3) / (2 * 4) = -2/8 = -1/4 = -.25 approx")(newline)
   (display "Actual: ")(quadratic 4 5 1)(newline) ; SCHEME EXPRESSION

;PART B

; Could not Convert ones

(display " QUESTION 3 PART B  (convert 1000 KBapple  Bytes)  => ")(newline)
   (display "Expected: Could not convert from KBapple to Bytes")(newline)
   (display "Actual: ")(convert 1000 "KBapple" "Bytes")(newline) ; SCHEME EXPRESSION

(display "QUESTION 3 PART B  (convert 1000 hello  B)  => ")(newline)
   (display "Expected: Could not convert from hello to B")(newline)
   (display "Actual: ")(convert 1000 "hello" "B")(newline) ; SCHEME EXPRESSION

; B to KB
(display "QUESTION 3 PART B  (convert 42 B  KB)  => ")(newline)
   (display "Expected: 42/1000 => 21/500 or 0.042")(newline)
   (display "Actual: ")(convert 42 "B" "KB")(newline) ; SCHEME EXPRESSION

; B to B
(display "QUESTION 3 PART B  (convert 42 B  B)  => ")(newline)
   (display "Expected: 42")(newline)
   (display "Actual: ")(convert 42 "B" "B")(newline) ; SCHEME EXPRESSION

; B to KiB
(display "QUESTION 3 PART B  (convert 1024 B  KiB)  => ")(newline)
   (display "Expected: 1")(newline)
   (display "Actual: ")(convert 1024 "B" "KiB")(newline) ; SCHEME EXPRESSION

; KB to KB
(display "QUESTION 3 PART B  (convert 42 KB  KB)  => ")(newline)
   (display "Expected: 42 ")(newline)
   (display "Actual: ")(convert 42 "KB" "KB")(newline) ; SCHEME EXPRESSION

; KB to B
(display "QUESTION 3 PART B  (convert 42 KB  B)  => ")(newline)
   (display "Expected: 42000")(newline)
   (display "Actual: ")(convert 42 "KB" "B")(newline) ; SCHEME EXPRESSION

; KB to KiB
(display "QUESTION 3 PART B  (convert 1024 KB  KiB)  => ")(newline)
   (display "Expected: 1000")(newline)
   (display "Actual: ")(convert 1024 "KB" "KiB")(newline) ; SCHEME EXPRESSION

; KiB to KB
(display "QUESTION 3 PART B  (convert 42 KiB  KB)  => ")(newline)
   (display "Expected: 43.008 ")(newline)
   (display "Actual: ")(convert 42 "KiB" "KB")(newline) ; SCHEME EXPRESSION

; KiB to B
(display "QUESTION 3 PART B  (convert 42 KiB  KB)  => ")(newline)
   (display "Expected: 43008")(newline)
   (display "Actual: ")(convert 42 "KiB" "B")(newline) ; SCHEME EXPRESSION

; KiB to KiB
(display "QUESTION 3 PART B  (convert 42 KiB  KiB)  => ")(newline)
   (display "Expected: 42")(newline)
   (display "Actual: ")(convert 42 "KiB" "KiB")(newline) ; SCHEME EXPRESSION


;X============X=================> END OF QUESTION 3 <=====================X==================X


;QUESTION 4
;PART 1

;(display " enter a number: ")
(define (user-num str)
  (display str)
  (define x(read))
  (if (real? x)  x 0))
(newline)

;PART 2
;THIS X====X EXTRACT X====X FUNCTION IS MY HELPER FUNCTION IT JUST GIVES ME THE FLOOR

(define (extract num)
  (cond ((> num 0) (floor (log   num 10)))        ; for values greater than 0
        ((< num 0) (floor (log   (- num) 10)))    ; for values less than 0
        ((= num 0) 0)))                           ; for values eual to 0


(define (sci-exponent num)
      (rationalize  (inexact->exact (extract num)) 1/10))
(newline)

;PART 3

(define (sci-coefficient num)
            (/ num (expt 10 (extract num))))
(newline)

;PART 4

(define (sci-num)
  (let ((y (user-num "Enter a Number: ")))
        (string-append (number->string (sci-coefficient y)) "x10^" (number->string (sci-exponent y)))))

;X============X=================> TESTING OF QUESTION 4 <=====================X==================X

; PART A

(display "QUESTION 4 PART A (user-num Enter a number: 123)  => ")(newline)
   (display "Expected: 123")(newline)
   (display "Actual: ")(user-num "Enter a number: ")(newline) ; SCHEME EXPRESSION

(display "QUESTION 4 PART A (user-num Enter a number: 1.23)  => ")(newline)
   (display "Expected: 1.23")(newline)
   (display "Actual: ")(user-num "Enter a number: ")(newline) ; SCHEME EXPRESSION

(display "QUESTION 4 PART A (user-num hello: hii)  => ")(newline)
   (display "Expected: 0")(newline)
   (display "Actual: ")(user-num "hello! ")(newline) ; SCHEME EXPRESSION

;PART B

(display "QUESTION 4 PART B (sci-exponent 1.234)  => ")(newline)
   (display "Expected: 0")(newline)
   (display "Actual: ")(sci-exponent 1.234)(newline) ; SCHEME EXPRESSION


(display "QUESTION 4 PART B (sci-exponent 12345)  => ")(newline)
   (display "Expected: 4")(newline)
   (display "Actual: ")(sci-exponent 12345)(newline) ; SCHEME EXPRESSION

(display "QUESTION 4 PART B (sci-exponent 0.001234)  => ")(newline)
   (display "Expected: -3")(newline)
   (display "Actual: ")(sci-exponent 0.001234)(newline) ; SCHEME EXPRESSION

(display "QUESTION 4 PART B (sci-exponent -12345)  => ")(newline)
   (display "Expected: 4")(newline)
   (display "Actual: ")(sci-exponent (- 12345))(newline) ; SCHEME EXPRESSION

(display "QUESTION 4 PART B (sci-exponent 0)  => ")(newline)
   (display "Expected: 0")(newline)
   (display "Actual: ")(sci-exponent 0)(newline) ; SCHEME EXPRESSION

;PART C

(display "QUESTION 4 PART C (sci-coefficient 1.2345)  => ")(newline)
   (display "Expected: 1.2345")(newline)
   (display "Actual: ")(sci-coefficient  1.2345)(newline) ; SCHEME EXPRESSION

(display "QUESTION 4 PART C (sci-coefficient 12345)  => ")(newline)
   (display "Expected: 1.2345")(newline)
   (display "Actual: ")(sci-coefficient 12345)(newline) ; SCHEME EXPRESSION

(display "QUESTION 4 PART C (sci-coefficient 0.001234)  => ")(newline)
   (display "Expected: 1.234")(newline)
   (display "Actual: ")(sci-coefficient 0.001234)(newline) ; SCHEME EXPRESSION

(display "QUESTION 4 PART C (sci-coefficient -12345)  => ")(newline)
   (display "Expected: -1.2345")(newline)
   (display "Actual: ")(sci-coefficient (- 12345))(newline) ; SCHEME EXPRESSION

(display "QUESTION 4 PART C (sci-coefficient 0)  => ")(newline)
   (display "Expected: 0")(newline)
   (display "Actual: ")(sci-coefficient 0)(newline) ; SCHEME EXPRESSION

;PART D

(display "QUESTION 4 PART D (sci-num) Enter the number: 12345  => ")(newline)
   (display "Expected: 1.2345x10^4")(newline)
   (display "Actual: ")(sci-num)(newline) ; SCHEME EXPRESSION

(display "QUESTION 4 PART D (sci-num) Enter the number: 1.234  => ")(newline)
   (display "Expected: 1.234x10^0")(newline)
   (display "Actual: ")(sci-num)(newline) ; SCHEME EXPRESSION

(display "QUESTION 4 PART D (sci-num) Enter the number: 0.0012345  => ")(newline)
   (display "Expected: 1.234x10^-3")(newline)
   (display "Actual: ")(sci-num)(newline) ; SCHEME EXPRESSION

(display "QUESTION 4 PART D (sci-num) Enter the number: hello  => ")(newline)
   (display "Expected: 0x10^0")(newline)
   (display "Actual: ")(sci-num)(newline) ; SCHEME EXPRESSION


;X============X=================> END OF QUESTION 4 <=====================X==================X


;QUESTION 5
#|(define (test x y) 
        (if (= x 0)
            x
            y))

    (test 0 (/ 3 0))|#

;APPLICATIVE ORDER
; (test 0 (/ 3 0))
; (test 0 (/ 3 0)) => 3/0 error division by 0
; it solves the bracket first so before sending the value of y to the function test it will solve the value of y
;and at the same time it will get error

(display "it solves the bracket first so before sending the value of y to the function test it will solve the value of y
;and at the same time it will get error")(newline)

;NORMAL ORDER EVALUATION
;(test 0 (/ 3 0))
;(define (test 0 (/ 3 0))
;        (if (= 0 0) 0
;         (/ 3 0)))
; According to Normal order evaluation the answer is supposed to be 0, Beacause it take the whole argument y in bracket
;and it doesnt solve it until the whole expression is created. Secondly, it checks the if condition it that's true. it
;doesn't jumps to else. so, in this case if statement is true. so it doesnt matter what the value of y is. it is not
;going to be considered because if statement above is true.

(display "According to Normal order evaluation the answer is supposed to be 0, Beacause it take the whole argument y in bracket
and it doesnt solve it until the whole expression is created. Secondly, it checks the if condition it that's true. it
doesn't jumps to else. so, in this case if statement is true. so it doesnt matter what the value of y is. it is not
going to be considered because if statement above is true.")(newline)

;X============X=================> END OF QUESTION 5 <=====================X==================X


;QUESTION 6
(define (foo a b)
		((cond ((> b 0) +)((= b 0) *)(else /)) a b))

;X============X=================> TESTING OF QUESTION 6 <=====================X==================X

;WHEN A AND B ARE BOTH POSITIVE

(display "QUESTION 6 (foo 5 3)  => ")(newline)
   (display "Expected: 8")(newline)
   (display "Actual: ")(foo 5 3)(newline) ; SCHEME EXPRESSION

;SUBSTITUTION MODEL
(foo 5 3)
((cond ((> 3 0) +)((= 3 0) *)(else /)) 5 3)
(+ 5 3)
8(newline)

;WHEN B IS 0 AND A IS POSITIVE

(display "QUESTION 6 (foo 2 0)  => ")(newline)
   (display "Expected: 0")(newline)
   (display "Actual: ")(foo 2 0)(newline) ; SCHEME EXPRESSION

;SUBSTITUTION MODEL
(foo 2 0)
((cond ((> 0 0) +)((= 0 0) *)(else /)) 2 0)
(* 2 0)
0(newline)

;WHEN  B IS NEGATIVE AND A IS POSITIVE

(display "QUESTION 6 (foo 2 -6)  => ")(newline)
   (display "Expected: -1/3")(newline)
   (display "Actual: ")(foo 2 (- 6))(newline) ; SCHEME EXPRESSION

;SUBSTITUTION MODEL
(foo 2 (- 6))
((cond ((> -6 0) +)((= -6 0) *)(else /)) 2 -6)
(/ 2 -6)
-1/3(newline)

(display "It always depends on the value of b whether its greater than 0 or greater than 0 if its less than 0 then its gonna be divide")