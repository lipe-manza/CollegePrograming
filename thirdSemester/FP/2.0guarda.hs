main :: IO ()
main = do
  print "HW"
  print (sinal 6)
  print (baskara 2 4 1)


-- função sinal (guarda)
sinal :: Int -> Int
sinal x
  | x < 0 = -1
  | x == 0 = 0
  | otherwise = 1

-- função baskara
baskara :: Double -> Double -> Double -> [Double]
baskara a b c
  | delta < 0 = []
  | delta == 0 = [x]
  | otherwise = [x', x'']
  where
    delta = b ^ 2 - 4 * a * c
    x = (-b) / (2 * a)
    sqdelta = sqrt delta
    x' = (-b + sqdelta) / (2 * a)
    x'' = (-b - sqdelta) / (2 * a)


