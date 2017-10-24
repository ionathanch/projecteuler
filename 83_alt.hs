import Data.List.Split
import Data.Matrix
import Data.Maybe
import Data.Foldable
import Data.PQueue.Min

type Value = Integer
type Distance = Maybe Integer  -- Nothing represents infinity
type Position = (Int, Int)
data Element = Element {
    value :: Value,
    distance :: Distance,
    position :: Position
 } deriving (Eq, Show)
data PQE = PQE Element Distance deriving (Eq, Show)

instance Ord PQE where
    PQE _ Nothing <= _ = False
    _ <= PQE _ Nothing = True
    PQE _ (Just d1) <= PQE _ (Just d2) = d1 <= d2

dijkstra :: Matrix Element -> MinQueue PQE -> Position -> Distance
dijkstra m q p =
    let PQE minElement minDistance = findMin q
    in  if position minElement == p
        then distance minElement
        else undefined --TODO


findShortestPathLength :: Matrix Element -> Distance
findShortestPathLength m =
    let initialElement = m ! (1, 1)
        initialMinQ = singleton $ PQE initialElement $ distance initialElement
        lastPos = (nrows m, ncols m)
    in  dijkstra m initialMinQ lastPos


setInitial :: Matrix Element -> Matrix Element
setInitial m =
    let v = value $ m ! (1, 1)
        maybeMatrix = safeSet (Element v (Just v) (1, 1)) (1, 1) m
    in  case maybeMatrix of 
        Just mm -> mm 
        Nothing -> m

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