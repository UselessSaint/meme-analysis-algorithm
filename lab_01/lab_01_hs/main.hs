module Main where

import Lev_matrix
import Dam_lev_matrix
import Dam_lev_rec

import Data.List
import Data.Matrix
import System.IO

import Data.Time.Clock
import Control.Exception

main :: IO()
main = do
    hSetBuffering stdout NoBuffering

    putStr "Run in test mode [Y/N]? \n"
    putStr "Answer: "
    ans <- getLine
    putStr "\n"
    
    if ans == "Y" || ans == "y"
        then do
            putStr "Input 1st: "
            s1 <- getLine
            putStr "Input 2st: "
            s2 <- getLine
            putStr "\n"
        
            putStr $ "Damerau Levenshtein distance: \n"
            start <- getCurrentTime
            -- print $ dam_lev_mtr_abs s1 s2
            evaluate $ dam_lev_mtr_abs s1 s2
            evaluate $ dam_lev_mtr_abs s1 s2
            evaluate $ dam_lev_mtr_abs s1 s2
            evaluate $ dam_lev_mtr_abs s1 s2
            evaluate $ dam_lev_mtr_abs s1 s2
            evaluate $ dam_lev_mtr_abs s1 s2
            evaluate $ dam_lev_mtr_abs s1 s2
            evaluate $ dam_lev_mtr_abs s1 s2
            evaluate $ dam_lev_mtr_abs s1 s2
            evaluate $ dam_lev_mtr_abs s1 s2
            
            end <- getCurrentTime
            
            putStr "Time for 12 times: "
            print $ diffUTCTime end start
            putStr "\n"
            
            putStr $ "Levenshtein distance: \n"
            start <- getCurrentTime
            -- print $ lev_mtr_abs s1 s2
            evaluate $ lev_mtr_abs s1 s2
            evaluate $ lev_mtr_abs s1 s2
            evaluate $ lev_mtr_abs s1 s2
            evaluate $ lev_mtr_abs s1 s2
            evaluate $ lev_mtr_abs s1 s2
            evaluate $ lev_mtr_abs s1 s2
            evaluate $ lev_mtr_abs s1 s2
            evaluate $ lev_mtr_abs s1 s2
            evaluate $ lev_mtr_abs s1 s2
            evaluate $ lev_mtr_abs s1 s2
            evaluate $ lev_mtr_abs s1 s2
            evaluate $ lev_mtr_abs s1 s2
            
            end <- getCurrentTime
            
            putStr "Time for 12 times: "
            print $ diffUTCTime end start
            putStr "\n"
         
            putStr $ "Damerau Levenshtein distance rec: "
            start <- getCurrentTime
            -- print $ dam_lev_rec s1 s2
            -- evaluate $ dam_lev_rec s1 s2
            end <- getCurrentTime
            
            print $ diffUTCTime end start
        else do
            putStr "Input 1st: "
            s1 <- getLine
            putStr "Input 2st: "
            s2 <- getLine
            
            putStr $ "Damerau Levenshtein distance: \n"
            print $ dam_lev_mtr_abs s1 s2
            
            putStr $ "Levenshtein distance: \n"
            print $ lev_mtr_abs s1 s2
            
            putStr $ "Damerau Levenshtein distance rec: "
            print $ dam_lev_rec s1 s2
