import Data.Char (digitToInt)
import qualified Data.Map as Map

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

type ChainMap = Map.Map Integer Integer
initialMap :: ChainMap
initialMap = Map.fromList [(169, 3), (363601, 3), (1454, 3),
                           (871, 2), (872, 2), (45361, 2), (45362, 2),
                           (1, 1), (2, 1), (145, 1)]

sumOfFactorialOfDigits :: Integer -> Integer
sumOfFactorialOfDigits n = sum $ map (digitFactorial . fromIntegral . digitToInt) $ show n

getChainLength :: Integer -> ChainMap -> (Integer, ChainMap)
getChainLength n chainMap = case Map.lookup n chainMap of 
    Just length -> (length, chainMap)
    Nothing     -> let next = sumOfFactorialOfDigits n
                       (nextLength, nextChainMap) = getChainLength next chainMap
                       length = nextLength + 1
                   in (length, Map.insert n length nextChainMap)

numOfLoops :: Integer -> Integer -> (Integer, ChainMap)
numOfLoops bound length = foldr (\n (num, oldMap) -> let (chainLength, newMap) = getChainLength n oldMap
                                                     in (num + if chainLength == length then 1 else 0, newMap)) (0, initialMap) [3..bound]

main = print $ let (length, sizeMap) = numOfLoops 10000 60
               in length
