package kata_test

import (
  . "math/rand"
  . "math"
  . "github.com/onsi/ginkgo"
  . "github.com/onsi/gomega"
  . "codewarrior/kata"
)

var _ = Describe("Test Example", func() {
  It("should handle basic cases", func() {
    Expect(LastDigit( []int{}                     )).To(Equal(1))
    Expect(LastDigit( []int{0,0}                  )).To(Equal(1)) // 0 ^ 0
    Expect(LastDigit( []int{0,0,0}                )).To(Equal(0)) // 0^(0 ^ 0) = 0^1 = 0
    Expect(LastDigit( []int{1,2}                  )).To(Equal(1))
    Expect(LastDigit( []int{3,4,5}                )).To(Equal(1))
    Expect(LastDigit( []int{4,3,6}                )).To(Equal(4))
    Expect(LastDigit( []int{7,6,21}               )).To(Equal(1))
    Expect(LastDigit( []int{12,30,21}             )).To(Equal(6))
    Expect(LastDigit( []int{2,0,1}                )).To(Equal(1))
    Expect(LastDigit( []int{2,2,2,0}              )).To(Equal(4))
    Expect(LastDigit( []int{937640,767456,981242} )).To(Equal(0))
    Expect(LastDigit( []int{123232,694022,140249} )).To(Equal(6))
    Expect(LastDigit( []int{499942,898102,846073} )).To(Equal(6))
  })
  
  It("should handle random cases", func() {
    var r1 int = Intn(100)
    var r2 int = Intn(10)
    var pow int = int(Pow(float64(r1 % 10), float64(r2)))

    Expect(LastDigit( []int{}       )).To(Equal(1))
    Expect(LastDigit( []int{r1}     )).To(Equal(r1 % 10))
    Expect(LastDigit( []int{r1, r2} )).To(Equal(pow % 10))
  })
})
