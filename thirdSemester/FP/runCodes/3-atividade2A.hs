main :: IO ()
main = do
  linha1 <- getLine
  let x = read linha1 :: Int

  linha2 <- getLine
  let y = read linha2 :: Int

  print $ length (ehDefeituoso x y)
  print $ length (ehPerfeito x y)
  print $ length (ehAbundante x y)

ehDefeituoso :: Int -> Int -> [Int]
ehDefeituoso x y = [s | s <- [x .. y], somaDivisores s < s]

ehPerfeito :: Int -> Int -> [Int]
ehPerfeito x y = [s | s <- [x .. y], somaDivisores s == s]

ehAbundante :: Int -> Int -> [Int]
ehAbundante x y = [s | s <- [x .. y], somaDivisores s > s]

somaDivisores :: Int -> Int
somaDivisores n = sum [d | d <- [1 .. n - 1], n `mod` d == 0]
