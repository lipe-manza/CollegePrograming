main:: IO()
main = do
    print "HW"
    print $ f 5
    print $ f (-1)
    print $ g (-4) (-1) (-5)
    print $ m
    case h 5 of
        Left f -> print f
        Right [] -> print "Empty list"
        Right (x:xs) -> print x


safeDiv :: (Fractional a, Eq a) => a -> a -> Either String a
safeDiv _ 0 = Left "Division by zero"
safeDiv x y = Right (x / y)

safeInverse :: (Fractional a, Eq a) => a -> Either String a
safeInverse 0 = Left ("Inverse of zero")
safeInverse x = Right (1 / x)

h :: Int -> Either Float [Int]
h 0 = Left 3.14
h x = Right [-x,x]

f x = do
    a <- safeInverse x
    b <- safeDiv a (x + 1)
    let c = a + b
    d <- safeInverse (c+1)
    return d

baskara a b c
    | a == 0 = [(-c)/b]
    | delta < 0 = []
    | delta == 0 = [x]
    | otherwise = [x', x'']
    where
        delta = b^2 - 4*a*c
        sqdelta = sqrt delta
        x = (-b)/(2*a)
        x' = (-b - sqdelta) / (2*a)
        x'' = (-b + sqdelta) / (2*a)

g :: Float -> Float -> Float -> [Float]
g a b c = do
    x <- baskara a 3 5
    y <- baskara b 2 7
    z <- baskara c 9 2
    let w = x + y + z
    k <-[-w,w +1]
    return k

m = do
    x<- [1..3]
    y <- [2,4,5]
    let w = x * y
    z <- [-w, w + 1]
    return z



--Left e >>= _ = Left e
--Right x >>= f = f x
