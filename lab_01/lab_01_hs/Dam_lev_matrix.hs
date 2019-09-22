module Dam_lev_matrix where

import Data.List
import Data.Matrix
import System.IO

dam_lev_mtr_abs :: String -> String -> Matrix Int
dam_lev_mtr_abs s1 s2 = do
    let a = length s2
    let b = length s1
    let mtr = fromLists [[j | j <- [i..a+i]] | i <- [0..b]]
    
    dam_lev_mtr s2 s1 2 2 mtr

cmp :: Char -> Char -> Int
cmp a b = if a == b
            then 0
            else 1

calc_min :: String -> String -> Int -> Int -> Matrix Int -> Int
calc_min s1 s2 i j mtr = 
    if (i > 2) && (j > 2)
        -- очень страшно, вырубай
        then if ((s1 !! (j-2)) == (s2 !! (i-3))) && ((s1 !! (j-3)) == (s2 !! (i-2)))
            then minimum [(getElem (i-1) j mtr) + 1, 
                          (getElem i (j-1) mtr) + 1,
                          (getElem (i-1) (j-1) mtr) + (cmp (s1 !! (j-2)) (s2 !! (i-2))),
                          (getElem (i-2) (j-2) mtr) + 1]
                          
            else minimum [(getElem (i-1) j mtr) + 1, 
                          (getElem i (j-1) mtr) + 1,
                          (getElem (i-1) (j-1) mtr) + (cmp (s1 !! (j-2)) (s2 !! (i-2)))]
                          
        else minimum [(getElem (i-1) j mtr) + 1, 
                      (getElem i (j-1) mtr) + 1,
                      (getElem (i-1) (j-1) mtr) + (cmp (s1 !! (j-2)) (s2 !! (i-2)))]
                 -- простите

dam_lev_mtr :: String -> String -> Int -> Int -> Matrix Int -> Matrix Int
dam_lev_mtr "" s2 i j mtr = mtr
dam_lev_mtr s1 "" i j mtr = mtr
dam_lev_mtr s1 s2 i j mtr = 
    -- проверка на выход за пределы матрицы {
    if i >= length s2 + 2
        then dam_lev_mtr s1 s2 2 (j+1) mtr
        else if j >= length s1 + 2
            then mtr
            -- проверка на выход за пределы матрицы }
            else dam_lev_mtr s1 s2 (i+1) j (setElem (calc_min s1 s2 i j mtr)  (i,j) mtr)