/*
	 Profit Calculator
			- Ask user for:
				- revenue, expenses, and tax rate
			- Calculate
				- Earnings before tax (earningBeforeTax = revenue - expenses)
				- Earnings after tax (earningsAfterTax = (revenue - expenses) * (taxRate/100))
				- Percent of profit after expenses (earningsBeforeTax / profit)
			- Display:
				- Earnings before tax
				- profit
				- profit ratio

V2 Update:

	1- Validate user input
		- Show error messages & exit if invalid input is provided
		- No negative numbers
		- not 0
	2- Store calculated results in file
*/
package main

import (
	"errors"
	"fmt"
	"os"
)

const FILE_NAME = "results.txt"

func main() {
	fmt.Println("**** Profit Calculator ****")

	// Variables
	var revenue float64
	var expensesTotal float64
	var taxRate float64
	var earningsBeforeTax float64
	var earningsAfterTax float64
	var profitRatio float64

	// User inputs
	var err error
	revenue, err = getUserFloatInput("Total revenue? $")
	if err != nil {
		fmt.Println(err)
		return
	}

	expensesTotal, err = getUserFloatInput("Expense total? $")
	if err != nil {
		fmt.Println(err)
		return
	}

	taxRate, err = getUserFloatInput("Tax rate (%)? ")
	if err != nil {
		fmt.Println(err)
		return
	}

	earningsBeforeTax = getEarningsBeforeTax(revenue, expensesTotal)
	earningsAfterTax = getEarningsAfterTax(earningsBeforeTax, taxRate)
	profitRatio = getProfitRatio(earningsAfterTax, revenue)

	fmt.Println("-------------------------")
	fmt.Printf("Earning before tax: $%.2f\n", earningsBeforeTax)
	fmt.Printf("Profit: $%.2f\n", earningsAfterTax)
	fmt.Printf("Profit ratio: %.1f%%\n", profitRatio)

	resultString := fmt.Sprintf("Earning before tax: $%.2f\nProfit: $%.2f\nProfit ratio: %.1f%%\n", earningsBeforeTax, earningsAfterTax, profitRatio)

	writeToFile(resultString)

}

// get user input
func getUserFloatInput(prompt string) (userInput float64, err error) {
	fmt.Print(prompt)
	fmt.Scan(&userInput)

	// Error handling if value is less then 1
	if userInput <= 0 {
		return 0, errors.New("[ERROR] value must be greater than 0")
	}

	return userInput, nil
}

// Calculate the earning before tax
func getEarningsBeforeTax(revenue float64, expensesTotal float64) float64 {
	return (revenue - expensesTotal)
}

// Calculate the earnings after task and return it
func getEarningsAfterTax(earningsBeforeTax float64, taxRate float64) float64 {
	return earningsBeforeTax - (earningsBeforeTax * (taxRate / 100))
}

// Calculate profit ratio
func getProfitRatio(earningsAfterTax float64, revenue float64) float64 {
	return (earningsAfterTax / revenue) * 100
}

// Write to file
func writeToFile(data string) {
	err := os.WriteFile(FILE_NAME, []byte(data), 0644)

	if err != nil {
		fmt.Println(err)
		return
	}
}
