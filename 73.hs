import Data.Ratio

numOfFrac bound = sum $ map (\d -> let nLower = ceiling (d % 3)
                                       nUpper = floor   (d % 2) 
                                   in length [n | n <- [nLower..nUpper], 
                                                  let ratio = (n % d), ratio > (1 % 3), ratio < (1 % 2), 
                                                  denominator ratio == d])
                        [2..bound]

main = print $ numOfFrac 12000
