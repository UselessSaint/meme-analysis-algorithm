module Dam_lev_rec where

import Data.List
import System.IO

cmp :: Char -> Char -> Int
cmp a b = if a == b
            then 0
            else 1

dam_lev_rec :: String -> String -> Int
dam_lev_rec "" s2 = length s2
dam_lev_rec s1 "" = length s1
dam_lev_rec s1 s2 = do
    let l1 = length s1
    let l2 = length s2
    if (l1 > 2) && (l2 > 2)
        then if ((last s1) == (s2 !! (l2-2)) && (s1 !! (l1-2)) == (last s2))
                then minimum [(dam_lev_rec (init s1)) s2 + 1, 
                              (dam_lev_rec s1 (init s2)) + 1,
                              (dam_lev_rec (init s1) (init s2)) + (cmp (last s1) (last s2)),
                              (dam_lev_rec (init (init s1)) (init (init s2))) + 1]
                              
                else minimum [(dam_lev_rec (init s1) s2) + 1, 
                              (dam_lev_rec s1 (init s2)) + 1,
                              (dam_lev_rec (init s1) (init s2)) + (cmp (last s1) (last s2))]
        else minimum [(dam_lev_rec "" s2) + 1, 
                      (dam_lev_rec s1 "") + 1,
                      (dam_lev_rec (init s1) (init s2)) + (cmp (last s1) (last s2))]