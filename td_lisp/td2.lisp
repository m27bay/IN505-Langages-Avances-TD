;; Exercice 1 :
;; Ecrire une fonction qui prend une liste de nombres et renvoie vrai si et seulement
;; si la difference entre deux nombres consecutifs est 1, en utilisant :
;; (a) la recursion
(defun diff_entre_deux_nbr_est_un (liste)
    (cond
        ((null liste) nil) ;; liste vide ?
        ((null (cdr liste)) nil) ;; il reste au moins un element en plus dans la liste ?
        ((not (numberp (car liste))) nil) ;; (car liste) est bien un nombre ?
        ((not (numberp (cadr liste))) nil) ;; (cdr (car liste)) est bien un nombre aussi ?
        ;; <=> (not (numberp (cdr (car liste))) nil)
        (t (or (= 1 (abs (- (car liste) (cadr liste)))) (diff_entre_deux_nbr_est_un (cdr liste))))
        ;; appel recursif et soustraction des deux = 1 ?
    )
)

(format t "~%##### test diff_entre_deux_nbr_est_un #####~%")
(format t "(diff_entre_deux_nbr_est_un '(1 2) : ~A ~%" (diff_entre_deux_nbr_est_un '(1 2)))
(format t "(diff_entre_deux_nbr_est_un '(1 3) : ~A ~%" (diff_entre_deux_nbr_est_un '(1 3)))
(format t "(diff_entre_deux_nbr_est_un '(1 3 4) : ~A ~%" (diff_entre_deux_nbr_est_un '(1 3 4)))
(format t "(diff_entre_deux_nbr_est_un '(2 3 5) : ~A ~%" (diff_entre_deux_nbr_est_un '(2 3 5)))

;; Exercice 1 :
;; Ecrire une fonction qui prend une liste de nombres et renvoie vrai si et seulement
;; si la difference entre deux nombres consecutifs est 1, en utilisant :
;; (b) do

;; Vide

;; Exercice 2 :
;; Ecrire une fonction qui renvoie le carre d’un nombre, et qui ne calcule pas le
;; carre si le nombre est un entier positif inferieur ou egal a 5.
(defun mon_carree_bizarre (entier)
    (cond
        ((not (numberp entier)) nil) ;; est ce bien un entier ?
        ((not (or (= entier 5) (< entier 5))) (* entier entier))
    )
)

(format t "~%##### test mon_carree_bizarre #####~%")
(format t "(mon_carree_bizarre 4) : ~A ~%" (mon_carree_bizarre 4))
(format t "(mon_carree_bizarre 5) : ~A ~%" (mon_carree_bizarre 5))
(format t "(mon_carree_bizarre 6) : ~A ~%" (mon_carree_bizarre 6))

;; Exercice 3 :
;; Reecrire la fonction mystery de l’exercice 6 (TD1) en utilisant cond.
(defun mystere (X Y)
    (if (null Y)
        nil
        (if (eql (car Y) X)
            0
            (let ( (Z (mystere X (cdr Y))) ) (and Z (+ Z 1)))
        )
    )
)

(format t "~%##### test mystere #####~%")
(format t "(mystere '(1 2 3) '(1 2 3)) : ~A ~%" (mystere '(1 2 3) '(1 2 3)))
(format t "(mystere '(1 3 5) '(2 4 6)) : ~A ~%" (mystere '(1 3 5) '(2 4 6)))
(format t "(mystere '(1 3 5) '(2 4)) : ~A ~%" (mystere '(1 3 5) '(2 4)))
(format t "(mystere '(1 3) '(2 4 6)) : ~A ~%" (mystere '(1 3) '(2 4 6)))
(format t "(mystere 1 '(1 2 3)) : ~A ~%" (mystere '(1 3) '(1 2 3)))
(format t "(mystere 4 '(1 2 3)) : ~A ~%" (mystere '(1 3) '(1 2 3)))

