module Main where

import Qsort
import Bsort

main :: IO()
main = do
    let v = [5,4,3,2,1,0]
    
    print $ qSort(v)
    
    print $ bSort(v)