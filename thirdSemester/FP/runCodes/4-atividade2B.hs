main :: IO ()
main = do
  linha1 <- getLine
  let x = read linha1 :: Int

  linha2 <- getLine
  let y = read linha2 :: Int

  print $ maxIntervalo $ filter (>= x) $ takeWhile (<= y) primos

primos :: [Int]
primos = p [2 ..]
  where
    p (x : xs) = x : p [y | y <- xs, mod y x /= 0]

maxIntervalo :: [Int] -> Int
maxIntervalo xs
    |null xs = 0
    |length xs == 1 = 0
    |otherwise  = maximum $ [b - a | (a, b) <- zip xs (drop 1 xs)]
