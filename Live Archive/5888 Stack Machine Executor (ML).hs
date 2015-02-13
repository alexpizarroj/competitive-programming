import Control.Monad.Trans.Class
import Control.Monad.Trans.State

default (Int)

data Instruction = NUM Int
                 | POP
                 | INV
                 | DUP
                 | SWP
                 | ADD
                 | SUB
                 | MUL
                 | DIV
                 | MOD
                 deriving (Read, Show, Eq)

type Stack = [Int]

type Command a = StateT Stack Maybe a

-- primitives

pop :: Command Int
pop = do
  s <- get
  case s of
    (x:xs)    -> do
      put xs
      return x
    _         -> lift Nothing

push :: Int -> Command ()
push x = do
  s <- get
  put (x:s)

binOp :: (Int -> Int -> Int) -> Command ()
binOp op = do
  x <- pop
  y <- pop
  let val = y `op` x
  if abs val > (10 ^ 9) then
    lift Nothing
  else
    push val

divOp :: (Int -> Int -> Int) -> Command ()
divOp op = do
  x <- pop
  if x == 0 then
    lift Nothing
  else do
    y <- pop
    push (y `op` x)

-- compilation

compile :: Instruction -> Command ()

compile (NUM x) = push x

compile POP     = pop >> return ()

compile INV     = do
  x <- pop
  push $ negate x

compile DUP     = do
  x <- pop
  push x
  push x

compile SWP     = do
  x <- pop
  y <- pop
  push x
  push y

compile ADD     = binOp (+)
compile SUB     = binOp (-)
compile MUL     = binOp (*)
compile DIV     = divOp div
compile MOD     = divOp mod

-- problem

type Program = [Instruction]

type Inputs = [Int]

data Case = Case Program Inputs

single :: [a] -> Maybe a
single [x] = Just x
single _   = Nothing

readProgram :: IO (Maybe Program)
readProgram = do
  ln <- getLine
  if ln == "QUIT" then
    return Nothing
  else do
    is <- go
    return $ Just (read ln : is)
  where
    go = do
      ln <- getLine
      if ln == "END" then
        return []
      else do
        is <- go
        return (read ln : is)

readCase :: IO (Maybe Case)
readCase = do
  mprog <- readProgram
  case mprog of
    Nothing   -> return Nothing
    Just prog -> do
      n <- readLn
      xs <- mapM (const readLn) [1..n]
      return $ Just $ Case prog xs

runProgram :: Program -> Stack -> Maybe Int
runProgram prog s = single =<< execStateT (mapM compile prog) s

runCase :: Case -> [Maybe Int]
runCase (Case prog ins) = map (runProgram prog) $ map (:[]) ins

printAns :: Maybe Int -> IO ()
printAns ans = maybe (putStrLn "ERROR") print ans

main :: IO ()
main = do
  mc <- readCase
  case mc of
    Nothing -> return ()
    Just c  -> do
      mapM_ printAns $ runCase c
      main -- recurse (:
