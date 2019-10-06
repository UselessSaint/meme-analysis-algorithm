module UsualMult where

transp :: Num a => [[a]] -> [[a]]
transp mtr = [[(mtr !! i) !! j | i <- [0..m-1]] | j <- [0..n-1]]
                where                 
                    n = Prelude.length $ mtr !! 0
                    m = Prelude.length $ mtr

                   
scalm :: Num a => [a] -> [a] -> a 
scalm v1 v2 = if Prelude.length v1 == Prelude.length v2
                then sum $ zipWith (*) v1 v2
                else error "Mtr.size.Error"

mult :: Num a => [[a]] -> [[a]] -> [[a]]
mult m1 m2 = 
    if n == m
        then [[scalm (m1 !! i) (tm2 !! j) | j <- [0..n-1]] | i <- [0..m-1]]
        else error "Mtr.size.Error"
            where 
                tm2 = transp m2
                n = Prelude.length $ m1 !! 0
                m = Prelude.length $ tm2 !! 0
