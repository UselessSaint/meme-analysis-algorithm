module Main where

import Qsort
import Bsort
import InSort

import Data.Time.Clock
import Control.Exception
import System.IO    
import System.Environment

test :: Int -> Int -> IO()
test f len = do
    let m = [len - i + 1 | i <- [1..len]]

    start <- getCurrentTime
    let !r1 = qSort m
    end <- getCurrentTime
    if f == 0
        then do 
            putStr "qSort TIme: "
            print $ diffUTCTime end start
        else 
            appendFile "qSort_times.txt" ((show len) ++ " " ++ (show $ diffUTCTime end start) ++ "\n")
            
    start <- getCurrentTime
    let !r2 = bSort m
    end <- getCurrentTime
    if f == 0
        then do 
            putStr "bSort TIme: "
            print $ diffUTCTime end start
        else 
            appendFile "bSort_times.txt" ((show len) ++ " " ++ (show $ diffUTCTime end start) ++ "\n")
            
    start <- getCurrentTime
    let !r3 = inSort m
    end <- getCurrentTime
    if f == 0
        then do 
            putStr "inSort TIme: "
            print $ diffUTCTime end start
        else 
            appendFile "inSort_times.txt" ((show len) ++ " " ++ (show $ diffUTCTime end start) ++ "\n")

main :: IO()
main = do
    hSetBuffering stdout NoBuffering

    args <- getArgs
    if length args == 2
        then do
            let len = read (args !! 1)::Int
            let f = read (args !! 0)::Int
            
            test f len
        else putStr "hey"
        