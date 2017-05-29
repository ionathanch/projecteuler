import Data.List

cubes = [n * n * n | n <- [4142..9999]]

arePermutations :: Integer -> Integer -> Bool
arePermutations a b = null (aStr \\ bStr) && null (bStr \\ aStr)
    where aStr = show a
          bStr = show b

permutes = [(a, b, c, d, e) | a <- cubes,
                              b <- cubes,
                              a < b,
                              arePermutations a b,

                              c <- cubes,
                              b < c,
                              arePermutations b c,
                                  
                              d <- cubes,
                              c < d,
                              arePermutations c d,
                              
                              e <- cubes,
                              d < e,
                              arePermutations d e]

main = print $ head permutes 
