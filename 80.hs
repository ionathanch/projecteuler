import Data.Foldable
import System.Environment

floorSqrt :: Integer -> Integer
floorSqrt n = floor $ sqrt $ fromIntegral n 

isPerfectSquare :: Integer -> Bool
isPerfectSquare n = 
    let floorSqrtN = floorSqrt n
    in floorSqrtN * floorSqrtN == n

data DigitState = DigitState Integer Integer Integer Integer deriving Show

instance Monoid DigitState where
    mempty = DigitState 0 0 0 0
    DigitState _ _ xa _ `mappend` DigitState _ _ xb _ = DigitState 0 0 (xa + xb) 0

getNewX :: Integer -> Integer -> Integer
getNewX c p = (fromIntegral $ length $ takeWhile (<= c) $ map (\x -> x * (20 * p + x)) [0..9]) - 1

getNewY :: Integer -> Integer -> Integer
getNewY p x = x * (20 * p + x)

getInitialState :: Integer -> DigitState
getInitialState c =
    let newX = getNewX c 0
        newY = newX * newX 
    in DigitState c 0 newX newY

nextState :: DigitState -> DigitState
nextState (DigitState c p x y) = 
    let newC = 100 * (c - y)
        newP = 10 * p + x
        newX = getNewX newC newP
        newY = getNewY newP newX
    in DigitState newC newP newX newY

sqrtDigitSum :: Int -> Integer -> Integer
sqrtDigitSum d n = 
    let initialState = getInitialState n
        stateList = initialState : map nextState stateList
        DigitState _ _ sum _ = fold $ take d stateList 
    in sum

sumSqrtDigitSums :: Integer -> Int -> Integer
sumSqrtDigitSums bound count = sum $ map (sqrtDigitSum count) $ filter (not . isPerfectSquare) [2..bound]

main = do 
    args <- getArgs
    print $ sumSqrtDigitSums 100 100 -- (read $ head args) (read $ last args)