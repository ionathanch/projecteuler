import Data.List

nextX :: (Integer, Integer, Integer, Integer, Integer) ->
         (Integer, Integer, Integer, Integer, Integer) ->
         Integer -> Integer
nextX (n'', d'', c'', a'', b'')
      (n' , d' , c' , a' , b' )
      q = if n * n - q * d * d == 1 
          then n
          else nextX (n', d', c', a', b') (n, d, c, a, b) q
          where a = (q - b' * b') `div` a'
                c = ceiling((sqrt (fromIntegral q) + fromIntegral b') / fromIntegral a - 1)
                b = a * c - b'
                d = c * d' + d''
                n = c * n' + n''


minX :: Integer -> Integer
minX q = let sqrtQ = floor . sqrt . fromIntegral $ q
         in if sqrtQ * sqrtQ == q
            then 0
            else nextX (1, 0, 0, 0, 0) (sqrtQ, 1, sqrtQ, 1, sqrtQ) q

main = print $ let mapping = map minX [1..1000]
                   max     = maximum mapping
               in  fmap (+1) $ elemIndex max mapping
