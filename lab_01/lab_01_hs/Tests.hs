module Tests where

import Data.List
import Data.Matrix
import System.IO

import Lev_matrix
import Dam_lev_matrix
import Control.Exception
import Data.Time.Clock

dam_lev_matrix_time_test :: IO()
dam_lev_matrix_time_test = do
    let s1 = "l6hkkvh4riajoyw0y88m0g5s43az4h787d5n5the"
    let s2 = "76apk7yraubwxe3gb5poe5wpn7kev1ub2hcydo7x"
    
    start <- getCurrentTime
    evaluate $ dam_lev_mtr_abs s1 s2
    end <- getCurrentTime
    
    print $ "Damerau-Levenshtein work time with 40 letter string: "
    print $ diffUTCTime end start

lev_matrix_time_test :: IO()
lev_matrix_time_test = do
    let s1 = "l6hkkvh4riajoyw0y88m0g5s43az4h787d5n5the"
    let s2 = "76apk7yraubwxe3gb5poe5wpn7kev1ub2hcydo7x"
    
    start <- getCurrentTime
    evaluate $ lev_mtr_abs s1 s2
    end <- getCurrentTime
    
    print $ "Levenshtein work time with 40 letter string: "
    print $ diffUTCTime end start

tests_main :: IO()
tests_main = do
    lev_matrix_time_test
    dam_lev_matrix_time_test
    