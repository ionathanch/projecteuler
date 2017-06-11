prevRowMax :: [Integer] -> [Integer]
prevRowMax prevRow = zipWith max ([0] ++ prevRow) (prevRow ++ [0])

pathSums :: [[Integer]] -> [Integer]
pathSums rows = foldl1 (\a b -> zipWith (+) (prevRowMax a) b) rows

main = do file <- readFile "p067_triangle.txt"
          let rows = map (\row -> map read $ words row) $ lines file :: [[Integer]]
          print $ maximum $ pathSums rows
