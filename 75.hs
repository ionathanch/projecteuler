import qualified Data.IntMap.Strict as M
import Debug.Trace

bound = 1500000

insertUpdate :: Int -> M.IntMap Int -> M.IntMap Int
insertUpdate k oldMap = 
    let v = M.findWithDefault 0 k oldMap
    in M.insert k (v+1) oldMap

populateMapM :: Int -> Int -> M.IntMap Int -> M.IntMap Int
populateMapM m n intMap =
    let p = 2 * m * (m + n)
        boundK = floor $ (fromIntegral bound)/(fromIntegral p)
        ks = [1..boundK]
    in foldr (\k accMap -> insertUpdate (p*k) accMap) intMap ks

populateMap :: Int -> M.IntMap Int -> M.IntMap Int
populateMap m intMap =
    let ns = [n | n <- [1..m-1], even (m*n), gcd m n == 1]
    in foldr (populateMapM m) intMap ns

singularTriples :: Int
singularTriples = 
    let boundM = floor . sqrt $ (fromIntegral bound) / 2
        finalMap = foldr populateMap M.empty [2..boundM]
    in M.size $ M.filter (== 1) finalMap

main = print $ singularTriples
