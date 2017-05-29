tri = [round $ n * (n + 1) / 2      | n <- [45..140]] 
sqr = [round $ n * n                | n <- [32..100]]
pnt = [round $ n * (3 * n - 1) / 2  | n <- [26..81]]
hex = [round $ n * (2 * n - 1)      | n <- [23..70]]
hep = [round $ n * (5 * n - 3) / 2  | n <- [21..63]]
oct = [round $ n * (3 * n - 2)      | n <- [19..58]]

tip :: Int -> String
tip n = take 2 $ show n

end :: Int -> String
end n = drop 2 $ show n 

isCyclic :: Int -> Int -> Bool
isCyclic x y = end x == tip y

poly = [tri, sqr, pnt, hex, hep]
cyclics = [(a, b, c, d, e, f) | a <- oct,
                                i <- [0..4],
                                b <- poly !! i,
                                isCyclic a b,
                                
                                j <- [0..4],
                                j /= i,
                                c <- poly !! j,
                                isCyclic b c,

                                k <- [0..4],
                                all (k /=) [i, j],
                                d <- poly !! k,
                                isCyclic c d,

                                l <- [0..4],
                                all (l /=) [i, j, k],
                                e <- poly !! l,
                                isCyclic d e,

                                m <- [0..4],
                                all (m /=) [i, j, k, l],
                                f <- poly !! m,
                                isCyclic e f,
                                isCyclic f a]

main = do print $ head cyclics 
          print $ let (a, b, c, d, e, f) = head cyclics
                  in a + b + c + d + e + f
