import Data.Char (digitToInt)

digitFactorial :: Integer -> Integer
digitFactorial n = case n of 
    0 -> 1
    1 -> 1
    2 -> 2
    3 -> 6
    4 -> 24
    5 -> 120
    6 -> 720
    7 -> 5040
    8 -> 40320
    9 -> 362880

loops :: Integer -> Maybe Integer
loops n 
    | n `elem` [169, 363601, 1454] = Just 3
    | n `elem` [871, 872, 45361, 45362] = Just 2
    | n `elem` [1, 2, 145, 40585] = Just 1
    | otherwise = Nothing

sumOfFactorialOfDigits :: Integer -> Integer
sumOfFactorialOfDigits n = sum $ map (digitFactorial . fromIntegral . digitToInt) $ show n

getChainLength :: Integer -> Integer
getChainLength n = getChainLengthRec n 1

getChainLengthRec :: Integer -> Integer -> Integer
getChainLengthRec n length = 
    let next = sumOfFactorialOfDigits n
    in case loops next of 
        Just x -> length + x
        Nothing -> getChainLengthRec next (length + 1)

numOfLoops :: Integer -> Integer -> Integer
numOfLoops bound length = foldr (\n num -> num + if getChainLength n == length then 1 else 0) 0 [3..bound]

main = print $ numOfLoops 1000000 60
