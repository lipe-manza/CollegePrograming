qs [] = []
qs [x] = [x]
qs (p:xs) =
    qs [x | x <- xs, x < p]
    ++ [p]
    ++ qs [x | x <- xs, x >= p]

main :: IO ()
main = do
    let l = [5,2,8,1,3]
    print (qs l)