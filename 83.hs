import Data.List.Split
import Data.Matrix
import Data.Maybe
import Data.Foldable

type Value = Integer
data IsVisited = Visited | Unvisited deriving (Eq, Show)
type Position = (Int, Int)
data Element = Element Value IsVisited Position deriving (Eq, Show)

instance Monoid Element where
    mempty = Element 0 Visited (0, 0)
    e `mappend` Element _ Unvisited _ = e
    Element _ Unvisited _ `mappend` e = e
    Element v1 Visited p1 `mappend` Element v2 Visited p2 =
        case getMin v1 v2 of 
            0  -> mempty
            v1 -> Element v1 Visited p1
            v2 -> Element v2 Visited p2

getMin :: Value -> Value -> Value
getMin v1 0  = v1
getMin 0  v2 = v2
getMin v1 v2 = min v1 v2

getUnvisitedNeighbours :: Matrix Element -> Element -> [Element]
getUnvisitedNeighbours m (Element _ _ (i, j)) =
    filter (\(Element _ isVisited _) -> isVisited == Visited)
        (catMaybes [safeGet (i - 1) j      m
                   ,safeGet (i + 1) j      m
                   ,safeGet  i     (j - 1) m
                   ,safeGet  i     (j + 1) m])

getNeighbourDistances :: Element -> [Element] -> [Element]
getNeighbourDistances e = map (addValue e)
    where addValue (Element ve isVisited _) (Element vn _ p) = Element (ve + vn) isVisited p

dijkstraMatrix :: Matrix Element -> Element
dijkstraMatrix m = 
    let neighbourDistanceMatrix = fmap (\e -> getNeighbourDistances e (getUnvisitedNeighbours m e)) m
    in fold (fmap fold neighbourDistanceMatrix)
    -- for unvisited element in matrix
        -- for unvisited neighbour of element
            -- if element value + neighbour value < min then set as min
    -- return min; default is (0, (0, 0))

nextMatrix :: Matrix Element -> Matrix Element
nextMatrix m =
    let Element minValue _ position = dijkstraMatrix m
        maybeMatrix = safeSet (Element minValue Visited position) position m
    in case maybeMatrix of 
        Just next -> next
        Nothing -> m

initElement :: Matrix Integer -> Position -> Element
initElement m p =
    let value = m ! p
    in Element value Unvisited p

toElementMatrix :: Matrix Integer -> Matrix Element
toElementMatrix m =
    matrix (nrows m) (ncols m) (initElement m)

main :: IO ()
main = do
    contents <- readFile "p081_matrix.txt"
    let listsMatrix = map (map read . (splitOn ",")) $ lines contents :: [[Integer]]
        valueMatrix = fromLists listsMatrix
        mtrx = toElementMatrix valueMatrix
    print $ nextMatrix mtrx