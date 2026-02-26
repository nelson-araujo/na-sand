"use strict";

// STring template
// console.log(`String templates`);
// // const myName = "Nelson"; // Don't use name since it's a reserved keyword
// const age = 46;
// const job = "enginer";

// const nelson = `My name is ${myName}, I'm" a ${age} year old ${job}`;
// // console.log(nelson);
//
// // Multiline
// // console.log(`\n\nMultipline string template`);
// const nelson2 = `${myName}:
//   - ${age} years old
//   - ${job}`;
//
// // console.log(nelson2);
//
// // Switch statement
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

// Terniary operator
// const age = 27;
// age >= 21 ? console.log(`Drink`) : console.log(`Don't drink!`);
//
// const isOfAge = age >= 21 ? true : false;
// console.log(`Can drink?: ${isOfAge}`);

// Testing strict mode
// let hasDriversLicence = false;
// const passTest = true;
//
// if (passTest) hasDriverLicense = true; // fail because it's the wrong variable strict will identify this
// if (hasDriversLicence) console.log(`I can drive :D`);

// Functions
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

// Arrays
// simple declaration
const daysOfWeekend = ["Saturday", "Sunday"];
console.log(`${daysOfWeekend}`);

const daysOfWorkWeek = new Array(
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursday",
  "Friday",
);
console.log(`${daysOfWorkWeek}`);

// Update an array
daysOfWeekend[0] = "Sat";
daysOfWeekend[1] = "Sun";

console.log(
  `${daysOfWorkWeek[0]} is the first day of the ${daysOfWorkWeek.length} work week`,
);

// Array inside another array
const daysOfTheWeek = [daysOfWorkWeek, daysOfWeekend];
console.log(`${daysOfTheWeek}`);
