import Data.List

solveRPN :: (Num a, Read a) => String -> a
solveRPN expression = head (foldl foldingFunction [] (words expression))
    where foldingFunction (x:y:ys) "*" = (x * y):ys
          foldingFunction (x:y:ys) "+" = (x + y):ys
          foldingFunction (x:y:ys) "-" = (y - x):ys
          foldingFunction (x:y:ys) "/" = (y / x):ys  
          foldingFunction (x:y:ys) "^" = (y ** x):ys  
          foldingFunction (x:xs) "ln" = log x:xs  
          foldingFunction xs "sum" = [sum xs]  
          foldingFunction xs numberString = read numberString:xs  
          