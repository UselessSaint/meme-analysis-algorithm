module WinogradMultU3 where
    
transpW :: Num a => [[a]] -> [[a]]
transpW mtr = [[(mtr !! i) !! j | i <- [0..m-1]] | j <- [0..n-1]]
                where                 
                    n = Prelude.length $ mtr !! 0
                    m = Prelude.length $ mtr
    
wMultU3 :: (Num a) => [[a]] -> [[a]] -> [[a]]
wMultU3 m1 m2 = 
    if m == n'
        then res 
        else error "Mtr.Size.Error"
    where
        n = length m1
        n' = length (m1 !! 0)

        tm2 = transpW m2
    
        m = length tm2
        m' = length (tm2 !! 0)
    
        np' = if even n' then n' else n' - 1
        mp' = if even m' then m' else m' - 1
    
        m1PreCalc = [Prelude.sum ([-1*((m1 !! i) !! j)*((m1 !! i) !! (j+1)) | j <- [0, 2..np'-2]]) | i <- [0..n-1]]
        m2PreCalc = [Prelude.sum ([-1*((tm2 !! i) !! j)*((tm2 !! (i)) !! (j+1)) | j <- [0, 2..mp'-2]]) | i <- [0..m-1]]

        res = if even n'
            then [[ (m1PreCalc !! (i)) + (m2PreCalc !! (j)) + wMultU3' (m1 !! i) (tm2 !! j) | j <- [0..n-1] ] | i <- [0..m'-1] ]
            else [[ (m1PreCalc !! (i)) + (m2PreCalc !! (j)) + wMultU3' (m1 !! i) (tm2 !! j) + 
                       ((m1 !! i) !! (n'-1)) * ((tm2 !! j) !! (m-1)) | j <- [0..n-1] ] | i <- [0..m'-1] ]
    
wMultU3' :: (Num a) => [a] -> [a] -> a
wMultU3' v1 v2 = 
    if n == m
        then res
        else error "Oh no, smth goes wrong"
    where
        n = length v1
        m = length v2
    
        n' = if even n then n else n-1
    
        res = Prelude.sum ( [ ((v1 !! i) + (v2 !! (i+1)))*
                              ((v1 !! (i+1) + (v2 !! i))) | i <- [0, 2..n'-2] ] )