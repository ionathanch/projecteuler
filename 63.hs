digits :: Integer -> Integer
digits n = 1 + (floor . logBase 10 . fromIntegral $ n)

powerDigits :: Integer -> Integer -> Bool
powerDigits n p = digits (n ^ p) == p

powers = takeWhile (powerDigits 9) [1..]

count = sum $ map (\n -> sum $ map (\p -> if powerDigits n p then 1 else 0) powers) [1..9]

main = do print count
