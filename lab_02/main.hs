module Main where

import Data.Matrix
import Data.Vector

import UsualMult
import WinogradMult
import WinogradMultU1
import WinogradMultU2
import WinogradMultU3

import Control.Exception
import Data.Time.Clock
import System.Environment
import Prelude as P

main :: IO()
main = do
    args <- getArgs
    let len = if P.length args > 0
                then
                    read numb::Int
                else 1000
                where
                    numb = args !! 0

    let m1 = fromLists [[2 | i <- [1..len]] | j <- [1..len]]
    let m2 = fromLists [[2 | i <- [1..len]] | j <- [1..len]]
    let m3 = fromLists [[2 | i <- [1..len]] | j <- [1..len]]
    let m4 = [[2 | i <- [1..len]] | j <- [1..len]]
    let m5 = fromLists [[2 | i <- [1..len]] | j <- [1..len]]

   -- Winograd
    start <- getCurrentTime
    evaluate $ wMult m1 m1
    end <- getCurrentTime

    --putStr "  WTime: "
    --print $ diffUTCTime end start
    
    appendFile "wMult_times.txt" ((show len) P.++ " " P.++ (show $ diffUTCTime end start) P.++ "\n")

   -- WinogradU1
    start <- getCurrentTime
    evaluate $ wMultU1 m2 m2
    end <- getCurrentTime

    --putStr "WU1Time: "
    --print $ diffUTCTime end start 

    appendFile "wMultU1_times.txt" ((show len) P.++ " " P.++ (show $ diffUTCTime end start) P.++ "\n")

   -- WinogradU2
    start <- getCurrentTime
    evaluate $ wMultU2 m3 m3
    end <- getCurrentTime

    --putStr "WU2Time: "
    --print $ diffUTCTime end start 

    appendFile "wMultU2_times.txt" ((show len) P.++ " " P.++ (show $ diffUTCTime end start) P.++ "\n")
    
   -- WinogradU3
    start <- getCurrentTime
    evaluate $ wMultU3 m5 m5
    end <- getCurrentTime

    --putStr "WU3Time: "
    --print $ diffUTCTime end start 

    appendFile "wMultU3_times.txt" ((show len) P.++ " " P.++ (show $ diffUTCTime end start) P.++ "\n")

   -- Usual
    start <- getCurrentTime
    evaluate $ uMult m4 m4
    end <- getCurrentTime

    -- putStr "UTime: "
    -- print $ diffUTCTime end start 
    
    appendFile "uMult_times.txt" ((show len) P.++ " " P.++ (show $ diffUTCTime end start) P.++ "\n")
    
    
    
    