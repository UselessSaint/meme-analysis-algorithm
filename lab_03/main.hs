module Main where

import Qsort
import Bsort
import InSort

import Data.Time.Clock
import Control.Exception
import System.IO    
import System.Environment

testF :: Int -> Int -> IO()
testF f len = do
    let m1 = [i | i <- [1..len]]
    let m2 = [i | i <- [1..len]]
    let m3 = [i | i <- [1..len]]

    start <- getCurrentTime
    let !r1 = qSort m1
    end <- getCurrentTime
    if f == 0
        then do 
            putStr "qSort TImeF: "
            print $ diffUTCTime end start
        else 
            appendFile "qSort_timesF.txt" ((show len) ++ " " ++ (show $ diffUTCTime end start) ++ "\n")
            
    start <- getCurrentTime
    let !r2 = bSort m2
    end <- getCurrentTime
    if f == 0
        then do 
            putStr "bSort TImeF: "
            print $ diffUTCTime end start
        else 
            appendFile "bSort_timesF.txt" ((show len) ++ " " ++ (show $ diffUTCTime end start) ++ "\n")
            
    start <- getCurrentTime
    let !r3 = inSort m3
    end <- getCurrentTime
    if f == 0
        then do 
            putStr "inSort TImeF: "
            print $ diffUTCTime end start
            putStr "---------\n"
        else 
            appendFile "inSort_timesF.txt" ((show len) ++ " " ++ (show $ diffUTCTime end start) ++ "\n")

testR :: Int -> Int -> IO()
testR f len = do
    let m1 = [len - i + 1 | i <- [1..len]]
    let m2 = [len - i + 1 | i <- [1..len]]
    let m3 = [len - i + 1 | i <- [1..len]]

    start <- getCurrentTime
    let !r1 = qSort m1
    end <- getCurrentTime
    if f == 0
        then do 
            putStr "qSort TImeR: "
            print $ diffUTCTime end start
        else 
            appendFile "qSort_timesR.txt" ((show len) ++ " " ++ (show $ diffUTCTime end start) ++ "\n")
            
    start <- getCurrentTime
    let !r2 = bSort m2
    end <- getCurrentTime
    if f == 0
        then do 
            putStr "bSort TImeR: "
            print $ diffUTCTime end start
        else 
            appendFile "bSort_timesR.txt" ((show len) ++ " " ++ (show $ diffUTCTime end start) ++ "\n")
            
    start <- getCurrentTime
    let !r3 = inSort m3
    end <- getCurrentTime
    if f == 0
        then do 
            putStr "inSort TImeR: "
            print $ diffUTCTime end start
            putStr "---------\n"
        else 
            appendFile "inSort_timesR.txt" ((show len) ++ " " ++ (show $ diffUTCTime end start) ++ "\n")
            
test :: Int -> Int -> IO()
test f len = do
    let a = [3,5,7,11,13,17,23]
    let m1 = [mod i (a !! (mod i 7)) | i <- [571123..len+571123]]
    let m2 = [mod i (a !! (mod i 7)) | i <- [571123..len+571123]]
    let m3 = [mod i (a !! (mod i 7)) | i <- [571123..len+571123]]

    start <- getCurrentTime
    let !r1 = qSort m1
    end <- getCurrentTime
    if f == 0
        then do 
            putStr "qSort TIme: "
            print $ diffUTCTime end start
        else 
            appendFile "qSort_times.txt" ((show len) ++ " " ++ (show $ diffUTCTime end start) ++ "\n")
            
    start <- getCurrentTime
    let !r2 = bSort m2
    end <- getCurrentTime
    if f == 0
        then do 
            putStr "bSort TIme: "
            print $ diffUTCTime end start
        else 
            appendFile "bSort_times.txt" ((show len) ++ " " ++ (show $ diffUTCTime end start) ++ "\n")
            
    start <- getCurrentTime
    let !r3 = inSort m3
    end <- getCurrentTime
    if f == 0
        then do 
            putStr "inSort TIme: "
            print $ diffUTCTime end start
            putStr "---------\n"
        else 
            appendFile "inSort_times.txt" ((show len) ++ " " ++ (show $ diffUTCTime end start) ++ "\n")

-- output filter
f [x] = show x
f (x:xs) = show x ++ " " ++ f xs

main :: IO()
main = do
    hSetBuffering stdout NoBuffering

    args <- getArgs
    if length args == 2
        then do
            let len = read (args !! 1)::Int
            let f = read (args !! 0)::Int
            
            testF f len
            testR f len
            test f len
        else do
            putStr "Enter array: "
            lArr <- getLine
            
            let arr = map (\i -> (read i)::Int) (words lArr)
            
            putStr "qSort result: "
            putStr $ (f $ qSort arr) ++ "\n"
            
            putStr "bSort result: "
            putStr $ (f $ bSort arr) ++ "\n"
        
            putStr "inSort result: "
            putStr $ (f $ inSort arr) ++ "\n"
        
        
        
        
        
        
        
        
        