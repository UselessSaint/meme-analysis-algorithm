module Main where

import Data.Matrix
import Data.Vector

transp :: Matrix Int -> Matrix Int
transp mtr = fromLists [[getElem i j  mtr | i <- [1..m]] | j <- [1..n]]
                where n = Data.Vector.length $ getRow 1 mtr
                      m = Data.Vector.length $ getCol 1 mtr

                   
scalm :: Vector Int -> Vector Int -> Int 
scalm v1 v2 = if Data.Vector.length v1 == Data.Vector.length v2
                then Prelude.sum [(v1 !! i)*(v2 !! i) | i <- [0..(Data.Vector.length v1 - 1)]]
                else 0
{-
sumArr :: [Int] -> Int -> Int
sumArr [] n = n
sumArr arr n = sumArr (Prelude.tail arr) (n + Prelude.head arr) 
-}
test :: Vector Int -> Vector Int
test q = q

main :: IO()
main = do
    let mtr = fromLists [[1,2], [3,4]]
    
    let v1 = [1,2]
    let v2 = [1,2]
    
    -- print $ sum $ getRow 1 mtr
    print $ scalm getRow 1 mtr getRow 2 mtr