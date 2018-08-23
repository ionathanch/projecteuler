import Data.List.Split
import Data.Matrix
import Data.Maybe
import Data.Foldable
import Data.PQueue.Min

type Value    = Integer
type Distance = Integer
type Position = (Int, Int)
data MElement = MElement {
    value :: Value,
    visited :: Bool
} deriving (Eq, Show)
data QElement = QElement {
    distance :: Distance,
    position :: (Int, Int)
} deriving (Eq, Show)

instance Ord QElement where
    QElement d1 p1 <= QElement d2 p2 = d1 <= d2

markVisited :: Position -> Matrix MElement -> Matrix MElement
markVisited pos m =
    let MElement value _ = m ! pos
    in  unsafeSet (MElement value True) pos m

getNeighbour :: Matrix MElement -> Distance -> Position -> Maybe QElement
getNeighbour m dist pos@(i, j) = do
    MElement val vis <- safeGet i j m
    if vis then Nothing
    else return $ QElement (dist + val) pos

getNeighbours :: Matrix MElement -> QElement -> [QElement]
getNeighbours m (QElement dist (i, j)) =
    catMaybes [getNeighbour m dist ((i - 1), j),
               getNeighbour m dist ((i + 1), j),
               getNeighbour m dist (i, (j - 1)),
               getNeighbour m dist (i, (j + 1))]

dijkstra :: Position -> Matrix MElement -> MinQueue QElement -> Distance
dijkstra p m q =
    let (minElement@(QElement dist pos), newQ) = deleteFindMin q
        neighbours = getNeighbours m minElement
    in  if pos == p then dist
        else dijkstra p (foldr update m neighbours) (foldr insert newQ neighbours)
        where update (QElement _ pos) = markVisited pos

findShortestPathLength :: Matrix MElement -> Distance
findShortestPathLength m =
    let MElement value _ = m ! (1, 1)
        initialMinQ = singleton $ QElement value (1, 1)
        lastPos = (nrows m, ncols m)
    in  dijkstra lastPos m initialMinQ

setInitial :: Matrix MElement -> Matrix MElement
setInitial m =
    let MElement v _ = m ! (1, 1)
    in  unsafeSet (MElement v True) (1, 1) m

initElement :: Matrix Integer -> Position -> MElement
initElement m p =
    let value = m ! p
    in  MElement value False

toElementMatrix :: Matrix Integer -> Matrix MElement
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