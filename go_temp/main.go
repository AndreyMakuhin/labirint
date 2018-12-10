package main

import "math"

func myFunc(x float64) float64 {
	k := 1.0
	b := 0.0
	return (k*x + b)
}

func divideAndFind(left float64, right float64) float64 {
	mid := (right - left) / 2
	if math.Abs(right-left) < 0.01 {
		return mid
	}

	if (myFunc(left) < 0 && myFunc(mid) > 0) ||
		(myFunc(left) > 0 && myFunc(mid) < 0) {
		return divideAndFind(left, mid)
	} else if (myFunc(right) < 0 && myFunc(mid) > 0) ||
		(myFunc(right) > 0 && myFunc(mid) < 0) {
		return divideAndFind(mid, right)
	} else {
		return 0.0
	}
}

func main() {
	print(divideAndFind(-10.0, 10.0))
}
