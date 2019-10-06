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

    let m = [[12 | i <- [1..len]] | j <- [1..len]]

    let m1 = fromLists [[12 | i <- [1..len]] | j <- [1..len]]

    let mtr = [[1,2],[3,4]]
    let mtrl = fromLists mtr

    -- Winograd
    start <- getCurrentTime
    evaluate $ wMult m1 m1
    end <- getCurrentTime

    -- putStr "  WTime: "
    -- print $ diffUTCTime end start
    
    appendFile "wMult_times.txt" ((show len) P.++ " " P.++ (show $ diffUTCTime end start) P.++ "\n")

{--}   
{- 
    -- WinogradU1
    start <- getCurrentTime
    evaluate $ wMultU1 m1 m1
    end <- getCurrentTime

    putStr "WU1Time: "
    print $ diffUTCTime end start 

    print $ show $ diffUTCTime end start 


    -- Usual
    start <- getCurrentTime
    print $  fromLists $ mult mtr mtr
    end <- getCurrentTime

    putStr "UTime: "
    print $ diffUTCTime end start 

    -- Default
    start <- getCurrentTime
    print $  multStrassenMixed mtrl mtrl
    end <- getCurrentTime

    putStr "DTime: "
    print $ diffUTCTime end start 
-}

    