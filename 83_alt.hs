import Data.List.Split
import Data.Matrix
import Data.Maybe
import Data.Foldable
import Data.PQueue.Min

type Value = Integer
type Distance = Integer
type Position = (Int, Int)
data Element = Element {
    value :: Value,
    distance :: Maybe Distance,  -- Nothing represents infinity
    position :: Position
 } deriving (Eq, Show)
data PQE = PQE Element Distance deriving (Eq, Show)

instance Ord PQE where
    PQE _ Nothing <= _ = False
    _ <= PQE _ Nothing = True
    PQE _ (Just d1) <= PQE _ (Just d2) = d1 <= d2

getNeighbours :: Matrix Element -> Element -> [Element]
getNeighbours m e =
    let (i, j) = position e
    in  catMaybes [safeGet (i - 1) j      m,
                   safeGet (i + 1) j      m,
                   safeGet  i     (j - 1) m,
                   safeGet  i     (j + 1) m]    

dijkstra :: Position -> Matrix Element -> MinQueue PQE -> Distance
dijkstra p m q =
    let PQE minElement minDistance = findMin q
    in  if position minElement == p
        then minDistance
        else let (newM, newQ) = foldr update (m, q) $ getNeighbours m minElement
             in  dijkstra p newM newQ
        where update neighbour (prevM, prevQ) =
                let newDistance = minDistance + value neighbour
                in  case distance neighbour of
                    Nothing -> undefined
                    Just d  -> undefined

findShortestPathLength :: Matrix Element -> Distance
findShortestPathLength m =
    let initialElement = m ! (1, 1)
        initialMinQ = singleton $ PQE initialElement $ value initialElement
        lastPos = (nrows m, ncols m)
    in  dijkstra lastPos m initialMinQ


setInitial :: Matrix Element -> Matrix Element
setInitial m =
    let v = value $ m ! (1, 1)
    in unsafeSet (Element v (Just v) (1, 1)) (1, 1) m

initElement :: Matrix Integer -> Position -> Element
initElement m p =
    let value = m ! p
    in  Element value Nothing p

toElementMatrix :: Matrix Integer -> Matrix Element
toElementMatrix m =
    matrix (nrows m) (ncols m) (initElement m)

main :: IO ()
main = do
    contents <- readFile "p083_matrix.txt"
    let listsMatrix = fmap (fmap read . (splitOn ",")) $ lines contents :: [[Integer]]
        valueMatrix = fromLists listsMatrix
        unvisitedMatrix = toElementMatrix valueMatrix
        mtrx = setInitial unvisitedMatrix
    print $ findShortestPathLength mtrx