-- Função que recebe uma lista de números e retorna a soma
processaNumeros :: [Int] -> Int
processaNumeros lista = sum [x * 2 | x <- lista, x > 0]

-- Função principal para testar
main :: IO ()
main = do
    let numeros = [-5, 3, 0, 2, -1, 4]
    let resultado = processaNumeros numeros
    putStrLn $ "O resultado da soma do dobro dos positivos é: " ++ show resultado