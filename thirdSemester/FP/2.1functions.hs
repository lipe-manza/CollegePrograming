main :: IO ()
main = do
  print(myMap (* 2) (myFilter (> 0) nums))
  print(foldr (+) 0 nums) -- ? 0 é o elemento neutro do foldr
  print(foldr (*) 1 nums) -- ? 1 é o elemento neutro do foldr


myLen :: (Num t) => [a] -> t
myLen [] = 0
myLen (x : xs) = 1 + myLen xs

mySum :: (Num t) => [t] -> t
mySum [] = 0
mySum (x : xs) = x + mySum xs

myProd :: (Num a) => [a] -> a
myProd [] = 1
myProd (x : xs) = x * mySum xs

myMap :: (t -> a) -> [t] -> [a]
myMap _ [] = []
myMap f (x : xs) = f x : myMap f xs

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter t (x : xs)
  | t x = x : myFilter t xs
  | otherwise = myFilter t xs

nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

-- ? /x -> x * 2 , representa uma funcao anonima