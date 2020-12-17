(defun hello_world () 'hello)

(defun carre (x)
    (if (numberp x)
        (* x x)
        "error"
    )
)

;; fonction anonyme 
;; (let ((x 1) (y 2)) (+ x y))
;; <=>
;; ((lambda (x y) (+ x y)) 1 2)

; Exo 2 
(defun 4th (l) 
    (if ( > (length l) 4)
        (car (cdr (cdr (cdr l)))) ;; <=> cadddr
        "error"
    )
)

(defun my_count (l) 
    (if (null l)
        0
        (+ 1 (my_count (cdr l)))
    )
        
)
 
(defun my_count (l)
    (mycountbis l 0)
)
	
(defun mycountbis (l res)
    (if (null l)
        res
        (mycountbis (cdr l) (+ 1 res))
    )    
)

; Exo 3
(defun maxi (x y)
    (and (numberp x) (numberp y)(max x y))    
)
; ou
(defun maxi (x y)
    (if (> x y) x y)
)

; Exo 3 bis
(defun my_length (l) 
    (if (null l)
        0
        (+ 1 (my_length (cdr l)))
    )
)

(defun my_lengthBis (l val)
    (if (null l)
        (+ val 0) 
        (my_lengthBis (cdr l) (+ val 1))
    )
)
 
; Exo 4
(defun foo (l)
    (cond
        ((null l) nil)
        ((listp (car l)) T)
        ( t (foo (cdr l)))
    )
)

; (cond (t1 a1) (t2 a2) .... (tn an))
; (progn instruction1 instruct2 .... instructionn) -> la valeur de instructionn
; (prog1 instruction1 instruct2 .... instructionn) -> la valeur de instruction1

; Exo 5	a
(defun affich_point_iter (n)
    (loop repeat n
        do (format t ".")
    )
)

(defun affich_point_recur (n)
    (cond
        ((equal n 0) nil)
        (t (progn (format t ".") (affich_point_recur (- n 1))))
    )
)		

; Exo 5	b
(defun count_symb (symb l)
    (cond
        ((null l) 0)
	    ((if (eq symb (car l)) (+ 1 (count_symb symb (cdr l)))))
	    (t (count_symb symb (cdr l)))
    )
)
	   
(defun count_symb_iter (symb l res)
    (cond
        ((null l) res)
        ((if (eq symb (car l)) (count_symb_iter symb (cdr l) (+ 1 res))))
        (t (count_symb_iter symb (cdr l) (+ 0 res)))
    )
)

(defun count_iter (symb l)
    (progn
        (setf res 0)
        (loop for x in l 
            do (if (eq x symb) (setf res (+ 1 res)) (setf res (+ 0 res)))
        )
        res
    )
)
		
(defun count_symb_all (symb l)
    (cond
        ((null l) 0)
        ((atom l) 0)
        ((eq symb l) 1)
        (t (+ (count_symb_all symb (car l)) (count_symb_all symb (cdr l))))
    )
)
	   
; Exo 6 la fonction enigme retourne T si la liste contient la liste vide, NIL sinon
(defun enigme (x)
    (and (not (null x)) (listp x) (or (null (car x)) (enigme (cdr x)))))
    
; la fonction mystère retourne la position de l'element x dans la liste y
(defun mystere (x y)
    (if (null y)
        nil
        (if (eql (car y) x) 1 (let ((z (mystere x (cdr y)))) (and z (+ 1 z))))
    )
)

; Exo 7 corrections du code
(defun summit (liste)
    (let
        ((x (remove nil liste)))
        (apply '+ x)
    )
)

(defun summit (liste)
    (apply '+ (remove nil liste))
)


(defun summit (liste)
    (if (null liste)
        0
        (let ((x (car liste)))
            (if (null x) (summit (cdr liste))
            (+ x (summit (cdr liste))))
        )
    )
)
	
	
;; TD2

; exo 1
(defun foo (l)
    (cond
        ((null l) T)
        ((null (cdr l) ) T)
        (t ( and (=  1 (abs (- (car l ) (cadr l)))) (foo (cdr l))))
    )    
)

;exo 2
(defun carre (x)
    (if (and (numberp x) (> x 5))
        (* x x)
        'error
    )
)
 
; exo 3
(defun mystere (x y)
    (if (null y)
        nil
        (if (eql (car y) x)
            1
            (let ((z (mystere x (cdr y)))) (and z (+ 1 z)))
        )
    )
)

; (cond (t1 a1) (t2 a2) .... (tn an))
(defun mystere (x y)
    (cond
        ((null y) nil)
        ((eq (car y) x) 1)
        (t (let ((z (mystere x (cdr y)))) (and z (+ 1 z)))
    )
)
 
 ; exo 4
(defun min_max_bis (l min max)
    (cond
        ((null l) (list min max))
        (( > (car l) max) (min_max_bis (cdr l) min (car l)))
        (( < (car l) min) (min_max_bis (cdr l) (car l) max))
        (t (min_max_bis (cdr l) min max))
    )
)

(defun min_max (l)
    (if (null l)
        nil
        (min_max_bis (cdr l) (car l) (car l))
    )    
)

; Exo 5
(defun maxi (l)
    (let
        (
            (x (cadr (min_max l)))
        )
        (let ((y (cadr (min_max (remove x l)))))
            (* x y)
        )
    )
)
		
; Exo 6
(defun rever (l)
    (cond
        ((null l) l)
        ( t (append (rever (cdr l)) (list (car l))))
    )
)

; Exo 6 bis
(defun my_remove (x l)
    (cond
        ((null l) l)
        ((equal x (car l)) (my_remove x (cdr l)))
        (t (cons (car l) (my_remove x (cdr l))))
    )
)

; Exo 6 ter
(defun my_remove_all (x l)
    (cond
        ((null l) l)
        ((equal x (car l)) (my_remove_all x (cdr l)))
        ((listp (car l)) (cons (my_remove_all x (car l)) (my_remove_all x (cdr l))))
        (t (cons (car l) (my_remove_all x (cdr l))))
    )
)

;Exo 6.4
(defun my_replace (symb1 symb2 l)
    (cond
        ((null l) l)
        ((equal (car l) symb1) (cons symb2 (my_replace symb1 symb2 (cdr l))))
        (t (cons (car l) (my_replace symb1 symb2 (cdr l))))
    )
)

;Exo 6.5
(defun my_replace_all (symb1 symb2 l)
    (cond
        ((null l) l)
        ((equal (car l) symb1) (cons symb2 (my_replace_all symb1 symb2 (cdr l))))
        ((listp (car l)) (cons (my_replace_all symb1 symb2 (car l)) (my_replace_all symb1 symb2 (cdr l))))
        (t (cons (car l) (my_replace_all symb1 symb2 (cdr l))))
    )
)

(format t "~A" (my_replace_all 'a 1 '((a b) c a ((a)))))


; exo 7
(defun my_equal (l1 l2)
    (cond
        ((and (null l1) (null l2)) T)
        ((and (atom l1) (atom l2)) (eq l1 l2))
        ((and (listp l1) (listp l2)) (and (my_equal (car l1) (car l2)) (my_equal (cdr l1) (cdr l2))))
        (t NIL)
    )
)

;exo 7.bis compte le nombre de fois où une s_exp apparaît dans une liste
(defun count_sexp (s l)
    (cond
        ((atom l) 0)
        ((equal s (car l)) (+ 1 (count_sexp s (cdr l))))
        ((listp (car l)) (+ (count_sexp s (car l)) (count_sexp s (cdr l))))
        (t (count_sexp s (cdr l)))
    )
)

;; TD3 
;; fonctions sur les vecteurs
;; (svref #(1 2 3)) 0)
;; (vector 4 5 'a "hi")
;; transformer un vecteur en une liste
;; (concatenate 'list #(1 2 3))
;; transformer une liste en 1 vecteur 
;; (concatenate 'vector '(1 2 3 5 a "hi"))

; exo 1 (version 1 en s'appyuant sur le corrigé du TD2)
(defun min_max_bis (l min max)
    (cond
        ((null l) (list min max))
        (( > (car l) max) (min_max_bis (cdr l) min (car l)))
        (( < (car l) min) (min_max_bis (cdr l) (car l) max))
        (t (min_max_bis (cdr l) min max))
    )
)

(defun min_max (l)
    (if (null l)
        nil
        (min_max_bis (cdr l) (car l) (car l))
    )
)

(defun min_max_vec (v)
	(let
        ((x (concatenate 'list v)))
	    (if (every 'numberp x)
            (min_max x)
            'Error
        )
    )
)
	
	
; exo 1 (version 2 avec fonction sur les vecteurs)
(defun min_max_vec_bis (v min max i)
    (cond
        ((= (length v) i) (list min max))
        (( > (svref v i) max) (min_max_vec_bis v min (svref v i) (+ i 1))) ;; svref prend dans le vector v l'element en position i
        (( < (svref v i) min) (min_max_vec_bis v (svref v i) max (+ i 1)))
        (t (min_max_vec_bis v min max (+ i 1)))
    )
)

(defun min_max_vec (v)
	(let
        ((x (concatenate 'list v)))
	    (if (not (every 'numberp x))'Error
	    (if (= (length v) 0)
            nil
            (min_max_vec_bis v (svref v 0) (svref v 0) 1 ))
        )
    )        
)

(defun 3nombres (liste)
    (cond
        ((null liste) 'perdant)
        ((not (>= (length liste) 3)) 'perdant)
        ((not (numberp (car liste))) 'perdant)
        ((not (numberp (cadr liste))) 'perdant)
        ((not (numberp (caddr liste))) 'perdant)
        (t 'bravo)
    )
)

(format t "~A ~%" (3nombres '(1 2 3)))
(format t "~A ~%" (3nombres '(1 cat)))
(format t "~A ~%" (3nombres (cons 1 (cons -100 (cons -1 ())))))

; exo 2
; version recursive
(defun exist (symb l)
    (cond
        ((null l) l)
        ((and (consp l) (eq symb (car l))) t)
        (t (exist symb (cdr l)))
    )
)

(defun remove_duplicate (l)
    (cond
        ((null l) l)
        ((and (consp l) (exist (car l) (cdr l))) (remove_duplicate (cdr l)))
        ((consp l) (cons (car l) (remove_duplicate (cdr l))))
        (t 'error)
    )    
)
	
(defun precede_rec (symb l)
    (cond
        ((null l) l)
        ((and (consp l) (not (null (cddr l))) (eq symb (cadr l)) (cons (car l) (precede_rec symb (cdr l)))))
        (t (precede_rec symb (cdr l)))
    )
)

(defun precede (symb chaine)
    (remove_duplicate (precede_rec symb (concatenate 'list chaine)))) ;; (concatenate 'list chaine) -> transforme la chaine(str) en liste
 
; version itérative
(defun precede_iter (symb chaine)
    (let
        ((res (loop for i from 1 to (- (length chaine) 1)
                collect ( if (eq symb (char chaine i)) (char chaine (- i 1))))
                ;; char recupere le char à la pos x                                                                    
                ;; collect créer une liste avec chaque iteration
            )
        )
        (remove_duplicate (remove nil res))
    )
)

;fonctions n-aire
(defun my_plusn (&rest ll)
    (cond
        ((null ll) 0)
        (t (+ (car ll) (apply (my_plusn (cdr ll))))
    )
)

; my_and  et my_or n-aire
(defun my_and (&rest ll)
    (cond
        ((null ll) T)
        (t (if (car ll) (apply 'my_and (cdr ll)) NIL))
    )
)

(defun my_or (&rest ll)
    (cond
        ((null ll) NIL)
        (t (if (car ll) (car ll) (apply 'my_or (cdr ll))))
    )
)

(defun my_list (&rest ll) ll)

;exo 4
(defun interspace (symb l)
    (cond
        ((null l) l)
        ((null (cdr l)) (list (car l)))
        (t (cons (car l) (cons symb (interspace symb (cdr l)))))
    )
)


;exo 3

; (funcall 'atom 1) = T
; (apply '+ '(1 2 3 4 5)) = 10
; (mapcap 'listp '(a (2) 4))  = (nil T nil)


(defun pos_+ (l &optional (res 0))
    (cond
        ((null l) l)
        ( T (cons (+ (car l) res) (pos_+ (cdr l) (+ 1 res))))
    )
)
       
(defun pos_iter (l)
    (loop for i in l
        for j from 0 to (- (length l) 1)
        collect (+ i j)
    )
)

(defun pos+_map (l)
    (cond
        ((null l) l)
        ((consp l) (cons (car l) (pos+_map (mapcar '1+ (cdr l)))))
        (t 'error)
    )
)

; Mapcar
(mapcar (lambda (x) (+ x 2)) '(3 4 5))
; fonction anonyme
(funcall (lambda (x) (* x x)) 5)

; TD4 
; Exo1
(defun fun_n (&rest ll)
(length ll))

; (progn (print "hello:") (read))

; Exo 2
(let ((val 0)) (defun foo (n)  (and (numberp n) (> n 0) (setf val (max n val)))))

; Exo 3
(let ((val 0)) (defun foo (n) (prog1 (> n val) (setf val n))))

;EXO 4
(defun affiche_fic (nom)
(with-open-file (stream nom)
     (loop for line = (read-line stream nil 'eof)
         until (eq line 'eof)
         do (print line))))
         
(defun affiche_fic (nom)
(with-open-file (stream nom)
     (loop for line = (read-line stream nil 'eof)
         until (eq line 'eof)
         collect line)))

; EXO 5
(defparameter *nom_fic_sortie* (open "sortie.txt"))

(defun transfert_fic (nom sortie)
(let ((out (open sortie :direction :output :if-exists :supersede)))
(with-open-file (in nom)
   (loop for line = (read-line in nil 'eof)
       until (eq line 'eof)
       do (if (not (eq '#\% (char line 0)))
            (progn (fresh-line out) (write-string line out))))
(close out))))

; composition de fonction
(defun composition (f g)
(lambda (x) (funcall g (funcall f x))))

(funcall (composition 'sin 'asin ) 1)
