module Qsort where

qSort :: [a] -> [a]
qSort [] = []
qSort (xs:x) = qSort(left) ++ xs ++ qSort(right)
    where
        left = [a | a <- x, a <= xs]
        right = [a | a <- x, a > xc]