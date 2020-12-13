;; test1
(defun test (liste)
    (format t "premier car (car ~A) : ~A ~%" liste(car liste))
    (format t "deuxieme car (car ~A) : ~A ~%" liste (car liste))
)

(test '(a b c d))

;; test2
(defun sommeElementListe (liste)
    (if (null liste)
        0
        (+ (car liste) (sommeElementListe (cdr liste)))
    )
)

(format t "(sommeElementListe '(1 2 3 4 5) : ~A ~%" (sommeElementListe '(1 2 3 4 5)))

;; test3
(defun sommeElementListe2 (liste)
    (cond
        ((null liste) 0)
        ((listp (car liste)) (sommeElementListe2 (car liste)))
        (+ (car liste) (sommeElementListe2 (cdr liste)))
    )
)

(format t "(sommeElementListe2 '(1 (2 3) 4 5) : ~A ~%" (sommeElementListe2 '(1 (2 3) 4 5)))

;; test4
(format t "(car (cdr '(1 (2 3) 4 5))) = ~A ~%" (car (cdr '(1 (2 3) 4 5))))

;; test5
(format t "(car '((a b) c d)) : ~A ~%" (car '((a b) c d)))

;; test6
(format t "(cons 'a (cons 'b (cons 'c nil))) : ~A ~%" (cons 'a (cons 'b (cons 'c nil))))

;; testApply
(format t "(apply #'+ 1 2 '(3 4 5) = ~A ~%" (apply #'+ 1 2 '(3 4 5)))