// https://www.codewars.com/kata/last-digit-of-a-huge-number/train/go

package kata

// LastDigit kata
func LastDigit(as []int) int {
	if len(as) == 0 {
		return 1
	}
	return newSimpleModPowBase(as[0], 10).ModPowMulti(as[1:]...)
}

type modPowBase struct {
	resultsPrefix []int
	resultsCycle  []int
}

func newSimpleModPowBase(x, n int) *modPowBase {
	// Assume: x >= 0; n > 0
	currentValue := 1 % n
	values := make([]int, 0, n)
	values = append(values, currentValue)
	indexByValue := map[int]int{currentValue: 0}

	for {
		currentValue = (currentValue * (x % n)) % n
		if _, exists := indexByValue[currentValue]; exists {
			break
		} else {
			currentValueIndex := len(values)
			values = append(values, currentValue)
			indexByValue[currentValue] = currentValueIndex
		}
	}

	cycleStartPos := indexByValue[currentValue]
	return &modPowBase{
		resultsPrefix: values[:cycleStartPos],
		resultsCycle:  values[cycleStartPos:],
	}
}

func newDerivedModPowBase(x int, n *modPowBase) *modPowBase {
	// Assume: x >= 0
	currentValue := n.ModPowAgainstPower(x, 0)
	values := make([]int, 0, n.Len())
	values = append(values, currentValue)
	indexByValue := map[int]int{currentValue: 0}

	for e := 1; true; e++ {
		currentValue = n.ModPowAgainstPower(x, e)
		if _, exists := indexByValue[currentValue]; exists {
			break
		} else {
			currentValueIndex := len(values)
			values = append(values, currentValue)
			indexByValue[currentValue] = currentValueIndex
		}
	}

	cycleStartPos := indexByValue[currentValue]
	return &modPowBase{
		resultsPrefix: values[:cycleStartPos],
		resultsCycle:  values[cycleStartPos:],
	}
}

func (c *modPowBase) Len() int {
	return c.PrefixLen() + c.CycleLen()
}

func (c *modPowBase) PrefixLen() int {
	return len(c.resultsPrefix)
}

func (c *modPowBase) CycleLen() int {
	return len(c.resultsCycle)
}

func (c *modPowBase) ModPow(y int) int {
	if y < c.PrefixLen() {
		return c.resultsPrefix[y]
	}
	return c.resultsCycle[(y-c.PrefixLen())%c.CycleLen()]
}

func (c *modPowBase) ModPowAgainstPower(y, z int) int {
	// Assume: y, z >= 0
	if z == 0 {
		return c.ModPow(1)
	} else if y == 0 {
		return c.ModPow(0)
	} else if y == 1 {
		return c.ModPow(1)
	}

	// Currently: y >= 2; z >= 1
	powerValue := y
	for i := 1; i <= z; i, powerValue = i+1, powerValue*y {
		if powerValue >= c.PrefixLen() {
			// If we get here, the result is NOT in the cycle prefix
			resultPos := newSimpleModPowBase(y, c.CycleLen()).ModPow(z) - c.PrefixLen()
			for resultPos < 0 {
				resultPos += c.CycleLen()
			}
			return c.resultsCycle[resultPos]
		}
	}
	return c.resultsPrefix[powerValue]
}

func (c *modPowBase) ModPowMulti(as ...int) int {
	if len(as) == 0 {
		return c.ModPow(1)
	} else if len(as) == 1 {
		return c.ModPow(as[0])
	} else if len(as) == 2 {
		return c.ModPowAgainstPower(as[0], as[1])
	}
	return newDerivedModPowBase(as[0], c).ModPowMulti(as[1:]...)
}
