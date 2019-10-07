module Main where

import Data.Matrix
import Data.Vector

import UsualMult
import WinogradMult
import WinogradMultU1

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

    let m = [[2 | i <- [1..len]] | j <- [1..len]]
    let m1 = fromLists [[2 | i <- [1..len]] | j <- [1..len]]
    let m2 = fromLists [[2 | i <- [1..len]] | j <- [1..len]]
    let m4 = [[2 | i <- [1..len]] | j <- [1..len]]
    
    let mtr1 = [[1,2,3],[1,2,3],[1,2,3]]
    let mtr = [[1,2],[3,4]]
    
    --print $ fromLists $ wMultU1 mtr mtr
    --print $ fromLists $ mult mtr mtr
    
   -- Winograd
    start <- getCurrentTime
    evaluate $ wMult m1 m1
    end <- getCurrentTime

    -- putStr "  WTime: "
    -- print $ diffUTCTime end start
    
    appendFile "wMult_times.txt" ((show len) P.++ " " P.++ (show $ diffUTCTime end start) P.++ "\n")

   -- WinogradU1
    start <- getCurrentTime
    evaluate $ wMultU1 m4 m4
    end <- getCurrentTime

    -- putStr "WU1Time: "
    -- print $ diffUTCTime end start 

    appendFile "wMultU1_times.txt" ((show len) P.++ " " P.++ (show $ diffUTCTime end start) P.++ "\n")

   -- Usual
    start <- getCurrentTime
    evaluate $ mult m m
    end <- getCurrentTime

    -- putStr "UTime: "
    -- print $ diffUTCTime end start 
    
    appendFile "uMult_times.txt" ((show len) P.++ " " P.++ (show $ diffUTCTime end start) P.++ "\n")
    
    