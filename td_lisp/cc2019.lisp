;; Exo 1
(defun my_replace (symb1 symb2 liste)
    (cond
        ((null liste) liste)
        ((eq (car liste) symb1) (cons symb2 (my_replace symb1 symb2 (cdr liste))))
        (t (cons (car liste) (my_replace symb1 symb2 (cdr liste))))
    )
)

(format t "~A ~%" (my_replace 'a 1 '((a b) c a ((a)))))

;; Exo2
(defun snoc (liste)
    (cond
        ((null liste) (format t " nil"))
        ((null (car liste)) (format t " nil"))
        (t (format t "(cons ~A" (car liste)) (snoc (cdr liste)) (format t ")"))
    )
)

(format t "~A ~%" (snoc '((1 2))))
(format t "~A ~%" (snoc '(1 2 3)))

;; Exo3
(defun produit_cartesien(liste1 liste2)
    (format t "(")
    (loop for valeur1 in liste1
        do (loop for valeur2 in liste2
            do (format t "( ~A ~A )"valeur1 valeur2)
        )
    )
    (format t ")")
)

(format t "~A ~%" (produit_cartesien '(1 2 3) '(a b)))