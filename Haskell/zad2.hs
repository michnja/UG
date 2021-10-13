myGcd :: (Ord a, Num a) => a -> a -> a
myGcd n m
  | n == m = n
  | n < m = myGcd n (m - n)
  | n > m = myGcd (n - m) m

myLcm :: (Fractional a, Ord a) => a -> a -> a
myLcm n m = (n * m) / myGcd n m

main :: IO ()
main = print [myGcd 21 14, lcm 4 9]