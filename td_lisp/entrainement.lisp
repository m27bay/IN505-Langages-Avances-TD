;; Exo : fonction qui retourne la taille d'une liste.
(defun tailleListe (liste)
  (if (null liste) 
    0
    (+ 1 (tailleListe (cdr liste)))
  )
)

(format t "~%##### test tailleListe #####~%")
(format t "(tailleListe '(1 2 3 4) : ~A ~%" (tailleListe '(1 2 3 4)))
(format t "(tailleListe '(1 (2 3) 4) : ~A ~%" (tailleListe '(1 (2 3) 4)))
(format t "(tailleListe '(1 ((2 3) 4)) : ~A ~%" (tailleListe '(1 ((2 3) 4))))
(format t "(tailleListe '((2 3) 4) : ~A ~%" (tailleListe '((2 3) 4)))


;; Iteratif
(defun tailleListeIteratif (liste) ;; marche pas
  (let ( (nombreElement 0) )
    (dolist (elt liste)
      (setf nombreElement (+ nombreElement 1) )
    )
    nombreElement
  )
)

(format t "~%##### test tailleListeIteratif #####~%")
(format t "(tailleListeIteratif '(1 2 3 4) : ~A ~%" (tailleListeIteratif '(1 2 3 4)))
(format t "(tailleListeIteratif '(1 (2 3) 4) : ~A ~%" (tailleListeIteratif '(1 (2 3) 4)))
(format t "(tailleListeIteratif '(1 ((2 3) 4)) : ~A ~%" (tailleListeIteratif '(1 ((2 3) 4))))
(format t "(tailleListeIteratif '((2 3) 4) : ~A ~%" (tailleListeIteratif '((2 3) 4)))

;; Exo du dessus mais qui marche pour les sous listes.
(defun tailleListe2 (liste) ;; marche pas
  (if (null liste)
    0
    (if (not (listp (car liste)))
      (+ 1 (tailleListe2 (cdr liste)))
      (tailleListe2 (car liste))
    )
  )
)

(format t "~%##### test tailleListe2 #####~%")
(format t "(tailleListe2 '(1 2 3 4) : ~A ~%" (tailleListe2 '(1 2 3 4)))
(format t "(tailleListe2 '(1 (2 3) 4) : ~A ~%" (tailleListe2 '(1 (2 3) 4)))
(format t "(tailleListe2 '(1 ((2 3) 4)) : ~A ~%" (tailleListe2 '(1 ((2 3) 4))))
(format t "(tailleListe2 '(1 (2 3)) : ~A ~%" (tailleListe2 '(1 (2 3))))
(format t "(tailleListe2 '((2 3) 4) : ~A ~%" (tailleListe2 '((2 3) 4)))


(defun fibo(n)
  (cond
    ((or (= n 0) (= n 1)) 1)
    (t (+ (fibo (- n 1)) (fibo (- n 2))))
  )
)

(format t "(fibo 5) : ~A ~%" (fibo 5))