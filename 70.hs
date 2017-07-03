import Math.NumberTheory.Primes.Factorisation
import Data.List
import Data.Ratio
import Data.Numbers.Primes

-- 4000 chosen through trial and error (sorry)
-- sqrt(10000000) is a bit more than 2000 so I tried using 1000 increments from 2000 onwards until the pair stopped changing
-- for 2000: (2239261, 2236192)
-- for 3000: (7026037, 7020736)
-- for 4000: (8319823, 8313928)
-- for 5000: ditto
primePairs :: Integer -> [(Integer, Integer)]
primePairs bound = [(x, y) | let bounded = takeWhile (< 4000) primes, x <- bounded, y <- bounded, x*y < bound]

totient :: (Integer, Integer) -> (Integer, Integer)
totient (p1, p2) = ((p1 * p2), ((p1-1) * (p2-1)))

arePermutations :: (Integer, Integer) -> Bool
arePermutations (n, t) = sort (show n) == sort (show t)

comparePairs :: (Integer, Integer) -> (Integer, Integer) -> Ordering
comparePairs (n1, t1) (n2, t2) = compare (n1 % t1) (n2 % t2)

minPermTote :: Integer -> (Integer, Integer)
minPermTote bound = minimumBy comparePairs $ filter arePermutations $ map totient $ primePairs bound

main = do print $ minPermTote 9999999
