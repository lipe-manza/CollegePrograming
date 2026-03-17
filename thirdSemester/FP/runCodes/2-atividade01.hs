main :: IO ()
main = do
  a <- readLn :: IO Double
  b <- readLn :: IO Double
  c <- readLn :: IO Double

  printCases a b c 

isValid a b c
    | a < b + c && b < a + c && c < a + b = True
    | a ==b && a==c && a== 0 = True
    | otherwise = False


calcArea  a b c =  
    area
    where   
        area = sqrt $ p* (p-a)*(p-b)*(p-c)
        p = (/2) $ a + b +  c

printCases  a b c 
    | isValid a b c = print $ calcArea a b c
    | otherwise = putStrLn "-"
