import Data.List (sort, sortBy)
import Data.Ord (comparing)

-- estrutura do país
data Pais = Pais
  { nome        :: String
  , confirmados :: Int
  , mortes      :: Int
  , recuperados :: Int
  , ativos      :: Int
  } deriving (Show, Read)

-- separa uma linha CSV por vírgula
parser :: String -> [String]
parser [] = []
parser xs =
  let (a, rest) = break (== ',') xs
  in a : parser (drop 1 rest)

-- tira espaço só das pontas
trim :: String -> String
trim = f . f
  where f = reverse . dropWhile (== ' ')

-- transforma uma linha do CSV em Pais
parsePais :: String -> Pais
parsePais l =
  let [n, c, d, r, a] = map trim (parser l)
  in Pais n (read c) (read d) (read r) (read a)

-- checa se a linha é o cabeçalho do arquivo
ehCabecalho :: String -> Bool
ehCabecalho l = take 7 l == "Country"

main :: IO ()
main = do
  entrada <- getLine
  let [n1, n2, n3, n4] = map read (words entrada)

  conteudo <- readFile "dados.csv"

  -- limpa linhas vazias e remove cabeçalho
  let linhas =
        filter (\l -> not (null l) && not (ehCabecalho l)) (lines conteudo)

  let paises = map parsePais linhas

  -- 1: soma dos ativos dos países com confirmados >= n1
  print $
    sum $
    map ativos $
    filter ((>= n1) . confirmados) paises

  -- 2:
  -- pega os n2 países com mais ativos
  -- depois ordena por confirmados crescente
  -- pega n3 primeiros e soma mortes
  print $
    sum $
    map mortes $
    take n3 $
    sortBy (comparing confirmados) $
    take n2 $
    sortBy (flip (comparing ativos)) paises

  -- 3:
  -- pega os n4 países com mais confirmados
  -- depois ordena os nomes em ordem alfabética
  -- imprime um por linha
  mapM_ putStrLn $
    sort $
    map nome $
    take n4 $
    sortBy (flip (comparing confirmados)) paises