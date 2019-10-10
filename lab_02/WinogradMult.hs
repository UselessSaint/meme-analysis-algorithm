module WinogradMult where

import Data.Matrix
import Data.Vector

wMult :: (Num a) => Matrix a -> Matrix a -> Matrix a
wMult m1 m2 = 
    if m == n'
        then res 
        else error "Mtr.Size.Error"
    where
        n = nrows m1
        n' = ncols m1
        m = nrows m2
        m' = ncols m2

        np' = if even n' then n' else n' - 1
        mp = if even m then m else m - 1

        m1PreCalc = [Prelude.sum ([-1*(getElem i j m1)*(getElem i (j+1) m1) | j <- [1, 3..np'-1]])
                         | i <- [1..n]]
        m2PreCalc = [Prelude.sum ([-1*(getElem j i m2)*(getElem (j+1) i m2) | j <- [1, 3..mp-1]])
                         | i <- [1..m']]

        res = matrix n m' $ \(i,j) ->
                (m1PreCalc !! (i-1)) + (m2PreCalc !! (j-1)) +  
                wMult' (getRow i m1) (getCol j m2) + 
                if odd n' then getElem i n' m1 * getElem m j m2 else 0

wMult' :: (Num a) => Vector a -> Vector a -> a
wMult' v1 v2 = 
    if n == m
        then res
        else error "Oh no, smth goes wrong"
    where
        n = Data.Vector.length v1
        m = Data.Vector.length v2

        n' = if even n then n else n-1

        res = Prelude.sum ( [ ((unsafeIndex v1 i) + (unsafeIndex v2 (i+1)))*
                              ((unsafeIndex v1 (i+1) + (unsafeIndex v2 i))) | i <- [0, 3..n'-2] ] )