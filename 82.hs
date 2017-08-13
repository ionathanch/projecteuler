import Data.List.Split
import Data.List
import Data.Maybe

getRightMin :: [Integer] -> [Integer] -> Maybe Integer
getRightMin prevRight currRight =
    case currRight of
        [] -> Nothing
        _ -> Just $ minimum $ zipWith (+) prevRight $ tail $ scanl (+) 0 currRight

getLeftMin :: [Integer] -> [Integer] -> Maybe Integer
getLeftMin prevLeft currLeft = getRightMin (reverse prevLeft) (reverse currLeft)

type Acc = ([Integer], [Integer], [Integer], [Integer])
type PrevCurr = (Integer, Integer)

getMin :: Acc -> PrevCurr -> Integer
getMin (prevLeft, currLeft, prevRight, currRight) (prev, curr) = 
    curr + (minimum $ catMaybes [getLeftMin prevLeft currLeft, Just prev, getRightMin prevRight currRight])

shift :: Acc -> PrevCurr -> Acc
shift (prevLeft, currLeft, prevRight, currRight) (prev, curr) =
    (prevLeft ++ [prev], currLeft ++ [curr], tail prevRight, tail currRight)

getNextLine :: [Integer] -> [Integer] -> [Integer]
getNextLine prevLine currLine =
    let initPrevLeft = []
        initCurrLeft = []
        initPrevRight = tail prevLine
        initCurrRight = tail currLine
        next acc prevCurr = (shift acc prevCurr, getMin acc prevCurr)
    in snd $ mapAccumL next (initPrevLeft, initCurrLeft, initPrevRight, initCurrRight) $ zip prevLine currLine 

main :: IO ()
main = do 
    contents <- readFile "p081_matrix.txt"
    let fileLines = lines contents
        upDownMatrix = map (map read . (splitOn ",")) fileLines
        matrix = transpose upDownMatrix
    print $ minimum $ foldl getNextLine (head matrix) (tail matrix)