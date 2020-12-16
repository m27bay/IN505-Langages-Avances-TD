;; Exercice 1 :
;; Ecrire une fonction recursive qui renvoie sous forme d’un couple le minimum et le
;; maximum d’un vecteur de nombres.

;; vector(1 2 3 'h) -> renvoie #(1 2 3 'h)
;; (every 'numberp '(1 a "hi")) -> renvoie NIL
;; (some 'numberp '(1 a "hi")) -> renvoie T

;; Exercice 4 :
;; Definir deux versions (iterative et recursive) d’une fonction qui prend un objet et
;; une liste et renvoie une nouvelle liste dans laquelle l’objet apparait entre chaque
;; paire d’el`ments de la liste initiale.
;; > (interspace ! − !(a b c d))
;; (A − B − C − D)

(defun interspace (symbole liste)
    (cond
        ((null liste) liste)
        ((null (cdr liste)) (list (car liste)))
        (t (cons (car liste) (cons symbole (interspace symbole (cdr liste)))))
    )
)

(format t "~%##### test interspace #####~%")
(format t "(interspace '_ '(a b c d)) : ~A ~%" (interspace '_ '(a b c d)))

