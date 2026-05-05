type Agenda = [(String, String)]

main :: IO ()
main = loop []

loop :: Agenda -> IO ()
loop agenda = do
  linha <- getLine

  if null linha
    then return ()
    else case words linha of
      ["adicionar", nome, numero] -> do
        let novaAgenda =
              case buscar nome agenda of
                Nothing -> (nome, numero) : agenda
                Just _ -> (nome, numero) : [(n, i) | (n, i) <- agenda, n /= nome]

        loop novaAgenda
      ["buscar", nome] -> do
        case buscar nome agenda of
          Nothing -> putStrLn "Contato nao encontrado."
          Just (n, i) -> putStrLn (n ++ " - " ++ i)
        loop agenda
      ["remover", nome] -> do
        let novaAgenda = remover nome agenda
        if novaAgenda == agenda
          then putStrLn "Contato nao encontrado."
          else putStrLn "Contato removido."
        loop novaAgenda
      ["listar"] -> do
        listar agenda
        loop agenda
      ["sair"] -> do
        putStrLn "Encerrando."
        return ()

buscar :: String -> [(String, String)] -> Maybe (String, String)
buscar _ [] = Nothing
buscar nome ((n, i) : xs)
  | nome == n = Just (n, i)
  | otherwise = buscar nome xs

listar :: [(String, String)] -> IO ()
listar [] = return ()
listar ((nome, num) : xs) = do
  putStrLn (nome ++ " - " ++ num)
  listar xs

remover :: String -> [(String, String)] -> [(String, String)]
remover _ [] = []
remover nome ((x, y) : xs)
  | nome == x = xs
  | otherwise = (x, y) : remover nome xs