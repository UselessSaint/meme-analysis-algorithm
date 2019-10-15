module UsualMultLib where

import Data.Matrix
import Data.Vector as V

scalm' :: (Num a) => Vector a -> Vector a -> a
scalm' v1 v2 = 
        if V.length v1 == V.length v2
            then Prelude.sum( [(unsafeIndex v1 i)*(unsafeIndex v2 i) | i <- [0..(V.length v1)-1]] )
            else error "Mtr.size.Error"

uMultLib :: (Num a) => Matrix a -> Matrix a -> Matrix a
uMultLib m1 m2 = do
    if n' == m
        then fromLists [[scalm' (getRow i m1) (getCol j m2) | j <- [1..m]] | i <- [1..n']]
        else error "Mtr.size.Error"
            where 
                n = ncols m1
                m = nrows m2

                n' = nrows m1
                m' = ncols m2

