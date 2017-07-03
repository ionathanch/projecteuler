import Math.NumberTheory.Primes.Factorisation
import Data.List

ratio :: Integer -> Double
ratio n = foldr (\(prime, _) acc -> let p = fromIntegral prime in p / (p - 1) * acc) 1.0 $ factorise n

answer :: Integer -> (Integer, Double)
answer n = let range  = [2, 4..n]
           in maximumBy (\(i1, r1) (i2, r2) -> compare r1 r2) $ zip range $ map ratio range

main = print $ answer 1000000
