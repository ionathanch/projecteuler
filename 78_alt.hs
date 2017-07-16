import qualified Data.IntMap.Strict as M

type Map = M.IntMap Integer
type Sign = Integer

getOrFail :: Int -> Map -> Integer
getOrFail n m = M.findWithDefault undefined n m

pentNumsSign :: [(Int, Sign)]
pentNumsSign = map (\n -> ((3 * n * n - n) `div` 2, if (even ((abs n) - 1)) then 1 else -1)) $ concat $ map (\n -> [n, -n]) [1..]

partition :: Int -> Map -> Map
partition n m = 
    let part = sum $ map (\(p, sgn) -> sgn * (getOrFail (n-p) m)) $ takeWhile (\(p, sgn) -> p <= n) pentNumsSign
    in M.insert n part m

findPartition :: Int -> Map -> Int
findPartition n m =
    let newM = partition n m
        val  = getOrFail n newM
    in if val `mod` 1000000 == 0
       then n
       else findPartition (n+1) newM

main = print $ findPartition 1 $ M.fromList [(0, 1)]
