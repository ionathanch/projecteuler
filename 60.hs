import Data.List

upper = 10000

isPrime :: Integer -> Bool
isPrime x = null [k | k <- [2..x-1], k * k <= x, x `mod` k == 0]

primes = [x | x <- [2..upper], isPrime x]
    
isPrimeNew :: Integer -> Bool
isPrimeNew x
    | x <= upper = elem x primes
    | otherwise = isPrime x
    
order :: (Integer, Integer, Integer, Integer, Integer) -> (Integer, Integer, Integer, Integer, Integer) -> Ordering
order (a1, b1, c1, d1, e1) (a2, b2, c2, d2, e2) =
    compare (a1 + b1 + c1 + d1 + e1) (a2 + b2 + c2 + d2 + e2)
  
combosArePrime :: Integer -> Integer -> Integer -> Integer -> Integer -> Bool
combosArePrime a b c d e = 
    isPrimeNew (read (show a ++ show b)) && 
    isPrimeNew (read (show b ++ show a)) &&
    isPrimeNew (read (show a ++ show c)) && 
    isPrimeNew (read (show c ++ show a)) &&
    isPrimeNew (read (show b ++ show c)) && 
    isPrimeNew (read (show c ++ show b)) &&
    isPrimeNew (read (show a ++ show d)) &&
    isPrimeNew (read (show d ++ show a)) &&
    isPrimeNew (read (show b ++ show d)) &&
    isPrimeNew (read (show d ++ show b)) &&
    isPrimeNew (read (show c ++ show d)) &&
    isPrimeNew (read (show a ++ show e)) &&
    isPrimeNew (read (show e ++ show a)) &&
    isPrimeNew (read (show b ++ show e)) &&
    isPrimeNew (read (show e ++ show b)) &&
    isPrimeNew (read (show c ++ show e)) &&
    isPrimeNew (read (show d ++ show e)) &&
    isPrimeNew (read (show e ++ show e))

quints = sortBy order [(a, b, c, d, e) | a <- primes, b <- primes, c <- primes, d <- primes, e <- primes,
    a < b, b < c, c < d, d < e, combosArePrime a b c d e]
  
main = print primes
