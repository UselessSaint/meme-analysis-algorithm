module WinogradMultU3 where

    import Data.Matrix
    import Data.Vector
    
    wMultU3 :: (Num a) => Matrix a -> Matrix a -> Matrix a
    wMultU3 m1 m2 = 
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

            res = if odd n'
                then matrix n m' $ \(i,j) ->
                            (m1PreCalc !! (i-1)) + (m2PreCalc !! (j-1)) +  
                            Prelude.sum ( [ ((unsafeIndex v1 i) + (unsafeIndex v2 (i+1))) * ((unsafeIndex v1 (i+1) + (unsafeIndex v2 i))) | i <- [0, 3..n'-2] ] ) + 
                            getElem i n' m1 * getElem m j m2
                else matrix n m' $ \(i,j) ->
                            (m1PreCalc !! (i-1)) + (m2PreCalc !! (j-1)) +  
                            Prelude.sum ( [ ((unsafeIndex v1 i) + (unsafeIndex v2 (i+1))) * ((unsafeIndex v1 (i+1) + (unsafeIndex v2 i))) | i <- [0, 3..n'-2] ] )
                    where 
                        sub = \v1 v2 np' -> Prelude.sum ( [ ((unsafeIndex v1 i) + (unsafeIndex v2 (i+1))) * ((unsafeIndex v1 (i+1) + (unsafeIndex v2 i))) | i <- [0, 3..n'-2] ] )

    {-
    wMultU3' :: (Num a) => Vector a -> Int -> Vector a -> Int -> a
    wMultU3' v1 n v2 m = 
        if n == m
            then res
            else error "Oh no, smth goes wrong"
        where
            n' = if even n then n else n-1
    
            res = Prelude.sum ( [ ((unsafeIndex v1 i) + (unsafeIndex v2 (i+1))) * ((unsafeIndex v1 (i+1) + (unsafeIndex v2 i))) | i <- [0, 3..n'-2] ] )-}