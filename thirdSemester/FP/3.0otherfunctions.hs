main :: IO()
main = do
    print $ take 10 primos
    print $ take 11 $ iteracao (*2) 1
    print $ take 10 fibs


iteracao f x = x:iteracao f (f x)

primos = p [2..]
    where
        p(x:xs) = x:p [y | y <-xs , mod y x /=0]

fibs = 1:1:zipWith (+) fibs (tail fibs)