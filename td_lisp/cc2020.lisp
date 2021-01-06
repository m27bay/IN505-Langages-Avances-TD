(defun my_some(f l)
  (if (null l) 
    nil 
    (or (funcall f (car l)) (my_some f (cdrl)))
  )
)

(format t "(my_some 'atom '(1 2 3 4) : ~A ~%" (my_some 'atom '(1 2 3 4)))

(defun my_mapc(f l)
  (and (consp l) (cons (funcall f (car l)) (my_mapc f (cdr l))))
)

(defun my_pairlis (lc lv)
  (if (consp lc) 
    (cons (list (car lc) (car lv)) (my_pairlis (cdr lc) (cdr lv)))
  )
)

(format t "(my_pairlis '(1 2 3 4) '(5 6 7 8) : ~A ~%" (my_pairlis '(1 2 3 4) '(5 6 7 8)))

(defun aplanir(l)
  (cond 
    ((null l) l)
    ((atom l) (list l))
    ((consp l) (append (aplanir (car l)) (aplanir (cdr l))))
  )
)

(format t "(aplanir '(1 (2 3) 4) : ~A ~%" (aplanir '(1 (2 3) 4)))
(format t "(aplanir '( 1 ((a) 2) ((b)) (d))) : ~A ~%" (aplanir '( 1 ((a) 2) ((b)) (d))))

(defun snoc(l)
  (cond 
    ((atom l) l)
    (T (list 'cons (snoc (car l)) (snoc (cdr l))))
  )

)
(format t "(snoc '(1 (2 3) 4 ()) : ~A ~%" (snoc '(1 (2 3) 4 ())))

(defun my_every (predicat liste)
  (cond
    ((null liste) T)
    (T (and (funcall predicat (car liste))(my_every predicat (cdr liste))))
  )
)

(format t "(my_every 'atom '(1 2 3 4) : ~A ~%" (my_every 'atom '(1 2 3 4)))
(format t "(my_every 'consp '(1 (a b c) 3))) : ~A ~%" (my_every 'consp '(1 (a b c) 3)))
(format t "(my_every 'atom '(1 2 3))) : ~A ~%" (my_every  'atom '(1 2 3)))