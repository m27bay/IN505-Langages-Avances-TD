;; Exo2
(defun my_third(x)
    (car (cdr (cdr x)))
)

(format t "(my_third '(1 2 3 4)) : ~A ~%" (my_third '(1 2 3 4)))

;; Exo2 v2
(defun my_thirdv2(x)
    (if (null x)
        nil ;; then
        (car (cdr (cdr x))) ;; else
    )

)

(format t "(my_thirdv2 '(1 2 3 4)) : ~A ~%" (my_thirdv2 '(1 2 3 4)))

;; Exo2 v3
(defun my_thirdv3(x)
    (if (null x) nil
        (if (listp x)
            (car (cdr (cdr x))) ;; then
            nil ;; else
        )
    )
)

(format t "(my_thirdv3 '(1 2 3 4)) : ~A ~%" (my_thirdv3 '(1 2 3 4)))

;; Exo2 v3 opti
(defun my_thirdv3opti(x)
    (if (or (not (null x)) (listp x))
        (car (cdr (cdr x))) ;; then
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
(defun )