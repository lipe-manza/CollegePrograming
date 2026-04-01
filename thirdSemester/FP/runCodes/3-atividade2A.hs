main :: IO ()
main = do
  linha1 <- getLine
  let x = read linha1 :: Int

  linha2 <- getLine
  let y = read linha2 :: Int

  print $ length ilter ehDefeituoso
ehDefeituoso x y = p[x..y]
    where
        

somaDivisores :: Int -> Int
somaDivisores n = sum [d | d <- [1 .. n - 1], n `mod` d == 0]
