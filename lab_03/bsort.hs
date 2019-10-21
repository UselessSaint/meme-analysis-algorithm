module Bsort where

bSort' :: (Ord a) => [a] -> [a]
bSort' [] = []
bSort' [x] = [x]
bSort' (xf:xs:x) = 
        if xf > xs
            then (xs:bSort'(xf:x))
            else (xf:bSort'(xs:x))
            
repNTimes :: (Ord a) => Int -> ([a] -> [a]) -> [a] -> [a]
repNTimes 1 f x = f x
repNTimes n f x = repNTimes (n-1) f (f x)

bSort :: (Ord a) => [a] -> [a]
bSort x = repNTimes (length x) bSort' x 