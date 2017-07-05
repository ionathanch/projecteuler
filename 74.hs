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

sizeOfLoop :: Integer -> Integer
sizeOfLoop n 
    | n == 169 || n == 363601 || n == 1454 = 3
    | n == 871 || n == 45361 = 2
    | n == 872 || n == 45362 = 2
    | n == 145 || n == 1 || n == 2 = 1
    | otherwise = 0

sumOfFactorialOfDigits :: Integer -> Integer
sumOfFactorialOfDigits n = sum $ map (digitFactorial . fromIntegral . digitToInt) $ show n

getChainLength :: Integer -> Integer
getChainLength n = getChainLengthRec n 1

getChainLengthRec :: Integer -> Integer -> Integer
getChainLengthRec n length = 
    let next = sumOfFactorialOfDigits n
        nextLength = sizeOfLoop next
    in if nextLength == 0 
       then getChainLengthRec next (length + 1)
       else length + nextLength
       
numOfLoops :: Integer -> Integer -> Integer
numOfLoops bound length = foldr (\n num -> num + if getChainLength n == length then 1 else 0) 0 [3..bound]

main = print $ numOfLoops 1000000 60
