;; Exo2
(defun my_third(list)
    (car (cdr (cdr list)))
)

(format t "(my_third '(1 2 3 4)) : ~A ~%" (my_third '(1 2 3 4)))

;; Exo2 v2
(defun my_thirdv2(list)
    (if (null list)
        nil ;; then
        (car (cdr (cdr list))) ;; else
    )

)

(format t "(my_thirdv2 '(1 2 3 4)) : ~A ~%" (my_thirdv2 '(1 2 3 4)))

;; Exo2 v3
(defun my_thirdv3(list)
    (if (null list) nil
        (if (listp list)
            (car (cdr (cdr list))) ;; then
            nil ;; else
        )
    )
)

(format t "(my_thirdv3 '(1 2 3 4)) : ~A ~%" (my_thirdv3 '(1 2 3 4)))

;; Exo2 v3 opti
(defun my_thirdv3opti(list)
    (if (or (not (null list)) (listp list))
        (car (cdr (cdr list))) ;; then
        nil ;; else
    )
)

(format t "(my_thirdv3opti '(1 2 3 4)) : ~A ~%" (my_thirdv3opti '(1 2 3 4)))

;; Exo3
(defun my_max(a b)
    (if (> a b)
        a ;; then
        b ;; else
    )
)

(format t "(my_max 4 10) : ~A ~%" (my_max 4 10))

;; Exo4
(defun is_sub_list(list)
    (if (null list)
        nil
        (or (listp (car list)) (is_sub_list(cdr list)))
    )
)

(format t "(is_sub_list '(1 '(1 2 3))) : ~A ~%" (is_sub_list '(1 '(1 2 3))))
(format t "(is_sub_list '(1 1 2 3)) : ~A ~%" (is_sub_list '(1 1 2 3)))

;; Exo5
(defun printPointIteratif(int)
    (loop for i from 1 to int
        do(format t "*" i)
    )
)

;; Exo5
(defun printPointIteratif(int)
    (loop for i from 1 to int
        do(format t "*")
    )
)

(format t "printPointIteratif 10 ")
(printPointIteratif 10)
(format t "~%")

;; Exo5
(defun printPointRec(int)
    (if (not (= int 1))
        (printPointRec (- int 1))
    )
    (format t "*")
)

(format t "printPointRec 10 ")
(printPointRec 10)
(format t "~%")

;; Exo5
;; (defun numAInList(list)
;;     (let (numA 0))
;;     (loop for elt in list
;;         do(if (= elt 'a) (+ numA 1) )
;;     )
;; )

;; (format t "(numAInList '(a b c d a)) ; ~A ~%" (numAInList '(a b c d a)))

;; Exo5
(defun numAInListRec(list)
    (if (null list)
        0
        (if (eql (car list) 'a)
            (+ 1 (numAInListRec (cdr list)))
            (numAInListRec (cdr list))
        )
    )
)

(format t "(numAInListRec '(a b c d a)) : ~A ~%" (numAInListRec '(a b c d a)))

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

(format t "(mystere 'a '(a b c d)) : ~A ~%" (mystere 'a '(a b c d)))

;; Exo7
;; (defun summit (list)

;; )