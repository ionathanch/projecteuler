import Math.NumberTheory.Primes.Factorisation

totient :: Integer -> Integer
totient n = foldr (\(p, _) acc -> acc * (p-1) `div` p) n $ factorise n

main = print $ sum $ map totient [2..1000000]
