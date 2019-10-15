module Bsort where

bSort :: (Ord a) => [a] -> [a]
bSort [] = []
bSort [x] = [x]
bSort (xf:xs:x) = 
        if xf > xs
            then (xs:bSort(xf:x))
            else (xf:bSort(xs:x))