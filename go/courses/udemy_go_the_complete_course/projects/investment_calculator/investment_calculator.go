package main

import (
	"fmt"
	"math"
)

func main(){
	const INFLATION_RATE float64 = 2.5

	var investmentAmmount float64
	var expectedReturnRate float64
	var years float64

	fmt.Println("**** Investment Calculator ****")
	
	fmt.Print("How much are you investing? ")
	fmt.Scan(&investmentAmmount)

	fmt.Print("How many years will you be investing? ")
	fmt.Scan(&years)

	fmt.Print("What is the expected return rate(%)? ")
	fmt.Scan(&expectedReturnRate)

	var futureValue = investmentAmmount *  math.Pow(1 + expectedReturnRate/100, years)
	futureRealValue := futureValue / math.Pow(1 + INFLATION_RATE/100, years)

	fmt.Println(futureValue)
	fmt.Println(futureRealValue)
}
