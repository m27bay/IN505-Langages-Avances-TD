;; Exercice 1 :
;; Ecrire une fonction qui prend une liste de nombres et renvoie vrai si et seulement
;; si la difference entre deux nombres consecutifs est 1, en utilisant :
;; (a) la recursion
(defun diff_entre_deux_nbr_est_un_rec (liste)
    (cond
        ((null liste) nil) ;; liste vide ?
        ((null (cdr liste)) nil) ;; il reste au moins un element en plus dans la liste ?
        ((not (numberp (car liste))) nil) ;; (car liste) est bien un nombre ?
        ((not (numberp (cadr liste))) nil) ;; (cdr (car liste)) est bien un nombre aussi ?
        ;; <=> (not (numberp (cdr (car liste))) nil)
        (t (or (= 1 (abs (- (car liste) (cadr liste)))) (diff_entre_deux_nbr_est_un_rec (cdr liste))))
        ;; appel recursif et soustraction des deux = 1 ?
    )
)

(format t "~%##### test diff_entre_deux_nbr_est_un_rec #####~%")
(format t "(diff_entre_deux_nbr_est_un_rec '(1 2) : ~A ~%" (diff_entre_deux_nbr_est_un_rec '(1 2)))
(format t "(diff_entre_deux_nbr_est_un_rec '(1 3) : ~A ~%" (diff_entre_deux_nbr_est_un_rec '(1 3)))
(format t "(diff_entre_deux_nbr_est_un_rec '(1 3 4) : ~A ~%" (diff_entre_deux_nbr_est_un_rec '(1 3 4)))
(format t "(diff_entre_deux_nb(defun rep_symb (symb l)
    (cond
        ((null l) nil)
        ((eq ('symb (car l))) (+ 1(rep_symb(cdr l))))
        (t (rep_symb (cdr l)))
    )
)
(format t "(rep_symb 'a '(5 a  a 9 a6a a 8 a)) : ~A ~%" (rep_symb 'a '(5 a  a 9 a6a a 8 a)))r_est_un_rec '(2 3 5) : ~A ~%" (diff_entre_deux_nbr_est_un_rec '(2 3 5)))

;; Exercice 1 :
;; Ecrire une fonction qui prend une liste de nombres et renvoie vrai si et seulement
;; si la difference entre deux nombres consecutifs est 1, en utilisant :
;; (b) do
(defun diff_entre_deux_nbr_est_un_ite (liste)
    ;; Empty
)

(format t "~%##### test diff_entre_deux_nbr_est_un_ite #####~%")
(format t "(diff_entre_deux_nbr_est_un_ite '(1 2) : ~A ~%" (diff_entre_deux_nbr_est_un_ite '(1 2)))
(format t "(diff_entre_deux_nbr_est_un_ite '(1 3) : ~A ~%" (diff_entre_deux_nbr_est_un_ite '(1 3)))
(format t "(diff_entre_deux_nbr_est_un_ite '(1 3 4) : ~A ~%" (diff_entre_deux_nbr_est_un_ite '(1 3 4)))
(format t "(diff_entre_deux_nbr_est_un_ite '(2 3 5) : ~A ~%" (diff_entre_deux_nbr_est_un_ite '(2 3 5)))

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
(format t "(mystere 1 '(1 2 3)) : ~A ~%" (mystere '1 '(1 2 3)))
(format t "(mystere 1 '(1 2 3)) : ~A ~%" (mystere '3 '(1 2 3)))
(format t "(mystere 4 '(1 2 3)) : ~A ~%" (mystere '4 '(1 2 3)))

;; Exercice 4 :
;; Ecrire la fonction min-max qui affiche le plus petit et le plus grand element
;; d’une liste.
(defun min_max (entier entier2)
    (cond
        ((not (numberp entier)) nil)  ;; verifie que entier est nombre
        ((not (numberp entier2)) nil) ;; verifie que entier2 est nombre
        ((> entier entier2) (format t "le plus grand entre ~A et ~A est ~A ~%" entier entier2 entier))
        ((> entier2 entier) (format t "le plus grand entre ~A et ~A est ~A ~%" entier entier2 entier2))
        ((< entier entier2) (format t "le plus petit entre ~A et ~A est ~A ~%" entier entier2 entier))
        ((< entier2 entier) (format t "le plus petit entre ~A et ~A est ~A ~%" entier entier2 entier2))
    )
)

(format t "~%##### test min_max #####~%")
(min_max 2 3)
(min_max 4 4)
(min_max 10 2)