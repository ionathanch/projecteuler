import Data.Ratio

closer :: Rational -> Rational -> Rational
closer curr prev = let goal = (3 % 7) in if curr < goal && (goal - curr) < (goal - prev) then curr else prev

closest :: Integer -> Rational
closest bound = foldr closer 0 $ map (\d -> let n = floor (d * 3 % 7) in (n % d)) [8..bound]

main = print $ closest 1000000
