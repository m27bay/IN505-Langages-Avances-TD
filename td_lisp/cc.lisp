;; Exo1
(defun my_replace_rec (symb1 symb2 liste)
    (cond
        ((null liste) l)
        ((null (car liste)) l)
        ((eql (car liste) symb1) (setf (car liste) symb2))
        (t (my_replace_rec symb1 symb2 (cdr liste)))
    )
)

(format t "~%##### test my_replace_rec #####~%")
(format t "(my_replace_rec 'a 1 '((a b) c a ((a)))) : ~A ~%" (my_replace_rec 'a 1 '((a b) c a ((a)))))

;; Correction theophile
(defun my_replace_all (x y l)
    (cond
        ((null l) l)
        ((equal x (car l)) (cons y (my_replace_all x y (cdr l))))
        ((listp (car l)) (cons (my_replace_all x y (car l)) (my_replace_all x y (cdr l))))
        (t (cons (car l) (my_replace_all x y (cdr l))))
    )
)

(format t "~%##### test my_replace_all #####~%")
(format t "(my_replace_all 'a 1 '((a b) c a ((a)))) : ~A ~%" (my_replace_all 'a 1 '((a b) c a ((a)))))