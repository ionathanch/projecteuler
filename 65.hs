seqOfE = (foldr (++) [] (map (\n -> [1, n, 1]) [64, 62..2])) ++ [2]

next n (a, b) = (b + n * a, a)

convergent tup seq = case seq of [] -> tup
                                 (n:ns) -> convergent (next n tup) ns

sumOfNumeratorDigits (n, _) = foldr (\c acc -> acc + read [c] :: Integer) 0 (show n)

main = print $ sumOfNumeratorDigits (convergent (68, 67) seqOfE)
