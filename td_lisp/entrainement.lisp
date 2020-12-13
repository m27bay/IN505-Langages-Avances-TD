;; Exo : fonction qui retourne la taille d'une liste.
(defun tailleListe (liste)
    (if (null liste) 
        0
        (+ 1 (tailleListe (cdr liste)))
    )
)

(format t "(tailleListe '(1 2 3 4) : ~A ~%" (tailleListe '(1 2 3 4)))

;; Exo du dessus mais qui marche pour les sous listes.
(defun tailleListe2 (liste)
    (cond
        (null liste)
    )
)

(format t "(tailleListe '(1 (2 3) 4) : ~A ~%" (tailleListe '(1 (2 3) 4)))

