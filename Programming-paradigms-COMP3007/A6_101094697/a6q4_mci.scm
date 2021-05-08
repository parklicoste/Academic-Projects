;;;; METACIRCULAR EVALUATOR FROM CHAPTER 4 (SECTIONS 4.1.1-4.1.4) of
;;;; STRUCTURE AND INTERPRETATION OF COMPUTER PROGRAMS
;Comp3007 - A6 - W2020

;;; From section 4.1.4 -- must precede def of metacircular apply

; line 136 added let identity
;line 92 to 106 function defined
;we have made functions for extracting arguments and variables from let expression
;and we are sending them in make procedure

;;; SECTION 4.1.1

;classifies the type of expression
;determines the value of an expression
(define (eval exp env)
  (cond ((self-evaluating? exp) exp)
        ((variable? exp) (lookup-variable-value exp env))
        ((quoted? exp) (text-of-quotation exp))
        ((assignment? exp) (eval-assignment exp env))
        ((definition? exp) (eval-definition exp env))
        ((if? exp) (eval-if exp env))
        ((lambda? exp)
         (make-procedure (lambda-parameters exp)
                         (lambda-body exp)
                         env))
        ((let? exp) (display "LET check status: done")(newline) (eval-let exp env));addition is happening here
        ((begin? exp) 
         (eval-sequence (begin-actions exp) env))
        ((cond? exp) (eval (cond->if exp) env))
        ((application? exp)
         ;(display "it comes here")
         (apply (eval (operator exp) env)
                (list-of-values (operands exp) env)))
        (else
         (error "Unknown expression type -- EVAL" exp))))

;executes the procedures on the given arguments
(define (apply procedure arguments)
  (cond ((primitive-procedure? procedure)
         (apply-primitive-procedure procedure arguments))
        ((compound-procedure? procedure)
         (eval-sequence (procedure-body procedure)
                        (extend-environment (procedure-parameters procedure)
                                            arguments
                                            (procedure-environment procedure))))
        (else
         (error
          "Unknown procedure type -- APPLY" procedure))))
(define apply-in-underlying-scheme apply)

;recurses down the list of operands, calling eval on each of them
;returns a corresponding list of values
(define (list-of-values exps env)
  (if (no-operands? exps)
      '()
      (cons (eval (first-operand exps) env)
            (list-of-values (rest-operands exps) env))))

;uses an if statement to evaluate a meta-if
(define (eval-if exp env)
  (if (true? (eval (if-predicate exp) env))
      (eval (if-consequent exp) env)
      (eval (if-alternative exp) env)))


;evals a sequence of subexpressions
(define (eval-sequence exps env)
  (cond ((last-exp? exps) (eval (first-exp exps) env))
        (else (eval (first-exp exps) env)
              (eval-sequence (rest-exps exps) env))))

;breaks up an expression to call set-variable-value to change the value of a variable
(define (eval-assignment exp env)
  (set-variable-value! (assignment-variable exp)
                       (eval (assignment-value exp) env)
                       env)
  'ok)

;breaks up an expression to call define-variable to create a variable
(define (eval-definition exp env)
  (define-variable! (definition-variable exp)
                    (eval (definition-value exp) env)
                    env)
  'ok)




;this is the function of let
(define (eval-let exp env)
  
  (define L (cadr exp))   ; saved the variable and expression in a list
  
  (display "eval-let status: done")(newline)
 
  (define (getListOfVariables Lis)
    (if (null? Lis) '()
        (cons  (caar Lis) (getListOfVariables (cdr Lis)))))
  
  (define (getListOfExpressions Lis)
    (if (null? Lis) '()
        (cons   (cadar Lis) (getListOfExpressions (cdr Lis)))))
 
  (apply (make-procedure (getListOfVariables L) (caddr exp) env)  (getListOfExpressions L)))
  ;(apply (list(make-lambda (getListOfVariables L) (list (caddr exp)))) (getListOfExpressions L)))
  ;(eval  (list(make-lambda (getListOfVariables L) (list (caddr exp))) (getListOfExpressions L)) env))
  
  ;(eval (make-lambda (getListOfExpressions L) (caddr exp)) env ))
  ;(apply (eval (list 'lambda (getListOfVaribles L) (caddr exp)) env) 
               ;(list-of-values (getListOfExpressions L) env)))


;(let ((a (+ 4 5)) (b (* 2 3))) (* a b))
;((lambda (L1)(* a b)) L2)





;;; SECTION 4.1.2

;predicate method for self-evaluating
(define (self-evaluating? exp)
  (cond ((number? exp) #t)
        ((string? exp) #t)
        (else #f)))

;predicate method for quote (')
(define (quoted? exp)
  (tagged-list? exp 'quote))

;accessor for quote
(define (text-of-quotation exp)(cadr exp))

;accessor for let ==========================================let identity added here
(define (let? exp) (tagged-list? exp 'let))

;predicate checking the type of an expression
(define (tagged-list? exp tag)
  (if (pair? exp)
      (eq? (car exp) tag)
      #f))

;predicate method for variables
(define (variable? exp) (symbol? exp))

;predicate and accessors for assignment (set!) 
(define (assignment? exp)
  (tagged-list? exp 'set!))

(define (assignment-variable exp) (cadr exp))

(define (assignment-value exp) (caddr exp))

;predicate and accessors for define
(define (definition? exp)
  (tagged-list? exp 'define))

;returns the variable to be bound
;note this works for both forms of define
(define (definition-variable exp)
  (if (symbol? (cadr exp))
      (cadr exp)
      (caadr exp)))

(define (definition-value exp)
  (if (symbol? (cadr exp))
      (caddr exp)
      (make-lambda (cdadr exp)
                   (cddr exp))))

;predicate and accessors for lambda
(define (lambda? exp) (tagged-list? exp 'lambda))

(define (lambda-parameters exp) (cadr exp))
(define (lambda-body exp) (cddr exp))

(define (make-lambda parameters body)
  (cons 'lambda (cons parameters body)))

;predicate and accessors for if
(define (if? exp) (tagged-list? exp 'if))

(define (if-predicate exp) (cadr exp))

(define (if-consequent exp) (caddr exp))

(define (if-alternative exp)
  (if (not (null? (cdddr exp)))
      (cadddr exp)
      'false))

;constructor for if statements
;   returns: (if pred cons alt)
(define (make-if predicate consequent alternative)
  (list 'if predicate consequent alternative))
  
  
;predicate for cond
(define (cond? exp) (tagged-list? exp 'cond))

;accessors for cond
(define (cond-clauses exp) (cdr exp))

(define (cond-else-clause? clause)
  (eq? (cond-predicate clause) 'else))

(define (cond-predicate clause) (car clause))

(define (cond-actions clause) (cdr clause))

;converts a cond to nested ifs
(define (cond->if exp)
  (expand-clauses (cond-clauses exp)))

;converts a cond to nested ifs
;helper method for cond->if
(define (expand-clauses clauses)
  (if (null? clauses)
      'false                          ; no else clause
      (let ((first (car clauses))
            (rest (cdr clauses)))
        (if (cond-else-clause? first)
            (if (null? rest)
                (sequence->exp (cond-actions first))
                (error "ELSE clause isn't last -- COND->IF"
                       clauses))
            (make-if (cond-predicate first)
                     (sequence->exp (cond-actions first))
                     (expand-clauses rest))))))


;predicate, accessors and constructor for begin
(define (begin? exp) (tagged-list? exp 'begin))

(define (begin-actions exp) (cdr exp))

(define (last-exp? seq) (null? (cdr seq)))
(define (first-exp seq) (car seq))
(define (rest-exps seq) (cdr seq))

(define (sequence->exp seq)
  (cond ((null? seq) seq)
        ((last-exp? seq) (first-exp seq))
        (else (make-begin seq))))

(define (make-begin seq) (cons 'begin seq))

;an application is any compound expression that's not one of the above
(define (application? exp) (pair? exp))
(define (operator exp) (car exp))
(define (operands exp) (cdr exp))

;accessors for a list of operands
(define (no-operands? ops) (null? ops))
(define (first-operand ops) (car ops))
(define (rest-operands ops) (cdr ops))

;;; SECTION 4.1.3

(define (true? x)
  (not (eq? x #f)))

(define (false? x)
  (eq? x #f))

;procedure objects are created by eval'ing lambdas
(define (make-procedure parameters body env)
  (list 'procedure parameters body env))

(define (compound-procedure? p)
  (tagged-list? p 'procedure))


(define (procedure-parameters p) (cadr p))
(define (procedure-body p) (caddr p))
(define (procedure-environment p) (cadddr p))

;acessors for the environment
(define (enclosing-environment env) (cdr env))

(define (first-frame env) (car env))

(define the-empty-environment '())

(define (make-frame variables values)
  (cons variables values))

(define (frame-variables frame) (car frame))
(define (frame-values frame) (cdr frame))

;adds a new binding to the front of the frame
(define (add-binding-to-frame! var val frame)
  (set-car! frame (cons var (car frame)))
  (set-cdr! frame (cons val (cdr frame))))

;adds a new frame to the front of the environment
(define (extend-environment vars vals base-env)
  (if (= (length vars) (length vals))
      (cons (make-frame vars vals) base-env)
      (if (< (length vars) (length vals))
          (error "Too many arguments supplied" vars vals)
          (error "Too few arguments supplied" vars vals))))

;variable lookup for evaluation
(define (lookup-variable-value var env)
  (define (env-loop env)
    (define (scan vars vals)   ;looks through one frame
      (cond ((null? vars)
             (env-loop (enclosing-environment env)))
            ((eq? var (car vars))
             (car vals))
            (else (scan (cdr vars) (cdr vals)))))
    (if (eq? env the-empty-environment)
        (error "Unbound variable" var)
        (let ((frame (first-frame env)))
          (scan (frame-variables frame)
                (frame-values frame)))))
  (env-loop env))

;variable lookup for mutation
(define (set-variable-value! var val env)
  (define (env-loop env)
    (define (scan vars vals)
      (cond ((null? vars)
             (env-loop (enclosing-environment env)))
            ((eq? var (car vars))
             (set-car! vals val))
            (else (scan (cdr vars) (cdr vals)))))
    (if (eq? env the-empty-environment)
        (error "Unbound variable -- SET!" var)
        (let ((frame (first-frame env)))
          (scan (frame-variables frame)
                (frame-values frame)))))
  (env-loop env))

;variable lookup for definition
(define (define-variable! var val env)
  (let ((frame (first-frame env)))
    (define (scan vars vals)
      (cond ((null? vars)
             (add-binding-to-frame! var val frame))
            ((eq? var (car vars))
             (set-car! vals val))
            (else (scan (cdr vars) (cdr vals)))))
    (scan (frame-variables frame)
          (frame-values frame))))

;;; SECTION 4.1.4

(define (setup-environment)
  (let ((initial-env
         (extend-environment (primitive-procedure-names)
                             (primitive-procedure-objects)
                             the-empty-environment)))
    (define-variable! 'true #t initial-env)
    (define-variable! 'false #f initial-env)
    initial-env))


;predicate for primitive procedures
(define (primitive-procedure? proc)
  (tagged-list? proc 'primitive))

;accessor for the actual function
  ;primitive values are stored in the frame as  ('primitive car '())
(define (primitive-implementation proc) (cadr proc))


;concrete definition of primitives (mapped to scheme)
(define primitive-procedures
  (list (list 'car car)
        (list 'cdr cdr)
        (list 'cons cons)
        (list 'null? null?)
        (list '+ +)
        (list '* *)
        (list '- -)
        (list '/ /)
        (list '= =)
        ;;      more primitives
        ))

;gets all primitive names
(define (primitive-procedure-names)
  (map car
       primitive-procedures))

;gets all primitive procedures in the form ('primitive proc)
(define (primitive-procedure-objects)
  (map (lambda (proc) (list 'primitive (cadr proc)))
       primitive-procedures))


;applies calls the built-in apply function to execute primitive procedures
(define (apply-primitive-procedure proc args)
  (apply-in-underlying-scheme
   (primitive-implementation proc) args))

;;; Prompts
(define input-prompt ";;; M-Eval input:")
(define output-prompt ";;; M-Eval value:")

;;;error procedure
(define (error message . args)
  (display message)
  (forEach args (lambda (arg) (display " ")(display arg)))
  (newline)
  ('error 'something 'went 'wrong);cause a native error
  )
;;helper for error
(define (forEach lis fun)
  (if (not (null? lis)) (begin (fun (car lis))(forEach (cdr lis) fun))))

;;; Main loop to drive metacircular interpreter 
(define (driver-loop)
  (prompt-for-input input-prompt)
  (let ((input (read)))
    (let ((output (eval input the-global-environment)))
      (announce-output output-prompt)
      (user-print output)))
  (driver-loop))

(define (prompt-for-input string)
  (newline) (newline) (display string) (newline))

(define (announce-output string)
  (newline) (display string) (newline))

(define (user-print object)
  (if (compound-procedure? object)
      (display (list 'compound-procedure
                     (procedure-parameters object)
                     (procedure-body object)
                     (procedure-environment object))) #| ;uncomment this for verbose environment listing
                     '<procedure-env>)) ;|#
      (display object)))

(display "Comp 3007 A6 W2020 METACIRCULAR INTERPRETER LOADED!")

;;Start the interpreter!
(define the-global-environment (setup-environment))
(driver-loop)

         
