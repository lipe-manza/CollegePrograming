import Data.ByteString (count)

main :: IO ()
main = do
  print "WH"
  print $ 5 +-+-* 7
  print $ (+-+-*) 5 7 -- tranform the function infix into prefix with ()
  print $ 8 `f2'` 5 -- transform the function prefix into infix with ``
  print $ 13 `mod` 5
  print $ pertence 3 [4, 6, 2, 6, 3]
  print $ pertence "Ades" ["Jose", "Carlos"]
  print $ f 5
  print $ f 6.2
  print $ fat 6
  print $ countDigits $ fat 1000

-- Prefix functions
f2' x y = x + y

(+-+-*) :: (Num a) => a -> a -> a
-- Infix functions (+-+-* is the name of the function)
x +-+-* y = x + y

f :: (Num a) => a -> a
f x = x + 1

pertence :: (Eq a) => a -> [a] -> Bool
e `pertence` [] = False
e `pertence` (x : xs)
  | e == x = True
  | otherwise = e `pertence` xs

fat :: Integer -> Integer
fat 0 = 1
fat n = n * fat (n - 1)

-- Função para contar dígitos de um número inteiro positivo
countDigits :: Integer -> Integer
countDigits 0 = 1
countDigits x = go (abs x) 0
  where
    go 0 c = c
    go n c = go (n `div` 10) (c + 1)
