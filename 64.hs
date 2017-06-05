next :: (Integer, Integer, Integer) -> (Integer, Integer, Integer)
next (a, b, n) = let nextA = (n - b * b) `div` a
                     nextB = nextA * ceiling((sqrt (fromIntegral n) + fromIntegral b) / fromIntegral nextA - 1) - b
                 in (nextA, nextB, n)

hasOddPeriod :: Integer -> Bool
hasOddPeriod n = let sqrtn   = floor . sqrt . fromIntegral $ n
                     initial = (1, sqrtn, n)
                 in if sqrtn * sqrtn == n 
                    then False
                    else odd . (+1) . length $ takeWhile (initial /=) (tail $ iterate next initial)

numOfOddPeriods :: Integer -> Int
numOfOddPeriods n = length $ filter (== True) $ map hasOddPeriod [2..n]

main = print $ numOfOddPeriods 10000
