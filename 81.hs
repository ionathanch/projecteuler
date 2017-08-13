import Data.List.Split

getInitialLine :: [Integer] -> [Integer]
getInitialLine firstLine = tail $ scanl (+) 0 firstLine

getNextLine :: [Integer] -> [Integer] -> [Integer]
getNextLine prevLine currLine =
    tail $ scanl minSum (head prevLine) (zip prevLine currLine)
    where minSum currSum (up, left) = min (left + up) (left + currSum)

main :: IO ()
main = do 
    contents <- readFile "p081_matrix.txt"
    let fileLines = lines contents
        matrix = map (map read . (splitOn ",")) fileLines
        initialLine = getInitialLine $ head matrix
    print $ last $ foldl getNextLine initialLine $ tail matrix