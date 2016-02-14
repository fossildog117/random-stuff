{-# LANGUAGE OverloadedStrings #-}

import Data.List (unfoldr)
import Network.HTTP.Base
import Network.HTTP.Headers
import qualified Data.ByteString as S
import Network.HTTP

insert :: Int -> [Int] -> [Int]
insert x [] = [x]
insert x (y:ys) = if x < y 
                  then x:y:ys
                  else y : insert x ys

iSort :: [Int] -> [Int]
iSort [x] = [x]
iSort (x:xs) = insert x (iSort xs)

--insert :: Int -> [Int] -> [Int]
--insert x [] = [x]
--insert x (y:ys) = if x < y 
--                 then x:y:ys 
--         else y : insert x ys

--insertionSort :: [Int] -> [Int]
--insertionSort [x] = [x]
--insertionSort (x:xs) = insert x (insertionSort xs)

quicksort :: (Ord a) => [a] -> [a] 
quicksort [] = []
quicksort (x:xs) =
    let smallerOrEqual = [a | a <- xs, a <= x]
        largerThan = [a | a <- xs, a > x]
    in quicksort smallerOrEqual ++ [x] ++ quicksort largerThan

splitAt' :: Int -> [a] -> ([a], [a])
splitAt' 0 xs     = ([], xs)
splitAt' _ []     = ([], [])
splitAt' n (x:xs) = (x:xs', xs'')
  where
    (xs', xs'') = splitAt (n - 1) xs

invertCombine :: ([a], [a]) -> [a]
invertCombine (a,b) = b ++ a

rotor :: Int -> [a] -> [a]
rotor n x = invertCombine(splitAt' n x)

-- Non HTTPS

-- 1. Perform a basic HTTP get request and return the body
get :: String -> IO String
get url = simpleHTTP (getRequest url) >>= getResponseBody

-- 2. Get the response code
--getCode :: String -> IO ResponseCode
--getCode url = simpleHTTP req >>= getResponseCode
--    where req = getRequest urlx

abacusPasswordGeneratorOne :: Int -> [[Char]]
abacusPasswordGeneratorOne n = zipWith (++) (replicate n "Abacus000") (map show [0..n])

abacusPasswordGeneratorTwo :: Int -> [[Char]]
abacusPasswordGeneratorTwo n = zipWith (++) (replicate n "Abacus00") (map show [10..n])

abacusPasswordGeneratorThree :: Int -> [[Char]]
abacusPasswordGeneratorThree n = zipWith (++) (replicate n "Abacus0") (map show [100..n])

abacusPasswordGeneratorFour :: Int -> [[Char]]
abacusPasswordGeneratorFour n = zipWith (++) (replicate n "Abacus") (map show [1000..n])

trueList :: Int -> [Bool] -> IO ()
trueList n a = if a == take n (repeat True)
               then print "True"
               else print "False"

evenList :: Integral a => [a] -> IO ()
evenList x = if sum(map(`rem` 2) x ) == 0 
             then print "All elements are even"
             else print "There are one or more elements that are not even"
        
inRange :: (Enum a, Num a) => [a]
inRange x y = drop (x - 1) [1..y]

countPositive :: (Num a, Num a1, Ord a1) => a1 -> a
countPositive x = sum([if x < 0 then 0 else 1 | x <- x ])

--newLength :: Num b => b
--newLength x = foldl (+) 0(map (+1) (map (0*) [2,1,1]))

main = do 
	putStrLn "Hello bless up"
	name <- getLine
	putStrLn $ "Hey my name is " ++ name ++ "."
