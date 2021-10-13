nwd_2 :: Double -> Double -> Double
nwd_2 a b
	a == b = a
	a > b = nwd_2 (a-b) b
	otherwise = nwd_2 a (b-a)