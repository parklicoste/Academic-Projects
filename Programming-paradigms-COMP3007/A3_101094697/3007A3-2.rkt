#lang scheme
;Jason Yang
;101028952



;1a)

(define square (lambda(x)(* x x)));from notes
(define double (lambda(x)(+ x x)));from notes 

(define (compose y z);nests functions Input :function function Output: function (anon)
  (lambda(x) (y ( z x  ))))

( (compose square double) 3  );Expected Output 36


;1b)
(define (divisibleBy y ) ;creates an anon function to calculate divisibleby Input: int Output: function (anon)
  (lambda (x) (= (modulo x y) 0))
  )
(define mod3 (divisibleBy 3))
(mod3 7);Expected Output#f
(mod3 9);Expected Output#t

;1c)
(define (recurse items f) ;applies a factor function to the list Input: list function Output: list
    (if (null? items)
        '()
        (cons (f (car items) )
              (recurse (cdr items) f ))))

(define (newmap f);creates anon function from recurse 
  (lambda (x) (recurse x f))
  )

(define squareAll (newmap (lambda(x)(* x x))))
(squareAll '(1 2 3 4));Expected Output(1 4 9 16)
(squareAll '(10 20 30));Expected Output(100 400 900)

;d)


(define (filter items f);filter items in list with predicate Input: list predicate  Output:list
    (if (null? items)
        '()
        (if (f (car items)) (cons (car items)(filter (cdr items) f )) (filter (cdr items) f ))))





(define (newFilter f);makes an anon function from filter
  (lambda (x) (filter x f))
  )

(define filterEvens (newFilter (divisibleBy 2)))
  (filterEvens'(1 2 3 4));Expected Output (2 4)
(define filterMO4 (newFilter (divisibleBy 4)))
  (filterMO4'(1 2 3 4));Expected Output(4)

;e)

(define (range a b);from notes
    (if (= a b) (list a)
        (cons a (range (+ a 1) b))))

(define myfunc (lambda (x) (squareAll(filterMO4 x))));squares all elements of list after being filtered  by multiples of 4

  (myfunc (range 1 20));Expected Output (16 64 144 256 400)




;2a)
(define (maximumL items);returns the maxixmun of a list Input: list Output:list
  (define (recurse2 items currMax)
    (if (null? items)
        currMax
        ( if (> (car items) currMax) (recurse2 (cdr items) (car items)) (recurse2 ( cdr items) currMax) )))
  (recurse2 items 0)
   )

(maximumL (list 2 3 4 5 7 5 1 2 3));Expected Output 7





;2b)
(define (after items n);makes a list only after a certain index of the original list Input list int Output:list
  (define (iter items x)
    (if (or (= x n) (null? items))
        items
                ( iter (cdr items) (+ x 1 ))))
  (iter items 0)
   
  )



(after (list 2 3 4 5 7 5 1 2 3) 4);Expected Output (7 5 1 2 3)








;2c)
(define (MaximumLI items);returns the index of the max not the max itself
  
  (define (iter items currMax Index i)
    
    (if (null? items)
        Index
        ( if (> (car items) currMax) (iter (cdr items) (car items) i (+ i 1)) (iter ( cdr items) currMax Index (+ i 1)) ));iterates through the list keeping track of teh current max and index, saving the index of the current max
    )
  (iter items 0 0 0)
   )



  (define (tails items);the function makes  a list consisting of elements after the max items repeatedly until the list is null Input: list Output:list
   
    (if ( null? items)
        '()
        (cons (after items (+ ( MaximumLI items) 1)) (tails (after items (+( MaximumLI items)1)) ) )
        )
        )
  
   
(tails '(3 6 8 9 7 4 8 6 3));Expected Output ((7 4 8 6 3) (6 3) (3) ())











;2d)

(define (sublist items start end);keeps only elements between start index and end index of a list Input: list int int Output: list
 
  (define (recurse items i)
    (cond ((< i start) (recurse (cdr items) (+ 1 i)))
          ((or (null? items) (>= i end)) '() )
          (else (cons (car items) (recurse  (cdr items) (+ i 1))))) 
   )
  (recurse items 0)
   
  )


(sublist '(0 1 2 3 4 5 6 7 8 9) 3 8);Expected Output(3 4 5 6 7) 
(sublist '(0 1 2 3 4 5 6 7 8 9) 5 25);Expected Output(5 6 7 8 9)
(sublist '(0 1 2 3 4 5) -10 3);Expected Output(0 1 2)







;3a)
(define (tree-filter pred T);filters a tree with a predicate Input: predicate tree Output: tree
    (cond ((null? T) '())
          ((list? (car T)) (cons (tree-filter pred (car T) )
                                 (tree-filter pred (cdr T))))
          (else (if (pred ( car T)) (cons (car T) (tree-filter pred (cdr T) )) ;only keeps elements if predicate si true
                      (tree-filter pred (cdr T) )))))

(tree-filter even? '(1 (2 3) ((4 5) (6 7)) (((8 (9))))));Expected Output ((2) ((4) (6)) (((8 ()))))
(tree-filter (divisibleBy 3) '(1 (2 3) ((4 5) (6 7)) (((8 (9))))));Expected Output((3) (() (6)) ((((9)))))








;3b)
(define (height tree);calculates hegiht of tree Input tree Output:Int
  (cond ((null? tree) 0)
        ((not (list? tree)) 0)
        (else (max (+ 1 (height(car tree)));adds one to the height of the current tree then compares it to the next subtrees  with max function
                   (height (cdr tree))))))
(height '(a)) ;Expected Output 1
(height '((((a((((b)))))))));Expected Output 8
(height '(a (b) c));Expected Output 2
(height 'a);Expected Output 0 





;3c)
(define (flattenList lst);makes a tree a list Input:tree Output :list
  
  (cond ((null? lst) '())
        ((pair? lst)
         (append (flattenList (car lst)) (flattenList (cdr lst))));if the tree structure (pair?) is stillpresent append the left and right side, untill you are jsut appending a bunch of lists together
        (else (list lst) )))

(flattenList '(1 (2 3) ((4 5 6 (7)))(((8 (9))))));Expected Output (1 2 3 4 5 6 7 8 9)






;3d)
(define (scale-tree T factor);Given from notes
    (cond ((null? T) '())
          ((list? (car T)) (cons (scale-tree (car T) factor)
                                 (scale-tree (cdr T) factor)))
          (else (cons (* (car T) factor)
                      (scale-tree (cdr T) factor)))))

(define (treeMerge t1 t2);merges two trees Input: tree tree Output:tree
        (cond (( null? t1) t2)
              (( null? t2) t1);
              ((and ( list? (car t1))(list? ( car t2))) (cons  (treeMerge (car t1) (car t2)) ( treeMerge (cdr t1)(cdr t2))) );tree merge left and right side if both are still lists at that point
              ((and (not (list? (car t1)))(not (list? (car t2)))) (cons (* (car t1) (car t2) ) (treeMerge (cdr t1) (cdr t2) )) );if a both are  leaf nodes, merge by multiplying leaf nodes
              ((and ( list? (car t1))(not (list? ( car t2)))) (cons (scale-tree (car t1) (car t2)) ( treeMerge (cdr t1)(cdr t2)) )); if one is a leaf and one is a tree at that point then scale the tree by the leaf
              ((and (not( list? (car t1)))(list? ( car t2))) (cons (scale-tree (car t2) (car t1)) ( treeMerge (cdr t1)(cdr t2)) ))
              
              
              

  ))

(treeMerge '(2 (2 3)(4 5 ( 5 6 7))) '((5 (4 3)( 2 1))6 ( 7 8 )));Expected Output ((10 (8 6) (4 2)) (12 18) (28 40 (5 6 7)))








;4a)
(define-syntax stream-cons
    (syntax-rules ()
        ((stream-cons a b)(cons a (delay b)))))

(define (stream-car stream) 
    (car stream))

(define (stream-cdr stream)

  (force (cdr stream)))

(define (list->stream lst);makes a stream from a list Input: List Output:Stream
  (if (null? lst)
      '()
      (stream-cons (car lst)
            (list->stream (cdr lst)))))

 (list->stream '(1 2 3 4 5 6 7 8 9 ));Expected output 1.promise








;4b)
(define (stream->list s n);prints a list from a stream (could be infinite)for the first n elements Input: stream int Output: List
    (cond ((null? s) '())
          ((> 1 n ) '() )
          (else (cons (stream-car s)(stream->list (stream-cdr s) (- n 1))))
  

          )
  )

(stream->list (list->stream '(1 2 3 4 5 6 7 8 9 )) 5) ;Expected output (1 2 3 4 5)








;4c)
(define (odds);prints out all the odd numbers fmo 1 to infinite Input: Output: stream infinite

  (define(recurse n)
    (stream-cons n (recurse (+ n 2)))

   )(recurse 1)



  )

(stream-car 
    (stream-cdr
         
            (odds)));Expected output 3







;4d)

(define (repeat x);repeats a number infinitely Input: number Output:stream infinite

  (define(recurse n)
    (stream-cons n (recurse n))

   )(recurse x)



  )
(repeat 7);expected output 7.promise
(stream-cdr (repeat 7));expected output 7.promise



;4e)

(define (stream-until s pred);returns the number of elements in teh stream passed before the rpedacate evaluates true Input: stream predicate Output: int
  (define (recurse s n)
   (cond ((null? s) -1)
          ((pred (stream-car s)) n );if predicate is true return teh number of elements passed to get there
         (else (recurse (stream-cdr s) (+ n 1)))
    )
  )(recurse s 0 )
)

(stream-until (list->stream '(1 2 3 4 5 6 7 8 9 )) (lambda (x) (=(modulo x 7)0)));expected output  6
(stream-until (list->stream '(1 2 3 4 5 6 7 8 9 )) (lambda (x) (=(modulo x 10)0))); expexted output  -1




;4f)
(define (loan a r p) ;funciton to generate stream of loans after each payment and rate calculation Input:int ammout in rate int payment Output: stream 
  (cond ( (< a 0)
          (stream-cons 0 '() ))
   
      (else(stream-cons a  
            (loan (+ (- a p) (* a r)) r p)))



      )


)


(stream->list (loan 10000 0.025 500) 5);expect output (10000 9750.0 9493.75 9231.09375 8961.87109375)
(stream->list (loan 20 0.003 10) 5);expect output (20 10.06 0.0901800000000005 0)




(define (make-graph)
  (let ((Lis '()))
 
  (define (check L x)
      (cond ((null?  L) #f)
            ((eq? (car L) x) #t)
            (else (check (cdr L) x))))
  
  (define (add-node x)
      (if (check  Lis x) #f (begin
                              (set! Lis (cons x Lis)) #t)))

  (define (display)
    (define (iter L)
      (if (null? L) " " ((lambda() (car L) ": ")) (
   
    (define (dispatch method)
      (cond ((eq? method 'add-node) add-node)
            ((eq? method 'display) display)
            (else "Unknown Request: ")))

    dispatch))


(define G (make-graph))
((G 'add-node) 'a)       ;=> #t
((G 'add-node) 'b)       ;=> #t
((G 'add-node) 'c)       ;=> #t
((G 'add-node) 'a)       ;=> #f
    





