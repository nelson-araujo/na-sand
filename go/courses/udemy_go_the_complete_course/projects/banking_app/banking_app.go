package main

import(
	"fmt"
	"os"
	"strconv"
)

const BALANCE_FILE_NAME = "balance"

func main(){
	exit := false

	fmt.Println("Welcome to The Bank")
	fmt.Println("-------------------")

	for !exit {

		// Menu
		fmt.Println(" 1 - Balance")
		fmt.Println(" 2 - Deposit")
		fmt.Println(" 3 - Withdraw")
		fmt.Println(" 4 - Exit")

		userSelection := getUserSelection()

		if userSelection == 1 {
			printBalance()

		} else if userSelection == 2 {
			deposit()

		} else if userSelection == 3 {
			withdraw()

		} else if userSelection == 4 {
			exit = true

		} else {
			fmt.Println("Unknown entry")

		}
	}
}

// Get the user menu selection
func getUserSelection() int {
	fmt.Printf("I wan to: ")
	var userSelection int 

	fmt.Scan(&userSelection)

	return userSelection
}

// Print the current balance
func printBalance() {
	balance := getBalanceFromFile()

	fmt.Printf("Current balance is $%.2f\n", balance)
}

// get balance from balance file
func getBalanceFromFile() float64 {
	// get file contents
	balanceByte, err := os.ReadFile(BALANCE_FILE_NAME)

	if err != nil {
		// Create file with 0 balance
		writeBalanceToFile(0)
		return 0.0
	}

	// convert byte array to string
	balanceString := string(balanceByte)

	//convert string to float64
	balance, err := strconv.ParseFloat(balanceString, 64)
	
	if err != nil {
		panic("Unable to convert string to float")
	}

	return balance
}

// Write to balance file
func writeBalanceToFile(balance float64) {
	// Convert balance to string
	balanceString := fmt.Sprint(balance)
	
	// write to file
	os.WriteFile(BALANCE_FILE_NAME, []byte(balanceString), 0644)
}

// Deposit money
func deposit() {
	var depositAmmount float64

	// Get value to deposit
	var isValid = false
	for !isValid {
		fmt.Printf("How much?: ")
		fmt.Scan(&depositAmmount)

		// check is the value entered is valid
		if depositAmmount <= 0 {
			fmt.Println("Invalid ammount, must be greater than 0")
		} else {
			isValid = true
		}
	}

	balance := getBalanceFromFile()
	balance += depositAmmount

	writeBalanceToFile(balance)

	fmt.Printf("$%.2f has been deposited, you new balance is $%.2f\n", depositAmmount, balance) 

}

// Withdraw
func withdraw(){
	var withdrawAmmount float64
	balance := getBalanceFromFile()

	if balance == 0 {
		fmt.Println("Unable to withdraw, your account balance is $0.")
		return
	}

	// Get value to withdraw
	isValid := false
	for !isValid {
		fmt.Printf("How much?: ")
		fmt.Scan(&withdrawAmmount)

		// Check if the value entered is valid
		if withdrawAmmount <= 0 {
			fmt.Println("Invalid ammount, must be greater than 0")

		} else if withdrawAmmount > balance {
			fmt.Printf("Invalid ammount, must be less than $%.2f\n", balance)

		} else {
			isValid = true

		}
	}

	balance -= withdrawAmmount

	writeBalanceToFile(balance)

	fmt.Printf("$%.2f has been withdrawn, your remaining balance is $%.2f\n", withdrawAmmount, balance)

}
