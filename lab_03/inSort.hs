module InSort where

insert :: (Ord a) => a -> [a] -> [a]
insert x [] = [x]
insert x (y:ys) = if x < y 
                    then x:y:ys 
                    else y : insert x ys
                    
inSort :: (Ord a) => [a] -> [a]
inSort [x] = [x]
inSort (x:xs) = insert x (inSort xs)                 
