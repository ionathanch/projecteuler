import qualified Data.IntMap.Strict as M

filterSum :: Int -> M.IntMap Int -> Int
filterSum n subMap = 
    let filterMap = M.filterWithKey (\k _ -> k <= n) subMap
    in M.foldr (+) 0 filterMap

getSubmap :: Int -> M.IntMap (M.IntMap Int) -> M.IntMap Int
getSubmap k numMap = M.findWithDefault undefined k numMap

insertSubmap :: Int -> M.IntMap (M.IntMap Int) -> M.IntMap (M.IntMap Int)
insertSubmap n numMap = 
    let getFilterSumInsert k subMap = M.insert k (filterSum k (getSubmap (n-k) numMap)) subMap
        subMap = foldr getFilterSumInsert M.empty [n, n-1..1]
    in M.insert n subMap numMap

createNummap :: Int -> M.IntMap (M.IntMap Int)
createNummap bound = 
    let initialMap = M.fromList [(0, M.fromList [(0, 1)])]
    in foldr insertSubmap initialMap [bound, bound-1..1]

main = print $ 
    let bound = 100
        ways = filterSum bound $ M.findWithDefault undefined bound $ createNummap bound
    in ways - 1
