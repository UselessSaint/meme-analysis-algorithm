module Main where

import Lev_matrix
import Dam_lev_matrix
import Dam_lev_rec
import Tests

import Data.List
import Data.Matrix
import System.IO

-- import Data.Time.Clock.System
import Data.Time.Clock
import Control.Exception


-- test_func :: 

main :: IO()
main = do
    hSetBuffering stdout NoBuffering

    putStr "Input 1st: "
    s1 <- getLine
    putStr "Input 2st: "
    s2 <- getLine
    {-
    putStr $ "Damerau Levenshtein distance: \n"
    print $ dam_lev_mtr_abs s1 s2
    
    putStr $ "Levenshtein distance: \n"
    print $ lev_mtr_abs s1 s2
    
    putStr $ "D-L D rec: "
    print $ dam_lev_rec s1 s2
    -}
    
    
    start <- getCurrentTime
    print $ dam_lev_rec s1 s2
    end <- getCurrentTime

    print $ diffUTCTime end start
