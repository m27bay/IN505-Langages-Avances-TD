;; Exo2
;; En utilisant car et cdr, ecrire une fonction qui renvoie le quatrieme
;; element d une liste.
(defun my_third(liste)
    (car (cdr (cdr liste)))
)

(format t "~%##### test my_third #####~%")
(format t "(my_third '(1 2 3 4)) : ~A ~%" (my_third '(1 2 3 4)))

;; Exo2 v2
;; En utilisant car et cdr, ecrire une fonction qui renvoie le quatrieme
;; element d une liste.
(defun my_thirdv2(liste)
    (if (null liste)
        nil ;; then
        (car (cdr (cdr liste))) ;; else
    )

)

(format t "~%##### test my_thirdv2 #####~%")
(format t "(my_thirdv2 '(1 2 3 4)) : ~A ~%" (my_thirdv2 '(1 2 3 4)))

;; Exo2 v3
;; En utilisant car et cdr, ecrire une fonction qui renvoie le quatrieme
;; element d une liste.
(defun my_thirdv3(liste)
    (if (null liste) nil
        (if (listp liste)
            (car (cdr (cdr liste)))
        )
    )
)

(format t "~%##### test my_thirdv3 #####~%")
(format t "(my_thirdv3 '(1 2 3 4)) : ~A ~%" (my_thirdv3 '(1 2 3 4)))

;; Exo2 v3 opti
;; En utilisant car et cdr, ecrire une fonction qui renvoie le quatrieme
;; element d une liste.
(defun my_thirdv3opti(liste)
    (if (or (not (null liste)) (listp liste))
        (car (cdr (cdr liste)))
    )
)

(format t "~%##### test my_thirdv3opti #####~%")
(format t "(my_thirdv3opti '(1 2 3 4)) : ~A ~%" (my_thirdv3opti '(1 2 3 4)))

;; Exo3
;; Ecrire une fonction qui prend deux arguments et renvoie le plus
;; grand des deux.
(defun my_max(a b)
    (if (> a b)
        a ;; then
        b ;; else
    )
)

(format t "~%##### test my_max #####~%")
(format t "(my_max 4 10) : ~A ~%" (my_max 4 10))

;; Exo4
;; Ecrire une fonction qui prend une liste comme argument et renvoie
;; vrai si l’un de ses elements est une liste.
(defun is_sub_liste(liste)
    (if (null liste)
        nil
        (or (listp (car liste)) (is_sub_liste(cdr liste)))
    )
)

(format t "~%##### test is_sub_liste #####~%")
(format t "(is_sub_liste '(1 '(1 2 3))) : ~A ~%" (is_sub_liste '(1 '(1 2 3))))
(format t "(is_sub_liste '(1 1 2 3)) : ~A ~%" (is_sub_liste '(1 1 2 3)))

;; Exo5
;; Ecrire une version iterative puis recursive d’une fonction qui :
;; (a) prend un entier positif et imprime autant de points.
(defun printPointIteratif(nombrePoint)
    (loop for i from 1 to nombrePoint
        do(format t "*" i)
    )
)

;; Exo5
;; Ecrire une version iterative puis recursive d’une fonction qui :
;; (a) prend un entier positif et imprime autant de points.
(defun printPointIteratif(nombrePoint)
    (loop for i from 1 to nombrePoint
        do(format t "*")
    )
)

(format t "~%##### test printPointIteratif #####~%")
(format t "printPointIteratif 10 ")
(printPointIteratif 10)
(format t "~%")

;; Exo5
;; Ecrire une version iterative puis recursive d’une fonction qui :
;; (a) prend un entier positif et imprime autant de points.
(defun printPointRec(nombrePoint)
    (if (not (= nombrePoint 1))
        (printPointRec (- nombrePoint 1))
    )
    (format t "*")
)

(format t "~%##### test printPointRec #####~%")
(format t "printPointRec 10 ")
(printPointRec 10)
(format t "~%")

;; Exo5
;; (b) prend une liste et renvoie le nombre de fois le symbole ’a’ apparaˆıt
;; dans cette liste.
(defun numAInliste(liste)
    (setf numA 0)
    (loop for elt in liste
        do(if (eql elt 'a) 
            (setf numA (+ numA 1))
        )
    )
    numA
)

(format t "~%##### test numAInliste #####~%")
(format t "(numAInliste '(a b c d a)) : ~A ~%" (numAInliste '(a b c d a)))

;; Exo5
;; (b) prend une liste et renvoie le nombre de fois le symbole ’a’ apparaˆıt
;; dans cette liste.
(defun numAInlisteRec(liste)
    (if (null liste)
        0
        (if (eql (car liste) 'a)
            (+ 1 (numAInlisteRec (cdr liste)))
            (numAInlisteRec (cdr liste))
        )
    )
)

(format t "~%##### test numAInlisteRec #####~%")
(format t "(numAInlisteRec '(a b c d a)) : ~A ~%" (numAInlisteRec '(a b c d a)))

;; Exo6
;; Check if one elt is nil
(defun enigme(X)
    (and 
        (not (null X))
        (or 
            (null (car X))
            (enigme (cdr X))
        )
    )
)

(format t "~%##### test enigme #####~%")
(format t "(enigme '(a b c d nil)) : ~A ~%" (enigme '(a b c d nil)))

;; Exo6
(defun mystere (X Y)
    (if (null Y)
        nil
        (if (eql (car Y) X)
            0
            (let ((Z (mystere X (cdr Y))))
            (and Z (+ Z 1)))
        )
    )
)

(format t "~%##### test mystere #####~%")
(format t "(mystere 'a '(a b c d)) : ~A ~%" (mystere 'a '(a b c d)))

;; Exo7
;; (defun summit (liste)
;;     (remove nil liste)
;;     ;; (apply #' + liste)
;; )

;; (format t "(summit '(a b nil c nil d)) : ~A ~%" (summit '(a b nil c nil d)))

;; Exo7 v1
(defun summit (liste)
    (cond
        ((null liste) 0)
        ((null (car liste)) (+ 1 (summit (cdr liste))))
        ((not (null (car liste)) )(+ 0 (summit (cdr liste))))
    )
)

(format t "~%##### test summit #####~%")
(format t "(summit '(1 nil 2 nil 3 nil nil 4)) : ~A ~%" (summit '(1 nil 2 nil 3 nil nil 4)))
(format t "(summit '((1 nil) 2 ((nil) 3) nil 4)) : ~A ~%" (summit '((1 nil) 2 ((nil) 3) nil 4)))

;; Exo7 correction theophile
(defun summit2 (liste)
    (apply #' + (remove nil liste))
)

(format t "~%##### test summit2 #####~%")
(format t "(summit2 '(1 nil 2 nil 3 nil 4) : ~A ~%" (summit2 '(1 nil 2 nil 3 nil 4)))
