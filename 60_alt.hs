import Data.List

upper = 10000

isPrime :: Int -> Bool
isPrime x = null [k | k <- [2..x-1], k * k <= x, x `mod` k == 0]

primes = [x | x <- [2..upper], isPrime x]
    
isPrimeNew :: Int -> Bool
isPrimeNew x
    | x <= upper = elem x primes
    | otherwise = isPrime x

isPrimePair :: Int -> Int -> Bool
isPrimePair a b = isPrime(read(show a ++ show b)) && isPrime(read(show b ++ show a))

primePairs = [(a, b) | a <- primes, b <- primes, a < b, isPrimePair a b]

main = print primePairs 
