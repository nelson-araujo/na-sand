"use strict";

// ****************************************************************************
// String template
// ****************************************************************************
// console.log(`String templates`);
// // const myName = "Nelson"; // Don't use name since it's a reserved keyword
// const age = 46;
// const job = "enginer";

// const nelson = `My name is ${myName}, I'm" a ${age} year old ${job}`;
// console.log(nelson);
//
// Multiline
// console.log(`\n\nMultipline string template`);
// const nelson2 = `${myName}:
//   - ${age} years old
//   - ${job}`;
//
// console.log(nelson2);

// ****************************************************************************
// Switch statement
// ****************************************************************************
// console.log(`\n\n Switch Statement \n`);
// const day = "Monday";
//
// switch (day) {
//   case "Monday": // Day === "Monday"
//     console.log(`Today is Monday`);
//     break;
//
//   case "Tuesday":
//     console.log(`Today is Tuesday`);
//     break;
//
//   case "Wednesday": // Empty case with no break, it prints both Wednesday and Thrusday
//
//   case "Thursday":
//     console.log(`Today is Thursday`);
//     break;
//
//   case "Friday":
//     console.log(`Today is Friday`);
// }

/******************************************************************************
 * For loop
 *****************************************************************************/
// console.log(`---- For loop ----`);
// const nelson = ["Nelson", "Araujo", 1980, "Enginer"];
// const dataTypes = [];
//
// for (let i = 0; i < nelson.length; i++) {
//   dataTypes[i] = typeof nelson[i];
//
//   console.log(`${nelson[i]} --> ${dataTypes[i]}`);
// }
//
// // Only display strings using continue
// console.log("\nStrings only with continue");
// for (let i = 0; i < nelson.length; i++) {
//   dataTypes[i] = typeof nelson[i];
//
//   if (dataTypes[i] !== "string") {
//     continue; // skip this current iteration because it's not a string
//   }
//
//   console.log(`${nelson[i]} --> ${dataTypes[i]}`);
// }
//
// // Only display until it finds a number
// console.log("\nShow until it finds a number");
// for (let i = 0; i < nelson.length; i++) {
//   dataTypes[i] = typeof nelson[i];
//
//   if (dataTypes[i] === "number") {
//     console.log(`${nelson[i]} is a number; exiting`);
//     break; // Exit the loop if the data type is a number
//   }
//
//   console.log(`${nelson[i]} --> ${dataTypes[i]}`);
// }
//
// // calculate tip
// console.log(`\nCalculate Tip`);
// let totals = [];
// const bills = [125, 555, 44];
//
// function calcTip(billAmount) {
//   if (billAmount > 50 && billAmount < 300) {
//     return billAmount * 0.15;
//   } else {
//     return billAmount * 0.2;
//   }
// }
//
// for (let i = 0; i < bills.length; i++) {
//   totals[i] = bills[i] + calcTip(bills[i]);
// }
//
// console.log(`${bills}`);
// console.log(`${totals}`);

/******************************************************************************
 * while loop
 ******************************************************************************/
// console.log(`--- while loop --- `);
//
// let dice = 0;
//
// while (dice !== 6) {
//   dice = Math.trunc(Math.random() * 6) + 1; // Get a whole number between 1 and 6
//
//   if (dice === 6) {
//     console.log(`You rolled a ${dice}, congratulations!`);
//   } else {
//     console.log(`You rolled a ${dice}; try again!`);
//   }
// }

/******************************************************************************
 * Terniary operator
 *******************************************************************************/
// const age = 27;
// age >= 21 ? console.log(`Drink`) : console.log(`Don't drink!`);
//
// const isOfAge = age >= 21 ? true : false;
// console.log(`Can drink?: ${isOfAge}`);

//******************************************************************************
// Testing strict mode
//******************************************************************************
// let hasDriversLicence = false;
// const passTest = true;
//
// if (passTest) hasDriverLicense = true; // fail because it's the wrong variable strict will identify this
// if (hasDriversLicence) console.log(`I can drive :D`);

/******************************************************************************
 * Functions
 ******************************************************************************/
// Basic function declaration
// const number1 = 10;
// const number2 = 20;
//
// function sum(num1, num2) {
//   console.log(`My first function`);
//
//   const sum = num1 + num2;
//
//   return sum;
// }
//
// const result = sum(number1, number2);
// console.log(`Sum of ${number1} and ${number2} is ${result}.`);
//
// // function declaration
// function calcAge1(birthYear) {
//   return 2037 - birthYear;
// }
//
// //function expression
// const calcAge2 = function (birthYear) {
//   return 2037 - birthYear;
// };
//
// // Arrow function
// const calcAge3 = (birthYear) => 2037 - birthYear;
//
// // More complext arrow function
// const yearsUntilRetirement = (birthYear, firstName) => {
//   const age = 2037 - birthYear;
//   const retirement = 65 - age;
//   return `${firstName} retires in ${retirement} years!`;
// };
//
// const age1 = calcAge1(1991);
// const age2 = calcAge2(1991);
// const age3 = calcAge3(1991);
//
// console.log(`age1: ${age1}\nage2: ${age2}\nage3: ${age3}`);
// console.log(yearsUntilRetirement(1980, "Nelson"));

/******************************************************************************
 * Arrays
 ******************************************************************************/
// // simple declaration
// const daysOfWeekend = ["Saturday", "Sunday"];
// console.log(`${daysOfWeekend}`);
//
// const daysOfWorkWeek = new Array(
//   "Monday",
//   "Tuesday",
//   "Wednesday",
//   "Thursday",
//   "Friday",
// );
// console.log(`${daysOfWorkWeek}`);
//
// // Update an array
// daysOfWeekend[0] = "Sat";
// daysOfWeekend[1] = "Sun";
//
// console.log(
//   `${daysOfWorkWeek[0]} is the first day of the ${daysOfWorkWeek.length} work week`,
// );
//
// // Array inside another array
// const daysOfTheWeek = [daysOfWorkWeek, daysOfWeekend];
// console.log(`${daysOfTheWeek}`);
//
// // Use push to append and expand the array
// const friends = ["Michael", "Steven", "Peter"];
// console.log(friends);
//
// // add a new friend to the end and expand array
// friends.push("Jay");
// console.log(friends);
//
// // add a new friend to the start and expand array
// friends.unshift("John");
// console.log(friends);
//
// // remove the last element of the array
// const removedElement = friends.pop(); // returns removed element
// console.log(`popped "${removedElement}".`);
// console.log(friends);
//
// // remove the first element of the array
// const removedElement2 = friends.shift();
// console.log(`shifted ${removedElement2}`);
// console.log(friends);
//
// // Find an element in an array and return index
// const myFriend = "Peter";
// console.log(`${myFriend} is at index ${friends.indexOf(myFriend)}`);
// console.log(`Do I have a friend named Dogfood? ${friends.indexOf("Dogfood")}`);
//
// // Find if the array includes a specific entry and return true/false
// console.log(`Do I have a friend named Dogfood? ${friends.includes("Dogfood")}`);

/*******************************************************************************
 * objects
 ******************************************************************************/
// console.log(`objects`);
// const jonas = {
//   firstName: "Jonas",
//   lastName: "Schmedtmann",
//   birthYear: 1991,
//   age: 0,
//   job: "teacher",
//   friends: ["Michael", "Peter", "Steven"],
//   hasDriverLicense: true,
//
//   calcAge: function (birthYear) {
//     return 2037 - birthYear;
//   },
//
//   calcAge2: function () {
//     this.age = 2037 - this.birthYear;
//     return this.age; // Good practice to also return the value
//   },
//
//   getSummary: function () {
//     return `${this.firstName} is a ${this.calcAge2()}-year old ${this.job}, he has ${this.hasDriverLicense ? "a" : "no"} driver license`;
//   },
// };
//
// // Get value via dot notation
// console.log(`${jonas.firstName}`);
//
// // Get value via square braket notation
// console.log(`${jonas["firstName"]}`);
//
// const nameKey = "Name";
// console.log(jonas["first" + nameKey]); // Get firstName
// console.log(jonas["last" + nameKey]); // Show lastName
//
// // Add entry
// jonas.location = "Portugal";
// jonas["twitter"] = "@jonasschmedtman";
// console.log(jonas.location, jonas.twitter);
//
// console.log(
//   `${jonas.firstName} has ${jonas.friends.length} friends, and his best friend is called ${jonas.friends[0]}`,
// );
//
// // calling a method
// console.log(`Jonas will be ${jonas.calcAge(1991)} year's old in 2037`);
// console.log(`Jonas will be ${jonas["calcAge"](1991)} year's old in 2037`);
// console.log(`Jonas will be ${jonas.calcAge2()} year's old in 2037`);
// console.log(`Jonas will be ${jonas.age} year's old in 2037`);
// console.log(jonas.getSummary());
