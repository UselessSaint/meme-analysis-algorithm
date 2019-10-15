module Qsort where

qSort :: (Ord a) => [a] -> [a]
qSort [] = []
qSort (x:xs) = qSort(left) ++ [x] ++ qSort(right)
    where
        left = [a | a <- xs, a <= x]
        right = [a | a <- xs, a > x]
