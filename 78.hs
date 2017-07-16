import qualified Data.IntMap.Strict as M

filterSum :: Int -> M.IntMap Int -> Int
filterSum n subMap = 
    let filterMap = M.filterWithKey (\k _ -> k <= n) subMap
    in M.foldr (+) 0 filterMap

getSubmap :: Int -> M.IntMap (M.IntMap Int) -> M.IntMap Int
getSubmap k numMap = M.findWithDefault undefined k numMap

insertSubmap :: Int -> M.IntMap (M.IntMap Int) -> M.IntMap (M.IntMap Int)
insertSubmap n numMap= 
    let getFilterSumInsert k subMap = M.insert k (filterSum k (getSubmap (n-k) numMap)) subMap
        subMap = foldr getFilterSumInsert M.empty [n, n-1..1]
    in M.insert n subMap numMap

addToList :: (M.IntMap (M.IntMap Int), (Int, Int)) -> Int -> (M.IntMap (M.IntMap Int), (Int, Int))
addToList (currMap, _) n = 
    let nextMap = insertSubmap n currMap
        nextVal = filterSum n $ getSubmap n $ nextMap
    in (nextMap, (n, nextVal))

createNummap :: [(M.IntMap (M.IntMap Int), (Int, Int))]
createNummap = 
    let initialMap = M.fromList [(0, M.fromList [(0, 1)])]
    in scanl addToList (initialMap, (1, 1)) [1..]

main = print $ 
    let (_, finalVal) = last $ takeWhile (\(_, (_, val)) -> val `mod` 1000000 /= 0) $ createNummap
    in finalVal
