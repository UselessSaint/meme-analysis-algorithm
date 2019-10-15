module Main where

import Data.Matrix
import Data.Vector

import UsualMult
import UsualMultLib
import WinogradMult
import WinogradMultU1
import WinogradMultU2
import WinogradMultU3

import Control.Exception
import Control.DeepSeq as D
import Data.Time.Clock
import System.IO
import System.Environment
import Prelude as P

test :: Int -> IO()
test len = do
    let m1m = fromLists [[1 | i <- [1..len]] | j <- [1..len]]
    let m2m = fromLists [[1 | i <- [1..len]] | j <- [1..len]]
    let m3m = fromLists [[1 | i <- [1..len]] | j <- [1..len]]
    let m4 = [[1 | i <- [1..len]] | j <- [1..len]]
    let m5m = fromLists [[1 | i <- [1..len]] | j <- [1..len]]
    let m6 = [[1 | i <- [1..len]] | j <- [1..len]]

    let qq = fromLists [[]]
{-
   -- Winograd
    start <- getCurrentTime
    let r1 = wMult m1m m1m
    evaluate $ getElem len len r1
    end <- getCurrentTime
 
    --putStr "  WTime: "
    --print $ diffUTCTime end start
    
    appendFile "wMult_times.txt" ((show len) P.++ " " P.++ (show $ diffUTCTime end start) P.++ "\n")

   -- WinogradU1
    start <- getCurrentTime
    let r2 = wMultU1 m2m m2m
    evaluate $ getElem len len r2
    end <- getCurrentTime

    --putStr "WU1Time: "
    --print $ diffUTCTime end start 

    appendFile "wMultU1_times.txt" ((show len) P.++ " " P.++ (show $ diffUTCTime end start) P.++ "\n")-}

   -- WinogradU2
    start <- getCurrentTime
    let r3 =  wMultU2 m3m m3m
    evaluate $ getElem len len r3
    end <- getCurrentTime

    --putStr "WU2Time: "
    --print $ diffUTCTime end start 

    appendFile "wMultU2_times.txt" ((show len) P.++ " " P.++ (show $ diffUTCTime end start) P.++ "\n")
{-
    -- WinogradU3
    start <- getCurrentTime
    let r4 =  wMultU3 m6 m6
    evaluate $ ((r4 !! (len-1)) !! (len-1))
    end <- getCurrentTime
   
    --putStr "WU3Time: "
    --print $ diffUTCTime end start 
   
    appendFile "wMultU3_times.txt" ((show len) P.++ " " P.++ (show $ diffUTCTime end start) P.++ "\n")

   -- Usual
    start <- getCurrentTime
    let r5 = uMult m4 m4
    evaluate $ ((r5 !! (len-1)) !! (len-1))
    end <- getCurrentTime

    --putStr "  UTime: "
    --print $ diffUTCTime end start
    
    appendFile "uMult_times.txt" ((show len) P.++ " " P.++ (show $ diffUTCTime end start) P.++ "\n")

   -- UsualLib
    start <- getCurrentTime
    let r6 = uMultLib m5m m5m
    evaluate $ getElem len len r6
    end <- getCurrentTime

    --putStr "  UTime: "
    --print $ diffUTCTime end start
    
    appendFile "uMultLib_times.txt" ((show len) P.++ " " P.++ (show $ diffUTCTime end start) P.++ "\n")-}

main :: IO()
main = do
    hSetBuffering stdout NoBuffering

    args <- getArgs
    if P.length args > 0
        then test (read (args !! 0)::Int)
        else do
            putStr "Enter mtr1 filename: "
            mtr1Filename <- getLine
            mtr1Source <- readFile mtr1Filename
            let mtr1 = P.map (\x ->  P.map (\i -> (read i) :: Int) $ words x) $ lines mtr1Source
           
            putStr "Enter mtr2 filename: "
            mtr2Filename <- getLine
            mtr2Source <- readFile mtr2Filename
            let mtr2 = P.map (\x ->  P.map (\i -> (read i) :: Int) $ words x) $ lines mtr2Source
            
            putStr "Mtr1 : \n"
            print $ fromLists mtr1
            putStr "Mtr2 : \n"
            print $ fromLists mtr2

            putStr "Usual Mult: \n"
            print $ fromLists $ uMult mtr1 mtr2

            putStr "Winograd Mult: \n"
            print $ wMult (fromLists mtr1) (fromLists mtr2)
            

                